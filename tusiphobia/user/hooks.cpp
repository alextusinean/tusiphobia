#include "pch.h"

#include "hooks.h"
#include "renderer.h"
#include "settings.h"
#include "main.h"
#include "gui.h"
#include "esp.h"

#if __has_include("config.h")
#include "config.h"
#endif

#pragma comment(lib, "detours.lib")

#pragma region Hooks

#pragma region Application_Quit

void (*Application_Quit)(int32_t exitCode, MethodInfo* method);

void Application_Quit_Hook(int32_t exitCode, MethodInfo* method) {
	shutdown();
	Application_Quit(exitCode, method);
}

#pragma endregion

#pragma region Application_Quit_1

void (*Application_Quit_1)(MethodInfo* method);

void Application_Quit_1_Hook(MethodInfo* method) {
	shutdown();
	Application_Quit_1(method);
}

#pragma endregion

#pragma region FirstPersonController_Start

SLight* tusiphobiaLight;

void (*FirstPersonController_Start)(app::FirstPersonController* __this, MethodInfo* method);

void FirstPersonController_Start_Hook(SFirstPersonController* __this, MethodInfo* method) {
	FirstPersonController_Start(__this, method);

	tusiphobiaLight = (SLight*) ((SComponent*) __this->getHeadTransform())->getGameObject()->addComponent(SType::get("UnityEngine.Light"));
	tusiphobiaLight->setType(SLightType::Spot);
	tusiphobiaLight->setShadows(SLightShadows::None);
	((SBehaviour*) tusiphobiaLight)->setEnabled(false);
}

#pragma endregion

#pragma region FirstPersonController_Update

bool isKeyPressed(int key) {
	if (GUI::isUnlocked)
		return false;

	return GetAsyncKeyState(key);
}

void (*FirstPersonController_Update)(app::FirstPersonController* __this, MethodInfo* method);

void FirstPersonController_Update_Hook(SFirstPersonController* __this, MethodInfo* method) {
	using namespace Settings::Movement;

	static bool noClipState = false;
	if (NoClip::enabled) {
		noClipState = true;
		((SCollider*) __this->getCharacterController())->setEnabled(false);

		STransform* transform = ((SComponent*) __this->getCharacterController())->getTransform();
		SVector3 position = {};

		if (isKeyPressed(0x57))
			position += transform->getForward();

		if (isKeyPressed(0x41))
			position -= transform->getRight();

		if (isKeyPressed(0x53))
			position -= transform->getForward();

		if (isKeyPressed(0x44))
			position += transform->getRight();

		if (isKeyPressed(VK_LSHIFT))
			position += transform->getUp();

		if (isKeyPressed(VK_LCONTROL))
			position -= transform->getUp();

		position *= STime::getDeltaTime() * NoClip::speed;
		position += transform->getPosition();

		transform->setPosition(position);
	}
	else if (noClipState) {
		noClipState = false;
		((SCollider*) __this->getCharacterController())->setEnabled(true);
	}

	FirstPersonController_Update(__this, method);
	if (__this->isRunning())
		__this->setCurrentSpeed(runSpeed);
	else
		__this->setCurrentSpeed(walkSpeed);

	{
		using namespace Settings::Visual::FullBright;

		((SBehaviour*) tusiphobiaLight)->setEnabled(enabled);
		tusiphobiaLight->setColor(color);
		tusiphobiaLight->setRange(range);
		tusiphobiaLight->setSpotAngle(spotAngle);
		tusiphobiaLight->setIntensity(intensity);
	}
}

#pragma endregion

#pragma region PlayerStamina_Update

void (*PlayerStamina_Update)(app::PlayerStamina* __this, MethodInfo* method);

void PlayerStamina_Update_Hook(SPlayerStamina* __this, MethodInfo* method) {
	if (Settings::Movement::infiniteStamina)
		__this->setStamina(3.0f);

	PlayerStamina_Update(__this, method);
}

#pragma endregion

#pragma region GhostAI_Start

void grabKeyIfNeeded(SKey* key) {
	using namespace Settings::Key::GrabAutomatically;

	if (all) {
		key->grab();
		return;
	}

	SKeyType keyType = key->getType();
	if ((keyType == SKeyType::Main && main)
		|| (keyType == SKeyType::Car && car)
		|| (keyType == SKeyType::Cabin && cabin))
	{
		key->grab();
	}
}

