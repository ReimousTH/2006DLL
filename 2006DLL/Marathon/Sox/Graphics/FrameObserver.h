#pragma once


#include <xtl.h>
#include <Sox/Memory/IDestructible.h>
#include <Sox/Misc/List.h>


namespace Sonicteam{
	namespace SoX{
		namespace Graphics{

	
			class FrameObserver
		{

		public:
			FrameObserver();
			~FrameObserver(void);

			virtual void ObserveFrameStep(double a1) = 0;
			virtual void DestroyObject(unsigned int flag);


			Sonicteam::SoX::RNodeF<FrameObserver> RNodeH;
			unsigned int UFOFlag0x10;
			

			void OnRNodeHClear();

			

	

			};
		};
	};
};
