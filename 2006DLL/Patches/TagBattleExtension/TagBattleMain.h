#pragma once
#include <Head.h>
#include "TagBattleMain_InBattle.h"



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

	class EmptyXNCPCSD:Sonicteam::SoX::RefCountObject,public Sonicteam::SoX::Engine::Task{


	};
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


	extern std::map<int, PLAYERS_DATA*> ordered_input;
	extern std::vector<int> origin_index_order;



	void GlobalInstall();

}


