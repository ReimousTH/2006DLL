#pragma once

#include "../MessageReceiver.h"
#include <SoX/RefCountObject.h>
#include "FrameSynchronizer.h"


#include <xtl.h>
#include <Sox/Misc/List.h>

namespace Sonicteam{
	namespace SoX{
		namespace Graphics{

			
			typedef class Frame;


			class Frame:Sonicteam::SoX::RefCountObject
		{

		public:
			Frame();
			~Frame();

			virtual void DestroyObject(unsigned int flag) override;

			unsigned int FrameRefFlag; // 0x8
			Sonicteam::SoX::RefCountObject* instance; // 0xC
			
			Frame* Layer1; //0x10
			Frame* Layer2; //0x14
			Frame* Layer3; //0x18
			Frame* Layer4; //0x1c




			Sonicteam::SoX::LinkedListB<Frame,Frame> Test;
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
