#pragma once

#include "Object.h"
#include "Sox/Misc/List.h"

namespace Sonicteam{
	namespace SoX{
	
	
	
		typedef class Component;

		struct IOComponent{
			Component* UComponent; //0x4
			Sonicteam::SoX::RNodeF<Component> RNodeF; //0x8,0xC,0x10
			//0x14...
		};


		class Component:public Object,public IOComponent
		{
		public:
			Component(Component*);
			~Component(void);

			//std::list<Component*> CompList;

			Sonicteam::SoX::LinkedNodeListB<Sonicteam::SoX::RNodeF<Component>,Sonicteam::SoX::RNodeF<Component>> UCLNLB0x14; //0x14,0x18,0x1C
			//0x20...




			virtual void DestroyObject(unsigned int flag) override;

		
			


			
		};
	}
}
