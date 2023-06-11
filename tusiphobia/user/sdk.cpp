#include "pch.h"

#include "helpers.h"

Il2CppClass* getClass(std::string namespaze, std::string name) {
	Il2CppClass* klass = nullptr;

	size_t assemblyCount;
	const Il2CppAssembly** assemblies = il2cpp_domain_get_assemblies(il2cpp_domain_get(), &assemblyCount);
	for (int i = 0; i < assemblyCount; i++) {
		klass = il2cpp_class_from_name(il2cpp_assembly_get_image(assemblies[i]), namespaze.c_str(), name.c_str());
		if (klass)
			break;
	}

	return klass;
}

#pragma region Behaviour

bool SBehaviour::isEnabled() {
	return app::Behaviour_get_enabled(this, nullptr);
}

void SBehaviour::setEnabled(bool enabled) {
	return app::Behaviour_set_enabled(this, enabled, nullptr);
}

#pragma endregion

#pragma region Quarernion

const SQuaternion SQuaternion::identity = SQuaternion::of(0.0f, 0.0f, 0.0f, 1.0f);

SQuaternion SQuaternion::of(float x, float y, float z, float w) {
	SQuaternion quaternion;
	quaternion.x = x;
	quaternion.y = y;
	quaternion.z = z;
	quaternion.w = w;

	return quaternion;
}

#pragma endregion

#pragma region Vector3

const SVector3 SVector3::zero = SVector3::of(0.0f, 0.0f, 0.0f);

const SVector3 SVector3::one = SVector3::of(1.0f, 1.0f, 1.0f);

bool SVector3::operator != (SVector3 const& obj) {
	return x != obj.x || y != obj.y || z != obj.z;
}

SVector3 SVector3::operator + (SVector3 const& obj) {
	SVector3 result;
	result.x = x + obj.x;
	result.y = y + obj.y;
	result.z = z + obj.z;

	return result;
}

SVector3 SVector3::operator += (SVector3 const& obj) {
	x += obj.x;
	y += obj.y;
	z += obj.z;

	return *this;
}

SVector3 SVector3::operator -= (SVector3 const& obj) {
	x -= obj.x;
	y -= obj.y;
	z -= obj.z;

	return *this;
}

SVector3 SVector3::operator *= (SQuaternion const& obj) {
	x *= obj.x;
	y *= obj.y;
	z *= obj.z;

	return *this;
}

SVector3 SVector3::operator + (float n) {
	SVector3 result;
	result.x = x + n;
	result.y = y + n;
	result.z = z + n;

	return result;
}

SVector3 SVector3::operator * (float n) {
	SVector3 result;
	result.x = x * n;
	result.y = y * n;
	result.z = z * n;

	return result;
}

SVector3 SVector3::operator *= (float n) {
	x *= n;
	y *= n;
	z *= n;

	return *this;
}

SVector3::operator std::string() {
	std::stringstream result;
	result << "SVector3(x=" << x << ", y=" << y << ", z=" << z << ")";

	return result.str();
}

SVector3 SVector3::of(app::Vector3 vector) {
	return *(SVector3*)&vector;
}

SVector3 SVector3::of(float x, float y, float z) {
	SVector3 result;
	result.x = x;
	result.y = y;
	result.z = z;

	return result;
}

#pragma endregion

#pragma region String

std::string SString::toString() {
	return il2cppi_to_string(this);
}

bool SString::equals(SString* string) {
	return app::String_Equals_1(this, string, nullptr);
}

bool SString::endsWith(SString* string) {
	return app::String_EndsWith(this, string, nullptr);
}

SString* SString::of(std::string string) {
	return (SString*)app::Marshal_PtrToStringAnsi((void*)string.c_str(), nullptr);
}

#pragma endregion

#pragma region Type

SType* SType::get(std::string name) {
	static std::map<std::string, SType*> typeMap = {};
	if (!typeMap.contains(name))
		typeMap[name] = (SType*)app::Type_GetType_3(SString::of(name), nullptr);

	return typeMap[name];
}

#pragma endregion

#pragma region Component

SGameObject* SComponent::getGameObject() {
	return (SGameObject*)app::Component_get_gameObject(this, nullptr);
}

STransform* SComponent::getTransform() {
	return (STransform*)app::Component_get_transform(this, nullptr);
}

#pragma endregion

#pragma region GameObject

bool SGameObject::isActive() {
	return app::GameObject_get_activeSelf(this, nullptr);
}

SComponent* SGameObject::addComponent(SType* type) {
	return (SComponent*)app::GameObject_AddComponent(this, type, nullptr);
}

SComponent* SGameObject::getComponent(SType* type) {
	return (SComponent*)app::GameObject_GetComponent(this, type, nullptr);
}

SComponent* SGameObject::getComponentInChildren(SType* type, bool includeInactive) {
	return (SComponent*)app::GameObject_GetComponentInChildren(this, type, includeInactive, nullptr);
}

