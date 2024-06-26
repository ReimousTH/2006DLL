#pragma once

#include <xtl.h>
#include <Sox/Memory/IDestructible.h>

#include <string>
#include "Project.h"
#include "RCObject.h"
#include "CResourceBase.h"





namespace Chao{
	namespace CSD{

		//BRUH 
		//I GUESS LinkedNodeList :(
		//maybe some kind of List , Scene poiners to ,1,2,3 if nothing then all == or no idea but pointers 
		struct SceneInfo{
			unsigned int SceneInfoFlag;
			unsigned int Scenes;

		};
		
	//No INFO so empty
		class CProject:Chao::CSD::CResourceBase<Chao::CSD::Project>
		{
		public:
			CProject(void);
			~CProject(void);

			virtual void CResourceBase0x4(void*);

			//Scenes
		protected:
			SceneInfo CPSceneInfo;


			unsigned int FCProject0x20;
			unsigned int FCProject0x24;
			unsigned int FCProject0x28;
			// RCPtr<TexList>, later
			RCObject<unsigned char> CPTexList;
			//
			unsigned int FCProject0x30;
			unsigned int FCProject0x34;
			unsigned int FCProject0x38;
			unsigned int FCProject0x3C;
			unsigned int FCProject0x40;
			unsigned int FCProject0x44;
		

	};
};
};