#pragma once

#include "../MessageReceiver.h"
#include "Task.h"
#include "GTask.h"
#include <xtl.h>



namespace Sonicteam{
	namespace SoX{
		namespace Engine{

			
			namespace{
			//Place 3 of them as anymoyus name space and use in class idk how
			class RootTask:Sonicteam::SoX::Engine::Task{
			public:
				virtual int OnMessageRecieved(Sonicteam::SoX::Message*);
				virtual char* GetObjectType(); //return change a later
				virtual void OnTaskUpdate();
			};
			class RootGTask:Sonicteam::SoX::Engine::GTask{
			public:
				virtual char* GetObjectType(); //return change a later

			};
			class DocModeExecutor:Sonicteam::SoX::Engine::Task{
			public:
				virtual int OnMessageRecieved(Sonicteam::SoX::Message*);
				virtual char* GetObjectType(); //return change a later 
				virtual void OnTaskUpdate();
			};
};
			


			class Doc
		{

		public:
			virtual ~Doc(void);
			virtual void EngineDocOnUpdate(float); //delta
			virtual void EngineDocDomeSome(); //CriticalNoIdea?s

			unsigned int Duint0x4;
			unsigned int Duint0x8;
			RootTask* RTask;
			RootGTask* RGTask;
			unsigned int Duint0x14; //ApplicationMarathon
			unsigned int Duint0x18;
			DocModeExecutor* DMExecutor;
			unsigned int DRenderScheduler; //Sonicteam::SoX::Engine::RenderSchedule
			CRITICAL_SECTION DocCriticalSectionFirst; //synchronization object
			CRITICAL_SECTION DocCriticalSectionSecond; //synchronization object
			
			

		};
	};
}
}
