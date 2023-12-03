#pragma once

#include "Object.h"

namespace Sonicteam{
	namespace SoX{
	
	
		struct IComponentNode:IObjectNode{
			Object* CurrentObject;
		};

		struct IComponent{
			Object* CurrentObject;
			IComponentNode Node;
		};


		class Component:public Object
		{
		public:
			Component(Component*);
			virtual ~Component(void);

			//std::list<Component*> CompList;


			IComponent CompList;

			static int FreeComponents(Sonicteam::SoX::IComponentNode *, Sonicteam::SoX::IComponentNode *, int);
			static void FreeComponentsOffsets(Sonicteam::SoX::IComponentNode *);

		
			


			
		};
	}
}
