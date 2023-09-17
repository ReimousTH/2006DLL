#pragma once
#include <string>

namespace SonicTeam{

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


