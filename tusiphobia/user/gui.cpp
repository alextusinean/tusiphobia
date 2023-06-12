#include "pch.h"

#include "gui.h"
#include "settings.h"

#pragma region main menu

void drawMainMenu() {
	if (ImGui::Begin("tusiphobia", nullptr, ImGuiWindowFlags_AlwaysAutoResize)) {
		using namespace Settings;

		if (ImGui::TreeNode("movement")) {
			using namespace Movement;

			if (ImGui::TreeNode("no clip")) {
				using namespace NoClip;

				ImGui::Checkbox("enabled", &enabled);
				ImGui::SliderFloat("speed", &speed, 0.0f, 15.0f);

				ImGui::TreePop();
			}

			ImGui::Checkbox("infinite stamina", &infiniteStamina);
			ImGui::SliderFloat("run speed", &runSpeed, 0.0f, 15.0f);
			ImGui::SliderFloat("walk speed", &walkSpeed, 0.0f, 15.0f);

			ImGui::TreePop();
		}

		if (ImGui::TreeNode("visual")) {
			using namespace Visual;

			if (ImGui::TreeNode("full bright")) {
				using namespace FullBright;

				ImGui::Checkbox("enabled", &enabled);
				ImGui::ColorEdit3("color", (float*)&color);
				ImGui::SliderFloat("range", &range, 0.0f, 999.0f);
				ImGui::SliderFloat("spotAngle", &spotAngle, 0.0f, 360.0f);
				ImGui::SliderFloat("intensity", &intensity, 0.0f, 10.0f);

				ImGui::TreePop();
			}

			if (ImGui::TreeNode("esp")) {
				using namespace ESP;

				if (ImGui::TreeNode("ghost")) {
					using namespace Ghost;

					ImGui::Checkbox("bones", &bones);
					ImGui::ColorEdit3("color", (float*)&color);

					ImGui::TreePop();
				}

				if (ImGui::TreeNode("player")) {
					using namespace Player;

					ImGui::Checkbox("label", &label);
					ImGui::Checkbox("bones", &bones);

					ImGui::ColorEdit3("color", (float*)&color);

					ImGui::TreePop();
				}

				if (ImGui::TreeNode("emf")) {
					using namespace EMF;

					ImGui::Checkbox("label", &label);
					ImGui::Checkbox("show level", &showLevel);
					ImGui::Checkbox("custom color", &customColor);

					ImGui::BeginDisabled(!customColor);
					ImGui::ColorEdit3("color", (float*)&color);
					ImGui::EndDisabled();

					ImGui::TreePop();
				}

				if (ImGui::TreeNode("cursed posession")) {
					using namespace ESP::CursedPosession;

					ImGui::Checkbox("label", &label);
					ImGui::ColorEdit3("color", (float*)&color);

					ImGui::TreePop();
				}

				if (ImGui::TreeNode("fingerprint")) {
					using namespace Fingerprint;

					ImGui::Checkbox("label", &label);
					ImGui::ColorEdit3("color", (float*)&color);

					ImGui::TreePop();
				}

				if (ImGui::TreeNode("footstep")) {
					using namespace Footstep;

					ImGui::Checkbox("label", &label);
					ImGui::ColorEdit3("color", (float*)&color);

					ImGui::TreePop();
				}

				if (ImGui::TreeNode("bone")) {
					using namespace Bone;

					ImGui::Checkbox("label", &label);
					ImGui::ColorEdit3("color", (float*)&color);

					ImGui::TreePop();
				}

				if (ImGui::TreeNode("dead body")) {
					using namespace DeadBody;

					ImGui::Checkbox("label", &label);
					ImGui::ColorEdit3("color", (float*)&color);

					ImGui::TreePop();
				}

				if (ImGui::TreeNode("dirty water")) {
					using namespace DirtyWater;

					ImGui::Checkbox("label", &label);
					ImGui::ColorEdit3("color", (float*)&color);

					ImGui::TreePop();
				}

				if (ImGui::TreeNode("ghost writing")) {
					using namespace GhostWriting;

					ImGui::Checkbox("label", &label);
					ImGui::ColorEdit3("color", (float*)&color);

					ImGui::TreePop();
				}

				ImGui::TreePop();
			}

			ImGui::TreePop();
		}

		if (ImGui::TreeNode("util")) {
			using namespace Util;

			if (ImGui::TreeNode("ghost")) {
				using namespace Ghost;

				if (ImGui::TreeNode("show")) {
					using namespace Show;

					if (ImGui::Button("check all")) {
						type = true;
						evidence = true;

						name = true;
						age = true;
						gender = true;
						deathLength = true;

						shyness = true;
						favouriteRoom = true;
					}

					ImGui::Checkbox("type", &type);
					ImGui::Checkbox("evidence", &evidence);

					ImGui::Checkbox("name", &name);
					ImGui::Checkbox("age", &age);
					ImGui::Checkbox("gender", &gender);
					ImGui::Checkbox("death length", &deathLength);

					ImGui::Checkbox("shyness", &shyness);
					ImGui::Checkbox("favourite room", &favouriteRoom);

					ImGui::TreePop();
				}

				if (ImGui::TreeNode("activity")) {
					using namespace Activity;

					if (ImGui::TreeNode("show")) {
						using namespace Activity::Show;

						if (ImGui::Button("check all")) {
							hunting = true;
							strength = true;
							graph = true;
						}

						ImGui::Checkbox("hunting", &hunting);
						ImGui::Checkbox("strength", &strength);
						ImGui::Checkbox("graph", &graph);

						ImGui::TreePop();
					}

					ImGui::TreePop();
				}

				if (ImGui::TreeNode("behavior")) {
					if (SGhostAI::instance) {
						if (ImGui::Button("Stop Hunt")) {
							SGhostAI::instance->stopHunt();
						}
						if (ImGui::Button("Appear"))
							SGhostAI::instance->appear(2);

						if (ImGui::Button("Look at nearest player"))
							SGhostAI::instance->lookAtNearestPlayer();

						if (ImGui::Button("Disappear"))
							SGhostAI::instance->disappear();
					}
					ImGui::TreePop();
				}
				ImGui::TreePop();
			}

			if (ImGui::TreeNode("players")) {
				using namespace Players;

				ImGui::Checkbox("show", &show);

				ImGui::TreePop();
			}

			if (SLevelController::get()) {
				if (ImGui::TreeNode("map")) {
					if (SFuseBox::get()) {
						if (ImGui::Button("Toggle Breaker")) {
							SFuseBox::get()->Toggle();
						}
					}
					ImGui::TreePop();
				}
			}
			ImGui::TreePop();
		}

		if (ImGui::TreeNode("key")) {
			using namespace Key;

			if (ImGui::TreeNode("grab automatically")) {
				using namespace GrabAutomatically;

				ImGui::Checkbox("all", &all);

				ImGui::BeginDisabled(all);
				ImGui::Checkbox("main", &main);
				ImGui::Checkbox("car", &car);
				ImGui::Checkbox("cabin", &cabin);
				ImGui::EndDisabled();

				ImGui::TreePop();
			}

			for (SKey* key : SKey::notGrabbedKeys) {
				const char* keyType = "none";
				switch (key->getType()) {
				case SKeyType::Main:
					keyType = "main";
					break;

				case SKeyType::Car:
					keyType = "car";
					break;

				case SKeyType::Cabin:
					keyType = "cabin";
					break;
				}

				if (ImGui::Button(std::string("grab ").append(keyType).c_str()))
					key->grab();
			}

			ImGui::TreePop();
		}

		if (ImGui::TreeNode("cursed posession")) {
			using namespace CursedPosession;

			if (SOuijaBoard::instance && ImGui::TreeNode("ouija board")) {
				using namespace OuijaBoard;

				static char _customResponse[16] = "sussy";
				ImGui::InputText("custom response", _customResponse, IM_ARRAYSIZE(_customResponse));

				bool isNotHost = !SPhotonNetwork::isMasterClient();
				ImGui::BeginDisabled(isNotHost);
				if (ImGui::Button("Send Custom Response"))
					customResponse = _customResponse;

				ImGui::EndDisabled();
				if (isNotHost && ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
					ImGui::SetTooltip("you need to be the host to use this");

				ImGui::TreePop();
			}

			ImGui::TreePop();
		}
	}

	ImGui::End();
}

#pragma endregion

#define ENUM_CASE_STRING(s) \
case s: \
	return #s;

const char* stringifyGhostType(SGhostType ghostType) {
	using enum SGhostType;

	switch (ghostType) {
		ENUM_CASE_STRING(spirit);
		ENUM_CASE_STRING(wraith);
		ENUM_CASE_STRING(phantom);
		ENUM_CASE_STRING(poltergeist);
		ENUM_CASE_STRING(banshee);
		ENUM_CASE_STRING(jinn);
		ENUM_CASE_STRING(mare);
		ENUM_CASE_STRING(revenant);
		ENUM_CASE_STRING(shade);
		ENUM_CASE_STRING(demon);
		ENUM_CASE_STRING(yurei);
		ENUM_CASE_STRING(oni);
		ENUM_CASE_STRING(yokai);
		ENUM_CASE_STRING(hantu);
		ENUM_CASE_STRING(goryo);
		ENUM_CASE_STRING(myling);
		ENUM_CASE_STRING(onryo);

	case theTwins:
		return "the twins";

		ENUM_CASE_STRING(raiju);
		ENUM_CASE_STRING(obake);
		ENUM_CASE_STRING(mimic);
		ENUM_CASE_STRING(moroi);
		ENUM_CASE_STRING(deogen);
		ENUM_CASE_STRING(thaye);
	}

	return "unknown";
}

const char* stringifyEvidenceType(SGhostEvidenceType evidenceType) {
	using enum SGhostEvidenceType;

	switch (evidenceType) {
		ENUM_CASE_STRING(none);
		ENUM_CASE_STRING(emf);

	case spiritBox:
		return "spirit box";

		ENUM_CASE_STRING(fingerprints);

	case ghostOrb:
		return "ghost orb";

	case ghostWriting:
		return "ghost writing";

		ENUM_CASE_STRING(freezing);
		ENUM_CASE_STRING(dots);
	}

	return "unknown";
}

#undef ENUM_CASE_STRING

void drawUtil() {
	using namespace Settings::Util;

	{
		using namespace Ghost;

		{
			using namespace Show;

			bool ghostInfoOpened = type || evidence || name || age || gender || deathLength || shyness || favouriteRoom;
			if (ghostInfoOpened) {
				bool oldGhostInfoOpened = ghostInfoOpened;
				if (ImGui::Begin("ghost info", &ghostInfoOpened, ImGuiWindowFlags_AlwaysAutoResize)) {
					if (SGhostAI::instance) {
						SGhostInfo* ghostInfo = SGhostAI::instance->getGhostInfo();
						SGhostTraits ghostTraits = ghostInfo->getGhostTraits();

						if (type) {
							SGhostType ghostType = ghostTraits.getType();
							ImGui::Text("type: %s", stringifyGhostType(ghostType));

							if (ghostType == SGhostType::mimic)
								ImGui::Text("mimic type: %s", stringifyGhostType(ghostTraits.getMimicType()));
						}

						if (evidence) {
							std::stringstream evidenceText;
							evidenceText << "evidence: ";

							int evidenceCount = 0;
							SGhostEvidenceType* evidences = ghostTraits.getEvidences(&evidenceCount);
							if (evidenceCount && evidences) {
								for (int i = 0; i < evidenceCount; i++) {
									if (i)
										evidenceText << " | ";

									evidenceText << stringifyEvidenceType(evidences[i]);
								}
							}
							else
								evidenceText << "none";

							ImGui::Text(evidenceText.str().c_str());
						}

						if (name) {
							SString* nameManagedString = ghostTraits.getName();
							std::string nameString = nameManagedString ? nameManagedString->toString() : "";
							if (nameString.empty())
								nameString = "???";

							ImGui::Text("name: %s", nameString.c_str());
						}

						if (age)
							ImGui::Text("age: %d", ghostTraits.getAge());

						if (gender)
							ImGui::Text("gender: %s", ghostTraits.isMale() ? "male" : "female");

						if (deathLength)
							ImGui::Text("death length: %d", ghostTraits.getDeathLength());

						if (shyness)
							ImGui::Text("is shy: %s", ghostTraits.isShy() ? "yes" : "no");

						SLevelRoom* _favouriteRoom = ghostInfo->getFavouriteRoom();
						if (favouriteRoom && _favouriteRoom)
							ImGui::Text("favourite room: %s", _favouriteRoom->getName()->toString().c_str());
					}
					else
						ImGui::Text("waiting for game...");
				}

				ImGui::End();
				if (!ghostInfoOpened && oldGhostInfoOpened) {
					type = false;
					evidence = false;

					name = false;
					age = false;
					gender = false;
					deathLength = false;

					shyness = false;
					favouriteRoom = false;
				}
			}
		}

		{
			using namespace Activity;
			using namespace Activity::Show;

			bool ghostActivityOpened = hunting || strength || graph;
			if (ghostActivityOpened) {
				bool oldGhostActivityOpened = ghostActivityOpened;
				if (ImGui::Begin("ghost activity", &ghostActivityOpened, ImGuiWindowFlags_AlwaysAutoResize)) {
					if (SGhostAI::instance) {
						if (hunting)
							ImGui::Text("is hunting: %s", SGhostAI::instance->isHunting() ? "yes" : "no");

						if (strength) {
							ImGui::Text("strength: %d", (int)std::floor(graphPoints[0] / 48));

							ImGui::SameLine();
							ImGui::TextDisabled("(?)");
							if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled))
								ImGui::SetTooltip("calculated by dividing the graph value with 48; a graph value of 480 would be strength 10");
						}

						if (graph)
							ImGui::PlotLines("graph", graphPoints, IM_ARRAYSIZE(graphPoints), 0, nullptr, 0, 480, { 200.0f, 100.0f });
					}
					else
						ImGui::Text("waiting for game...");
				}

				ImGui::End();
				if (!ghostActivityOpened && oldGhostActivityOpened) {
					hunting = false;
					strength = false;
					graph = false;
				}
			}
		}
	}

	{
		using namespace Players;

		if (show) {
			if (ImGui::Begin("players", &show, ImGuiWindowFlags_AlwaysAutoResize)) {
				if (SGhostAI::instance) {
					std::vector<SPlayerSpot*> playerSpots = SNetwork::get()->getPlayerSpots();

					float sanities = 0.0f;
					for (SPlayerSpot* playerSpot : playerSpots) {
						SPlayer* player = playerSpot->getPlayer();
						if (player)
							sanities += player->getSanity()->getSanity();
					}

					ImGui::Text("average sanity: %.2f%%", sanities / playerSpots.size());
					for (SPlayerSpot* playerSpot : playerSpots) {
						SPhotonPlayer* photonPlayer = playerSpot->getPhotonPlayer();
						bool isLocal = photonPlayer->isLocal();

						SPlayer* player = playerSpot->getPlayer();
						if (player && ImGui::TreeNode(playerSpot, "%s%s", photonPlayer->getNickName()->toString().c_str(), isLocal ? " (you)" : "")) {
							ImGui::Text("sanity: %.2f%%", player ? player->getSanity()->getSanity() : 0.0f);

							bool isNotHost = !SPhotonNetwork::isMasterClient();
							bool needsHost = isNotHost && !isLocal;

							ImGui::BeginDisabled(needsHost || player->isDead());
							if (ImGui::Button(isLocal ? "suicide" : "kill"))
								isNotHost ? player->kill() : player->startKilling();

							ImGui::EndDisabled();
							if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled)) {
								if (needsHost)
									ImGui::SetTooltip("you need to be the host to use this");
								else if (player->isDead())
									ImGui::SetTooltip("%s already dead", isLocal ? "you are" : "this player is");
							}

							ImGui::SameLine();
							ImGui::BeginDisabled(needsHost || !player->isDead() || SLiftButton::instance->isClosed());
							if (ImGui::Button("revive"))
								player->revive();

							ImGui::EndDisabled();
							if (ImGui::IsItemHovered(ImGuiHoveredFlags_AllowWhenDisabled)) {
								if (needsHost)
									ImGui::SetTooltip("you need to be the host to use this");
								else if (!player->isDead())
									ImGui::SetTooltip("%s already alive", isLocal ? "you are" : "this player is");
								else if (SLiftButton::instance->isClosed())
									ImGui::SetTooltip("the truck needs to be open to use this");
							}

							if (ImGui::Button("spawn body (takes some seconds)"))
								app::PhotonView_RPC(player->fields._________, SString::of("SpawnDeadBodyNetworked"), app::RpcTarget__Enum::All, app::Array_Empty_15(*app::Array_Empty_15__MethodInfo), nullptr);

							if (isLocal) {
								if (ImGui::Button("Max Sanity")) {
									SPlayerSanity* sanity = player->getSanity();
									sanity->fields._________ = 0.00f;
								}

								ImGui::SameLine();
								if (ImGui::Button("No Sanity")) {
									SPlayerSanity* sanity = player->getSanity();
									sanity->fields._________ = 100.00f;
								}
							}
							ImGui::TreePop();
						}
					}
				}
				else
					ImGui::Text("waiting for game...");
			}

			ImGui::End();
		}
	}
}

bool GUI::isInitialized = false;
bool GUI::isUnlocked = false;

void GUI::draw() {
	ImGui::PushStyleVar(ImGuiStyleVar_Alpha, isUnlocked ? 0.75f : 0.25f);

	if (isUnlocked)
		drawMainMenu();

	drawUtil();

	ImGui::PopStyleVar();
}