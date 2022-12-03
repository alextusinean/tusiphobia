#pragma once

#include "sdk.h"

class ESP {
public:
	struct LabelData {
		bool enabled;
		SVector3 position;
		std::string text;
		SColor color;

		LabelData() : enabled(false), position(SVector3::zero), text("???"), color(SColor::white) {}
	};

	static void reset();

	static void registerAnimator(SAnimator* animator);

	static void drawAnimator(SAnimator* animator, SColor color, SCamera* camera, int layer);

	static void addLabel(void* labelId, LabelData labelData = {});

	static void addEvidence(SEvidence* evidence);

	static void prepareEvidence();

	static void drawLabels();

	static LabelData* getLabelData(void* labelId);

	static void removeLabel(void* labelId);

	static void removeEvidence(SEvidence* evidence);

private:
	struct AnimatorData {
		SMesh* mesh;
		SMaterial* material;

		AnimatorData();

		void reset();

		void registerVertex(SVector3 position, SColor color);

		void build(SMeshTopology meshTopology = SMeshTopology::Lines);

	private:
		SVector3_List* vertices;
		SColor_List* colors;
		SInt32_List* indices;
		int buildIndex;
	};

	static std::map<SAnimator*, AnimatorData> animatorDataMap;
	static std::map<void*, LabelData> labelDataMap;
	static std::set<SEvidence*> evidenceSet;
};
