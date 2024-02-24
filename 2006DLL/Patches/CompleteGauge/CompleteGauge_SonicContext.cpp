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
			_this->c_super_ring_dec_time += a2;
			if (_this->c_super_ring_dec_time > 1.0){
				_this->c_super_ring_dec_time = 0.0f;
				_this->ScorePlugin.get()->RingsCount--;


			}
			if (_this->ScorePlugin.get()->RingsCount <= 0){
				_this->IsSuper = false;
				//Switch back

			}
		}


		BranchTo(0x82219530,int,_this,a2);

		//Complete Output Flag
		_this->UnknownFlags01 |= (LVL_UP ? 0x10000000 : 0) | (FULL_GAUGE ? 0x20000000 : 0);


	}

	void GlobalInstall_SonicContext(){


		WRITE_DWORD(0x821B5BCC,POWERPC_ADDI(3,0,sizeof(SonicContextExtended)));
		WRITE_DWORD(0x8200B564,SonicContextOnStep);
	}
	
}