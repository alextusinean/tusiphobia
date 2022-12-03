#include "pch.h"

#include "esp.h"
#include "settings.h"

static const ImGuiWindowFlags espWindowFlags =
	ImGuiWindowFlags_NoTitleBar
	| ImGuiWindowFlags_NoBackground
	| ImGuiWindowFlags_AlwaysAutoResize
	| ImGuiWindowFlags_NoInputs
	| ImGuiWindowFlags_NoFocusOnAppearing
	| ImGuiWindowFlags_NoSavedSettings;

const SHumanBodyBones espBonePairs[] = {
	SHumanBodyBones::Head, SHumanBodyBones::Neck,
	SHumanBodyBones::Neck, SHumanBodyBones::Hips,

	SHumanBodyBones::Neck, SHumanBodyBones::LeftUpperArm,
	SHumanBodyBones::LeftUpperArm, SHumanBodyBones::LeftLowerArm,
	SHumanBodyBones::LeftLowerArm, SHumanBodyBones::LeftHand,

	SHumanBodyBones::Neck, SHumanBodyBones::RightUpperArm,
	SHumanBodyBones::RightUpperArm, SHumanBodyBones::RightLowerArm,
	SHumanBodyBones::RightLowerArm, SHumanBodyBones::RightHand,

	SHumanBodyBones::Hips, SHumanBodyBones::LeftUpperLeg,
	SHumanBodyBones::LeftUpperLeg, SHumanBodyBones::LeftLowerLeg,
	SHumanBodyBones::LeftLowerLeg, SHumanBodyBones::LeftFoot,

	SHumanBodyBones::Hips, SHumanBodyBones::RightUpperLeg,
	SHumanBodyBones::RightUpperLeg, SHumanBodyBones::RightLowerLeg,
	SHumanBodyBones::RightLowerLeg, SHumanBodyBones::RightFoot
};

const int espBonePairsLength = (int) (sizeof(espBonePairs) / sizeof(SHumanBodyBones));

ESP::AnimatorData::AnimatorData() {
	mesh = SMesh::of();
	mesh->markDynamic();

	material = SMaterial::of(SShader::find(SString::of("Hidden/Internal-Colored")));
	material->setInt(SString::of("_ZTest"), 0);
}

void ESP::AnimatorData::reset() {
	vertices = SVector3_List::of();
	colors = SColor_List::of();
	indices = SInt32_List::of();

	buildIndex = 0;
}

void ESP::AnimatorData::registerVertex(SVector3 position, SColor color) {
	vertices->add(position);
	colors->add(color);
	indices->add(buildIndex);

	buildIndex++;
}

void ESP::AnimatorData::build(SMeshTopology meshTopology) {
	mesh->setVertices(vertices->toArray());
	mesh->setColors(colors->toArray());
	mesh->setIndices(indices->toArray(), meshTopology);
}

std::map<SAnimator*, ESP::AnimatorData> ESP::animatorDataMap = {};
std::map<void*, ESP::LabelData> ESP::labelDataMap = {};
std::set<SEvidence*> ESP::evidenceSet = {};

void ESP::reset() {
	animatorDataMap.clear();
	labelDataMap.clear();
	evidenceSet.clear();
}

void ESP::registerAnimator(SAnimator* animator) {
	animatorDataMap[animator] = AnimatorData();
}

void ESP::drawAnimator(SAnimator* animator, SColor color, SCamera* camera, int layer) {
	if (!animatorDataMap.contains(animator))
		throw std::exception("animator not registered");

	AnimatorData data = animatorDataMap[animator];
	data.reset();

	for (int i = 0; i < espBonePairsLength; i++) {
		data.registerVertex(animator->getBoneTransform(espBonePairs[i])->getPosition(), color);
	}

	data.build();
	SGraphics::drawMesh(data.mesh, SMatrix4x4::trs(SVector3::zero, SQuaternion::identity, SVector3::one), data.material, layer, camera, 0);
}

void ESP::addLabel(void* labelId, LabelData labelData) {
	labelDataMap[labelId] = labelData;
}

void ESP::addEvidence(SEvidence* evidence) {
	addLabel(evidence);
	evidenceSet.insert(evidence);
}

#define ENUM_CASE_STRING(s) \
case s: \
	return #s;

