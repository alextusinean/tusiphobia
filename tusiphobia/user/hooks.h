#pragma once

class Hook {
	void** target;
	void* detour;

public:
	Hook() : target{ nullptr }, detour{ nullptr } {}
	Hook(void** target, void* detour) : target{ target }, detour{ detour } { }

	void attach();
	void detach();
};

namespace Hooks {
	void init();
	void uninit();
}
