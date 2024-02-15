#include "MessagesUtil.h"

void DebugLogV2::ChangeMessagePosition(UINT32 TextEntity,float x,float y)
{

	XMVECTOR* pos = (XMVECTOR*)(TextEntity + 0x30);
	pos->x = x;
	pos->y = y;
	*(_BYTE *)(TextEntity + 0xDD) = 1;
	BranchTo(0x8262AF00,int,TextEntity,30.0);
	BranchTo(0x8262B008,int,TextEntity);


}

void DebugLogV2::ChangeMessagePositionY(UINT32 TextEntity,float y)
{
	XMVECTOR* pos = (XMVECTOR*)(TextEntity + 0x30);
	pos->x = 0.0;
	pos->y = 480 + y;
	*(_BYTE *)(TextEntity + 0xDD) = 1;
	BranchTo(0x8262AF00,int,TextEntity,30.0);
	BranchTo(0x8262B008,int,TextEntity);
}

void DebugLogV2::EditMessage(UINT32 TextEntity,const wchar_t* msg)
{
	*(_BYTE *)(TextEntity + 0xDD) = 1;
	BranchTo(0x8262DB90,int,TextEntity,msg,0); //New Text
	BranchTo(0x8262B008,int,TextEntity);
}

UINT32 DebugLogV2::SpawnMessage(const wchar_t* msg,float pos_x,float pos_y)
{

	Sonicteam::DocMarathonImp* doc = *(Sonicteam::DocMarathonImp**)(*(UINT32*)0x82D3B348 + 0x180);
	UINT32 Resouce = doc->DocGetUnkGameResources();
	// 8 * (index + 3)
	UINT32 RequiredResouce = (8*(3)) + Resouce;

	//wchar_t or i
	//i dunno text-size???// 
	//Z-Inddex ???
	UINT32 TextEntity = BranchTo(0x8262DC60,UINT32,malloc06(0x110),RequiredResouce,msg,0,0);

	BranchTo(0x8262AF00,int,TextEntity,30.0);

	XMVECTOR* pos = (XMVECTOR*)(TextEntity + 0x30);
	pos->x = pos_x;
	pos->y = pos_y;
	*(_BYTE *)(TextEntity + 0xDD) = 1;
	//BranchTo(0x8262DB90,int,TextEntity,L"JUCK",0); //New Text
	//ARGB(Alpha,Red,Green,Blue)
	UINT flag = ((0xFF << 24) |(0xFF << 16) | (0xFF << 8) |  0x00 );
	BranchTo(0x8262B288,int,TextEntity,&flag);
	BranchTo(0x8262B008,int,TextEntity);
	return TextEntity;
}






namespace DebugLogV2{
LPCWSTR g_pwstrButtonsXx[1] = { L"------------OK----------------" };
wchar_t *convertCharArrayToLPCWSTR(const char* charArray)
{
	wchar_t* wString=new wchar_t[4096];
	MultiByteToWideChar(CP_ACP, 0, charArray, -1, wString, 4096);
	return wString;
}

DWORD WINAPI ThreadProc( LPVOID lpParameter )
{

	DWORD dwThreadNumber = (DWORD) lpParameter;



	while (true){

		ATG::GAMEPAD* gc = ATG::Input::GetMergedInput(0);


		if (gc->wPressedButtons & XINPUT_GAMEPAD_DPAD_UP){
			std::string* si = new std::string();
			for (int i = 0;i<DebugLogV2::log.size();i++){
				si->append(*DebugLogV2::log[i]);
				si->append("\n");
			}

			MESSAGEBOX_RESULT result;
			XOVERLAPPED m_Overlapped; 
			XShowMessageBoxUI(0,L"Debug.Log(Result)",convertCharArrayToLPCWSTR(si->c_str()),1,g_pwstrButtonsXx,1,XMB_ALERTICON,&result,&m_Overlapped);

			while (result.dwButtonPressed != 0){
			}
			Sleep(1000);




		}
		if (gc->wPressedButtons & XINPUT_GAMEPAD_DPAD_DOWN){

			for (int i = 0;i<DebugLogV2::log.size();i++){
				delete DebugLogV2::log[i];
			}


			DebugLogV2::log.resize(0);
		}


	}


	return 0;
}



static int luaB_print (lua_State *L) {

	int n = lua_gettop(L);  /* number of arguments */
	int i;
	lua_getglobal(L, "tostring");
	for (i=1; i<=n; i++) {
		const char *s;
		lua_pushvalue(L, -1);  /* function to be called */
		lua_pushvalue(L, i);   /* value to print */
		lua_call(L, 1, 1);
		s = lua_tostring(L, -1);  /* get result */
		if (s == NULL)
			return luaL_error(L, "`tostring' must return a string to `print'");

		DebugLogV2::log.push_back(new std::string(s));

		//if (i>1) fputs("\t", stdout);
		//fputs(s, stdout);
		lua_pop(L, 1);  /* pop result */
	}
	fputs("\n", stdout);
	return 0;
}


}



void DebugLogV2::MessageUtilGlobalInstall()
{


	WRITE_DWORD(0x8203B8AC,luaB_print);
	WRITE_DWORD(0x82049094,luaB_print);

	const int stackSize = 65536;
	HANDLE Thr = CreateThread( NULL, stackSize, ThreadProc, (VOID *)0, CREATE_SUSPENDED, NULL );
	ResumeThread(Thr);

}

UINT32 DebugLogV2::SpawnMessage(const wchar_t* msg,float pos_y)
{
	Sonicteam::DocMarathonImp* doc = *(Sonicteam::DocMarathonImp**)(*(UINT32*)0x82D3B348 + 0x180);
	UINT32 Resouce = doc->DocGetUnkGameResources();
	// 8 * (index + 3)
	UINT32 RequiredResouce = (8*(3)) + Resouce;

	//wchar_t or i
	//i dunno text-size???// 
	//Z-Inddex ???
	UINT32 TextEntity = BranchTo(0x8262DC60,UINT32,malloc06(0x110),RequiredResouce,msg,0,0);


	BranchTo(0x8262AF00,int,TextEntity,30.0);

	XMVECTOR* pos = (XMVECTOR*)(TextEntity + 0x30);
	pos->x = 0;
	pos->y = 480.0 + pos_y;
	*(_BYTE *)(TextEntity + 0xDD) = 1;
	//BranchTo(0x8262DB90,int,TextEntity,L"JUCK",0); //New Text
	//ARGB(Alpha,Red,Green,Blue)
	UINT flag = ((0xFF << 24) |(0xFF << 16) | (0xFF << 8) |  0x00 );
	BranchTo(0x8262B288,int,TextEntity,&flag);
	BranchTo(0x8262B008,int,TextEntity);
	return TextEntity;
}
