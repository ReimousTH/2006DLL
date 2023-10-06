#pragma once


#include "Object2.h"
#include "CommonContext.h"





namespace SonicTeam{

	namespace Player{
		namespace State{


		

		
			//8200BAD8
			class CommonObject:Object2
			{
			public:
				CommonObject(IMachine*);
				virtual ~CommonObject(void);



				virtual void Object2Start()  = 0 ;
				virtual unsigned int Object2Update() = 0;	
				virtual void Object2End() = 0;	

				virtual void Object2PreUpdateCmn(float) override;	
				virtual void Object2PostUpdateCmn(float) override;	


				//FILEDS
				CommonContext* CObjContext;



			

			};

		}

	}

}

