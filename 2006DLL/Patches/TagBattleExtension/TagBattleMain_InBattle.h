#pragma once


#include <Head.h>
#include "..\DebugLog\MessagesUtil.h"
#include <string>

#include <DocMarathonImp.h>

#include <vector>

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}



#include "..\All06Functions.hpp"


namespace TagBattleMain{


	extern int GoalCount;
	extern std::vector <int> GoalActors;
	void GlobalInstall_InBattle();

}