SComponent* SGameObject::getComponent(SString* typeName) {
	return (SComponent*)app::GameObject_GetComponent_1(this, typeName, nullptr);
}

STransform* SGameObject::getTransform() {
	return (STransform*)app::GameObject_get_transform(this, nullptr);
}

SGameObject* SGameObject::find(SString* name) {
	return (SGameObject*)app::GameObject_Find(name, nullptr);
}

SGameObject* SGameObject::findWithTag(SString* tag) {
	return (SGameObject*)app::GameObject_FindGameObjectsWithTag(tag, nullptr)->vector[0];
}

SGameObject* SGameObject::of(SString* name) {
	SGameObject* gameObject = (SGameObject*)il2cpp_object_new((Il2CppClass*)*app::GameObject__TypeInfo);
	app::GameObject__ctor(gameObject, name, nullptr);

	return gameObject;
}

#pragma endregion

#pragma region Transform

SVector3 STransform::getPosition() {
	return SVector3::of(app::Transform_get_position(this, nullptr));
}

SVector3 STransform::getForward() {
	return SVector3::of(app::Transform_get_forward(this, nullptr));
}

SVector3 STransform::getRight() {
	return SVector3::of(app::Transform_get_right(this, nullptr));
}

SVector3 STransform::getUp() {
	return SVector3::of(app::Transform_get_up(this, nullptr));
}

void STransform::setLocalPosition(SVector3 localPosition) {
	app::Transform_set_localPosition(this, localPosition, nullptr);
}

void STransform::setPosition(SVector3 position) {
	app::Transform_set_position(this, position, nullptr);
}

STransform* STransform::findChild(SString* childName) {
	return (STransform*)app::Transform_Find(this, childName, nullptr);
}

SQuaternion STransform::getRotation() {
	return (SQuaternion)app::Transform_get_rotation(this, nullptr);
}

void STransform::setRotation(SQuaternion rotation) {
	app::Transform_set_rotation(this, rotation, nullptr);
}

STransform* STransform::getParent() {
	return (STransform*)app::Transform_get_parent(this, nullptr);
}

void STransform::setParent(STransform* parent) {
	app::Transform_set_parent(this, parent, nullptr);
}

std::vector<STransform*> STransform::getChildren() {
	std::vector<STransform*> result;

	auto enumerator = (app::Transform_Enumerator*)app::Transform_GetEnumerator(this, nullptr);
	while (app::Transform_Enumerator_MoveNext(enumerator, nullptr))
		result.push_back((STransform*)app::Transform_Enumerator_get_Current(enumerator, nullptr));

	return result;
}

#pragma endregion

#pragma region Collider

bool SCollider::getEnabled() {
	return app::Collider_get_enabled(this, nullptr);
}

void SCollider::setEnabled(bool enabled) {
	app::Collider_set_enabled(this, enabled, nullptr);
}

#pragma endregion

#pragma region FirstPersonController

SCharacterController* SFirstPersonController::getCharacterController() {
	return (SCharacterController*)fields.m_CharacterController;
}

STransform* SFirstPersonController::getHeadTransform() {
	return ((SComponent*)this)->getTransform()->findChild(SString::of("PCPlayerHead"));
}

float SFirstPersonController::getCurrentSpeed() {
	return fields.currentSpeed;
}

void SFirstPersonController::setCurrentSpeed(float currentSpeed) {
	fields.currentSpeed = currentSpeed;
}

bool SFirstPersonController::isRunning() {
	return getCurrentSpeed() == 3.0f;
}

bool SFirstPersonController::isWalking() {
	return getCurrentSpeed() == 1.6f;
}

#pragma endregion

#pragma region Time

float STime::getTime() {
	return app::Time_get_time(nullptr);
}

float STime::getDeltaTime() {
	return app::Time_get_deltaTime(nullptr);
}

#pragma endregion

#pragma region PlayerStamina

bool SPlayerStamina::isWalking() {
	return fields._________;
}

bool SPlayerStamina::isRunning1() {
	return fields.__________2;
}

bool SPlayerStamina::isRunning() {
	return fields.__________3;
}

bool SPlayerStamina::isWalking2() {
	return fields.__________4;
}

bool SPlayerStamina::isRunning3() {
	return fields.__________5;
}

bool SPlayerStamina::isOutOfBreath() {
	return fields.__________6;
}

bool SPlayerStamina::isRecharging() {
	return fields.__________7;
}

float SPlayerStamina::getStamina() {
	return fields.__________9;
}

void SPlayerStamina::setStamina(float stamina) {
	fields.__________9 = stamina;
}

#pragma endregion

#pragma region Color

const SColor SColor::dummy = SColor::of(-1.0f, -1.0f, -1.0f, -1.0f);
const SColor SColor::black = SColor::of(0.0f, 0.0f, 0.0f);
const SColor SColor::red = SColor::of(1.0f, 0.0f, 0.0f);
const SColor SColor::green = SColor::of(0.0f, 1.0f, 0.0f);
const SColor SColor::blue = SColor::of(0.0f, 0.0f, 1.0f);
const SColor SColor::white = SColor::of(1.0f, 1.0f, 1.0f);

