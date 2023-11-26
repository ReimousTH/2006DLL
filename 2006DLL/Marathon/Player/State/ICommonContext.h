#pragma once

#include "IContext.h"
#include "ICommonContextIF.h"
#include <vector>

namespace Sonicteam{

	namespace Player{

		namespace State{

			class ICommonContext:IContext,ICommonContextIF
			{
			public:

				///IDynamicLink
				// normal call
				virtual void OnLink() override  {};
				///

				///IVarible
				//pure_call
				virtual void OnVarible(LuaSystem**) override = 0;
				///


				///IContext
				//pure_call
				virtual void ICOnPostInputTick(void) override = 0;
				virtual void ICOnInputTick(float) override;
				///IContext(ICommonContextAddition)
				//for some reason just zero  = 0 idk how is this possbile tho
				virtual void ICOnOnDamage(DWORD) = 0; 
				///



	


				///IFlagCommunicator
				virtual void ImportAnimationStateFlag(DWORD flag_value) override; //TODO FUNCTION sub_82208F58
				///



				///ICommonContextIF
				//all pure_calls should be
				virtual void ICCIF_01(float,float,float) override;
				virtual void ICCIF_02(float,float,float,float) override;
				virtual void ICCIF_03() override = 0;
				virtual void ICCIF_04() override = 0;
				virtual void ICCIF_05() override = 0;
				virtual float ICCIF_06() override;
				virtual float ICCIF_07() override;
				///



			public:
				//fields_but i not sure  that all should be here
				//or 
			
				float CurrentSpeed; //Can Be Added
				float VelocityX;
				float VelocityY;
				float VelocityZ;
			
				DWORD CurrentAnimation;
				float LockInputTime;

				float LastVelocityX;
				float LastVelocityZ;
				float LastLockInputTime;
				DWORD Input; // What button was pressed

				float CurrentStickBorder;
				float unk02;

				XMFLOAT4 StickFixedRotationMb; // (Camera not used in Calculation)

				DWORD AnimationState;
				//0x74 ->
				float field_74;
				float field_78;
				float field_7C;
				float field_80;

				//By Looking to CommonContext new vfttable start from 0x90 means something should be there
				float field_84;
				float field_88;
				float field_8C;







				ICommonContext(void);
				~ICommonContext(void);
			};

		}
	}
}

