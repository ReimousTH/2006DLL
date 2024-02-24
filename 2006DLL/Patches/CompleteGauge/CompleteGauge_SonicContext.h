#pragma once

#include <Head.h>
#include "Player/State/SonicContext.h"
namespace CompleteGauge{
	


	class SonicContextExtended:public  Sonicteam::Player::State::SonicContext{

	public:
		bool IsSuper;
		float c_super_ring_dec_time;

	};
	
	void GlobalInstall_SonicContext();
	
}