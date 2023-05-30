#include "pch.h"

#include "exports.h"

FARPROC OriginalFuncs_dwmapi[99];
FARPROC OriginalFuncs_psapi[27];
FARPROC OriginalFuncs_version[17];
FARPROC OriginalFuncs_winhttp[65];
FARPROC OriginalFuncs_winmm[181];

void Exports::load(HMODULE originalModule, const char* const* exportNames, FARPROC* originalFunctions, size_t arraySize) {
	for (int i = 0; i < arraySize; i++)
		originalFunctions[i] = GetProcAddress(originalModule, exportNames[i]);
}

bool Exports::isModuleCompatible(const std::string& moduleName, size_t* index) {
	for (int i = 0; i < compatibleModules.size(); i++) {
		if (moduleName == compatibleModules[i]) {
			*index = i;
			return true;
		}
	}

	return false;
}
