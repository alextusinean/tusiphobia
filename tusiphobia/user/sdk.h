#pragma once

enum class SLightType : int32_t {
	Spot,
	Directional,
	Point,
	Area,
	Rectangle,
	Disc
};

enum class SMeshTopology : int32_t {
	Triangles = 0x00000000,
	Quads = 0x00000002,
	Lines = 0x00000003,
	LineStrip = 0x00000004,
	Points = 0x00000005
};

enum class SKeyType : int32_t {
	None,
	Main,
	Car,
	Cabin
};

enum class SHumanBodyBones : int32_t {
	Hips = 0x00000000,
	LeftUpperLeg = 0x00000001,
	RightUpperLeg = 0x00000002,
	LeftLowerLeg = 0x00000003,
	RightLowerLeg = 0x00000004,
	LeftFoot = 0x00000005,
	RightFoot = 0x00000006,
	Spine = 0x00000007,
	Chest = 0x00000008,
	UpperChest = 0x00000036,
	Neck = 0x00000009,
	Head = 0x0000000a,
	LeftShoulder = 0x0000000b,
	RightShoulder = 0x0000000c,
	LeftUpperArm = 0x0000000d,
	RightUpperArm = 0x0000000e,
	LeftLowerArm = 0x0000000f,
	RightLowerArm = 0x00000010,
	LeftHand = 0x00000011,
	RightHand = 0x00000012,
	LeftToes = 0x00000013,
	RightToes = 0x00000014,
	LeftEye = 0x00000015,
	RightEye = 0x00000016,
	Jaw = 0x00000017,
	LeftThumbProximal = 0x00000018,
	LeftThumbIntermediate = 0x00000019,
	LeftThumbDistal = 0x0000001a,
	LeftIndexProximal = 0x0000001b,
	LeftIndexIntermediate = 0x0000001c,
	LeftIndexDistal = 0x0000001d,
	LeftMiddleProximal = 0x0000001e,
	LeftMiddleIntermediate = 0x0000001f,
	LeftMiddleDistal = 0x00000020,
	LeftRingProximal = 0x00000021,
	LeftRingIntermediate = 0x00000022,
	LeftRingDistal = 0x00000023,
	LeftLittleProximal = 0x00000024,
	LeftLittleIntermediate = 0x00000025,
	LeftLittleDistal = 0x00000026,
	RightThumbProximal = 0x00000027,
	RightThumbIntermediate = 0x00000028,
	RightThumbDistal = 0x00000029,
	RightIndexProximal = 0x0000002a,
	RightIndexIntermediate = 0x0000002b,
	RightIndexDistal = 0x0000002c,
	RightMiddleProximal = 0x0000002d,
	RightMiddleIntermediate = 0x0000002e,
	RightMiddleDistal = 0x0000002f,
	RightRingProximal = 0x00000030,
	RightRingIntermediate = 0x00000031,
	RightRingDistal = 0x00000032,
	RightLittleProximal = 0x00000033,
	RightLittleIntermediate = 0x00000034,
	RightLittleDistal = 0x00000035,
	LastBone = 0x00000037
};

enum class SCameraClearFlags : int32_t {
	Skybox = 0x00000001,
	Color = 0x00000002,
	SolidColor = 0x00000002,
	Depth = 0x00000003,
	Nothing = 0x00000004
};

enum class SGhostType : int32_t {
	spirit = 0x00000000,
	wraith = 0x00000001,
	phantom = 0x00000002,
	poltergeist = 0x00000003,
	banshee = 0x00000004,
	jinn = 0x00000005,
	mare = 0x00000006,
	revenant = 0x00000007,
	shade = 0x00000008,
	demon = 0x00000009,
	yurei = 0x0000000a,
	oni = 0x0000000b,
	yokai = 0x0000000c,
	hantu = 0x0000000d,
	goryo = 0x0000000e,
	myling = 0x0000000f,
	onryo = 0x00000010,
	theTwins = 0x00000011,
	raiju = 0x00000012,
	obake = 0x00000013,
	mimic = 0x00000014,
	moroi = 0x00000015,
	deogen = 0x00000016,
	thaye = 0x00000017
};

