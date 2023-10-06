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
	void GlobalInstall();
}





#endif