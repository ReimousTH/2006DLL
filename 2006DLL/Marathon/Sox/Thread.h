#pragma once

#include <xtl.h>
#include <string>
#include <list>

#include <boost/ptr_container/ptr_list.hpp>
#include <boost/ptr_container/ptr_set.hpp>
#include <deque>
#include "Perfomance.h"

#include "Sox/Misc/List.h"
#include <SoX/Memory/IDestructible.h>


namespace Sonicteam{
	namespace SoX{
		
		
		class Thread {
        public:
            int m_Field1; //0x4 
            int m_Field2; //0x8
			Thread* instance; //0xC
			
            HANDLE m_Event1; //0x10
            HANDLE m_Event2; //0x14
            LPDWORD m_ThreadID;        //0x18 // ThreadID
            HANDLE m_ThreadHandle;  // 0x1C   Assuming HANDLE is used for thread identifier
			int ThreadFlag1; //0x20
			float m_Field3; //Performance //0x24
			int m_Field4; //0x28
			int m_Field5; //0x2c
			const char* m_ThreadName;
			int m_Field6; //0x34
			int ThreadFlag2; //0x38
			
			

        public:
            Thread(const char* ThreadName,int Priority,int Flag);

			virtual void DestroyObject(unsigned int Flag);
			virtual void ThreadOnUpdate();
			virtual void ThreadOnStart();
			virtual void ThreadOnStep();


            virtual void start() = 0;
            virtual void stop() = 0;
		
            ~Thread();
  
		};
	};
};