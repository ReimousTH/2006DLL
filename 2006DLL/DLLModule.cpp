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
};

bool _NoArcMode = false;
bool _TimeSystemRestore = false;
bool _Multiplayer4P = false;
bool _DebugLogRestore = false;
bool _OmegaHoverGauge = false;







extern "C" void OnDLLStart(){

	std::string Loaded;

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

