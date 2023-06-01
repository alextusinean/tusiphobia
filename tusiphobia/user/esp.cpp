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

std::map<SAnimator*, ESP::AnimatorData> ESP::animatorDataMap = {};
std::map<void*, ESP::LabelData> ESP::labelDataMap = {};
std::set<SEvidence*> ESP::evidenceSet = {};

void ESP::reset() {
	for (auto const& entry : animatorDataMap) {
		free(entry.second.bonePositions);
	}

	animatorDataMap.clear();
	labelDataMap.clear();
	evidenceSet.clear();
}

void ESP::addEvidence(SEvidence* evidence) {
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

		ENUM_CASE_STRING(fingerprint);
		ENUM_CASE_STRING(footstep);
		ENUM_CASE_STRING(bone);
		ENUM_CASE_STRING(ghost);

		case deadBody:
			return "dead body";

		case dirtyWater:
			return "dirty water";

		case musicBox:
			return "music box";

		case tarotCards:
			return "tarot cards";

		case summoningCircle:
			return "summoning circle";

		case hauntedMirror:
			return "haunted mirror";

		case voodooDoll:
			return "voodoo doll";

		case ghostWriting:
			return "ghost writing";

		case usedCrucifix:
			return "used crucifix";

		ENUM_CASE_STRING(dots);

		case monkeyPaw:
			return "monkey paw";

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

void ESP::updateAnimator(SAnimator* animator, SColor* color, bool* shouldDraw) {
	if (!animatorDataMap.contains(animator))
		animatorDataMap[animator] = { (SVector3*) calloc(espBonePairsLength, sizeof(SVector3)), color, shouldDraw };

	SVector3 bonePositions[espBonePairsLength] { };
	for (int i = 0; i < espBonePairsLength; i++) {
		bonePositions[i] = animator->getBoneTransform(espBonePairs[i])->getPosition();
	}

	memcpy_s(animatorDataMap[animator].bonePositions, espBonePairsLength * sizeof(SVector3), bonePositions, espBonePairsLength * sizeof(SVector3));
}

void ESP::drawAnimators() {
	SCamera* camera = SCamera::getMain();
	if (!camera)
		return;

	ImVec2 displaySize = ImGui::GetIO().DisplaySize;
	int width = SScreen::getWidth();
	int height = SScreen::getHeight();

	for (auto const& entry : animatorDataMap) {
		SAnimator* animator = entry.first;
		AnimatorData animatorData = entry.second;

		if (!animatorData.bonePositions)
			continue;

		if (!*animatorData.shouldDraw)
			continue;

		std::stringstream windowName;
		windowName << "esp animator " << animator;

		ImGui::SetNextWindowPos(ImVec2(0, 0));
		ImGui::SetNextWindowSize(ImVec2(width, height));
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
		if (ImGui::Begin(windowName.str().c_str(), nullptr, espWindowFlags)) {
			ImU32 color = ImGui::ColorConvertFloat4ToU32(
				ImVec4(animatorData.color->r, animatorData.color->g, animatorData.color->b, animatorData.color->a));

			ImGuiWindow* window = ImGui::GetCurrentWindow();
			for (int i = 0; i < espBonePairsLength; i += 2) {
				SVector3 start = camera->worldToScreenPoint(animatorData.bonePositions[i]);
				SVector3 end = camera->worldToScreenPoint(animatorData.bonePositions[i + 1]);

				if ((start.z <= 0 && end.z <= 0) || ((start.x < 0 || start.x > width || start.y < 0 || start.y > height) && (end.x < 0 || end.x > width || end.y < 0 || end.y > height)))
					continue;

				float startX = displaySize.x * (start.x / width);
				float startY = displaySize.y * ((height - start.y) / height);

				float endX = displaySize.x * (end.x / width);
				float endY = displaySize.y * ((height - end.y) / height);

				window->DrawList->AddLine(ImVec2(startX, startY), ImVec2(endX, endY), color);
			}
		}

		ImGui::End();
		ImGui::PopStyleVar();
	}
}

void ESP::drawLabels() {
	SCamera* camera = SCamera::getMain();
	if (!camera)
		return;

	ImVec2 displaySize = ImGui::GetIO().DisplaySize;
	int width = SScreen::getWidth();
	int height = SScreen::getHeight();

	for (auto const& entry : labelDataMap) {
		LabelData labelData = entry.second;
		if (!labelData.enabled)
			continue;

		SVector3 position = camera->worldToScreenPoint(labelData.position);
		if (position.z <= 0)
			continue;

		float x = displaySize.x * (position.x / width);
		float y = displaySize.y * ((height - position.y) / height);
		ImGui::SetNextWindowPos(ImVec2(x, y), ImGuiCond_Always, ImVec2(0.5, 0.5));

		std::stringstream windowName;
		windowName << "esp label " << entry.first;

		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
		if (ImGui::Begin(windowName.str().c_str(), nullptr, espWindowFlags))
			ImGui::TextColored(ImVec4(labelData.color.r, labelData.color.g, labelData.color.b, labelData.color.a), labelData.text.c_str());

		ImGui::End();
		ImGui::PopStyleVar();
	}
}

ESP::LabelData* ESP::getLabelData(void* labelId) {
	if (!labelDataMap.contains(labelId))
		labelDataMap[labelId] = { };

	return &labelDataMap[labelId];
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

void ESP::removeAnimator(SAnimator* animator) {
	auto iterator = animatorDataMap.find(animator);
	if (iterator != animatorDataMap.end()) {
		free(animatorDataMap[animator].bonePositions);
		animatorDataMap.erase(animator);
	}
}
