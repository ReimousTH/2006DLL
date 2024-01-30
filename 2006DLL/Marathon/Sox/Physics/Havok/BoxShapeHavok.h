#pragma once

#include <xtl.h>
#include <Sox/RefCountObject.h>
#include <Sox/Memory/IDestructible.h>

#include <Sox/Physics/BoxShape.h>


namespace Sonicteam{
	namespace SoX{
		namespace Physics{
			namespace Havok{
				class BoxShapeHavok:Sonicteam::SoX::Physics::BoxShape
			{
			public:
				//size0x60
				BoxShapeHavok(void);
				~BoxShapeHavok(void);

				virtual void DestroyObject(unsigned int flag) override;

			};
			};
		};
	}
}
