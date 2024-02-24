#pragma once


#include <Head.h>
#include "Player/Gauge/SonicGauge.h"

namespace CompleteGauge{
	
	
	class SonicGaugeExtended:public Sonicteam::Player::SonicGauge{

	public:
		float c_current_gauge_maturity;
		float c_current_gauge_maturity_add;
		int c_current_gauge_level;
		bool IsFull;

		void ResetMaturityAdd(){
				c_current_gauge_maturity_add = 0;
		}
		float GetMaturityToAdd(){
			return c_current_gauge_maturity_add;
		}




	};

	
	void GlobalInstall_SonicGauge();
	
}