const SColor SColor::brown = SColor::of(0.4f, 0.3f, 0.2f);
const SColor SColor::orange = SColor::of(1.0f, 0.6f, 0.0f);
const SColor SColor::yellow = SColor::of(1.0f, 1.0f, 0.0f);
const SColor SColor::cyan = SColor::of(0.0f, 1.0f, 1.0f);
const SColor SColor::purple = SColor::of(1.0f, 0.0f, 1.0f);

SColor SColor::of(app::Color color) {
	return *(SColor*)&color;
}

SColor SColor::of(float r, float g, float b, float a) {
	return of({ r, g, b, a });
}

#pragma endregion

#pragma region Light

SLightType SLight::getType() {
	return (SLightType)app::Light_get_type(this, nullptr);
}

void SLight::setType(SLightType type) {
	app::Light_set_type(this, (app::LightType__Enum)type, nullptr);
}

float SLight::getIntensity() {
	return app::Light_get_intensity(this, nullptr);
}

void SLight::setIntensity(float intensity) {
	app::Light_set_intensity(this, intensity, nullptr);
}

float SLight::getBounceIntensity() {
	return app::Light_get_bounceIntensity(this, nullptr);
}

void SLight::setBounceIntensity(float bounceIntensity) {
	app::Light_set_bounceIntensity(this, bounceIntensity, nullptr);
}

SColor SLight::getColor() {
	return SColor::of(app::Light_get_color(this, nullptr));
}

void SLight::setColor(SColor color) {
	app::Light_set_color(this, color, nullptr);
}

float SLight::getSpotAngle() {
	return app::Light_get_spotAngle(this, nullptr);
}

void SLight::setSpotAngle(float spotAngle) {
	app::Light_set_spotAngle(this, spotAngle, nullptr);
}

float SLight::getRange() {
	return app::Light_get_range(this, nullptr);
}

void SLight::setRange(float range) {
	app::Light_set_range(this, range, nullptr);
}

float SLight::getShadowStrength() {
	return app::Light_get_shadowStrength(this, nullptr);
}

void SLight::setShadowStrength(float shadowStrength) {
	app::Light_set_shadowStrength(this, shadowStrength, nullptr);
}

SLightShadows SLight::getShadows() {
	return (SLightShadows)app::Light_get_shadows(this, nullptr);
}

void SLight::setShadows(SLightShadows shadows) {
	return app::Light_set_shadows(this, (app::LightShadows__Enum)shadows, nullptr);
}

#pragma endregion

#pragma region PCFlashlight

SLight* SPCFlashlight::getLight() {
	return (SLight*)fields.__________1;
}

SLight* SPCFlashlight::getHeadLight() {
	return (SLight*)fields.headLight;
}

#pragma endregion

#pragma region UnityObject

int SUnityObject::getInstanceId() {
	return app::Object_1_GetInstanceID(this, nullptr);
}

SString* SUnityObject::getName() {
	return (SString*)app::Object_1_get_name(this, nullptr);
}

#pragma endregion

#pragma region Torch

SLight* STorch::getLight() {
	return (SLight*)fields._________;
}

bool STorch::isUV() {
	return ((SUnityObject*)this)->getName()->toString() == "Blacklight Flashlight";
}

bool STorch::isWeakFlashlight() {
	return ((SUnityObject*)this)->getName()->toString() == "Flashlight";
}

#pragma endregion

#pragma region PCPropGrab

SLight* SPCPropGrab::getAreaLight() {
	return (SLight*)((SComponent*)((SComponent*)this)->getTransform()->findChild(SString::of("PCAreaLight")))->getGameObject()->getComponent(SType::get("UnityEngine.Light"));
}

#pragma endregion

#pragma region Key

std::vector<SKey*> SKey::notGrabbedKeys = { };

SKeyType SKey::getType() {
	if (fields.info->fields.keyType == app::___Enum_6::Main)
		return SKeyType::Main;

	std::string objectName = ((SUnityObject*)this)->getName()->toString();
	if (objectName == "CarKey")
		return SKeyType::Car;

	if (objectName == "CabinKey")
		return SKeyType::Cabin;

	return SKeyType::None;
}

void SKey::grab() {
	app::Key_GrabbedKey(this, nullptr);
}

#pragma endregion

#pragma region Shader

SShader* SShader::find(SString* name) {
	return (SShader*)app::Shader_Find(name, nullptr);
}

#pragma endregion

#pragma region Material

void SMaterial::setShader(SShader* shader) {
	app::Material_set_shader(this, shader, nullptr);
}

void SMaterial::setColor(SColor color) {
	app::Material_set_color(this, color, nullptr);
}

void SMaterial::setInt(SString* name, int value) {
	app::Material_SetInt(this, name, value, nullptr);
}

void SMaterial::setPass(int pass) {
	app::Material_SetPass(this, pass, nullptr);
}

