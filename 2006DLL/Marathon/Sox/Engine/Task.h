#pragma once

#include "../MessageReceiver.h"
#include "../Component.h"

namespace Sonicteam{
	namespace SoX{
		namespace Engine{
			class Task:Sonicteam::SoX::Component,MessageReceiver
		{
		public:
			Task(void); //no idea THRERE TWO OF THEM
			virtual ~Task(void);

			virtual int OnMessageRecieved(Sonicteam::SoX::Message*);

			virtual char* GetObjectType();

			virtual void OnTaskUpdate() = 0;


			//Fields
			unsigned int Tuint0x24;
			unsigned int Tuint0x28;
			unsigned int Tuint0x2C;
			unsigned int Tuint0x30;
			unsigned int Tuint0x34;// CurrentMode (MainMode, and There Others)
			unsigned int Tuint0x38;// 
			unsigned int TaskEngineDoc; // Sonicteam::SoX::Engine::Doc ,0x3C
			Sonicteam::SoX::IObjectNode TaskList;
			unsigned int Tuint0x48;


		};
	};
}
}
