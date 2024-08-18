#pragma once
#include "CommonContext.h"
#include "..\Gauge\SonicGauge.h"
#include "..\IExportPostureRequestFlag.h"
#include "..\IExportWeaponRequestFlag.h"
#include "..\Score.h"
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/scoped_ptr.hpp>
#include <xtl.h>

namespace Sonicteam{

	namespace Player{

		namespace State{

		

			//only fields for now, i finish when i comlete CommmonContext FUll  methods
			class SonicContext:public CommonContext
			{
			public:

				DWORD CurrentGemImage;
				boost::shared_ptr<Sonicteam::Player::SonicGauge> GaugePlugin;
				char IsHoming; //byte23C
				char byte23D;
				char byte23E;
				char byte23F;
				char byte240;
				char byte241;
				char isShrink;
				char isThunderGuard;
				char IsTornado;
				char byte245;
				char byte246;
				char isSlowTime;
				char IsMachSpeed;
				char byte249;
				char field_24A;
				char field_24B;
				DWORD HomingSmashCounter;
				int CurrentGem;
				float c_homing_spd;
				float c_homing_brake;
				float c_sliding_time;
				float c_spindash_spd;
				float c_spindash_time;
				float c_bound_jump_spd_0;
				float c_bound_jump_spd_1;
				float c_lightdash_speed;
				float c_boundjump_jmp;
				float c_boundjump_block;
				float c_attack_brake;
				float c_sliding_speed_min;
				float c_sliding_speed_max;
				float c_homing_smash_charge;
				float c_custom_action_slow_time;
				float c_custom_action_machspeed_acc;
				float c_custom_action_machspeed_time;
				float c_scale_run_speed_max;
				float c_scale_run_acc;
				float c_scale_walk_speed_max;
				float c_scale_jump_speed;
				float c_scale_jump_block;

				virtual void DestroyObject(unsigned int flag) override;




			};

		}

	}
}

