#pragma once

#include "../MessageReceiver.h"
#include <SoX/RefCountObject.h>
#include "FrameSynchronizer.h"
#include "FrameObserver.h"

#include <xtl.h>
#include <Sox/Misc/List.h>
#include <Sox/Memory/IDestructible.h>

namespace Sonicteam{
	namespace SoX{
		namespace Graphics{

			
			typedef class Frame;


			//TODO Original Destructor 
			class Frame:public Sonicteam::SoX::RefCountObject
		{

		public:
			Frame();
			~Frame();

			virtual void DestroyObject(unsigned int flag) override;


			//Virtual Methods
			virtual int FrameUnk01();
			virtual int FrameUnk02();
			
			virtual XMMATRIX FrameGetTransformMatrix1() = 0;
			virtual XMMATRIX FrameGetTransformMatrix2() = 0;
			virtual void FrameSetTransformMatrix2(XMMATRIX&) = 0;
			virtual void FrameUnk06(XMMATRIX&) = 0;
			virtual void FrameUnk07() = 0;
				
			virtual int FrameUnk08();




		

			////
			unsigned int FrameRefFlag; // 0x8
			Sonicteam::SoX::RefCountObject* instance; // 0xC
			
			Frame* Layer1; //0x10
			Frame* Layer2; //0x14
			Frame* Layer3; //0x18
			Frame* Layer4; //0x1c

			Sonicteam::SoX::LinkedNodeListB<Sonicteam::SoX::RNodeF<FrameObserver>> FUULLB0x20;
			unsigned int Fuint0x28; //not pointer, message, or flags or some like that, beacuse with each restart it changes from point to non and to value
			unsigned int Fuint0x2C; //Pointer, Can be struct because 40 16 84 E0 points tho themselfs (last pointer points to other )
			Sonicteam::SoX::Graphics::FrameSynchronizer* FrameSynchronizer; //Poitner only, not reference	

			Sonicteam::SoX::RNodeF<Frame> BNF0x34; 

		//	ListEX03_06<Sonicteam::SoX::RefCountObject> Fuint0x34;
		//	unsigned int Fuint0x34; //PointToFrame(base) + 0x34
		//	unsigned int Fuint0x38; ////PointToFrame(base) + 0x34 (different or can be same), not in constructor :|
			//Sonicteam::SoX::RefCountObject& Fuint0x3C;

			//40 16 84 EC((to this point) ) 40 16 84 EC(to previous point) 00 00 00 00 40 16 84 F8 40 16 84 F8  (only point to exactly this point,both)
			
			Sonicteam::SoX::RNodeF<Frame> BNF0x40;
		//	ListEX03_06<Sonicteam::SoX::RefCountObject> Fuint0x40;
			//unsigned int Fuint0x40; //Points To Frame Base + 0x40, but this this it seems always changing
			//unsigned int Fuint0x44; //44 same they both changing between
			//Sonicteam::SoX::RefCountObject& Fuint0x48;
	
	


			//just 
			static Frame* New();


			
			

		};
	};
}
}
