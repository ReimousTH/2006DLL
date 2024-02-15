#pragma  once
#include <vector>
#include <xtl.h>


namespace DebugLogV2{


	static std::vector<int> DebugMessagesPlace;
	static std::vector<int> DebugMessages;
	static XMFLOAT4 ScrollPosition;

	void ChangeMessagePosition(UINT32 TextEntity,float x,float y);
	void ChangeMessagePositionY(UINT32 TextEntity,float y);
	void EditMessage(UINT32 TextEntity,const wchar_t* msg);
	UINT32 SpawnMessage(const wchar_t* msg,float pos_x,float pos_y);
	UINT32 SpawnMessage(const wchar_t* msg,float pos_y);

}

