
#include "Basics.h"


LPCWSTR g_pwstrButtonsX[1] = { L"------------OK----------------" };

void ShowXenonMessage(LPCWSTR Title,LPCWSTR wTitle){

	PushXenonMessage(Title,wTitle);
}

wchar_t *convertCharArrayToLPCWSTR(const char* charArray)
{
	wchar_t* wString=new wchar_t[4096];
	MultiByteToWideChar(CP_ACP, 0, charArray, -1, wString, 4096);
	return wString;
}

void ShowXenonMessage(LPCWSTR Title,char* wTitle){
	PushXenonMessage(Title,wTitle);
}
void ShowXenonMessage(LPCWSTR Title,const char* wTitle){
	PushXenonMessage(Title,wTitle);
}




void ShowXenonMessage(LPCWSTR Title,int value,char*){

	PushXenonMessage(Title,value);

}




void ShowXenonMessage(LPCWSTR Title,float value,char*){
	PushXenonMessage(Title,value);
}

