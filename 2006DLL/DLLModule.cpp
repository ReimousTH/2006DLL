//-----------------------------------------------------------------------------
//  DLLModule.cpp
//
// Demonstrates the use of Dynamic Link Library (aka DLL) by
// Using the Load/FreeLibrary API.
//
//
// Xbox Advanced Technology Group.
// Copyright (C) Microsoft Corporation. All rights reserved.
//-----------------------------------------------------------------------------


#pragma warning(push)
#pragma warning(disable: 4101)
// here goes your code where the warning occurs
#pragma warning(pop)
//-----------------------------------------------------------------------------
//  DLLModule.cpp
//
// Demonstrates the use of Dynamic Link Library (aka DLL) by
// Using the Load/FreeLibrary API.
//
//
// Xbox Advanced Technology Group.
// Copyright (C) Microsoft Corporation. All rights reserved.
//-----------------------------------------------------------------------------



//#include "MPatches.h"
//#include "Marathon.h"
//#include "Patches.cpp"


#include <xtl.h>
void* operator new(size_t size) {
	return HeapAlloc(GetProcessHeap(), 0, size);
}

void operator delete(void* ptr) {
	HeapFree(GetProcessHeap(), 0, ptr);
}




#include "PatchData.h"
#include "Patches/DebugLog/DebugLog.h"
#include "Patches/DevTitle/DevTitle.h"
#include "Patches/CompleteGauge/CompleteGauge.h"
#include "Patches/TagBattleExtension/TagBattleMain.h"





struct DFastActions{
	char* GlobalName;
	void (__cdecl *Install)(void);
	
};

DFastActions _PreLoadPatches[] = {
	{"DebugLog_Enabled",DebugLogV2::GlobalInstall},
	{"DevTitleV2",DevTitleV2::GlobalInstall},
	{"Multiplayer4P_Enabled",Multiplayer4P::GlobalInstall},
	{"NoArcMode",ArcRemover::GlobalInstall},
	{"TimeSystemRestore",TimeSystemRestore::GlobalInstall},
	{"OmegaHoverGauge",OmegaF::GlobalInstall},
	{"CompleteGauge",CompleteGauge::GlobalInstall},
	{"AmyV2",AmyRework::GlobalInstall},
	{"TagStory",TagStory::GlobalInstall},
	{"TailsGauge",TailsGauge::GlobalInstall},
	{"AmyLOS",AmyLOS::GlobalInstall},
	{"TagBattleExtension",TagBattleMain::GlobalInstall}
};

bool _NoArcMode = false;
bool _TimeSystemRestore = false;
bool _Multiplayer4P = false;
bool _DebugLogRestore = false;
bool _OmegaHoverGauge = false;

int __declspec( naked ) MainAsmHookIline(_DWORD *a1, int* HandleManager, std::string* a3, std::string *a4, int* a5, int a6){
	__asm{
		mflr r12
			std       r29, -0x20(r1)
			std       r30, -0x18(r1)
			std       r31, -0x10(r1)
			stw       r12, -0x8(r1)
			stwu      r1, -0xC0(r1)
			mr        r29, r3
			lis r11,0x8258  
			ori r11,r11,0x2658 
			mtctr r11
			bctr r11
	}
}	
bool TOGLE = true;

HOOK(int,__fastcall,LoadFromArcHOOK_GLOBAL,0x82582648,_DWORD *a1, int* HandleManager, std::string* a3, std::string *a4, int* a5, int ShowErrors){



	DWORD test;
	__asm{
		mflr r12;
		stw r12,test
	}

	if (TOGLE){


		//ShowXenonMessage(L"MSG",a3->c_str());


	}

	//std::string* po = new std::string();
	//po->append(a3->c_str());
	//po->append(" : ");
	//po->append(a4->c_str());


	//std::stringstream ss;
	//std::stringstream ss1;

	//if (a5 == 0){
	//	ss << a5;
	//}
	//else{
	//	ss << *a5;
	//}


	//ss1 << ShowErrors;



	//	po->append(" : ");
	//	po->append(ss.str().c_str());

	//	po->append(" : ");
	//	po->append(ss1.str().c_str());










	if (a3->find("player.arc") != std::string::npos)
	{
		
//		    std::stringstream ss;
//		    ss << std::hex << test;
///			ShowXenonMessage(L"MSG",ss.str().c_str());
//			Sleep(1000);
//			while (true){
//
	//		}
	//		return MainAsmHookIline(a1,HandleManager,a3,a4,a5,0);



	}


	return MainAsmHookIline(a1,HandleManager,a3,a4,a5,ShowErrors);



};