SMaterial* SMaterial::of(SShader* shader) {
	SMaterial* material = (SMaterial*)il2cpp_object_new((Il2CppClass*)*app::Material__TypeInfo);
	app::Material__ctor(material, shader, nullptr);

	return material;
}

#pragma endregion

#pragma region Renderer

SMaterial* SRenderer::getMaterial() {
	return (SMaterial*)app::Renderer_get_material(this, nullptr);
}

#pragma endregion

#pragma region LineRenderer

int SLineRenderer::getPositionCount() {
	return app::LineRenderer_get_positionCount(this, nullptr);
}

void SLineRenderer::setStartWidth(float startWidth) {
	app::LineRenderer_set_startWidth(this, startWidth, nullptr);
}

void SLineRenderer::setEndWidth(float endWidth) {
	app::LineRenderer_set_endWidth(this, endWidth, nullptr);
}

void SLineRenderer::setWidth(float width) {
	setStartWidth(width);
	setEndWidth(width);
}

void SLineRenderer::setStartColor(SColor startColor) {
	app::LineRenderer_set_startColor(this, startColor, nullptr);
}

void SLineRenderer::setEndColor(SColor endColor) {
	app::LineRenderer_set_endColor(this, endColor, nullptr);
}

void SLineRenderer::setColor(SColor color) {
	setStartColor(color);
	setEndColor(color);
}

void SLineRenderer::setPosition(int index, SVector3 position) {
	app::LineRenderer_SetPosition(this, index, position, nullptr);
}

#pragma endregion

#pragma region Array

void SArray::setValue(int index, SObject* value) {
	app::Array_SetValue_5(this, value, index, *app::Array_SetValue_5__MethodInfo);
}

#pragma endregion

#pragma region Object_Array

SObject_Array* SObject_Array::of() {
	return (SObject_Array*)app::Array_Empty_15(*app::Array_Empty_15__MethodInfo);
}

#pragma endregion

#pragma region Int32

SInt32* SInt32::of(int value) {
	SInt32* result = (SInt32*)malloc(sizeof(SInt32));
	result->m_value = value;

	return result;
}

#pragma endregion

#pragma region Int32_Array

void SInt32_Array::resize(int newSize) {
	app::Array_Resize_51(this, newSize, *app::Array_Resize_51__MethodInfo);
}

void SInt32_Array::setValue(int index, int value) {
	vector[index] = value;
}

SInt32_Array* SInt32_Array::empty() {
	return (SInt32_Array*)app::Array_Empty_10(*app::Array_Empty_10__MethodInfo);
}

#pragma endregion

#pragma region Vector3_Array

void SVector3_Array::resize(int newSize) {
	app::Array_Resize_83(this, newSize, *app::Array_Resize_83__MethodInfo);
}

void SVector3_Array::setValue(int index, SVector3 value) {
	vector[index] = value;
}

SVector3_Array* SVector3_Array::empty() {
	return SVector3_List::of()->toArray();
}

#pragma endregion

#pragma region Color_Array

void SColor_Array::resize(int newSize) {
	app::Array_Resize_42(this, newSize, *app::Array_Resize_42__MethodInfo);
}

void SColor_Array::setValue(int index, SColor value) {
	vector[index] = value;
}

#pragma endregion

#pragma region Int32_List

void SInt32_List::clear() {
	static MethodInfo* methodInfo = (MethodInfo*)il2cpp_class_get_method_from_name((Il2CppClass*)*app::List_1_System_Int32___TypeInfo, "Clear", 0);
	app::List_1_System_Int32__Clear(this, methodInfo);
}

void SInt32_List::ensureCapacity(int capacity) {
	static MethodInfo* methodInfo = (MethodInfo*)il2cpp_class_get_method_from_name((Il2CppClass*)*app::List_1_System_Int32___TypeInfo, "EnsureCapacity", 1);
	app::List_1_System_Int32__EnsureCapacity(this, capacity, methodInfo);
}

void SInt32_List::add(int value) {
	static MethodInfo* methodInfo = (MethodInfo*)il2cpp_class_get_method_from_name((Il2CppClass*)*app::List_1_System_Int32___TypeInfo, "Add", 1);
	app::List_1_System_Int32__Add(this, value, methodInfo);
}

void SInt32_List::insert(int index, int value) {
	static MethodInfo* methodInfo = (MethodInfo*)il2cpp_class_get_method_from_name((Il2CppClass*)*app::List_1_System_Int32___TypeInfo, "Insert", 2);
	app::List_1_System_Int32__Insert(this, index, value, methodInfo);
}

SInt32_Array* SInt32_List::toArray() {
	static MethodInfo* methodInfo = (MethodInfo*)il2cpp_class_get_method_from_name((Il2CppClass*)*app::List_1_System_Int32___TypeInfo, "ToArray", 0);
	return (SInt32_Array*)app::List_1_System_Int32__ToArray(this, methodInfo);
}

