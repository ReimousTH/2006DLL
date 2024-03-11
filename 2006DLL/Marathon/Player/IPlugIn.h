#pragma once
#include <string>
#include <Sox/Memory/IDestructible.h>



namespace Sonicteam{

	namespace Player{

		class IPlugIn:public Sonicteam::SoX::Memory::IDestructible
		{
		public:
			IPlugIn(char*);
			~IPlugIn(void);

			virtual void DestroyObject(unsigned int flag) override;

			std::string PluginName;

		};
	};
};

