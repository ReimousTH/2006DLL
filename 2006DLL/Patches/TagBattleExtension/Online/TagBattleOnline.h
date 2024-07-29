#pragma once
#include <Head.h>
#include "..\..\DebugLog\MessagesUtil.h"
#include <string>

#include <DocMarathonImp.h>

#include <vector>

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}
#include "..\All06Functions.hpp"

#include "Socket.h"


namespace TagBattleMain{

	
	struct PLAYERS_DATA{

		XMVECTOR Rotation;
		XMVECTOR Position;
		int SelectionIndex;
		int LastSelectionIndex;
		int CurrentController;
		int input_data;
		int input_container[2];
		float hold_time;
		float hold_time_Y;
		int selected;

	};






	void GlobalInstall_ONLINE();

}


