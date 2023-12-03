#pragma once

#include <string>
#include <list>

#include <boost/ptr_container/ptr_list.hpp>
#include <boost/ptr_container/ptr_set.hpp>
#include <deque>


namespace Sonicteam{
	namespace SoX{
		typedef class Object;
		typedef class ObjectRework;
		typedef class Component;
		typedef class IObjectStep;
		


		struct IObjectNode{
			IObjectNode* NextIObjStp;
			IObjectNode* PreviousIObjStp;
			virtual ~IObjectNode(){
			}
		};
		struct IObject{
	
			Object* CurrentObject;
			IObjectNode Node;
			virtual ~IObject(){

			}
		};



		//this is the best that i can think
		class Object
		{
		public:
			//size0x60
			Object(void);
			virtual char* GetObjectType(); 
			virtual ~Object(void);
			//std::list<Object*> ObjList;
		    IObject ObjList;

	
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
