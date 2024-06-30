#pragma once
#include <Sox/Graphics/Frame.h>
#include <Sox/Memory/IDestructible.h>
#include <Player/IPlugIn.h>
#include <Player/IExportExternalFlag.h>
#include <Sox/Engine/Doc.h>
#include <Sox/Memory/DEFINITIONS.hpp>

#include <map>
#include <Player/ILoad.h>


namespace Sonicteam{
	namespace Player{


		//UNK 
		struct PLoadBodyPackage{
			PLoadBodyPackage();
			~PLoadBodyPackage();


			char buffer[0x30];

		};

		struct PLoadHeadPackage{
			PLoadHeadPackage();
			~PLoadHeadPackage();
	

			char buffer[0x34];

		};


		
		class Load:ILoad
		{
		public:
			Load(Sonicteam::SoX::Engine::Doc* doc);
			~Load(void);

			virtual void DestroyObject(unsigned int flag) override;
			//YES IT IS  std::_Tree<std::_Tmap_traits< match 

			std::map<int,PLoadBodyPackage*> PackageBody;
			std::map<int,PLoadHeadPackage*> PackageHead;
			unsigned int unk0x38;
			unsigned int unk0x40;
			unsigned int unk0x44;
			unsigned int unk0x48;
			Sonicteam::SoX::Engine::Doc* EDoc;
		

			_MARATHON_DEFINE_CONSTRUCTOR_(Load,0x821E2C18,Sonicteam::SoX::Engine::Doc* doc);


		

		};

	}
}