void (*GhostAI_Start)(app::GhostAI* __this, MethodInfo* method);

void GhostAI_Start_Hook(SGhostAI* __this, MethodInfo* method) {
	GhostAI_Start(__this, method);
	SGhostAI::instance = __this;

	for (SKey* key : SKey::notGrabbedKeys) {
		grabKeyIfNeeded(key);
	}
}

#pragma endregion

bool ghostAnimatorRegistered = false;

#pragma region SceneManager_Internal_ActiveSceneChanged

void (*SceneManager_Internal_ActiveSceneChanged)(app::Scene previousActiveScene, app::Scene newActiveScene, MethodInfo* method);

void SceneManager_Internal_ActiveSceneChanged_Hook(app::Scene previousActiveScene, app::Scene newActiveScene, MethodInfo* method) {
	ghostAnimatorRegistered = false;
	SGhostAI::instance = nullptr;

	SKey::notGrabbedKeys.clear();
	ESP::reset();

	{
		using namespace Settings::Info::Ghost::Activity;

		for (int i = 0; i < std::size(graphPoints); i++) {
			graphPoints[i] = 0;
		}
	}

	SceneManager_Internal_ActiveSceneChanged(previousActiveScene, newActiveScene, method);
}

#pragma endregion

#pragma region Key_GrabbedKey

void (*Key_GrabbedKey)(app::Key* __this, MethodInfo* method);

void Key_GrabbedKey_Hook(SKey* __this, MethodInfo* method) {
	std::erase(SKey::notGrabbedKeys, __this);

	Key_GrabbedKey(__this, method);
}

#pragma endregion

#pragma region Key_Start

void (*Key_Start)(app::Key* __this, MethodInfo* method);

void Key_Start_Hook(SKey* __this, MethodInfo* method) {
	Key_Start(__this, method);

	SKey::notGrabbedKeys.push_back(__this);
	if (SGhostAI::instance)
		grabKeyIfNeeded(__this);
}

#pragma endregion

#pragma region GhostAI_Update

void (*GhostAI_Update)(app::GhostAI* __this, MethodInfo* method);

void GhostAI_Update_Hook(SGhostAI* __this, MethodInfo* method) {
	GhostAI_Update(__this, method);

	{
		using namespace Settings::Visual::ESP::Ghost;

		SAnimator* ghostAnimator = __this->getAnimator();
		if (!ghostAnimatorRegistered) {
			if (ghostAnimator) {
				ESP::registerAnimator(__this->getAnimator(), &color, &bones);
				ghostAnimatorRegistered = true;
			}
		} else
			ESP::updateAnimator(ghostAnimator);
	}

	{
		using namespace Settings::CursedPosession::OuijaBoard;

		if (customResponse) {
			SOuijaBoard::instance->sendResponse(SString::of(customResponse));
			customResponse = nullptr;
		}
	}
}

#pragma endregion

#pragma region LineRenderer_SetPosition

void (*LineRenderer_SetPosition)(app::LineRenderer* __this, int index, app::Vector3 position, MethodInfo* method);

void LineRenderer_SetPosition_Hook(SLineRenderer* __this, int index, SVector3 position, MethodInfo* method) {
	using namespace Settings::Info::Ghost::Activity;

	if (__this->getPositionCount() == 61)
		graphPoints[index] = position.y;

	LineRenderer_SetPosition(__this, index, position, method);
}

#pragma endregion

#pragma region Player_1_Start

void (*Player_1_Start)(app::Player_1* __this, MethodInfo* method);

void Player_1_Start_Hook(SPlayer* __this, MethodInfo* method) {
	using namespace Settings::Visual::ESP::Player;

	if (!__this->isLocal()) {
		ESP::registerAnimator(__this->getAnimator(), &color, &bones);

		if (label)
			ESP::addLabel(__this);
	}

	Player_1_Start(__this, method);
}

#pragma endregion

#pragma region Player_1_Update

void (*Player_1_Update)(app::Player_1* __this, MethodInfo* method);

