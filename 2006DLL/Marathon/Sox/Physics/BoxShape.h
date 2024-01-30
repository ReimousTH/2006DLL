#pragma once
#include "..\RefCountObject.h"
#include <xtl.h>

namespace Sonicteam{
	namespace SoX{
		namespace Physics{
			class BoxShape:Sonicteam::SoX::RefCountObject
			{
			public:
				//size0x60
				BoxShape(double width,double height,double length);
				~BoxShape(void);

				unsigned int BSFlag;
				unsigned int SVolume; // w*h*l * FLT_MIN

				float Width;
				float Height;
				float Length;
				

				virtual void DestroyObject(unsigned int flag) override;


			};
		};
	}
}
