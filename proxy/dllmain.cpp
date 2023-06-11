#include "pch.h"

#include "proxy.h"

BOOL APIENTRY DllMain(HMODULE moduleHandle, DWORD callReason, LPVOID lpReserved) {
	if (callReason != DLL_PROCESS_ATTACH)
		return TRUE;

	DisableThreadLibraryCalls(moduleHandle);
	initialize(moduleHandle);

	return TRUE;
}