bool TOOGLE = false;
DWORD WINAPI ThreadProc( LPVOID lpParameter )
{
	while (1){
		if (ATG::Input::GetMergedInput(0)->wLastButtons & XINPUT_GAMEPAD_Y)
		{
			TOOGLE = true;
		}

	}
}






HOOK(DWORD*,__fastcall,DocMarathonState_GLOBAL,0x82160B98,DWORD* a1,int a2){

  // Create a thread in a suspended state
    HANDLE hThread = CreateThread(
        NULL,                      // lpThreadAttributes
        0,                         // dwStackSize
        ThreadProc,                // lpStartAddress
        (LPVOID)THREAD_SUSPEND_RESUME,  // lpParameter
        CREATE_SUSPENDED,          // dwCreationFlags
        NULL                       // lpThreadId
    );

	byte s0[0x1C];
	byte s1[0x1C];
	byte s2[0x1C];
	byte s3[0x1C];


	DWORD handle1;
	DWORD handle2;
	DWORD handle3;




	BranchTo(0x821620E8,int,&s1,"DLL/cache_3P.arc");
	BranchTo(0x821620E8,int,&s3,"DLL/sprites_4P.arc");
	BranchTo(0x821620E8,int,&s2,"DLL/scripts_4P.arc");



	sub_825EB070((int)a1, a2);
	*a1 = 0x8200094C;



	int result1 = ArcHandle(&handle1,&s1,2,2);
	int result2 = ArcHandle(&handle1,&s2,2,2);
	int result3 = ArcHandle(&handle1,&s3,2,2);



	sub_82582C10(*(DWORD*)result1);
	sub_82582C10(*(DWORD*)result2);
	sub_82582C10(*(DWORD*)result3);


	return a1;
}


int __fastcall sub_8264E068(int a1, int a2, int a3) {
    Sonicteam::SoX::IResource* resource = (Sonicteam::SoX::IResource*)a1;

    if (resource->str1.find("archive.pkg") != std::string::npos) {
        int FixedArchive = (*(int(__fastcall**)(int, const char*))(*(_DWORD*)a1 + 0x30))(a1, "archive_fixed");
        int Handle;

 //       if (int* FileToProcess = (int*)(*(int(__fastcall**)(int*, int, std::string*))(*(_DWORD*)FixedArchive + 4))(&Handle, FixedArchive, &std::string("DLL/player_Super.arc"))) {
   //         // Process the file
     //   }
    }

    int r = BranchTo(0x8264E068, int, a1, a2, a3);

    if (resource->str1.find("archive.pkg") != std::string::npos) {
        int Handle;

        if (Sonicteam::SoX::IResource** ArcFile = (Sonicteam::SoX::IResource**)ArcHandle(&Handle, &std::string("DLL/player_Super.arc"), 2, 2)) {
            // Process the archive file
        }
    }

    // ExtraPackage

    return r;
}

