#pragma once
#include "CompleteGauge_SonicStates.h"
#include <Player/State/CommonObject.h>
#include <Player/State/SonicContext.h>
#include <LuaSystem.h>
#include <Player/INotification.h>


namespace CompleteGauge{
	



	void Switch(Sonicteam::Player::State::CommonContext* _context,const char* lua_name,const char* package_name,const char* sound_name){

		Sonicteam::Player::Score* score =  _context->ScorePlugin.get();
		int ObjPlayer = score->PtrObjectPlayer;
		
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


		//Reload others(model include)

		std::vector<boost::shared_ptr<Sonicteam::Player::IDynamicLink>>* PluginsXX = reinterpret_cast<std::vector<boost::shared_ptr<Sonicteam::Player::IDynamicLink>>*>(ObjPlayer + 0x21C);
		for (std::vector<boost::shared_ptr<Sonicteam::Player::IDynamicLink>>::iterator it = PluginsXX->begin(); it != PluginsXX->end(); it++) {

			boost::shared_ptr<Sonicteam::Player::IDynamicLink> pluginPtr = *it;

			if (Sonicteam::Player::IVariable* plugin = dynamic_cast<Sonicteam::Player::IVariable*>(pluginPtr.get())) {
				plugin->OnVarible(&p);
			}

		}


		//Reload Items

		std::vector<boost::shared_ptr<Sonicteam::Player::IDynamicLink>>* PluginsX = reinterpret_cast<std::vector<boost::shared_ptr<Sonicteam::Player::IDynamicLink>>*>(ObjPlayer + 0x22C);
		for (std::vector<boost::shared_ptr<Sonicteam::Player::IDynamicLink>>::iterator it = PluginsX->begin(); it != PluginsX->end(); it++) {

			boost::shared_ptr<Sonicteam::Player::IDynamicLink> pluginPtr = *it;

			if (Sonicteam::Player::IVariable* plugin = dynamic_cast<Sonicteam::Player::IVariable*>(pluginPtr.get())) {

				plugin->OnVarible(&p);

			}

		}


		int ModelPlayer = *(int*)(ObjPlayer + 0xD4);
	


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







	void SonicSuperOnStateEnd(Sonicteam::Player::State::BasedObject<SonicContextExtended>* _this){

	
		Switch(_this->CObjContext,"player/sonic_super.lua","player/sonic_super","player_sonic");
		_this->BOContext->IsSuper = true;
		_this->BOContext->c_super_ring_dec_time = true;


	}

	void GlobalInstall_SonicStates()
	{
		WRITE_DWORD(0x82003B64,SonicSuperOnStateEnd);
	}
	
}