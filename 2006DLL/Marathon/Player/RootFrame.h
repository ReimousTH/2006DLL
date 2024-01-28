#pragma once
#include <Sox/Graphics/Frame.h>
#include <Sox/Memory/IDestructible.h>
#include <Player/IPlugIn.h>
#include <Player/IExportExternalFlag.h>


namespace Sonicteam{
	namespace Player{

		
		class RootFrame:Sonicteam::SoX::Graphics::Frame,Sonicteam::Player::IPlugIn,Sonicteam::Player::IExportExternalFlag
		{
		public:
			RootFrame(void);
			~RootFrame(void);

			virtual void DestroyObject(unsigned int flag) override;

			virtual XMFLOAT4* FrameUnk03(XMFLOAT4);

			virtual XMFLOAT4* FrameUnk04(XMFLOAT4);

			virtual XMFLOAT4* FrameUnk05(XMFLOAT4);

			virtual XMFLOAT4* FrameUnk06(float* Matrix);

			virtual XMFLOAT4* FrameUnk07();

			virtual DWORD ExportExternalFlag(void);


			////Fields

			XMFLOAT4 RFRotation0x70; //Rotation 0x70
			XMFLOAT4 RFSurfaceRotation0x80; //Surface Rotation (Normal Rotation or some like that) 0x80 
			XMFLOAT4 RFRotationInverted0x90; //Rotation( BackWards = RFRotation, but on last element need to inverted)
			
			XMFLOAT4 RFPosition0xA0; //Position 0xA0
			XMFLOAT4 RFRotation0xB0; //Rotation 0xB0

			XMFLOAT4 RFScale0xC0; //Not Sure IDEK 0xC0
			XMFLOAT4 RFRotation0xD0; // why?s 0xD0


			XMFLOAT4 RFPosition0xE0; //Position 0xE0
			XMFLOAT4 RFPosition0xF0; //Position 0xF0
			XMFLOAT4 RFPosition0x100; //Position 0xF0


			XMFLOAT4 RFForce0x110; //Force (Not Translated, Not Rotated)
			unsigned int RFUINTunkFlag0x120; // 01 00 00 00 = default
			unsigned int RFUINTunkFlag0x124; // 
			unsigned int RFUINTunkFlag0x128; // 
			unsigned int RFUINTunkFlag0x12C; // 

			float RFRotation0x130[4]; //Rotation (Why? Not Translated)
			XMFLOAT4 RFRotation0x140; //Rotaion
			unsigned long long ExternalFlag; //0x150
			

			//8 Bytes of others should be padded i guess


			////


		
			



		};

	}
}