enum class SGhostEvidenceType : int32_t {
	none = 0x00000000,
	emf = 0x00000001,
	spiritBox = 0x00000002,
	fingerprints = 0x00000003,
	ghostOrb = 0x00000004,
	ghostWriting = 0x00000005,
	freezing = 0x00000006,
	dots = 0x00000007
};

enum class STextAnchor : int32_t {
	UpperLeft = 0x00000000,
	UpperCenter = 0x00000001,
	UpperRight = 0x00000002,
	MiddleLeft = 0x00000003,
	MiddleCenter = 0x00000004,
	MiddleRight = 0x00000005,
	LowerLeft = 0x00000006,
	LowerCenter = 0x00000007,
	LowerRight = 0x00000008
};

enum class SEvidenceType : int32_t {
	emf = 0x00000000,
	ouijaBoard = 0x00000001,
	fingerprint = 0x00000002,
	footstep = 0x00000003,
	bone = 0x00000004,
	ghost = 0x00000005,
	deadBody = 0x00000006,
	dirtyWater = 0x00000007,
	musicBox = 0x00000008,
	tarotCards = 0x00000009,
	summoningCircle = 0x0000000a,
	hauntedMirror = 0x0000000b,
	voodooDoll = 0x0000000c,
	ghostWriting = 0x0000000d,
	usedCrucifix = 0x0000000e,
	dots = 0x0000000f,
	none = 0x00000010,
};

struct SGameObject;

struct STransform;

struct SObject : app::Object {

};

struct SQuaternion : app::Quaternion {
	static const SQuaternion identity;

	static SQuaternion of(float x, float y, float z, float w);
};

struct SVector3 : app::Vector3 {
	static const SVector3 zero;

	static const SVector3 one;

	bool operator != (SVector3 const& obj);

	SVector3 operator + (SVector3 const& obj);

	SVector3 operator += (SVector3 const& obj);

	SVector3 operator -= (SVector3 const& obj);

	SVector3 operator *= (SQuaternion const& obj);

	SVector3 operator + (float n);

	SVector3 operator * (float n);

	SVector3 operator *= (float n);

	operator std::string();

	static SVector3 of(app::Vector3 vector);

	static SVector3 of(float x, float y, float z);
};

struct SString : app::String {
	std::string toString();

	bool equals(SString* string);

	bool endsWith(SString* string);

	static SString* of(std::string string);
};

struct SType : app::Type {
	static SType* get(std::string name);
};

struct SComponent : app::Component {
	SGameObject* getGameObject();

	STransform* getTransform();
};

struct SGameObject : app::GameObject {
	bool isActive();

	SComponent* addComponent(SType* type);

	SComponent* getComponent(SType* type);

	SComponent* getComponentInChildren(SType* type, bool includeInactive = false);

	SComponent* getComponent(SString* typeName);

	STransform* getTransform();

	static SGameObject* find(SString* name);

	static SGameObject* findWithTag(SString* tag);

	static SGameObject* of(SString* name);
};

struct STransform : app::Transform {
	SVector3 getPosition();

	SVector3 getForward();

	SVector3 getRight();

	SVector3 getUp();

	void setLocalPosition(SVector3 localPosition);

	void setPosition(SVector3 position);

	STransform* findChild(SString* childName);

	SQuaternion getRotation();

	void setRotation(SQuaternion rotation);

	STransform* getParent();

	void setParent(STransform* parent);

	std::vector<STransform*> getChildren();
};

struct SCollider : app::Collider {
	bool getEnabled();

	void setEnabled(bool enabled);
};

struct SCharacterController : app::CharacterController {

};

struct SFirstPersonController : app::FirstPersonController {
	SCharacterController* getCharacterController();

	STransform* getHeadTransform();

	float getCurrentSpeed();

	void setCurrentSpeed(float currentSpeed);

	bool isRunning();

	bool isWalking();
};

struct STime : app::Time {
	static float getTime();

	static float getDeltaTime();
};

struct SPlayerStamina : app::PlayerStamina {
	bool isWalking();

	bool isRunning1();

	bool isRunning();

	bool isWalking2();

	bool isRunning3();

	bool isOutOfBreath();

	bool isRecharging();

	float getMaxStamina();

	float getMaxOutOfBreathDelay();

	float getOutOfBreathDelay();

	float getStamina();

	void setStamina(float stamina);

	float getStartRechargingDelay();

	app::UnityEvent* getRegainedBreathEvent();
};

