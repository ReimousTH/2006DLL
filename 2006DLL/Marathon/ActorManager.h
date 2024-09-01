#pragma once
#include <vector>
#include <xmath.h>

#include <Sox/Memory/IDestructible.h>
#include <Sox/Engine/Task.h>

namespace Sonicteam{

	

	//not complete :(

	class ActorManager
		{
		public:
			~ActorManager();
			ActorManager();

			unsigned int ActorID[0xFFFF];
			Sonicteam::SoX::Engine::Task* Actor[0xFFFF]; //Actor class
			unsigned int LastActorID; // guess, correct 
			unsigned int LastActorIndex; // Count-1, 39 is actually, but 38 here	

		
			virtual void DestroyObject(unsigned int flag);

		

	};
};