void Player_1_Update_Hook(SPlayer* __this, MethodInfo* method) {
	using namespace Settings::Visual::ESP::Player;

	if (!__this->isLocal()) {
		SNetwork* network;
		if (label && (network = SNetwork::get())) {
			ESP::LabelData* labelData = ESP::getLabelData(__this);
			for (SPlayerSpot* playerSpot : network->getPlayerSpots()) {
				if (playerSpot->getPlayer() == __this) {
					labelData->enabled = true;
					labelData->position = __this->getAnimator()->getBoneTransform(SHumanBodyBones::Head)->getPosition();
					labelData->text = playerSpot->getPhotonPlayer()->getNickName()->toString();
					labelData->color = color;
					break;
				}
			}
		}

		ESP::updateAnimator(__this->getAnimator());
	}

	Player_1_Update(__this, method);
}

#pragma endregion

#pragma region Evidence_OnEnable

void (*Evidence_OnEnable)(app::Evidence* __this, MethodInfo* method);

void Evidence_OnEnable_Hook(SEvidence* __this, MethodInfo* method) {
	SType::get("EMF"); // cache it

	Evidence_OnEnable(__this, method);
	ESP::addEvidence(__this);

	if (__this->getType() == SEvidenceType::ouijaBoard)
		SOuijaBoard::instance = (SOuijaBoard*) ((SComponent*) ((SComponent*) __this)->getTransform()->getParent())->getGameObject()->getComponent(SType::get("OuijaBoard"));
}

#pragma endregion

#pragma region Evidence_OnDisable

void (*Evidence_OnDisable)(app::Evidence* __this, MethodInfo* method);

void Evidence_OnDisable_Hook(SEvidence* __this, MethodInfo* method) {
	if (__this->getType() == SEvidenceType::ouijaBoard)
		SOuijaBoard::instance = nullptr;

	ESP::removeEvidence(__this);
	Evidence_OnDisable(__this, method);
}

#pragma endregion

#pragma region PhotonNetwork_get_PhotonServerSettings

#ifdef TUSIPHOBIA_PHOTON_APPID

app::ServerSettings* (*PhotonNetwork_get_PhotonServerSettings)(MethodInfo* method);

app::ServerSettings* PhotonNetwork_get_PhotonServerSettings_Hook(MethodInfo* method) {
	static app::ServerSettings* serverSettings;
	if (!serverSettings) {
		serverSettings = PhotonNetwork_get_PhotonServerSettings(method);

		SString* appId = SString::of(TUSIPHOBIA_PHOTON_APPID);
		serverSettings->fields.AppSettings->fields.AppIdRealtime = app::String_Replace_1(serverSettings->fields.AppSettings->fields.AppIdRealtime, serverSettings->fields.AppSettings->fields.AppIdRealtime, appId, nullptr);
		serverSettings->fields.AppSettings->fields.AppIdVoice = app::String_Replace_1(serverSettings->fields.AppSettings->fields.AppIdVoice, serverSettings->fields.AppSettings->fields.AppIdVoice, appId, nullptr);
	}

	return serverSettings;
}

#endif

#pragma endregion

#pragma endregion

#pragma region Other Hooks

#pragma region windowProcedure

app::CursorLockMode__Enum previousCursorLockMode;

void toggleGUI(bool isUnlocked = !GUI::isUnlocked) {
	GUI::isUnlocked = isUnlocked;
	if (GUI::isUnlocked) {
		previousCursorLockMode = app::Cursor_1_get_lockState(nullptr);
		app::Cursor_1_set_lockState(app::CursorLockMode__Enum::None, nullptr);
		app::Cursor_1_set_visible(true, nullptr);
	}
	else {
		app::Cursor_1_set_lockState(previousCursorLockMode, nullptr);
		if (previousCursorLockMode == app::CursorLockMode__Enum::Locked)
			app::Cursor_1_set_visible(false, nullptr);
	}
}

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

WNDPROC originalWindowProcedure;

LRESULT windowProcedureHook(HWND windowHandle, UINT message, WPARAM wParam, LPARAM lParam) {
	if (message == WM_CLOSE)
		shutdown();

	if (message == WM_KEYUP && wParam == VK_INSERT)
		toggleGUI();

	if (GUI::isUnlocked) {
		ImGui_ImplWin32_WndProcHandler(windowHandle, message, wParam, lParam);
		return true;
	}

	return CallWindowProc(originalWindowProcedure, windowHandle, message, wParam, lParam);
}

#pragma endregion

#pragma region Present

HWND windowHandle;
ID3D11DeviceContext* deviceContext;
ID3D11RenderTargetView* targetView;
ID3DPresent Present;

