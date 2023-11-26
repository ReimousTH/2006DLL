#pragma once
#include <string>

namespace Sonicteam{

	namespace Player{

		class IPlugIn
		{
		public:
			IPlugIn(char*);
			virtual ~IPlugIn(void);
			std::string PluginName;
		};

	}

	

}


