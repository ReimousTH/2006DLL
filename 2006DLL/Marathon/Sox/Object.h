#pragma once

#include <string>
#include <list>



namespace SonicTeam{
	namespace SoX{
		typedef class Object;

		struct IObject
		{

			IObject* NextIObject;
			IObject* PreviousIObject;
			Object* CurrentObject; //why?


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
