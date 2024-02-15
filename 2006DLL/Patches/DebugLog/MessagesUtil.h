#pragma once

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}


#include <vector>
#include <xtl.h>


#include <DocMarathonImp.h>
#include <Head.h>
#include "AtgInput.h"
#include <string>

#define  _BYTE char

namespace DebugLogV2{


	static std::vector<int> DebugMessagesPlace;
	static std::vector<int> DebugMessages;
	static XMFLOAT4 ScrollPosition;

	void ChangeMessagePosition(UINT32 TextEntity,float x,float y);
	void ChangeMessagePositionY(UINT32 TextEntity,float y);
	void EditMessage(UINT32 TextEntity,const wchar_t* msg);
	UINT32 SpawnMessage(const wchar_t* msg,float pos_x,float pos_y);
	UINT32 SpawnMessage(const wchar_t* msg,float pos_y);


	//OriginalLog
	static std::vector<std::string*> log;
	void MessageUtilGlobalInstall();

}

