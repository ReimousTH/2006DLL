#pragma once

#ifndef __MARATHON_ACTOR__
#define __MARATHON_ACTOR__

#ifndef __MARATHON_ACTORMANAGER__
#define __MARATHON_ACTORMANAGER__
#include "ActorManager.h"
#endif




#include <Sox/Memory/IDestructible.h>
#include <Sox/Engine/Task.h>
#include <boost/weak_ptr.hpp>


namespace Sonicteam{

	

	//not complete :(



	class Actor:Sonicteam::SoX::Engine::Task
		{
		public:
			~Actor();
			 Actor(Sonicteam::Actor* other, boost::weak_ptr<unsigned int>& gameimp);

			boost::weak_ptr<unsigned int> GameImp;
		
			virtual void DestroyObject(unsigned int flag);



		

	};
};

#endif