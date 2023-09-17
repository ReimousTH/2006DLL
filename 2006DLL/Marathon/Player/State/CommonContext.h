#pragma once
#include "ICommonContext.h"
#include "..\IExportPostureRequestFlag.h"
#include "..\IExportWeaponRequestFlag.h"
#include <xtl.h>

namespace SonicTeam{

	namespace Player{

		namespace State{

			class CommonContext:ICommonContext,IExportPostureRequestFlag,IExportWeaponRequestFlag
			{
			public:
				CommonContext(void);
				virtual ~CommonContext(void);

	
			
				virtual void OnVarible() override;
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
				virtual void OnLink() override;





				//fields
				int PComboAttackManager; //Pointer To Other Class For now just int
				DWORD IsBarrierEnabled; // 0-1
				DWORD unkA0;
				DWORD unkA4;
				DWORD PostureFlags;
				DWORD WeaponFlags;
				float DamageInvincibleTime;
				float InvicibilityTimerWEffect;
				float SpeedUpTime;
				float UnkSomeTimer; // In Core behavious have no idea what is it
				float AngleMoveDataMB; // 8220E8F4 behavious, using StickRotation to calculate Idk for what, not used in 06
				DWORD GroundAirDataFlags; // (vft_table 0x28(IFlagCommunicator table)) (8219681C here LR call from Object::Update) falldata old name
 



		





			};

		}

	}
}

