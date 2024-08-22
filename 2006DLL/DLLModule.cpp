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


#include <Player/LuaInfoInit.h>


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
	{"TagBattleExtension",TagBattleMain::GlobalInstall},
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


	//ShowXenonMessage(L"MSG",Sonicteam::Player::CharacterStateAnimationTableCommon.RegisteredAnimations.items[0]);

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








bool CheckDLLFile(std::string* str_file_name)
{
	std::stringstream ss;
	ss << "game://" << "common/" << str_file_name->c_str();


	HANDLE handle = CreateFile( ss.str().c_str(), GENERIC_READ, 0, NULL, 
		OPEN_EXISTING, 0, NULL );

	if (handle != INVALID_HANDLE_VALUE)
	{
		CloseHandle(handle);
		return true;
	}
	else
	{
		return false;
	}
}

void LoadDLLArcFile(const char* file){


	std::string _file = file;
	if (CheckDLLFile(&_file))
	{
		Sonicteam::SoX::IResource* resouce;
		ArcHandle(&resouce,_file,2,2);
		sub_82582C10(resouce);
	}

}

HOOK(DWORD*,__fastcall,DocMarathonState_GLOBAL,0x82160B98,DWORD* a1,int a2){
    
	


	

	sub_825EB070((int)a1, a2);
	*a1 = 0x8200094C;



	std::vector<std::string>* pkg = 	ExFileSystem::GetArcs();
	for (std::vector<std::string>::iterator it = pkg->begin();it!= pkg->end();it++){
		LoadDLLArcFile(it->c_str());
	}

	

//	LoadDLLArcFile("DLL/cache_3P.arc");
//	LoadDLLArcFile("DLL/sprites_4P.arc");
//	LoadDLLArcFile("DLL/scripts_4P.arc");



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

		std::vector<std::string>* pkg = 	ExFileSystem::GetArcs_pkg();
		for (std::vector<std::string>::iterator it = pkg->begin();it!= pkg->end();it++){
			LoadDLLArcFile(it->c_str());
		}

    }

    // ExtraPackage

    return r;
}



unsigned long long& PerformanceFrequencyOutput = *(unsigned long long*)0x82D3B800;
unsigned int& dword_82B7D6C8 = *(unsigned int*)0x82B7D6C8;








HOOK(void,__fastcall,sub_825B19C0,0x825B1870,int a1,double delta)
{
	UINT start_ticks;
	UINT end_ticks;
	char _stack[0xD0];	

	BranchTo(0x825D3F98,int,_stack[0x50]); //Perfomance some

	BranchTo(0x825D3FD0,int,&_stack[0x58],&_stack[0x50]);
	for ( ; (*(_BYTE *)(a1 + 4) & 1) != 1; ){

		start_ticks = GetTickCount();
		double f31 = 0.000001;

		BranchTo(0x825D3FD0,int,&_stack[0x50],&_stack[0x60]);
		BranchTo(0x825B0988,int,a1); //ProcessXboxSignNotifies
		BranchTo(0x825B0AC0,int,a1); //Proess
		int v2 = *(unsigned __int8 *)(a1 + 0x122);
		if ( *(_DWORD *)(a1 + 0x148) == 1 )
		{
			if ( *(_DWORD *)(a1 + 0x12C) == 0x3E5 )
			{
				v2 = 1;
			}
			else
			{

				*(_DWORD *)(a1 + 0x148) = 0;
				*(_DWORD *)(a1 + 0x128) = BranchTo(0x82AEA67C,int,dword_82B7D6C8);
			}
		}
		*(_BYTE *)(a1 + 0x122) = (v2 & 0x20) != 0;
		BranchTo(0x825D3FD0,int,&_stack[0x50],&_stack[0x68]);


		unsigned long long* _stack0x58 = (unsigned long long*)&_stack[0x58];
		unsigned long long* _stack0x68 = (unsigned long long*)&_stack[0x68];
		unsigned long long* _stack0x70 = (unsigned long long*)&_stack[0x70];
		unsigned long long* _stack0x78 = (unsigned long long*)&_stack[0x78];
		unsigned long long _stack0x58x0x68_calc = *_stack0x58 - *_stack0x68;
		*_stack0x58 = *_stack0x68;
		*_stack0x70 = _stack0x58x0x68_calc;
		unsigned long r11 =   BranchTo(0x825D4018,unsigned long,&_stack[0x70]); //825B1944 
		*_stack0x78 = r11;



		BranchTo(0x82580E90,int,a1,(double)*_stack0x78 * f31);
	    unsigned long long* r11_pointer =  BranchTo(0x825D3FD0,unsigned long long*,&_stack[0x50],&_stack[0x90]);
		unsigned long long* _stack0x60 = (unsigned long long*)&_stack[0x60];
		unsigned long long* _stack0x80 = (unsigned long long*)&_stack[0x80];
		unsigned long long _stack0x60_calc = *_stack0x60 - *r11_pointer;
		*_stack0x80 = _stack0x60_calc;	
	    unsigned long long r11_o =   BranchTo(0x825D4018,unsigned long long,&_stack[0x80]); //825B1944 
		*(unsigned long long *)(a1 + 0xE8) = r11_o;
		unsigned long long* r11_pointer_o =  BranchTo(0x825D3FD0,unsigned long long*,&_stack[0x50],&_stack[0x98]);
		unsigned long long* _stack0x88 = (unsigned long long*)&_stack[0x88];
		*_stack0x88 = *_stack0x60 - *r11_pointer_o;

		unsigned long long r11_oo =   BranchTo(0x825D4018,unsigned long long ,&_stack[0x88]); //825B1944 
		*(	unsigned long long *)(a1 + 0xE0) = r11_oo;


		int Ticks = GetTickCount() - start_ticks;
		if (Ticks < 33){
			Sleep(33-Ticks);
		}
	

	}


}



extern "C" void OnDLLStart(){

	

		

	

//	Sonicteam::SoX::Thread* _thread =  new Sonicteam::SoX::Thread("T",0,0);
//	ShowXenonMessage(L"MSG",_thread->m_ThreadName);



	


	std::string Loaded;
	CheckEmulated::GlobalInstall();
	ExFileSystem::getInstance();

	//new SonicGaugeExtended()
	BaseLua.DoFile(true);


	if (BaseLua.executed){


		Socket::IP_ADDR = BaseLua.GetGlobalString("IP_ADRESS");	


		if (BaseLua.GetGlobalBool("FPS30") == true){

			INSTALL_HOOK(sub_825B19C0);
			WRITE_DWORD(0x820167AC,0x3D088886);
			WRITE_DWORD(0x82000B88,0x3D088889);

		}


		for (int i = 0;i<sizeof(_PreLoadPatches) / sizeof(DFastActions);i++){

			if (BaseLua.GetGlobalBool(_PreLoadPatches[i].GlobalName) == true){
				//ShowXenonMessage(L"MSG",_PreLoadPatches[i].GlobalName);
				Loaded.append(_PreLoadPatches[i].GlobalName);
				Loaded.append("\n");
				_PreLoadPatches[i].Install();
			}
		}
	}


	
	bool disable = false;
	if (BaseLua.executed){


		if (BaseLua.GetGlobalBool("NoArcMode") == true){

			disable = true;

		}
	}

	
	if (!disable){
		WRITE_DWORD(0x8204D3A8,sub_8264E068);
		INSTALL_HOOK(DocMarathonState_GLOBAL);
		INSTALL_HOOK(LoadFromArcHOOK_GLOBAL);

	}

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

