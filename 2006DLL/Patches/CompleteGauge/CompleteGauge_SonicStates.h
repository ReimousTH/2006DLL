#pragma once
#include <Head.h>
#include "CompleteGauge_SonicContext.h"

namespace CompleteGauge{
	
	
	void Switch(Sonicteam::Player::State::CommonContext* _context,const char* lua_name,const char* package_name,const char* sound_name,const char* char_name);
	void GlobalInstall_SonicStates();
	
}