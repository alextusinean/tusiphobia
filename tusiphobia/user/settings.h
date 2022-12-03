#pragma once

#include "sdk.h"

namespace Settings {
	namespace Movement {
		namespace NoClip {
			extern bool enabled;
			extern float speed;
		}

		extern bool infiniteStamina;
		extern float runSpeed;
		extern float walkSpeed;
	}

	namespace Visual {
		namespace Light {
			namespace Advanced {
				extern bool enabled;

#define LIGHT(name) \
namespace name { \
	extern bool initialSet; \
	extern bool enabled; \
	extern SLightType type; \
	extern SColor color; \
	extern float intensity; \
	extern float bounceIntensity; \
	extern float spotAngle; \
	extern float range; \
	extern float shadowStrength; \
}
			
				LIGHT(Flashlight);
				LIGHT(UVLight);
				LIGHT(HeadLight);
				LIGHT(AreaLight);

#undef LIGHT

			}

			namespace FullBright {
				extern bool enabled;
				extern bool always;
				extern bool holdingOnly;

				extern SLightType type;
				extern SColor color;
				extern float intensity;
				extern float spotAngle;
				extern float range;
			}
		}

		namespace ESP {
			namespace Ghost {
				extern bool bones;
				extern SColor color;
			}

			namespace Player {
				extern bool label;
				extern bool bones;

				extern SColor color;
			}

			namespace EMF {
				extern bool label;
				extern bool showLevel;
				extern bool customColor;

				extern SColor color;
			}

			namespace CursedPosession {
				extern bool label;
				extern SColor color;
			}

			namespace Fingerprint {
				extern bool label;
				extern SColor color;
			}

			namespace Footstep {
				extern bool label;
				extern SColor color;
			}

			namespace Bone {
				extern bool label;
				extern SColor color;
			}

			namespace DeadBody {
				extern bool label;
				extern SColor color;
			}

			namespace DirtyWater {
				extern bool label;
				extern SColor color;
			}

			namespace GhostWriting {
				extern bool label;
				extern SColor color;
			}
		}
	}

	namespace Info {
		namespace Ghost {
			namespace Show {
				extern bool type;
				extern bool evidence;

				extern bool name;
				extern bool age;
				extern bool gender;
				extern bool deathLength;

				extern bool shyness;
				extern bool favouriteRoom;
			}

			namespace Activity {
				extern float graphPoints[61];

				namespace Show {
					extern bool hunting;
					extern bool strength;
					extern bool graph;
				}
			}
		}

		namespace Sanity {
			extern bool show;
		}
	}
	
	namespace Key {
		namespace GrabAutomatically {
			extern bool all;
			extern bool main;
			extern bool car;
			extern bool cabin;
		}
	}

	namespace CursedPosession {
		namespace OuijaBoard {
			extern char* customResponse;
		}
	}
}
