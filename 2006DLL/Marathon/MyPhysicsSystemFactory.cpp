#include "MyPhysicsSystemFactory.h"


using namespace Sonicteam;




Sonicteam::MyPhysicsSystemFactory::MyPhysicsSystemFactory(void)
{

}

//not complete
Sonicteam::MyPhysicsSystemFactory::~MyPhysicsSystemFactory(void)
{
	
	
}

void Sonicteam::MyPhysicsSystemFactory::CreateSphereShapeHavok(double delta)
{

}

void Sonicteam::MyPhysicsSystemFactory::CreateBoxShapeHavok()
{

}

void Sonicteam::MyPhysicsSystemFactory::CreateCapsuleShapeHavok()
{

}

void Sonicteam::MyPhysicsSystemFactory::CreateCylinderShapeHavok()
{

}

void Sonicteam::MyPhysicsSystemFactory::CreateMeshShapeHavok()
{

}

void Sonicteam::MyPhysicsSystemFactory::CreateConvexShapeHavok()
{

}

void Sonicteam::MyPhysicsSystemFactory::CreateBodyHavokA()
{

}

void Sonicteam::MyPhysicsSystemFactory::CreateBodyHavokB()
{

}

//not complete
void Sonicteam::MyPhysicsSystemFactory::DestroyObject(unsigned int flag)
{
	
}


MyPhysicsSystemFactory* Sonicteam::MyPhysicsSystemFactory::GetInstance()
{
	
	if (!MyPhysicsSystemFactory::Instance){

		MyPhysicsSystemFactory::Instance = &CreateInstance();
	}
	return MyPhysicsSystemFactory::Instance;
	
}

MyPhysicsSystemFactory& Sonicteam::MyPhysicsSystemFactory::CreateInstance()
{
	static MyPhysicsSystemFactory instance;
	return instance;
}

MyPhysicsSystemFactory*& Sonicteam::MyPhysicsSystemFactory::GetOriginInstance()
{
	return *MyPhysicsSystemFactoryInstanceMarathon;
}

MyPhysicsSystemFactory* Sonicteam::MyPhysicsSystemFactory::Instance;


MyPhysicsSystemFactory** Sonicteam::MyPhysicsSystemFactory::MyPhysicsSystemFactoryInstanceMarathon = (MyPhysicsSystemFactory**)0x82D3C194;

