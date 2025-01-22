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

Sonicteam::SoX::Engine::Task* Sonicteam::ActorManager::SearchActorByID(unsigned int& ID)
{
	int SearchIndex = 0;
	if (ID > MaxID) return 0;

	// Binary search for the index of ID in ActorIDs
	int low = 0;
	int high = this->LastActorIndex - 1;
	int Index = 0;
	while (low <= high) {
		int mid = (low + high) / 2;

		if (this->ActorID[mid] < ID) {
			low = mid + 1; // Move to the upper half
		} else if (this->ActorID[mid] > ID) {
			high = mid - 1; // Move to the lower half
		} else {
			Index = mid; // Found the index of ID
		}
	}

	if (!this->Actor[Index]) return 0;
	return this->Actor[Index];

}
