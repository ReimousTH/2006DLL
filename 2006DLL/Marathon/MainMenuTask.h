#pragma once
#include <Sox/Engine/Task.h>
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/scoped_ptr.hpp>


namespace Sonicteam{


	//TODO Construuctor and complete many things :((((((
	struct MMT_MST_Resources{
		unsigned int EngineDoc;
		unsigned int msg_mainmenu; //mst
		unsigned int msg_system; //mst
		unsigned int msg_town_mission_sonic;
		unsigned int msg_town_mission_shadow;
		unsigned int msg_town_mission_silver;
		unsigned int msg_gold_results;

	};


	class MainMenuTask:Sonicteam::SoX::Engine::Task
		{
		public:

			MainMenuTask(void);

			virtual char* GetObjectType();
			virtual ~MainMenuTask(void);

			virtual void OnTaskUpdate();
			virtual int OnMessageRecieved(Sonicteam::SoX::Message*); //Input Messages

			unsigned int MMTuint0x4C;
			unsigned int MMTuint0x50;
			unsigned int MMTuint0x54;

			MMT_MST_Resources MMText; //Mst Text

			unsigned int MMTuint0x74;
			unsigned int MMTuint0x78;
			unsigned int MMTuint0x7C;
			unsigned int MMTuint0x80;
			unsigned int MMTuint0x84;
			unsigned int MMTuint0x88;
			unsigned int MMTuint0x8C;
			unsigned int MMTuint0x90;
			unsigned int MMTuint0x94;
			unsigned int MMTuint0x98;
			unsigned int MMTuint0x9C;
			unsigned int MMTuint0xA0;
			unsigned int MMTuint0xA4;
			unsigned int MMTuint0xA8;
			unsigned int MMTuint0xAC;
			unsigned int MMTuint0xB0;
			unsigned int MMTuint0xB4;
			unsigned int MMTuint0xB8;
			unsigned int MMTuint0xBC;
			unsigned int MMTuint0xC0;
			unsigned int MMTuint0xC4;
			unsigned int MMTuint0xC8;
			unsigned int MMTuint0xCC;
			unsigned int MMTuint0xD0;
			unsigned int MMTuint0xD4;
			unsigned int P2SelectedChr;
			unsigned int MMTuint0xDC;
			unsigned int MMTuint0xE0;
			unsigned int MMTuint0xE4;
			unsigned float EngineSoundVolume1;
			unsigned float EngineSoundVolume2;
			unsigned int MMTuint0xF0;
			unsigned int MMTuint0xF4;
			unsigned int MMTuint0xF8;
			unsigned int MMTuint0xFC;
			unsigned float MMTfloat0x100;
			unsigned float MMTfloat0x104;
			unsigned int MMTuint0x108;
			unsigned int MMTuint0x10C;
			unsigned int MMTuint0x110;
			unsigned int MMTuint0x114;
			unsigned int MMTuint0x118;
			unsigned int MMTuint0x11C;
			unsigned int MMTuint0x120;
			unsigned int MMTuint0x124;
			unsigned int MMTuint0x128;
			boost::shared_ptr<unsigned int> MMTuint0x12C; //PTR 


			

		


	};
};