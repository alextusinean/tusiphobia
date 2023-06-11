#include "pch.h"

#include "il2cpp-init.h"
#include "helpers.h"
#include "hooks.h"

#ifdef _DEBUG
bool debug = true;
#else
bool debug = false;
#endif

using namespace app;

// Set the name of your log file here
extern const LPCWSTR LOG_FILE = L"il2cpp-log.txt";

HMODULE hModule;
bool running = true;

int run() {
	if (strstr(GetCommandLineA(), "--tusiphobia.debug") != nullptr)
		debug = true;

	printf("tusiphobia initializing...\n");
	Hooks::init();

	printf("initialized successfully\n");
	while ((!debug || !GetAsyncKeyState(VK_END) & 1) && running) {
		Sleep(200);
	}

	printf("tusiphobia exiting...");
	Hooks::uninit();

	return 0;
}

void quit(int code) {
	FreeConsole();
	CloseHandle(GetCurrentThread());
	FreeLibraryAndExitThread(hModule, code);
}

void run(void* lpParameter) {
	hModule = (HMODULE)lpParameter;

	init_il2cpp();
	il2cpp_thread_attach(il2cpp_domain_get());

	quit(run());
}

void shutdown() {
	running = false;
}