SInt32_List* SInt32_List::of() {
	SInt32_List* list = (SInt32_List*)il2cpp_object_new((Il2CppClass*)*app::List_1_System_Int32___TypeInfo);

	static MethodInfo* methodInfo = (MethodInfo*)il2cpp_class_get_method_from_name((Il2CppClass*)*app::List_1_System_Int32___TypeInfo, ".ctor", 0);
	app::List_1_System_Int32___ctor(list, methodInfo);

	return list;
}

#pragma endregion

#pragma region Vector3_List

void SVector3_List::clear() {
	app::List_1_UnityEngine_Vector3__Clear(this, *app::List_1_UnityEngine_Vector3__Clear__MethodInfo);
}

int SVector3_List::getCount() {
	return app::List_1_UnityEngine_Vector3__get_Count(this, *app::List_1_UnityEngine_Vector3__get_Count__MethodInfo);
}

void SVector3_List::ensureCapacity(int capacity) {
	static MethodInfo* methodInfo = (MethodInfo*)il2cpp_class_get_method_from_name((Il2CppClass*)*app::List_1_UnityEngine_Vector3___TypeInfo, "EnsureCapacity", 1);
	return app::List_1_UnityEngine_Vector3__EnsureCapacity(this, capacity, methodInfo);
}

void SVector3_List::add(SVector3 value) {
	app::List_1_UnityEngine_Vector3__Add(this, value, *app::List_1_UnityEngine_Vector3__Add__MethodInfo);
}

void SVector3_List::insert(int index, SVector3 value) {
	static MethodInfo* methodInfo = (MethodInfo*)il2cpp_class_get_method_from_name((Il2CppClass*)*app::List_1_UnityEngine_Vector3___TypeInfo, "Insert", 2);
	app::List_1_UnityEngine_Vector3__Insert(this, index, value, methodInfo);
}

SVector3 SVector3_List::get(int index) {
	return (SVector3)app::List_1_UnityEngine_Vector3__get_Item(this, index, *app::List_1_UnityEngine_Vector3__get_Item__MethodInfo);
}

SVector3_Array* SVector3_List::toArray() {
	static MethodInfo* methodInfo = (MethodInfo*)il2cpp_class_get_method_from_name((Il2CppClass*)*app::List_1_UnityEngine_Vector3___TypeInfo, "ToArray", 0);
	return (SVector3_Array*)app::List_1_UnityEngine_Vector3__ToArray(this, methodInfo);
}

SVector3_List* SVector3_List::of() {
	SVector3_List* list = (SVector3_List*)il2cpp_object_new((Il2CppClass*)*app::List_1_UnityEngine_Vector3___TypeInfo);
	app::List_1_UnityEngine_Vector3___ctor(list, *app::List_1_UnityEngine_Vector3___ctor__MethodInfo);

	return list;
}

#pragma endregion

#pragma region Color_List

void SColor_List::clear() {
	static MethodInfo* methodInfo = (MethodInfo*)il2cpp_class_get_method_from_name((Il2CppClass*)*app::List_1_UnityEngine_Color___TypeInfo, "Clear", 0);
	app::List_1_UnityEngine_Color__Clear(this, methodInfo);
}

void SColor_List::ensureCapacity(int capacity) {
	static MethodInfo* methodInfo = (MethodInfo*)il2cpp_class_get_method_from_name((Il2CppClass*)*app::List_1_UnityEngine_Color___TypeInfo, "EnsureCapacity", 1);
	return app::List_1_UnityEngine_Color__EnsureCapacity(this, capacity, methodInfo);
}

void SColor_List::add(SColor value) {
	static MethodInfo* methodInfo = (MethodInfo*)il2cpp_class_get_method_from_name((Il2CppClass*)*app::List_1_UnityEngine_Color___TypeInfo, "Add", 1);
	app::List_1_UnityEngine_Color__Add(this, value, methodInfo);
}

void SColor_List::insert(int index, SColor value) {
	static MethodInfo* methodInfo = (MethodInfo*)il2cpp_class_get_method_from_name((Il2CppClass*)*app::List_1_UnityEngine_Color___TypeInfo, "Insert", 2);
	app::List_1_UnityEngine_Color__Insert(this, index, value, methodInfo);
}

SColor_Array* SColor_List::toArray() {
	static MethodInfo* methodInfo = (MethodInfo*)il2cpp_class_get_method_from_name((Il2CppClass*)*app::List_1_UnityEngine_Color___TypeInfo, "ToArray", 0);
	return (SColor_Array*)app::List_1_UnityEngine_Color__ToArray(this, methodInfo);
}

SColor_List* SColor_List::of() {
	SColor_List* list = (SColor_List*)il2cpp_object_new((Il2CppClass*)*app::List_1_UnityEngine_Color___TypeInfo);

	static MethodInfo* methodInfo = (MethodInfo*)il2cpp_class_get_method_from_name((Il2CppClass*)*app::List_1_UnityEngine_Color___TypeInfo, ".ctor", 0);
	app::List_1_UnityEngine_Color___ctor(list, methodInfo);

	return list;
}

