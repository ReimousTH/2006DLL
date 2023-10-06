#pragma once


#include "../../Sox/Object.h"
#include <xtl.h>

namespace SonicTeam{
	namespace Player{


		namespace Input{


			//size 0x18
			class IListener:SonicTeam::SoX::Object
			{
			public:
				IListener(void);

				//virtual char* GetObjectType() override;
				
				//virtual ~IListener(void);

				virtual void ListenerOnUpdate() = 0;
				virtual XMFLOAT4 ListenerGetVector4() = 0;
				virtual float ListenerGetPower() = 0; // Stick power
				virtual unsigned int ListenerGetResult() = 0; // Result value
				virtual int Listener5() = 0; //always 1

				byte IL0x10;
				byte IL0x11;
				byte IL0x12;
				byte IL0x13;
				unsigned int IL0x14; //-0x18

	
			};

		}
		
	}
}

