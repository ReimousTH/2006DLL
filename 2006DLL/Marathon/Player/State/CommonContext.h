#pragma once
#include "ICommonContext.h"
#include "..\IExportPostureRequestFlag.h"
#include "..\IExportWeaponRequestFlag.h"
#include "..\Score.h"
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/scoped_ptr.hpp>
#include "../Input/IListener.h"
#include <xtl.h>


namespace Sonicteam{

	namespace Player{

		namespace State{

			namespace OtherCommonContext{

				struct StateTableBase{
					unsigned int Flag1;
					unsigned int Flag2;
				};
				static  StateTableBase StateTable0x82009AB8[0x15];


			}

			class CommonContext:public ICommonContext,IExportPostureRequestFlag,IExportWeaponRequestFlag
			{
			public:
				CommonContext(void);
				~CommonContext(void);
				virtual void OnVarible(LuaSystem**) override;
				virtual void ICCIF_03() override;
				virtual void ICCIF_04() override;
				virtual void ICCIF_05() override;


				////VFT_table
				virtual void ICOnPostInputTick(void)  override;
				virtual void ICOnInputTick(float) override;
				virtual void ICOnOnDamage(DWORD) override;
				

				///IExportPostureRequestFlag
				virtual DWORD IEPRFExportFlag(void);
				///IExportWeaponRequestFlag
				virtual DWORD IEWRFExportFlag(void);


				///IDynamicLink(0x24)
				virtual void OnLink(Sonicteam::Player::IPlugIn*& plugin) override;

				//fields
				int PComboAttackManager;
				int UnknownFlags01;
				unsigned int unkA0;
				unsigned int ContextFlags; //Export
				unsigned int ExportPostureRequestFlag;
				unsigned int ExportWeaponRequestFlag;
				float DamageInvincibleTime;
				float InvicibilityTimerWEffect;
				float SpeedUpTime;
				int UnkSomeTimer;
				float AngleMoveDataMB;
				unsigned int GroundAirDataFlags; //0xC4
				unsigned long long UnknownFlags0xC8;
				int UnknownFlags0xD0;
				int UnknownFlags0xD4;
				int UnknownUnUsedFlagD8;
				int FreeUnknownFlagsDC;
				char IsSonicDied;
				char IsRingGhostMode; 
				char IsBlinkingMode;
				char IsForcedMovement;
				char IsInvulnerable;
				char IsInvulnerable2;
				char IsUnkE6;
				char IsGravityDisabled;
				char IsUnkE8;
				char IsJumped_PostureVelocityYHandle;
				char IsInActionsRunJumpBound_MB;
				char IsUnkEB;
				char IsUnkEC;
				char IsUnkED; //IsGrindFlag
				char IsUnkEE;
				char IsUnkEF;

				/* UnkownFlagsUnk01 OLD
				char IsAttackSlideSpindashCollisionOn;
				char IsUnkF1_SetsToZeroUpdate;
				char IsUnkF2;
				char IsUnkF3;
				char IsCommonEdge;
				char IsUnkF5;
				char IsUnkF6;
				char IsUnkF7;
				*/
				unsigned long long UnkownFlagsUnk01;


				char IsDidSpinAnimation;
				char IsUnkF9;
				char IsForceTypeA_DashpanelsJumpRunHoming;
				char IsUnkFB;
				char IsUnkFC;
				char IsUnkFD;
				char IsUnkFE;
				char IsUnkFF;
				char IsSendCharacterToPositionVectorZero;
				char IsUnk101;
				char IsUnk102;
				char IsUnk103;
				char IsBarrier;
				char IsUnk105_AlwaysSetsZero;
				char IsDoSomethingWeirdWithChrRotation;
				char IsUnk107;
				char IsPsiEffect;
				char IsCharacterControlTypeB;
				char IsAntiGravity;
				char IsChrCamDisabled;
				char IsUnk10C;
				char IsOneHitMode;
				char IsUnk10E;
				char IsUnk10F;
				char IsUnk110;
				char UnknownFlags0x111[0x15];
				char IsUnk126;
				char IsUnk127;
				boost::shared_ptr<Sonicteam::Player::Score> ScorePlugin;
				boost::shared_ptr<int> GravityPlugin;
				boost::shared_ptr<Sonicteam::Player::Input::IListener> ListenerNormalInputPlugin;
				boost::shared_ptr<int> PlayerAIAmigoPlugin;
				float float148;
				float gravity;
				float c_brake_acc;
				float c_brake_dashpanel;
				float c_walk_border;
				float c_run_border;
				float c_walk_speed_max;
				float c_run_acc;
				float c_run_speed_max;
				float c_speedup_acc;
				float c_speedup_speed_max;
				float c_jump_time_min;
				float c_jump_brake;
				float c_jump_speed_acc;
				float c_jump_speed_brake;
				float c_jump_speed;
				float c_jump_walk;
				float c_jump_run;
				float c_brake_quick_acc;
				float c_wait_no_input_time;
				float c_damage_time;
				float c_damage_jump;
				float c_damage_speed;
				float c_run_against_time;
				float c_grind_speed_org;
				float c_grind_acc;
				float c_grind_speed_max;
				float c_grind_time;
				float c_grind_penalty_time;
				float c_grind_brake_acc;
				float c_invincible_time;
				float c_invincible_time_ring1;
				float c_invincible_item;
				float c_speedup_time;
				float c_wind_init;
				float c_wind_spd;
				float c_wind_dist;
				float c_border_gravity;
				float c_landing_time;
				float c_ottoto_time;
				float c_dead_animation_time;
				float c_dead_animation_time_coll;
				float c_wallwait_time;
				float c_lclick_time;
				float c_flight_acc;
				float c_flight_speed_acc;
				float c_flight_speed_min;
				float c_flight_speed_max;
				float c_hovering_acc;
				float c_climb_speed;
				float c_stun;
				float c_brake_acc_sand;
				float c_run_acc_sand;
				float c_jump_speed_sand;
				float c_psi_throw_speed;
				float float224;
				float float228;
				float float22C;



				//NON VIRTUAL METHODS

				void SetAnimation(int);

				virtual void DestroyObject(unsigned int flag) override;



		





			};

		}

	}
}

