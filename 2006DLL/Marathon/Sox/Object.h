#pragma once

#include <string>
#include <list>

#include <boost/ptr_container/ptr_list.hpp>
#include <boost/ptr_container/ptr_set.hpp>
#include <deque>

#include "Sox/Misc/List.h"
#include <SoX/Memory/IDestructible.h>


namespace Sonicteam{
	namespace SoX{
		typedef class Object;
		typedef class IObject;
		



		//Inteface Object Object
		struct IOObject{	
			Sonicteam::SoX::RNodeF<Sonicteam::SoX::Object> RNodeF; //0x4,0x8,0xC
			unsigned int IOFlag;  //0x10
			//0x14...
		};


		

		
		/************************************************************************/
		/*         Inherit with IOObject or custom struct  */
		/************************************************************************/
		class Object
		{
		public:
			//size0x60
			Object(void);
			virtual char* GetObjectType(); 
			virtual void DestroyObject(unsigned int flag);
			 ~Object(void);

			 //0x14...



	
		};

		class ObjectRework{

		public:
			//size0x60
			ObjectRework(void);
			virtual char* GetObjectType(); 
			virtual ~ObjectRework(void);
	

		
		
	

		};
	}
}
