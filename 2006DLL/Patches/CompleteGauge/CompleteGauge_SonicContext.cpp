#pragma once
#include "CompleteGauge_SonicContext.h"



#include "CompleteGauge_SonicGauge.h"




namespace CompleteGauge{
	
	
	//temp story values
	static float gauge_storage[8] = {0};
	static int gauge_levels_storage[8] = {0};






	//Core
	void SonicContextOnStep(SonicContextExtended *_this, double a2){


		bool LVL_UP = false;
		bool FULL_GAUGE = false;
		bool Homing_Smash_Charge = false;
		bool Homing_Smash_Release = false;
		
		if ( SonicGaugeExtended* gauge = (SonicGaugeExtended*)_this->GaugePlugin.get())
		{
			
			if (gauge->c_current_gauge_maturity_add != 0){

				gauge_storage[_this->CurrentGem] += gauge->GetMaturityToAdd();
				gauge->ResetMaturityAdd();

				if (gauge_storage[_this->CurrentGem] >= 1.0){

					gauge_levels_storage[_this->CurrentGem]++;
					gauge_storage[_this->CurrentGem] = 0;
					LVL_UP = true;
				}
			}
			//Gauge IsFull Controller
			if (gauge->GaugeValue >= gauge->c_gauge_max && !gauge->IsFull){
				gauge->IsFull = true;
			}
			else if (gauge->GaugeValue < gauge->c_gauge_max && gauge->IsFull){
				gauge->IsFull = false;
			}

			//ExportFlagRequest
			if (gauge->IsFull) FULL_GAUGE = true;


			//Always

			gauge->c_current_gauge_maturity = gauge_storage[_this->CurrentGem];
			gauge->c_current_gauge_level = gauge_levels_storage[_this->CurrentGem];


		}

		if (_this->IsSuper) {

			_this->IsInvulnerable = 1; 
			_this->c_super_ring_dec_time += a2;
			if (_this->c_super_ring_dec_time > 1.0){
				_this->c_super_ring_dec_time = 0.0f;
				if (_this->ScorePlugin.get()->RingsCount > 0) _this->ScorePlugin.get()->RingsCount--;


			}
		

			if (_this->ScorePlugin.get()->RingsCount <= 0 || _this->IsSonicDied){
				_this->IsInvulnerable = 0;
				_this->IsSuper = false;
				//Switch back
				Switch(_this,"player/sonic_new.lua","player/sonic_new","player_sonic","sonic");

			}
		}
	


		BranchTo(0x82219530,int,_this,a2);

		//Complete Output Flag
		_this->UnknownFlags01 |= (LVL_UP ? 0x10000000 : 0) | (FULL_GAUGE ? 0x20000000 : 0);


	}


	void __declspec( naked ) SonicContextConstructorH(SonicContextExtended* _this){
		__asm{
				mflr r12
				stw       r12, -0x8(r1)
				std		  r31, -0x10(r1)
				stwu      r1, -0x60(r1)
				lis r11,0x8221
				ori r11,r11,0x9330
				mtctr r11
				bctr r11
		}
	}	

	HOOK(void,__fastcall,SonicContextConstructor,0x82219320,SonicContextExtended* _this){
		SonicContextConstructorH(_this);
		_this->IsSuper = false;
	}
	


	void __fastcall ScaleVisibleSwitchAuraController(int a1, int a2, double a3){

	}
	INT __fastcall ModelController_Sonic_Effects(INT result, unsigned int a2){

		return 0;
	}



	void GlobalInstall_SonicContext(){


		WRITE_DWORD(0x821B5BCC,POWERPC_ADDI(3,0,sizeof(SonicContextExtended)));
		INSTALL_HOOK(SonicContextConstructor);
		WRITE_DWORD(0x8200B564,SonicContextOnStep);
	//	WRITE_DWORD(0x8200CFF0,ScaleVisibleSwitchAuraController);
	//	WRITE_DWORD(0x8200CFB8,ModelController_Sonic_Effects);
	}
	
}