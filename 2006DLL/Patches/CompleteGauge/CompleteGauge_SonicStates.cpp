#pragma once
#include "CompleteGauge_SonicStates.h"
#include <Player/State/CommonObject.h>
#include <Player/State/SonicContext.h>
#include <LuaSystem.h>
#include <Player/INotification.h>


#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>

#include <boost/cast.hpp>


namespace CompleteGauge{
	

	class SonicSuperStateExtended:public Sonicteam::Player::State::BasedObject<SonicContextExtended>{
	public:
		float time;
		float time_max;
		bool Trigger;
	};


	float ObjPlayerGetCurrentAnimTime(Sonicteam::Player::State::CommonContext* _context){

		Sonicteam::Player::Score* score =  _context->ScorePlugin.get();
		int ObjPlayer = score->PtrObjectPlayer;
		int ModelPlayer = *(int*)(ObjPlayer + 0xD4);
		int ObjectPackageModel = *(int*)(ModelPlayer + 0x30);
		int IntrpoalateAnimationPackageModel = *(int*)(ObjectPackageModel + 0x98); //InterpolateAnimation Mostly
		int AnimationPackageModel;
		if (*(int*)IntrpoalateAnimationPackageModel == 0x8200CA6C){
			AnimationPackageModel = *(int*)(IntrpoalateAnimationPackageModel +0xC);
		}
		else{
			AnimationPackageModel = IntrpoalateAnimationPackageModel;
		}

		int AnimationHierarchyCommon = *(int*)(AnimationPackageModel + 0x4);
		return  *(float*)(AnimationHierarchyCommon +0x18);

	}
	void ObjPlayerSetCurrentAnimTime(Sonicteam::Player::State::CommonContext* _context,float value){

		Sonicteam::Player::Score* score =  _context->ScorePlugin.get();
		int ObjPlayer = score->PtrObjectPlayer;
		int ModelPlayer = *(int*)(ObjPlayer + 0xD4);
		int ObjectPackageModel = *(int*)(ModelPlayer + 0x30);
		int IntrpoalateAnimationPackageModel = *(int*)(ObjectPackageModel + 0x98); //InterpolateAnimation Mostly
		int AnimationPackageModel;
		if (*(int*)IntrpoalateAnimationPackageModel == 0x8200CA6C){
			AnimationPackageModel = *(int*)(IntrpoalateAnimationPackageModel +0xC);
		}
		else{
			AnimationPackageModel = IntrpoalateAnimationPackageModel;
		}

		int AnimationHierarchyCommon = *(int*)(AnimationPackageModel + 0x4);
		*(float*)(AnimationHierarchyCommon +0x18) = value;

	}


