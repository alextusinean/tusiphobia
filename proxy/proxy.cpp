#include "pch.h"

#include "proxy.h"
#include "exports.h"

#if __has_include("config.h")
#include "config.h"
#endif

#ifdef _DEBUG
bool debug = true;
#else
bool debug = false;
#endif

namespace fs = std::filesystem;
std::string messageBoxCaption;

void error(std::string message) {
	MessageBoxA(NULL, message.c_str(), messageBoxCaption.c_str(), MB_ICONERROR | MB_OK);
	exit(1);
}

std::string GetLastErrorString() {
	DWORD errorMessageId = GetLastError();
	if (errorMessageId == 0)
		return std::string("Success");

	LPSTR messageBuffer = NULL;
	size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL, errorMessageId, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR) &messageBuffer, 0, NULL);

	std::string message(messageBuffer, size);
	LocalFree(messageBuffer);

	return message;
}

void initialize(HMODULE moduleHandle) {
	if (strstr(GetCommandLineA(), "--tusiphobia-disable"))
		return;

	if (strstr(GetCommandLineA(), "--tusiphobia-debug"))
		debug = true;

	if (debug) {
		AllocConsole();

		FILE* file;
		freopen_s(&file, "CONOUT$", "w", stdout);
		freopen_s(&file, "CONOUT$", "w", stderr);
	}

	char modulePathBuffer[MAX_PATH];
	GetModuleFileNameA(moduleHandle, modulePathBuffer, MAX_PATH);

	fs::path modulePath(modulePathBuffer);
	std::string moduleName = modulePath.filename().string();
	std::transform(moduleName.begin(), moduleName.end(), moduleName.begin(), tolower);
	messageBoxCaption = moduleName + " - tusiphobia";

	size_t index;
	if (!Exports::isModuleCompatible(moduleName, &index)) {
		error("incompatible proxy name");
		return;
	}

	char systemPathBuffer[MAX_PATH];
	GetSystemDirectoryA(systemPathBuffer, MAX_PATH);

	HMODULE originalModule = LoadLibraryA((fs::path(systemPathBuffer) / moduleName).string().c_str());
	if (!originalModule) {
		printf("%s\n", GetLastErrorString().c_str());
		error("failed loading original dll");
		return;
	}

	Exports::load(index, originalModule);

	if (!strstr(GetCommandLineA(), "--tusiphobia-no-steam")) {
		std::string steamAppId;

		int argc = 0;
		LPWSTR* argv = CommandLineToArgvW(GetCommandLineW(), &argc);

		bool steamAppIdFound = false;
		for (int i = 0; i < argc; i++) {
			size_t argLength;
			char buffer[8191];
			wcstombs_s(&argLength, buffer, 8191, argv[i], 8191);

			std::string arg(buffer);
			std::transform(arg.begin(), arg.end(), arg.begin(), [](unsigned char c) { return std::tolower(c); });
			if (steamAppIdFound) {
				steamAppId = arg;
				break;
			}

			if (arg == "--tusiphobia-steam-app-id" && (i + 1) < argc)
				steamAppIdFound = true;
		}

#ifdef TUSIPHOBIA_STEAM_APPID
		if (!steamAppIdFound) {
			steamAppId = TUSIPHOBIA_STEAM_APPID;
			steamAppIdFound = true;
		}
#endif

		if (steamAppIdFound) {
			DWORD activeUser;
			DWORD activeUserSize = sizeof(activeUser);
			LSTATUS activeUserStatus = RegGetValueA(HKEY_CURRENT_USER,
				"SOFTWARE\\Valve\\Steam\\ActiveProcess\\", "ActiveUser",
				RRF_RT_REG_DWORD, nullptr, &activeUser, &activeUserSize);

			if (activeUserStatus != ERROR_SUCCESS || activeUser == 0) {
				error("Steam is not launched or no user is logged in");
				return;
			}

			char steamPath[MAX_PATH];
			DWORD steamPathSize = sizeof(steamPath);
			LSTATUS steamPathStatus = RegGetValueA(HKEY_CURRENT_USER,
				"SOFTWARE\\Valve\\Steam\\", "SteamPath",
				RRF_RT_REG_SZ, nullptr, steamPath, &steamPathSize);

			if (steamPathStatus != ERROR_SUCCESS) {
				error("failed getting Steam's path");
				return;
			}

			if (!SetEnvironmentVariableA("SteamAppId", steamAppId.c_str())) {
				printf("%s\n", GetLastErrorString().c_str());
				error("failed setting SteamAppId environment variable");
				return;
			}

			if (!LoadLibraryA((fs::path(steamPath) / "GameOverlayRenderer64.dll").string().c_str())) {
				error("failed loading GameOverlayRenderer64.dll");
				return;
			}
		}
	}

#ifdef _DEBUG
	fs::path tusiphobiaPath(TUSIPHOBIA_PATH);
#else
	fs::path tusiphobiaPath = modulePath.parent_path() / "tusiphobia.dll";
#endif

	if (!fs::exists(tusiphobiaPath)) {
		error("tusiphobia.dll is missing");
		return;
	}

	if (!LoadLibraryA(tusiphobiaPath.string().c_str())) {
		printf("%s\n", GetLastErrorString().c_str());
		error("failed loading tusiphobia");
	}
}
