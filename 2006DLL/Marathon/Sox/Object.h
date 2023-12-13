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
		
		};
		struct IObject{
	
			Object* CurrentObject;
			IObjectNode Node;
			
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
			
			Object* getNextObject() {
        if (ObjList.Node.NextIObjStp != 0) {
            // Предполагая, что obj.Next указывает на объект типа Object
            return reinterpret_cast<Object*>(ObjList.Node.NextIObjStp);
        }
        return 0;
    }


	
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
