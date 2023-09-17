
#include "Basics.h"


LPCWSTR g_pwstrButtonsX[1] = { L"------------OK----------------" };

void ShowXenonMessage(LPCWSTR Title,LPCWSTR wTitle){

	MESSAGEBOX_RESULT result;
	XOVERLAPPED m_Overlapped; 
	XShowMessageBoxUI(0,Title,wTitle,1,g_pwstrButtonsX,1,XMB_ALERTICON,&result,&m_Overlapped);
}

wchar_t *convertCharArrayToLPCWSTR(const char* charArray)
{
	wchar_t* wString=new wchar_t[4096];
	MultiByteToWideChar(CP_ACP, 0, charArray, -1, wString, 4096);
	return wString;
}

void ShowXenonMessage(LPCWSTR Title,char* wTitle){

	MESSAGEBOX_RESULT result;
	XOVERLAPPED m_Overlapped; 


	XShowMessageBoxUI(0,Title,convertCharArrayToLPCWSTR(wTitle),1,g_pwstrButtonsX,1,XMB_ALERTICON,&result,&m_Overlapped);
}

MESSAGEBOX_RESULT* ShowXenonMessage(LPCWSTR Title,const char* wTitle){

	MESSAGEBOX_RESULT result;
	XOVERLAPPED m_Overlapped; 
	XShowMessageBoxUI(0,Title,convertCharArrayToLPCWSTR(wTitle),1,g_pwstrButtonsX,1,XMB_ALERTICON,&result,&m_Overlapped);
	return &result;
}


void ShowXenonMessage(LPCWSTR Title,int value,char*){


	int vIn = value;;
	wchar_t vOut [12];
	_itow_s(vIn,vOut,sizeof(vOut)/2,10);

	ShowXenonMessage(Title,vOut);

}



void ShowXenonMessage(LPCWSTR Title,float value,char*){


	float vIn = value;
	char vOutChar [17];
	_gcvt_s(vOutChar,sizeof(vOutChar),vIn,8);
	wchar_t vOut[17];
	mbstowcs_s(NULL,vOut,sizeof(vOut)/2,vOutChar,sizeof(vOutChar));

	ShowXenonMessage(Title,vOut);

}
