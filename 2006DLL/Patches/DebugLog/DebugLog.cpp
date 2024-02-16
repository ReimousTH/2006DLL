#include "DebugLog.h"

namespace DebugLogV2{


	int __declspec( naked ) sub_825DB498H(lua_State* LS){

		__asm{
			mflr      r12
				stw       r12, -8(r1)
				std       r31, -0x10(r1)

				stwu      r1, -0x60(r1)
				lis r11,0x825D
				ori r11,r11,0xB4A8
				mtctr r11
				bctr
		}
	}





	HOOK(int,__cdecl ,sub_825DB498,0x825DB498,lua_State* LS){
		

	
		DebugLabel_GlobalInstall(LS);
		BitLibGlobalInstall(LS);
		PlayerLIB_GlobalInstall(LS);
		STRLIB_GlobalInstall(LS);
		MemoryLIB_GlobalInstall(LS);

		return sub_825DB498H(LS);
	}


	int __declspec( naked ) PlayBGMH(lua_State* LS){

		__asm{
			mflr      r12
				stw       r12, -8(r1)
				std       r30, -0x18(r1)
				std       r31, -0x10(r1)

				lis r11,0x8246
				ori r11,r11,0x23E8
				mtctr r11
				bctr

		}
	}
	HOOK(int,__cdecl ,PlayBGM,0x824623D8,lua_State* LS){



		int dt =   (int)lua_touserdata(LS, -10002); 
		BranchTo(0x8216B360,int,dt,lua_tostring(LS,1));

		return PlayBGMH(LS);
	}







	void GlobalInstall()
	{
		INSTALL_HOOK(sub_825DB498); //MathLibReplacement
		INSTALL_HOOK(PlayBGM); //FIX



		MessageUtilGlobalInstall();


	}
}



