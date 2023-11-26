#pragma once
#ifndef PatchDataCPP
#define PatchDataCPP
#include "Hook.h"
#include "Basics.h"
#include "Marathon/Marathon.h"


#include "All06Functions.hpp"

#include "IdaExports.h"



static ZLua BaseLua =  ZLua((const char*)"game:\\common\\DLL.lua");

static ZLua QuickBootLua =  ZLua((const char*)"game:\\common\\QuickBoot.lua");




namespace DebugLogRestore{
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

	namespace Gems{
		enum Gems{
			Green,
			Red,
			Blue,
			White,
			Sky,
			yellow,
			purple,
			super
		};

	}
	

#define IContext_TypeDescriptor 0x82B17464
#define ICommonContext_TypeDescriptor 0x82B17464
#define SonicContext_TypeDescriptor 0x82B177A8


	class SonicMachSpeed:public Sonicteam::Player::State::CommonObject{
	public:
		Sonicteam::Player::State::SonicContext* CObjContext;
		float c_custom_action_machspeed_time;

	};


	void GlobalInstall();
}






namespace AmyRework{

	void GlobalInstall();
};
#endif