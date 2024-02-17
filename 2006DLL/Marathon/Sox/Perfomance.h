#pragma once

#include <xtl.h>
#include <string>
#include <list>

#include <boost/ptr_container/ptr_list.hpp>
#include <boost/ptr_container/ptr_set.hpp>
#include <deque>

#include "Sox/Misc/List.h"
#include <SoX/Memory/IDestructible.h>


namespace Sonicteam {
	namespace SoX {
		class PerformanceFrequency {
		private:
		
			PerformanceFrequency();

		public:


			LARGE_INTEGER PerformanceFrequencyOutput;


			static PerformanceFrequency& getInstance() {
				static PerformanceFrequency instance;
				return instance;
			}

			 LARGE_INTEGER GetPerformanceFrequency();
			 unsigned __int64 GetTimeBase();
		};
	};
};