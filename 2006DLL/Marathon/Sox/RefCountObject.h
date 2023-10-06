#pragma once

namespace SonicTeam{
	namespace SoX{
		class IResource
		{
		public:
			IResource(void);
			virtual ~IResource(void);

			virtual void Unk00() = 0; // int(r3)self,int(r4),int(r5)
			virtual void Unk01(); //return 0  (r3(buffer[64]-or some),r4 -int,r5-std::string) // Static function
 			virtual void Unk03() = 0;
			virtual void Unk04(); //return 1
			
		};
	}
}
