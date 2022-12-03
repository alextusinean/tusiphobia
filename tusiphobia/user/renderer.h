#pragma once

typedef HRESULT(__stdcall* ID3DPresent)(IDXGISwapChain* __this, UINT sync, UINT flags);

namespace Renderer {
	void* getPresent();
}
