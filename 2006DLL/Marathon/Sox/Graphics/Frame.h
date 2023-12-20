#pragma once

#include "../MessageReceiver.h"
#include <SoX/RefCountObject.h>
#include "FrameSynchronizer.h"

#include <xtl.h>
//#include <Sox/Misc/List.h>

namespace Sonicteam{
	namespace SoX{
		namespace Graphics{

			

			class Frame:Sonicteam::SoX::RefCountObject
		{

		public:
			Frame();
			~Frame();

			virtual void ObjectDestroy(unsigned int flag);

			unsigned int Fuint0x8; //Flag??
			//Sonicteam::SoX::RefCountObject& Fuint0xC;

			unsigned int FUNodeA_1;
			//Sonicteam::SoX::FrameNode<Frame> FUNodeA_1;
			//Sonicteam::SoX::FrameNode<Frame> FUNodeA_2;
			//should be FrameObserver
		//	Sonicteam::SoX::LinkedListB<unsigned int,Frame> LLB;
//				ListEX01_06 Fuint0x10; // + 0x1C
			//	unsigned int Fuint0x10; // 0
			//	unsigned int Fuint0x14; // 0
			
			
		//	ListEX01_06 Fuint0x18;
		//	unsigned int Fuint0x18; //RootFramePlayer, which have some at position 0x18
		//	unsigned int Fuint0x1C; //FrameGP and again 0x18-0x1C

		//	ListEX01_06 Fuint0x20; //they point to themselfs somehow
		//	unsigned int Fuint0x20;
		//	unsigned int Fuint0x24;


		//	unsigned int Fuint0x28; //not pointer, message, or flags or some like that, beacuse with each restart it changes from point to non and to value

			//40 16 84 E0(to this point) 40 16 84 E0(to previous point) 00 00 00 00 40 16 84 EC(only point to exactly this point)

		//	unsigned int Fuint0x2C; //Pointer, Can be struct because 40 16 84 E0 points tho themselfs (last pointer points to other )
		//	Sonicteam::SoX::Graphics::FrameSynchronizer* FrameSynchronizer; //Poitner only, not reference	
			
		//	ListEX03_06<Sonicteam::SoX::RefCountObject> Fuint0x34;
		//	unsigned int Fuint0x34; //PointToFrame(base) + 0x34
		//	unsigned int Fuint0x38; ////PointToFrame(base) + 0x34 (different or can be same), not in constructor :|
			//Sonicteam::SoX::RefCountObject& Fuint0x3C;

			//40 16 84 EC((to this point) ) 40 16 84 EC(to previous point) 00 00 00 00 40 16 84 F8 40 16 84 F8  (only point to exactly this point,both)
			
		//	ListEX03_06<Sonicteam::SoX::RefCountObject> Fuint0x40;
			//unsigned int Fuint0x40; //Points To Frame Base + 0x40, but this this it seems always changing
			//unsigned int Fuint0x44; //44 same they both changing between
			//Sonicteam::SoX::RefCountObject& Fuint0x48;
	
	

			


			
			

		};
	};
}
}
