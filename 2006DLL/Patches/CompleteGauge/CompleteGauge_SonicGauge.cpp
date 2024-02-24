#pragma once
#include "CompleteGauge_SonicGauge.h"




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





	void GlobalInstall_SonicGauge()
	{


		//Later, Move To CompleteGauge_CommonGauge
		WRITE_DWORD(0x82198C70,0x409A0018);//Fix Recieve

		//Allocate more memory
		WRITE_DWORD(0x8219F038,POWERPC_ADDI(3,0,sizeof(SonicGaugeExtended)));

		WRITE_DWORD(0x8223EF64,0x419A0010); //Allow flag to heal


		WRITE_DWORD(0x8200D4E0,SonicGaugeGetGaugeLevel);
		WRITE_DWORD(0x8200D4E4,SonicGaugeGetGaugeMaturity);
		WRITE_DWORD(0x8200D4F0,SonicGaugeAddGaugeMaturity);
	}
	
}