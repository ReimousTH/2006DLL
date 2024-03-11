#pragma once

#include <Head.h>
#include "Player/State/SonicContext.h"
#include "CompleteGauge_SonicStates.h"


namespace CompleteGauge{
	


	class SonicContextExtended:public  Sonicteam::Player::State::SonicContext{

	public:
		bool IsSuper;
		float c_super_ring_dec_time;

	};
	//temp story values
	static float gauge_storage[8] = {0};
	static int gauge_levels_storage[8] = {0};

	
	void GlobalInstall_SonicContext();
	
}