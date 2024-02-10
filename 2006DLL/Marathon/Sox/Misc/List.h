#pragma  once


namespace Sonicteam{
	namespace SoX{


		template <typename T>
		class RNodeH {
		public:
			RNodeH* Previous;
			RNodeH* Next;

			inline ~RNodeH(){
				if (this->Previous){
					this->Previous->Next = this->Next;
				}
				if (this->Next){
					this->Next->Previous = this->Previous;
				}
			}
			inline void Reset(){this->Previous->Next = this->Next;this->Next->Previous = this->Previous;this->Next =0;this->Previous = 0;}

			// Constructor
			RNodeH() : Previous(0), Next(0) {}


		};

		template <typename T>
		class RNodeF : public RNodeH<T> {
		public:
			// Constructor
			RNodeF() : RNodeH<T>(), FObject(0) {}

			RNodeF(T* FO) : RNodeH<T>(), FObject(FO) {}

			inline ~RNodeF(){FObject = 0;}
			T* FObject;
		};	

		template <typename T,typename Y>
		class RNodeFH : public RNodeH<T> {
		public:
			// Constructor
			RNodeFH() : RNodeF<T>(), HObject(0) {}
			Y* HObject;
		};	



		template <typename T,typename Y = T,typename Z = RNodeF<T>>
		class LinkedNodeListB:Z{
		public:

			LinkedNodeListB(){this->Next = this; this->Previous = this;}
			~LinkedNodeListB()
			{
				Z* temp = (Z*)Next;
				Z* temp2 = 0;
				if (this != Next){
					do 
					{
						temp2 = (Z*)(temp->Next);
						temp->Previous = 0;		
						temp->Next = 0;
						temp = temp2;


					} while (temp2 != this);
				}


			}


			//T Have Should have non virtual method OnRNodeHClear, whi

			inline void Clear(){
				Z* temp = (Z*)Next;
				Z* temp2 = 0;
				if (this != Next){ //Just Do twice for fun later
					do 
					{
						temp2 = (Z*)(temp->Next);		
						temp2->FObject->OnRNodeHClear();
						temp = temp2;
	
					} while (temp2 != this);
				}

			}

		};




	
	};
};




//NEW ONE