struct SColor : app::Color {
	static const SColor dummy;
	static const SColor black;
	static const SColor red;
	static const SColor green;
	static const SColor blue;
	static const SColor white;

	static const SColor brown;
	static const SColor orange;
	static const SColor yellow;
	static const SColor cyan;
	static const SColor purple;

	static SColor of(app::Color color);

	static SColor of(float r, float g, float b, float a = 1.0f);
};

struct SLight : app::Light {
	SLightType getType();

	void setType(SLightType type);

	float getIntensity();

	void setIntensity(float intensity);

	float getBounceIntensity();

	void setBounceIntensity(float bounceIntensity);

	SColor getColor();

	void setColor(SColor color);

	float getSpotAngle();

	void setSpotAngle(float spotAngle);
	
	float getRange();

	void setRange(float range);

	float getShadowStrength();

	void setShadowStrength(float shadowStrength);
};

struct SPCFlashlight : app::PCFlashlight {
	SLight* getLight();

	SLight* getHeadLight();
};

struct SUnityObject : app::Object_1 {
	int getInstanceId();

	SString* getName();
};

struct STorch : app::Torch {
	using app::Torch::fields;

	SLight* getLight();

	bool isUV();

	bool isWeakFlashlight();
};

struct SPCPropGrab : app::PCPropGrab {
	SLight* getAreaLight();
};

struct SKey : app::Key {
	using app::Key::fields;

	static std::vector<SKey*> notGrabbedKeys;

	SKeyType getType();

	void grab();
};

struct SShader : app::Shader {
	static SShader* find(SString* name);
};

struct SMaterial : app::Material {
	void setShader(SShader* shader);

	void setColor(SColor color);

	void setInt(SString* name, int value);

	void setPass(int pass);

	static SMaterial* of(SShader* shader);
};

struct SRenderer : app::Renderer {
	SMaterial* getMaterial();
};

struct SLineRenderer : app::LineRenderer {
	int getPositionCount();

	void setStartWidth(float startWidth);

	void setEndWidth(float endWidth);

	void setWidth(float width);

	void setStartColor(SColor startColor);

	void setEndColor(SColor endColor);

	void setColor(SColor color);
	
	void setPosition(int index, SVector3 position);
};

struct SArray : app::Array {
	void setValue(int index, SObject* value);
};

struct SObject_Array : app::Object__Array {
	static SObject_Array* of();
};

struct SInt32 : app::Int32 {
	static SInt32* of(int value);
};

struct SInt32_Array : app::Int32__Array {
	void resize(int newSize);

	void setValue(int index, int value);

	static SInt32_Array* empty();
};

struct SVector3_Array : app::Vector3__Array {
	void resize(int newSize);

	void setValue(int index, SVector3 value);

	static SVector3_Array* empty();
};

struct SColor_Array : app::Color__Array {
	void resize(int newSize);

	void setValue(int index, SColor value);
};

struct SInt32_List : app::List_1_System_Int32_ {
	void clear();

	void ensureCapacity(int capacity);

	void add(int value);

	void insert(int index, int value);

	SInt32_Array* toArray();

	static SInt32_List* of();
};

struct SVector3_List : app::List_1_UnityEngine_Vector3_ {
	void clear();

	int getCount();

	void ensureCapacity(int capacity);

	void add(SVector3 value);

	void insert(int index, SVector3 value);

	SVector3 get(int index);

	SVector3_Array* toArray();

	static SVector3_List* of();
};

struct SColor_List : app::List_1_UnityEngine_Color_ {
	void clear();

	void ensureCapacity(int capacity);

	void add(SColor value);

	void insert(int index, SColor value);

	SColor_Array* toArray();

	static SColor_List* of();
};

struct SMesh : app::Mesh {
	void markDynamic();

	void clear();

	SVector3_Array* getVertices();

	void setVertices(SVector3_Array* vertices);

	void setVertices(SVector3_List* vertices);

	SColor_Array* getColors();

	void setColors(SColor_Array* colors);

	void setColors(SColor_List* colors);

	SInt32_Array* getIndices(int subMeshIndex = 0);

	void setIndices(SInt32_Array* indices, SMeshTopology meshTopology = SMeshTopology::Lines, int subMeshIndex = 0);

	static SMesh* of();
};

