#pragma once


namespace SonicTeam{
	namespace Player{

		
		class IVarible
		{
		public:
			IVarible(void);
			static const char* varible;
			virtual void OnVarible(void) = 0;

			
		};

	}
}