	void Switch(Sonicteam::Player::State::CommonContext* _context,const char* lua_name,const char* package_name,const char* sound_name,const char* char_name){

		Sonicteam::Player::Score* score =  _context->ScorePlugin.get();
		int ObjPlayer = score->PtrObjectPlayer;

		if (*(std::string*)(ObjPlayer + 0x1D8) == char_name ){
			return;
		}



		int ModelPlayer = *(int*)(ObjPlayer + 0xD4);
		
		Sonicteam::LuaSystem* p;
		if (!lua_name)
		const char* lua_name = "player/sonic_super.lua";
		if (!package_name)
		const char* package_name = "player/sonic_super";
		if (!sound_name)
		const char* sound_name = "player_sonic";


	    BranchTo(0x821EA260,int,&p,&std::string(lua_name),0x82003380,0x1D);
	


	


		//Reload Package
		std::string* S1 =  (std::string *)(ObjPlayer + 0x74);
		*S1 = package_name;
		int v6 = *(_DWORD *)(ObjPlayer + 0x154);
		if ( v6 )
		{	
				int v11[8];
				int* v7 = (int *)(*(int (__fastcall **)(int *, int, int))(*(_DWORD *)v6 + 4))(v11, v6, ObjPlayer + 0x74); //Player Load Load Package File
				int v8 = *v7;		

				Sonicteam::SoX::RefCountObject* v9 = *(	Sonicteam::SoX::RefCountObject**)(ObjPlayer + 0xD0);
				*(_DWORD *)(ObjPlayer + 0xD0) = v8;
				if ( v9 )
					v9->LoseObject();
		}


		
		

		float Save0x18 = ObjPlayerGetCurrentAnimTime(_context);
	
		

		//Reload (IVarible)) (input,model, gravity, state_context, zock, path, path_gd, path_col, score, physicsbody, automatic_dead, lockon, homing, lockon_homing, path_ld, lockon_lightdash, gauge, sonic_weapons,input vehicle, waterslider, item, ai)
		std::vector<boost::shared_ptr<Sonicteam::Player::IVariable>>* PluginsXX = reinterpret_cast<std::vector<boost::shared_ptr<Sonicteam::Player::IVariable>>*>(ObjPlayer + 0x21C);
	
	
		for (std::vector<boost::shared_ptr<Sonicteam::Player::IVariable>>::iterator it = PluginsXX->begin(); it != PluginsXX->end(); it++) {
			boost::shared_ptr<Sonicteam::Player::IVariable> pluginPtr = *it;

			if (Sonicteam::Player::IPlugIn* plugin = dynamic_cast<Sonicteam::Player::IPlugIn*>(pluginPtr.get())) {
				if  (plugin->PluginName == "item"){
				//	_DWORD* v1 = (_DWORD *)plugin;
				//	int v2 = (int)(plugin) + 0x38;
				//	int v3 = *(_DWORD *)((int)(plugin) + 0x3C);

				//	int PlayerLoad = *(_DWORD *)(ObjPlayer + 0x154);
				//	int PlayerRootFrame = *(_DWORD *)(ObjPlayer + 0xCC);
				//	int a1 = (int)plugin;
				//	BranchTo(0x8223C560,int,plugin); //Destroy
				//	memset((void*)plugin,0,0x4C);
				//	BranchTo(0x8223C480,int,plugin,PlayerLoad,&PlayerRootFrame); //Destroy
					//pluginPtr.get()->OnVarible(&p);
					
					

				}
				if (plugin->PluginName == "model"){
				//	BranchTo(0x82237A20,int,plugin);
				//	int PlayerLoad = *(_DWORD *)(ObjPlayer + 0x154);
				//	int PlayerRootFrame = *(_DWORD *)(ObjPlayer + 0xCC);
				//	memset((void*)plugin,0,0x150);
				//	BranchTo(0x82237878,int,plugin,PlayerLoad,&PlayerRootFrame,0x820032C0);
				//	pluginPtr.get()->OnVarible(&p);
		
				}


			}

		}
		
		
	
	

		BranchTo(0x82195ED0,int,ObjPlayer); //I Dont know what this does but it fixing upgrades
		BranchTo(0x821962E8,int,ObjPlayer,&p); //This instead 





		ObjPlayerSetCurrentAnimTime(_context,Save0x18);




		/*
		BranchTo(0x821966E0,int,ObjPlayer);
		BranchTo(0x82196CF8,int,ObjPlayer);
		BranchTo(0x82196768,int,ObjPlayer);
		*/

	
	
		//Reload Sound

		std::vector<boost::shared_ptr<Sonicteam::Player::INotification>>* Plugins = reinterpret_cast<std::vector<boost::shared_ptr<Sonicteam::Player::INotification>>*>(ObjPlayer + 0x2DC);
		for (std::vector<boost::shared_ptr<Sonicteam::Player::INotification>>::iterator it = Plugins->begin(); it != Plugins->end(); it++) {
			boost::shared_ptr<Sonicteam::Player::INotification> pluginPtr = *it;

			if (Sonicteam::Player::IPlugIn* plugin = dynamic_cast<Sonicteam::Player::IPlugIn*>(pluginPtr.get())) {
			

				if (plugin->PluginName == "sound"){

					int a1 = (int)plugin;

					int *v6; // r27
					int v7 = 0x8200EB78;
					int v8; // r11
					int v9; // r3
					char *v10; // r28
					int v11; // r3
					int v12; // r3
					int result; // r3


					v6 = (int *)(a1 + 0x5C);

					int ModelPlayer = *(int*)(ObjPlayer + 0xD4);

					v9 = *(_DWORD *)(a1 + 0x2C);
					Sonicteam::SoX::RefCountObject* CommonSound;
					Sonicteam::SoX::RefCountObject* SpecificSound;
					BranchTo(0x82618068,int,&CommonSound,ObjPlayer + 0xD0,"common");
					BranchTo(0x82618068,int,&SpecificSound,ObjPlayer + 0xD0,"specific");

					(*(void (__fastcall **)(int, int))(*(_DWORD *)v9 + 4))(v9, (int)&CommonSound);
					(*(void (__fastcall **)(int, int))(*(_DWORD *)v9 + 4))(v9, (int)&SpecificSound);



					do
					{
						v8 = *(_DWORD *)v7;
						if ( !*(_DWORD *)v7 )
							v8 = (int)sound_name;
						v9 = *(_DWORD *)(a1 + 0x2C);
						v10 = *(char **)(v7 + 4);
						if ( v9  )
						{
							v11 = (*(int (__fastcall **)(int, int))(*(_DWORD *)v9 + 0x14))(v9, v8);
							v12 = (*(int (__fastcall **)(_DWORD, int, char *))(**(_DWORD **)(a1 + 0x2C) + 0x1C))(
								*(_DWORD *)(a1 + 0x2C),
								v11,
								v10);
						}
						else
						{
							v12 = 0;
						}
						v7 += 8;
						*v6++ = v12;
					}
					while (v7 != 0x8200ED20 );
					//Do More Later


					BranchTo(0x822668A8,int,a1 + 0x20,&ModelPlayer);



					break;
				}

			}
		}




	

	

	









		p->LoseObject();


	}







	
	
	void SonicSuperOnStart(SonicSuperStateExtended* _this){
		BranchTo(0x821A3318,int,_this);
		_this->time = 0;
		_this->time_max = 1.5f;
		_this->Trigger = false;

	}
	//Complete REDO
	void SonicSuperOnUpdate(SonicSuperStateExtended* _this,float delta){
		_this->time+=delta;
		if (_this->time > _this->time_max && _this->Trigger == false){
			_this->Trigger = true;


			Switch(_this->CObjContext,"player/sonic_super.lua","player/sonic_super","player_sonic","supersonic");
			
		}
		
		BranchTo(0x821A3328,int,_this,delta);



	}
	void SonicSuperOnStateEnd(SonicSuperStateExtended* _this){
		_this->BOContext->IsSuper = true;
		_this->BOContext->c_super_ring_dec_time = 1.0f;
	}

	
	
	
	
	
	void GlobalInstall_SonicStates()
	{
		WRITE_DWORD(0x82003B5C,SonicSuperOnStart);
		WRITE_DWORD(0x82003B60,SonicSuperOnUpdate);
		WRITE_DWORD(0x82003B64,SonicSuperOnStateEnd);
		WRITE_DWORD(0x821A32B8,POWERPC_ADDI(3,0,sizeof(SonicSuperStateExtended)));
	}
	
}