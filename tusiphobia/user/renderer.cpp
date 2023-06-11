#include "pch.h"

#include "renderer.h"

#pragma comment(lib, "d3d11.lib")

static const D3D_DRIVER_TYPE driverTypes[4] = { D3D_DRIVER_TYPE_REFERENCE, D3D_DRIVER_TYPE_SOFTWARE, D3D_DRIVER_TYPE_HARDWARE, D3D_DRIVER_TYPE_WARP };

bool getSwapChain(IDXGISwapChain** swapChain, ID3D11Device** device) {
	WNDCLASSEX wc{ 0 };
	wc.cbSize = sizeof(wc);
	wc.lpfnWndProc = DefWindowProc;
	wc.lpszClassName = TEXT("tusiphobia");

	if (!RegisterClassEx(&wc))
		return false;

	DXGI_SWAP_CHAIN_DESC description{ 0 };
	description.BufferCount = 1;
	description.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	description.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	description.OutputWindow = GetForegroundWindow();
	description.SampleDesc.Count = 1;
	description.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	description.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
	description.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	description.Windowed = TRUE;

	D3D_FEATURE_LEVEL level;
	bool success = false;

	for (const auto& driverType : driverTypes) {
		HRESULT hResult = D3D11CreateDeviceAndSwapChain(
			nullptr, driverType, nullptr, 0, NULL, 0,
			D3D11_SDK_VERSION, &description, swapChain,
			device, &level, nullptr
		);

		if (SUCCEEDED(hResult)) {
			success = true;
			break;
		}
	}

	DestroyWindow(description.OutputWindow);
	UnregisterClass(wc.lpszClassName, GetModuleHandle(nullptr));
	return success;
}

void* Renderer::getPresent() {
	IDXGISwapChain* swapChain;
	ID3D11Device* device;
	if (getSwapChain(&swapChain, &device)) {
		void** vmt = *(void***)swapChain;
		if (swapChain) { swapChain->Release(); swapChain = nullptr; }
		if (device) { device->Release(); device = nullptr; }

		return vmt[8];
	}

	return nullptr;
}