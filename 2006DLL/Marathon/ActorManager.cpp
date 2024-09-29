#include "ActorManager.h"


using namespace Sonicteam;

Sonicteam::ActorManager::~ActorManager()
{

}

Sonicteam::ActorManager::ActorManager()
{

}

void Sonicteam::ActorManager::DestroyObject(unsigned int flag)
{
	Sonicteam::ActorManager::~ActorManager();
	Sonicteam::SoX::Memory::IUDestructible::DestroyObject(this,flag);
}

void Sonicteam::ActorManager::SearchActorByID(unsigned int& ID)
{
	int SearchIndex = 0;
	if (MaxID - ID) return;
	if ((LastActorIndex - 1) > 0){
		for (int i = 0;i<LastActorIndex && SearchIndex < ID ;i++){
			if (ActorID[i] < ID){	
				SearchIndex = SearchIndex + 1;
			}
			else{
				SearchIndex = LastActorIndex + SearchIndex;
			}
		}
	}






}
