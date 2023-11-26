#pragma once

#include <string>
#include <list>



namespace Sonicteam{
	namespace SoX{
		typedef class Object;

		struct IObject
		{

			IObject* NextIObject;
			IObject* PreviousIObject; //0x4->0x8
			Object* CurrentObject; //why? 0x8->0xC		


		};


		class Object:public IObject
		{
		public:
			//size0x60
			Object(void);
			virtual char* GetObjectType(); 
			virtual ~Object(void);
			//Object* CurrentObject; //why?

		};
	}
}
