#pragma once
#ifndef PatchDataCPP
#define PatchDataCPP
#include "HookV2.h"
#include "Basics.h"
#include "Marathon/Marathon.h"





#include "All06Functions.hpp"
#include "IdaExports.h"



static ZLua BaseLua =  ZLua((const char*)"game:\\common\\DLL.lua");
static ZLua QuickBootLua =  ZLua((const char*)"game:\\common\\QuickBoot.lua");







namespace CheckEmulated{
	void GlobalInstall();
}

namespace DebugLogRestore{




	struct LabelData {
		int* ptr;
	};

	static std::vector<int> DebugMessagesPlace;
	static std::vector<int> DebugMessages;
	static XMFLOAT4 ScrollPosition;

	void ChangeMessagePosition(UINT32 TextEntity,float x,float y);
	void ChangeMessagePositionY(UINT32 TextEntity,float y);
	void EditMessage(UINT32 TextEntity,const wchar_t* msg);
	UINT32 SpawnMessage(const wchar_t* msg,float pos_x,float pos_y);
	UINT32 SpawnMessage(const wchar_t* msg,float pos_y);


	void GlobalInstall();
}

namespace Multiplayer4P{
	void GlobalInstall();
}


namespace LuaDLL{
	static lua_State* LState;
	void GlobalInstall();
}


namespace D3DH{
	void GlobalInstall();
}

namespace DevTitle{
	void GlobalInstall();
}

namespace TestProject{
	void GlobalInstall();
}


namespace TimeSystemRestore{
	void GlobalInstall();
}
namespace ArcRemover{
		void GlobalInstall();
}

namespace ImGUI{

	void GlobalInstall();
}

namespace OmegaF{
	void GlobalInstall();
}

namespace ChainJumpTest{
	void GlobalInstall();
}


namespace WhiteGameRestored
{


	void GlobalInstall();
}






namespace AmyRework{

	void GlobalInstall();
};

namespace AmyLOS{


	class AmyContextE:public Sonicteam::Player::State::AmyContext{

	public:
		float c_before_dizzy_time;
	};


	void GlobalInstall();
};

namespace TagStory{
	void GlobalInstall();
}

namespace TailsGauge{

	void GlobalInstall();
}













#endif
