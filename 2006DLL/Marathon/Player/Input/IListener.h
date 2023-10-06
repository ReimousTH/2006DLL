#pragma once


#include "../../Sox/Object.h"
#include <xtl.h>

namespace SonicTeam{
	namespace Player{


		namespace Input{
			struct IListenerInputStruc01{
				unsigned int unk00;
				SonicTeam::SoX::Object* PtrMyInputObj;
				SonicTeam::SoX::Object* PtrKhronoControlInputListener;
				unsigned int unk0xC;
				unsigned int wLastButtons; //Triggers & DPAD includ
				unsigned int ComplementwLastButtons; //Binary One's Complement (in short = ~wLastButtons)
				unsigned int unk14;
				unsigned int unk18;
				
				// Thumb stick values converted to range [-1,+1]
				FLOAT      fX1;
				FLOAT      fY1;
				unsigned int fX1Y1Unk; // (0-2 Left,2-4 Right) fx1(y1) > 0   =  0x8001 , fx1(y1) < 0 = -0x8001 

				// Thumb stick values converted to range [-1,+1]
				FLOAT      fX2;
				FLOAT      fY2;
				unsigned int fX2Y2Unk; // (0-2 Left,2-4 Right) fx2(y2) > 0   =  0x8001 , fx2(y2) < 0 = -0x8001
				//Next is Unk and not sure 

			};


			//size 0x18
			class IListener:SonicTeam::SoX::Object
			{
			public:
				IListener(void);

				//virtual char* GetObjectType() override;
				
				//virtual ~IListener(void);

				virtual void ListenerOnUpdate(int,float) = 0;
				virtual XMFLOAT4 ListenerGetStickVector4() = 0;
				virtual float ListenerGetStickPower() = 0; // Stick power
				virtual unsigned int ListenerGetWPressedHoldReleaseButtons() = 0; // Result value
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