#pragma endregion

#pragma region Mesh

void SMesh::markDynamic() {
	app::Mesh_MarkDynamic(this, nullptr);
}

void SMesh::clear() {
	app::Mesh_Clear(this, nullptr);
}

SVector3_Array* SMesh::getVertices() {
	return (SVector3_Array*)app::Mesh_get_vertices(this, nullptr);
}

void SMesh::setVertices(SVector3_Array* vertices) {
	app::Mesh_set_vertices(this, vertices, nullptr);
}

void SMesh::setVertices(SVector3_List* vertices) {
	app::Mesh_SetVertices(this, vertices, nullptr);
}

SColor_Array* SMesh::getColors() {
	return (SColor_Array*)app::Mesh_get_colors(this, nullptr);
}

void SMesh::setColors(SColor_Array* colors) {
	static MethodInfo* methodInfo = (MethodInfo*)il2cpp_class_get_method_from_name((Il2CppClass*)*app::Mesh__TypeInfo, "set_colors", 1);
	app::Mesh_set_colors(this, colors, nullptr);
}

void SMesh::setColors(SColor_List* colors) {
	app::Mesh_SetColors(this, colors, nullptr);
}

SInt32_Array* SMesh::getIndices(int subMeshIndex) {
	return (SInt32_Array*)app::Mesh_GetIndices(this, subMeshIndex, nullptr);
}

void SMesh::setIndices(SInt32_Array* indices, SMeshTopology meshTopology, int subMeshIndex) {
	app::Mesh_SetIndices(this, indices, (app::MeshTopology__Enum)meshTopology, subMeshIndex, nullptr);
}

SMesh* SMesh::of() {
	SMesh* mesh = (SMesh*)il2cpp_object_new((Il2CppClass*)*app::Mesh__TypeInfo);
	app::Mesh__ctor(mesh, nullptr);

	return mesh;
}

#pragma endregion

#pragma region Matrix4x4

SMatrix4x4 SMatrix4x4::trs(SVector3 position, SQuaternion rotation, SVector3 scale) {
	return (SMatrix4x4)app::Matrix4x4_TRS(position, rotation, scale, nullptr);
}

#pragma endregion

#pragma region Camera

float SCamera::getDepth() {
	return app::Camera_get_depth(this, nullptr);
}

void SCamera::setDepth(float depth) {
	app::Camera_set_depth(this, depth, nullptr);
}

float SCamera::getFieldOfView() {
	return app::Camera_get_fieldOfView(this, nullptr);
}

void SCamera::setFieldOfView(float fieldOfView) {
	app::Camera_set_fieldOfView(this, fieldOfView, nullptr);
}

int SCamera::getCullingMask() {
	return app::Camera_get_cullingMask(this, nullptr);
}

void SCamera::setCullingMask(int cullingMask) {
	app::Camera_set_cullingMask(this, cullingMask, nullptr);
}

void SCamera::setNearClipPlane(float nearClipPlane) {
	app::Camera_set_nearClipPlane(this, nearClipPlane, nullptr);
}

void SCamera::setFarClipPlane(float farClipPlane) {
	app::Camera_set_farClipPlane(this, farClipPlane, nullptr);
}

void SCamera::setClearFlags(SCameraClearFlags clearFlags) {
	app::Camera_set_clearFlags(this, (app::CameraClearFlags__Enum)clearFlags, nullptr);
}

void SCamera::setUseOcclusionCulling(bool useOcclusionCulling) {
	app::Camera_set_useOcclusionCulling(this, useOcclusionCulling, nullptr);
}

SVector3 SCamera::worldToScreenPoint(SVector3 position) {
	return (SVector3)app::Camera_WorldToScreenPoint_1(this, position, nullptr);
}

SCamera* SCamera::getMain() {
	return (SCamera*)app::Camera_get_main(nullptr);
}

SCamera* SCamera::getCurrent() {
	return (SCamera*)app::Camera_get_current(nullptr);
}

#pragma endregion

#pragma region Graphics

void SGraphics::drawMesh(SMesh* mesh, SMatrix4x4 matrix, SMaterial* material, int layer, SCamera* camera, int submeshIndex) {
	app::Graphics_DrawMesh_4(mesh, matrix, material, layer, camera, submeshIndex, nullptr);
}

void SGraphics::drawMesh(SMesh* mesh, SVector3 position, SQuaternion rotation, SMaterial* material, int layer) {
	app::Graphics_DrawMesh_2(mesh, position, rotation, material, layer, nullptr);
}

void SGraphics::drawMeshNow(SMesh* mesh, SMatrix4x4 matrix) {
	app::Graphics_DrawMeshNow_1(mesh, matrix, nullptr);
}

#pragma endregion

#pragma region Animator

STransform* SAnimator::getBoneTransform(SHumanBodyBones bone) {
	return (STransform*)app::Animator_GetBoneTransform(this, (app::HumanBodyBones__Enum)bone, *app::Animator_GetBoneTransform__MethodInfo);
}