HRESULT Present_Hook(IDXGISwapChain* __this, UINT sync, UINT flags) {
	if (!GUI::isInitialized) {
		GUI::isInitialized = true;

		ID3D11Device* device;
		__this->GetDevice(__uuidof(ID3D11Device), (void**) &device);
		device->GetImmediateContext(&deviceContext);

		DXGI_SWAP_CHAIN_DESC description;
		__this->GetDesc(&description);

		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
		io.ConfigWindowsResizeFromEdges = false;

		windowHandle = description.OutputWindow;
		ImGui_ImplWin32_Init(windowHandle);

		ImGui_ImplDX11_Init(device, deviceContext);
		ImGui::GetIO().ImeWindowHandle = windowHandle;

		ID3D11Texture2D* back_buffer;
		__this->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*) &back_buffer);
		device->CreateRenderTargetView(back_buffer, NULL, &targetView);
		back_buffer->Release();

		originalWindowProcedure = (WNDPROC) SetWindowLongPtr(windowHandle, GWLP_WNDPROC, (LONG_PTR) windowProcedureHook);
	}

	ImGui_ImplWin32_NewFrame();
	ImGui_ImplDX11_NewFrame();

	ImGui::NewFrame();
	GUI::draw();

	ESP::prepareEvidence();
	ESP::drawAnimators();
	ESP::drawLabels();

	ImGui::PushStyleVar(ImGuiStyleVar_Alpha, 0.25f);
	ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 5.0f);

	// don't remove/change the next 10 lines, please :)

	ImVec2 displaySize = ImGui::GetIO().DisplaySize;
	ImGui::SetNextWindowPos(ImVec2(10.0f, displaySize.y - 10.0f), ImGuiCond_Always, ImVec2(0.0f, 1.0f));

	bool watermarkWindowOpen = true;
	if (ImGui::Begin("watermark", &watermarkWindowOpen, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoInputs | ImGuiWindowFlags_NoFocusOnAppearing)) {
		ImGui::Text("e-mail: alex@tusinean.ro");
		ImGui::Text("https://alex.tusinean.ro");
		ImGui::Text("https://github.com/alextusinean/tusiphobia");
	}

	ImGui::End();
	ImGui::PopStyleVar();
	ImGui::PopStyleVar();

	ImGui::EndFrame();
	ImGui::Render();

	deviceContext->OMSetRenderTargets(1, &targetView, NULL);
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

	return Present(__this, sync, flags);
}

#pragma endregion

#pragma endregion

#pragma region Internal

std::vector<Hook> hooks;

void hook(void** target, void* detour) {
	Hook hook(target, detour);
	hooks.push_back(hook);

	hook.attach();
}

void unhookAll() {
	for (Hook hook : hooks)
		hook.detach();
}

#pragma endregion

void Hook::attach() {
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourAttach(target, detour);
	DetourTransactionCommit();
}

void Hook::detach() {
	DetourTransactionBegin();
	DetourUpdateThread(GetCurrentThread());
	DetourDetach(target, detour);
	DetourTransactionCommit();
}

void Hooks::init() {
	hooks.clear();

#define HOOK(target) \
target = app::##target; \
hook(&(LPVOID&) target, target##_Hook);

	HOOK(Application_Quit);
	HOOK(Application_Quit_1);
	HOOK(FirstPersonController_Start);
	HOOK(FirstPersonController_Update);
	HOOK(PlayerStamina_Update);
	HOOK(SceneManager_Internal_ActiveSceneChanged);
	HOOK(Key_GrabbedKey);
	HOOK(Key_Start);
	HOOK(GhostAI_Start);
	HOOK(GhostAI_Update);
	HOOK(LineRenderer_SetPosition);
	HOOK(Player_1_Start);
	HOOK(Player_1_Update);
	HOOK(Evidence_OnEnable);
	HOOK(Evidence_OnDisable);

#ifdef TUSIPHOBIA_PHOTON_APPID
	HOOK(PhotonNetwork_get_PhotonServerSettings);
#endif

#undef HOOK

	Present = (ID3DPresent) Renderer::getPresent();
	hook(&(LPVOID&) Present, Present_Hook);
}

void Hooks::uninit() {
	toggleGUI(false);

	unhookAll();
	SetWindowLongPtr(windowHandle, GWLP_WNDPROC, (LONG_PTR) originalWindowProcedure);
}
