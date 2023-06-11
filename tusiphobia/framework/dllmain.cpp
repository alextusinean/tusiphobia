#include "pch.h"

#include "hooks.h"
#include "main.h"

Hook il2cpp_runtime_invoke_hook;
HMODULE moduleHandle;

const char* (*original_il2cpp_method_get_name)(const MethodInfo*);

Il2CppObject* (*original_il2cpp_runtime_invoke)(const MethodInfo*, void*, void**, Il2CppException**);

Il2CppObject* il2cpp_runtime_invoke_detour(const MethodInfo* method, void* obj, void** params, Il2CppException** exc) {
	if (strstr(original_il2cpp_method_get_name(method), "Internal_ActiveSceneChanged")) {
		il2cpp_runtime_invoke_hook.detach();
		CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)run, moduleHandle, 0, NULL);
	}

	return original_il2cpp_runtime_invoke(method, obj, params, exc);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD callReason, LPVOID lpReserved) {
	if (callReason == DLL_PROCESS_ATTACH) {
		moduleHandle = hModule;

		HMODULE gameAssemblyModuleHandle = LoadLibraryA("GameAssembly.dll");
		if (!gameAssemblyModuleHandle) {
			printf("couldn't get GameAssembly module handle\n");
			return FALSE;
		}

#define GET_EXPORT(n) \
original_##n = (decltype(original_##n)) GetProcAddress(gameAssemblyModuleHandle, #n); \
if (!original_##n) { \
    printf("couldn't get %s procedure address\n", #n); \
    return FALSE; \
}

		GET_EXPORT(il2cpp_method_get_name)
			GET_EXPORT(il2cpp_runtime_invoke);

#undef GET_EXPORT

		il2cpp_runtime_invoke_hook = Hook(&(LPVOID&)original_il2cpp_runtime_invoke, il2cpp_runtime_invoke_detour);
		il2cpp_runtime_invoke_hook.attach();
	}

	return TRUE;
}