#pragma once
#include <DocMarathonImp.h>
#include <sox/Memory/IDestructible.h>
#include <Sox/Engine/Task.h>
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/scoped_ptr.hpp>


namespace Sonicteam{


	 
	//Or SonicTeamSoxComponent
	class MyPhysicsSystemFactory
		{
		public:
			MyPhysicsSystemFactory(void);
			~MyPhysicsSystemFactory(void);

			
			unsigned int Flag; // IsDestructible




			virtual void CreateSphereShapeHavok(double delta); //0x0 + 0x0 (void = type (r3))
			virtual void CreateBoxShapeHavok(); // 0x0 + 0x4
			virtual void CreateCapsuleShapeHavok(); // 0x0 + 0x8
			virtual void CreateCylinderShapeHavok(); // 0x0 + 0xC
			virtual void CreateMeshShapeHavok(); // 0x0 + 0xC
			virtual void CreateConvexShapeHavok(); // 0x0 + 0xC

			virtual void CreateBodyHavokA(); // 0x0 + 0xC
			virtual void CreateBodyHavokB(); // 0x0 + 0xC
			
			//??????s
			void DestroyObject(unsigned int flag); //0x0 + 0x10



			static MyPhysicsSystemFactory* GetInstance();
			static MyPhysicsSystemFactory& CreateInstance();
			static MyPhysicsSystemFactory*& GetOriginInstance();



			static MyPhysicsSystemFactory* Instance;
			static MyPhysicsSystemFactory** MyPhysicsSystemFactoryInstanceMarathon;
	};
};