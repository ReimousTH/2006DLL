#pragma once

namespace Sonicteam{
	namespace Player{
		class IDynamicLink
		{
		public:
			IDynamicLink(void);
			virtual ~IDynamicLink(void);
			virtual void OnLink();
		};
	}
}