#pragma endregion

#pragma region GhostTraits

SGhostType SGhostTraits::getType() {
	return (SGhostType)_________;
}

SGhostType SGhostTraits::getMimicType() {
	return (SGhostType)__________1;
}

SGhostEvidenceType* SGhostTraits::getEvidences(int* count) {
	if (!__________2)
		return nullptr;

	if (count)
		*count = __________2->fields._size;

	return (SGhostEvidenceType*)__________2->fields._items->vector;
}

SGhostEvidenceType* SGhostTraits::getOtherEvidences(int* count) {
	if (!__________3)
		return nullptr;

	if (count)
		*count = __________3->fields._size;

	return (SGhostEvidenceType*)__________3->fields._items->vector;
}

int SGhostTraits::getAge() {
	return __________4;
}

bool SGhostTraits::isMale() {
	return __________5;
}

SString* SGhostTraits::getName() {
	return (SString*)__________6;
}

int SGhostTraits::get7() {
	return __________7;
}

int SGhostTraits::get8() {
	return __________8;
}

bool SGhostTraits::isShy() {
	return __________9;
}

int SGhostTraits::getDeathLength() {
	return __________10;
}

int SGhostTraits::getFavouriteRoomId() {
	return __________11;
}

bool SGhostTraits::get12() {
	return __________12;
}

#pragma endregion

#pragma region LevelRoom

SString* SLevelRoom::getName() {
	return (SString*)fields.__________7;
}

#pragma endregion

#pragma region GhostInfo

SGhostTraits SGhostInfo::getGhostTraits() {
	return (SGhostTraits)fields._________;
}

SLevelRoom* SGhostInfo::getFavouriteRoom() {
	return (SLevelRoom*)fields.__________1;
}

#pragma endregion

#pragma region GhostAI

SGhostAI* SGhostAI::instance = nullptr;

bool SGhostAI::isAppeared() {
	return fields.__________11;
}

float SGhostAI::getAppearTimer() {
	return fields.__________19;
}

bool SGhostAI::isHunting() {
	return fields.__________20;
}

SGhostInfo* SGhostAI::getGhostInfo() {
	return (SGhostInfo*)fields.__________3;
}

SAnimator* SGhostAI::getAnimator() {
	app::GhostModel* ghostModel = fields.__________8;
	if (!ghostModel)
		return nullptr;

	return (SAnimator*)ghostModel->fields.__________3;
}

bool SGhostAI::lookAtNearestPlayer() {
	return app::GhostAI_LookAtNearestPlayer(this, nullptr);
}

void SGhostAI::appear(int unk) { // no clue what the int does
	app::GhostAI_Appear(this, unk, nullptr);
}

void SGhostAI::disappear() {
	app::GhostAI_UnAppear(this, nullptr);
}

#pragma endregion

#pragma region LevelController

SGhostAI* SLevelController::getGhostAI() {
	return (SGhostAI*)fields.__________3;
}

SLevelController* SLevelController::get() {
	return (SLevelController*)(*app::LevelController__TypeInfo)->static_fields->_________;
}

#pragma endregion

#pragma region FuseBox
SFuseBox* SFuseBox::get() {
	return (SFuseBox*)(SLevelController::get()->fields.__________11);
}
void SFuseBox::Toggle() {
	app::FuseBox_Use(this, nullptr);
}
#pragma endregion

#pragma region PlayerSanity

float SPlayerSanity::getInsanity() {
	return fields._________;
}

float SPlayerSanity::getSanity() {
	return 100.0f - getInsanity();
}

#pragma endregion

#pragma region Player

bool SPlayer::isDead() {
	return fields.__________1;
}

bool SPlayer::isLocal() {
	return getFirstPersonController() != nullptr;
}

SFirstPersonController* SPlayer::getFirstPersonController() {
	return (SFirstPersonController*)fields.__________35;
}

SPlayerSanity* SPlayer::getSanity() {
	return (SPlayerSanity*)fields.__________22;
}

SAnimator* SPlayer::getAnimator() {
	return (SAnimator*)fields.__________43;
}

void SPlayer::startKilling() {
	app::Player_1_StartKillingPlayer(this, nullptr);
}

void SPlayer::kill() {
	app::Player_1_KillPlayer(this, nullptr);
}

void SPlayer::revive() {
	app::Player_1_RevivePlayer(this, nullptr);
}

#pragma endregion

#pragma region PhotonPlayer

bool SPhotonPlayer::isLocal() {
	return fields.IsLocal;
}

SString* SPhotonPlayer::getUserId() {
	return (SString*)app::Player_get_UserId(this, nullptr);
}

SString* SPhotonPlayer::getNickName() {
	return (SString*)fields.nickName;
}

#pragma endregion

#pragma region PlayerSpot

SPhotonPlayer* SPlayerSpot::getPhotonPlayer() {
	return (SPhotonPlayer*)fields.photonPlayer;
}