struct SMatrix4x4 : app::Matrix4x4 {
	static SMatrix4x4 trs(SVector3 position, SQuaternion rotation, SVector3 scale);
};

struct SCamera : app::Camera {
	float getDepth();

	void setDepth(float depth);

	float getFieldOfView();

	void setFieldOfView(float fieldOfView);

	int getCullingMask();

	void setCullingMask(int cullingMask);

	void setNearClipPlane(float nearClipPlane);

	void setFarClipPlane(float farClipPlane);

	void setClearFlags(SCameraClearFlags clearFlags);

	void setUseOcclusionCulling(bool useOcclusionCulling);

	SVector3 worldToScreenPoint(SVector3 position);

	static SCamera* getMain();

	static SCamera* getCurrent();
};

struct SGraphics : app::Graphics {
	static void drawMesh(SMesh* mesh, SMatrix4x4 matrix, SMaterial* material, int layer, SCamera* camera, int submeshIndex);

	static void drawMesh(SMesh* mesh, SVector3 position, SQuaternion rotation, SMaterial* material, int layer);

	static void drawMeshNow(SMesh* mesh, SMatrix4x4 matrix);
};

struct SAnimator : app::Animator {
	STransform* getBoneTransform(SHumanBodyBones bone);
};

struct SGhostTraits : app::__152 {
	SGhostType getType();

	SGhostType getMimicType();

	SGhostEvidenceType* getEvidence();

	int getAge();

	int isMale();

	SString* getName();

	int get6();

	int get7();

	bool isShy();

	int getDeathLength();

	int getFavouriteRoomId();

	bool get11();
};

struct SLevelRoom : app::LevelRoom {
	SString* getName();
};

struct SGhostInfo : app::GhostInfo {
	SGhostTraits getGhostTraits();

	SLevelRoom* getFavouriteRoom();
};

struct SGhostAI : app::GhostAI {
	static bool started;

	bool isAppeared();

	float getDefaultSpeed();

	float getAppearTimer();

	bool isHunting();

	bool getSmudgeSticksUsed();

	SGhostInfo* getGhostInfo();

	SAnimator* getAnimator();

	bool lookAtNearestPlayer();

	void appear(int unk);

	void disappear();

	static SGhostAI* get();
};

struct SLevelController : app::LevelController {
	SGhostAI* getGhostAI();

	static SLevelController* get();
};

struct SPlayerSanity : app::PlayerSanity {
	float getInsanity();

	float getSanity();
};

struct SPlayer : app::Player_1 {
	bool isLocal();

	SFirstPersonController* getFirstPersonController();

	SPlayerSanity* getSanity();

	SAnimator* getAnimator();
};

struct SPhotonPlayer : app::Player {
	bool isLocal();

	SString* getUserId();

	SString* getNickName();
};

struct SPlayerSpot : app::Network_PlayerSpot {
	SPhotonPlayer* getPhotonPlayer();

	SPlayer* getPlayer();
};

struct SNetwork : app::Network {
	std::vector<SPlayerSpot*> getPlayerSpots();

	static SNetwork* get();
};

struct SGUIStyleState : app::GUIStyleState {
	void setTextColor(SColor color);

	static SGUIStyleState* of();
};

struct SGUIStyle : app::GUIStyle {
	SGUIStyleState* getNormal();

	void setNormal(SGUIStyleState* state);

	void setAlignment(STextAnchor alignment);

	static SGUIStyle* of();
};

struct SRect : app::Rect {
	static SRect of(float x, float y, float w, float h);
};

struct SGUI : app::GUI {
	static void drawLabel(SRect rect, SString* label, SGUIStyle* style);
};

struct SScreen : app::Screen {
	static int getWidth();

	static int getHeight();
};

struct SOuijaBoard : app::OuijaBoard {
	static SOuijaBoard* instance;

	void sendResponse(SString* response);
};

struct SPhotoValues : app::PhotoValues {
	SEvidenceType getEvidenceType();
};

struct SEvidence : app::Evidence {
	SPhotoValues* getPhotoValues();

	SEvidenceType getType();

	bool isCursedPosession();
};

struct SEMF : app::EMF {
	static SColor color1;
	static SColor color2;
	static SColor color3;
	static SColor color4;
	static SColor color5;

	int getLevel();

	float getTimer();

	SColor getColor();

	static SColor getColor(int level);
};