std::string stringifyEvidenceType(SEvidenceType evidenceType) {
	switch (evidenceType) {
		using enum SEvidenceType;

		ENUM_CASE_STRING(emf);

		case ouijaBoard:
			return "ouija board";
			break;

		ENUM_CASE_STRING(fingerprint);
		ENUM_CASE_STRING(footstep);
		ENUM_CASE_STRING(bone);
		ENUM_CASE_STRING(ghost);

		case deadBody:
			return "dead body";
			break;

		case dirtyWater:
			return "dirty water";
			break;

		case musicBox:
			return "music box";
			break;

		case tarotCards:
			return "tarot cards";
			break;

		case summoningCircle:
			return "summoning circle";
			break;

		case hauntedMirror:
			return "haunted mirror";
			break;

		case voodooDoll:
			return "voodoo doll";
			break;

		case ghostWriting:
			return "ghost writing";
			break;

		case usedCrucifix:
			return "used crucifix";
			break;

		ENUM_CASE_STRING(dots);
		ENUM_CASE_STRING(none);
	}

	return "unknown";
}

#undef ENUM_CASE_STRING

void ESP::prepareEvidence() {
	for (SEvidence* evidence : evidenceSet) {
		using namespace Settings::Visual::ESP;
		using enum SEvidenceType;

		SEvidenceType type = evidence->getType();
		LabelData* labelData = getLabelData(evidence);
		labelData->text = stringifyEvidenceType(type);

		bool enabled = false;
		{
			using namespace EMF;

			if (type == emf && label) {
				SEMF* emfInstance = (SEMF*) ((SComponent*) evidence)->getGameObject()->getComponent(SType::get("EMF"));
				if (!emfInstance)
					throw std::exception("EMF instance not found");

				if (showLevel)
					labelData->text.append(" " + std::to_string(emfInstance->getLevel() + 1));

				labelData->color = customColor ? color : emfInstance->getColor();
				enabled = true;
			}
		}

		{
			using namespace CursedPosession;

			if (evidence->isCursedPosession() && label) {
				labelData->color = color;
				enabled = true;
			}
		}

		{
			using namespace Fingerprint;

			if (type == fingerprint && label) {
				labelData->color = color;
				enabled = true;
			}
		}

		{
			using namespace Footstep;

			if (type == footstep && label) {
				labelData->color = color;
				enabled = true;
			}
		}

		{
			using namespace Bone;

			if (type == bone && label) {
				labelData->color = color;
				enabled = true;
			}
		}

		{
			using namespace DeadBody;

			if (type == deadBody && label) {
				labelData->color = color;
				enabled = true;
			}
		}

		{
			using namespace DirtyWater;

			if (type == dirtyWater && label) {
				labelData->color = color;
				enabled = true;
			}
		}

		{
			using namespace GhostWriting;

			if (type == ghostWriting && label) {
				labelData->color = color;
				enabled = true;
			}
		}

		labelData->enabled = enabled;
		if (enabled)
			labelData->position = ((SComponent*) evidence)->getTransform()->getPosition();
	}
}

void ESP::drawLabels() {
	SCamera* camera = SCamera::getMain();
	if (camera) {
		ImVec2 displaySize = ImGui::GetIO().DisplaySize;
		int w = SScreen::getWidth();
		int h = SScreen::getHeight();

		for (auto const& entry : labelDataMap) {
			LabelData labelData = entry.second;
			if (!labelData.enabled)
				continue;

			SVector3 position = camera->worldToScreenPoint(labelData.position);
			if (position.z <= 0)
				continue;

			float x = displaySize.x * (position.x / w);
			float y = displaySize.y * ((h - position.y) / h);
			ImGui::SetNextWindowPos(ImVec2(x, y), ImGuiCond_Always, ImVec2(0.5, 0.5));

			std::stringstream windowName;
			windowName << "esp label " << entry.first;

			if (ImGui::Begin(windowName.str().c_str(), nullptr, espWindowFlags))
				ImGui::TextColored(ImVec4(labelData.color.r, labelData.color.g, labelData.color.b, labelData.color.a), labelData.text.c_str());

			ImGui::End();
		}
	}
}

ESP::LabelData* ESP::getLabelData(void* labelId) {
	auto iterator = labelDataMap.find(labelId);
	if (iterator == labelDataMap.end())
		return nullptr;

	return &iterator->second;
}

void ESP::removeLabel(void* labelId) {
	auto iterator = labelDataMap.find(labelId);
	if (iterator != labelDataMap.end())
		labelDataMap.erase(iterator);
}

void ESP::removeEvidence(SEvidence* evidence) {
	evidenceSet.erase(evidence);
	removeLabel(evidence);
}