SPlayer* SPlayerSpot::getPlayer() {
	return (SPlayer*)fields.player;
}

#pragma endregion

#pragma region Network

std::vector<SPlayerSpot*> SNetwork::getPlayerSpots() {
	std::vector<SPlayerSpot*> playerSpots;
	for (int i = 0; i < fields.__________1->fields._size; i++) {
		playerSpots.push_back((SPlayerSpot*)fields.__________1->fields._items->vector[i]);
	}

	return playerSpots;
}

SNetwork* SNetwork::get() {
	static app::Network__Class* networkClass;
	if (!networkClass) {
		networkClass = (app::Network__Class*)getClass("", "Network");
		if (!networkClass)
			return nullptr;
	}

	return (SNetwork*)networkClass->static_fields->_________;
}

#pragma endregion

#pragma region GUIStyleState

void SGUIStyleState::setTextColor(SColor color) {
	app::GUIStyleState_set_textColor(this, color, nullptr);
}

SGUIStyleState* SGUIStyleState::of() {
	SGUIStyleState* guiStyleState = (SGUIStyleState*)il2cpp_object_new((Il2CppClass*)*app::GUIStyleState__TypeInfo);
	app::GUIStyleState__ctor(guiStyleState, nullptr);

	return guiStyleState;
}

#pragma endregion

#pragma region GUIStyle

SGUIStyleState* SGUIStyle::getNormal() {
	return (SGUIStyleState*)fields.m_Normal;
}

void SGUIStyle::setNormal(SGUIStyleState* state) {
	fields.m_Normal = state;
}

void SGUIStyle::setAlignment(STextAnchor alignment) {
	app::GUIStyle_set_alignment(this, (app::TextAnchor__Enum)alignment, nullptr);
}

SGUIStyle* SGUIStyle::of() {
	SGUIStyle* guiStyle = (SGUIStyle*)il2cpp_object_new((Il2CppClass*)*app::GUIStyle__TypeInfo);
	app::GUIStyle__ctor(guiStyle, nullptr);

	return guiStyle;
}

#pragma endregion

#pragma region Rect

SRect SRect::of(float x, float y, float w, float h) {
	SRect rect;
	rect.m_XMin = x;
	rect.m_YMin = y;
	rect.m_Width = w;
	rect.m_Height = h;

	return rect;
}

#pragma endregion

#pragma region GUI

void SGUI::drawLabel(SRect rect, SString* label, SGUIStyle* style) {
	app::GUI_Label_1(rect, label, style, nullptr);
}

#pragma endregion

#pragma region Screen

int SScreen::getWidth() {
	return app::Screen_get_width(nullptr);
}

int SScreen::getHeight() {
	return app::Screen_get_height(nullptr);
}

#pragma endregion

#pragma region OuijaBoard

SOuijaBoard* SOuijaBoard::instance = nullptr;

void SOuijaBoard::sendResponse(SString* response) {
	app::OuijaBoard___________36(this, response, nullptr);
}

#pragma endregion

#pragma region PhotoValues

SEvidenceType SPhotoValues::getEvidenceType() {
	return (SEvidenceType)fields.evidenceType;
}

#pragma endregion

#pragma region Evidence

SPhotoValues* SEvidence::getPhotoValues() {
	return (SPhotoValues*)fields._________;
}

SEvidenceType SEvidence::getType() {
	return getPhotoValues()->getEvidenceType();
}

bool SEvidence::isCursedPosession() {
	using enum SEvidenceType;

	SEvidenceType type = getType();
	return type == ouijaBoard || type == musicBox || type == tarotCards || type == summoningCircle || type == hauntedMirror || type == voodooDoll || type == monkeyPaw;
}

#pragma endregion

#pragma region EMF

SColor SEMF::color1 = SColor::cyan;
SColor SEMF::color2 = SColor::green;
SColor SEMF::color3 = SColor::yellow;
SColor SEMF::color4 = SColor::orange;
SColor SEMF::color5 = SColor::red;

int SEMF::getLevel() {
	return fields.__________1;
}

float SEMF::getTimer() {
	return fields.__________5;
}

SColor SEMF::getColor() {
	return getColor(getLevel());
}

SColor SEMF::getColor(int level) {
	switch (level) {
	case 0:
		return color1;

	case 1:
		return color2;

	case 2:
		return color3;

	case 3:
		return color4;

	case 4:
		return color5;
	}

	return SColor::dummy;
}

#pragma endregion

#pragma region PhotonNetwork

bool SPhotonNetwork::isMasterClient() {
	return app::PhotonNetwork_get_IsMasterClient(nullptr);
}

#pragma endregion

#pragma region LiftButton

SLiftButton* SLiftButton::instance = nullptr;

bool SLiftButton::isAnimating() {
	return fields.__________1;
}

bool SLiftButton::isClosed() {
	return fields.__________2;
}

bool SLiftButton::canBeClosed() {
	return fields.__________3;
}

#pragma endregion