extern "C" void OnDLLStart(){
	TagBattleMain::GlobalInstall();
	std::string Loaded;

	DebugLogV2::GlobalInstall();
	CheckEmulated::GlobalInstall();
	//DevTitleV2::GlobalInstall();
	//DevTitle::GlobalInstall();



	//new SonicGaugeExtended()
	BaseLua.DoFile(true);

	if (BaseLua.executed){

		for (int i = 0;i<sizeof(_PreLoadPatches) / sizeof(DFastActions);i++){

			if (BaseLua.GetGlobalBool(_PreLoadPatches[i].GlobalName) == true){
				//ShowXenonMessage(L"MSG",_PreLoadPatches[i].GlobalName);
				Loaded.append(_PreLoadPatches[i].GlobalName);
				Loaded.append("\n");
				_PreLoadPatches[i].Install();
			}
		}
	}


	



	WRITE_DWORD(0x8204D3A8,sub_8264E068);
	INSTALL_HOOK(DocMarathonState_GLOBAL);
	INSTALL_HOOK(LoadFromArcHOOK_GLOBAL);
	
	ShowXenonMessage(L"LoadedDLLPatches",Loaded.c_str());
	Loaded.clear();


	//ImGUI::GlobalInstall();
	//TestProject::GlobalInstall();

	//ImGUI::GlobalInstall();

	//AmyRework::GlobalInstall();
	//ChainJumpTest::GlobalInstall();



//new Sonicteam::Player::State::CommonContext();

//new Sonicteam::Combo::AttackManager();



//new Sonicteam::Player::Input::ListenerNormal(0,0);


//(new Sonicteam::SoX::Object())->getNextObject();


//new Sonicteam::SoX::Component(0);
	

//new Sonicteam::SoX::ObjectRework();
//Sonicteam::Player::SonicGauge* gg = new Sonicteam::Player::SonicGauge();


//std::type_info* z0 = (std::type_info*)&typeid(Sonicteam::Player::SonicGauge);

//const char* tu = z0->name();

//Sonicteam::Player::State::Machine2* t = new Sonicteam::Player::State::Machine2();

//SonicTeam::Player::State::CommonObject* v = new SonicTeam::Player::State::CommonObject((SonicTeam::Player::State::IMachine*)t);





//Sonicteam::Player::State::AmyContext* tz = new Sonicteam::Player::State::AmyContext();

//if (*(int*)tz == 0x82000000){
//tz->AmyUnkFlags = 1;
//}



//Sonicteam::DocMarathonImp* impl = new Sonicteam::DocMarathonImp(0);

//Sonicteam::SoX::RefCountObject* _reference = new Sonicteam::SoX::RefCountObject();

//_reference->ObjectDestroy(1);
//Sonicteam::HUDOption* _opt = new Sonicteam::HUDOption();
//_opt->DestroyObject(1);


 //Sonicteam::Player::RootFrame* rf =  new Sonicteam::Player::RootFrame();

 //XMMATRIX a =  rf->FrameGetTransformMatrix1();

//boost::shared_ptr<Sonicteam::Player::GaugeStandard> tuu (new Sonicteam::Player::GaugeStandard());

//tuu.reset();


//t->GetMashineContext();


//Sonicteam::Player::Effect::IParticle* v = new Sonicteam::Player::Effect::IParticle(new Sonicteam::Player::IPlugIn("test"),std::string("t"));

//v->BufferParticleName = std::string("et");

//Sonicteam::MyPhysicsSystemFactory* tax = Sonicteam::MyPhysicsSystemFactory::GetOriginInstance();

//Sonicteam::MyPhysicsSystemFactory* tax1 = Sonicteam::MyPhysicsSystemFactory::GetInstance();

//delete tax;
//delete tax1;

//	ImGUI::GlobalInstall();

//	Sonicteam::SoX::Physics::BoxShape* v = new Sonicteam::SoX::Physics::BoxShape(10,10,10);
//	v->Width = 0;

	
}


//-----------------------------------------------------------------------------
// Name: DllMain()
// Desc: The function which is called at initialization/termination of the process
//       and thread and whenever LoadLibrary() or FreeLibrary() are called.
//       The DllMain routine should not be used to load another module or call a
//       routine that may block.
//-----------------------------------------------------------------------------
BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		OnDLLStart();
        break;
    case DLL_THREAD_ATTACH:
        break;
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        break;

    }
    return TRUE;
}


//-----------------------------------------------------------------------------
// Desc: Export a global constant variable
//-----------------------------------------------------------------------------
extern "C" const TCHAR szModuleName[] = TEXT("DLLModule.dll");

//-----------------------------------------------------------------------------
// Name: Function1()
// Desc: Export function
//-----------------------------------------------------------------------------

