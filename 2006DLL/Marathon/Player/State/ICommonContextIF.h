#pragma once

namespace SonicTeam{
	namespace Player{
		namespace State{

			class ICommonContextIF
			{
			public:
				ICommonContextIF(void);
				virtual void ICCIF_01(float,float,float)= 0;
				virtual void ICCIF_02(float,float,float,float)= 0;
				virtual void ICCIF_03()= 0;
				virtual void ICCIF_04()= 0;
				virtual void ICCIF_05()= 0; 
				virtual float ICCIF_06()= 0; // no args
				virtual float ICCIF_07()= 0; // no args
				static const float  unk_float;





			};


		}


	}
}

