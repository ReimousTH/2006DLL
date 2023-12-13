#pragma once
#include "CommonContext.h"
#include <boost/weak_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/scoped_ptr.hpp>
#include <xtl.h>

namespace Sonicteam{

	namespace Player{

		namespace State{

		

			//only fields for now, i finish when i comlete CommmonContext FUll  methods
			class TailsContext:public CommonContext
			{
			public:

				float TCuint0x230;
				unsigned int TCuint0x234;
				unsigned int TCuint0x238; //flags
		
				float c_flight_timer; //0x23C
				float c_flight_timer_b;
				float c_flight_acc;
				float c_ignore_spread_time;
	
				


			};

		}

	}
}

