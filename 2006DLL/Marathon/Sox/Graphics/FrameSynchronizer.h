#pragma once

#include "../MessageReceiver.h"
#include <xtl.h>
#include <Sox/Memory/IDestructible.h>



namespace Sonicteam{
	namespace SoX{
		namespace Graphics{

	
			class FrameSynchronizer
		{

		public:
			FrameSynchronizer();
			FrameSynchronizer(unsigned int); //Frame Count
			~FrameSynchronizer(void);

			virtual void DestroyObject(unsigned int flag);

			unsigned int FSuint0x4; //self
			unsigned int FSuint0x8; //self
			unsigned int FSuint0xC; 
			unsigned int FSFrameBuffer01; //0x10
			unsigned int FSFrameBuffer02; //0x14
			unsigned int FSFrameCount; //0x18
			unsigned int FSuint0x1C; //

	

			};
		};
	};
};
