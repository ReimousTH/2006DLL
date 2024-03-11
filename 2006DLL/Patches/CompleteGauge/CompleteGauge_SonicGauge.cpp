#pragma once
#include "CompleteGauge_SonicGauge.h"



float clamp(float value, float minVal, float maxVal) {
	if (value < minVal) {
		return minVal;
	} else if (value > maxVal) {
		return maxVal;
	} else {
		return value;
	}
}
namespace CompleteGauge{
	

	


	int SonicGaugeGetGaugeLevel(SonicGaugeExtended* _this){
		return _this->c_current_gauge_level;

	}

	float SonicGaugeGetGaugeMaturity(SonicGaugeExtended* _this){
		return _this->c_current_gauge_maturity;
	}

	void SonicGaugeAddGaugeMaturity(SonicGaugeExtended* _this){
		_this->c_current_gauge_maturity_add += 0.1f;
	}



	void __declspec( naked ) SonicGaugeConstructorH(SonicGaugeExtended* _this){
		__asm{
			mflr r12
				stw       r12, -0x8(r1)
				std		  r31, -0x10(r1)
				stwu      r1, -0x60(r1)
				lis r11,0x8223
				ori r11,r11,0xF218
				mtctr r11
				bctr r11
		}
	}	

	

	HOOK(void,__fastcall,SonicGaugeConstructor,0x8223F208,SonicGaugeExtended* _this){



		 SonicGaugeConstructorH(_this);
	
		 _this->c_current_gauge_maturity_add = 0;
		 _this->c_current_gauge_maturity = 0;
		 _this->c_current_gauge_level = 0;
		 _this->c_current_gauge_fatigue = 100;
		
	}

	//_this->IsNotGrounded fatigue now
	void GaugeModuleStep(int _thisu, double delta){

		SonicGaugeExtended* _this = (SonicGaugeExtended*)(_thisu -0x24);

		
		_this->c_current_gauge_fatigue = clamp(_this->c_current_gauge_fatigue,1,100);
	
		
		
		_this->GaugeGroundTime +=delta;
		if (_this->GaugeGroundTime > _this->c_gauge_heal_delay){
			
			_this->c_current_gauge_fatigue+=1.0f * delta;// weak_fatigue
			
			float fdelta = _this->c_current_gauge_fatigue / 100.0f;
			_this->AddGaugeValue((_this->c_gauge_heal * fdelta ) * delta );
		}

	
	}


	void GlobalInstall_SonicGauge()
	{


		//Later, Move To CompleteGauge_CommonGauge
		WRITE_DWORD(0x82198C70,0x409A0018);//Fix Recieve

		//Allocate more memory
		WRITE_DWORD(0x8219F038,POWERPC_ADDI(3,0,sizeof(SonicGaugeExtended)));
		INSTALL_HOOK(SonicGaugeConstructor);

		//WRITE_DWORD(0x8223EF64,0x419A0010); //Allow flag to heal


		WRITE_DWORD(0x8200D4E0,SonicGaugeGetGaugeLevel);
		WRITE_DWORD(0x8200D4E4,SonicGaugeGetGaugeMaturity);
		WRITE_DWORD(0x8200D4F0,SonicGaugeAddGaugeMaturity);

		WRITE_DWORD(0X8200D4C8,GaugeModuleStep);




	}
	
}