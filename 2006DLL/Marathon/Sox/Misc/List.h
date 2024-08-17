#pragma  once



namespace Sonicteam{
	namespace SoX{


		//UPDATED



		template <typename T>
		struct LinkNodeBase {
			T* PThread;
			T* NThread;

		public:
			LinkNodeBase() : PThread(NULL), NThread(NULL) {}

			void RemoveLink(){
				PThread->NThread = NThread;
				NThread->PThread = PThread;
				NThread = NULL;
				PThread = NULL;

			}

			~LinkNodeBase() {
				if (PThread)
					PThread->NThread = NThread;
				if (NThread)
					NThread->PThread = PThread;

			}
		};



	
		template <typename T>
		struct LinkNode:LinkNodeBase<LinkNode<T>> {
		public:
			T* TThread;
			LinkNode() : LinkNodeBase<LinkNode<T>>() {}
			LinkNode(T* TThread) : LinkNodeBase<LinkNode<T>>(), TThread(TThread) {}

		};

	













		template <typename T = int>
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








		//template <typename Z = RNodeF<T>>
		template <typename Z>
		static void RNodeFClear(Z* PREV,Z* NEXT,unsigned int Flag){

			Z* temp = NEXT;
			Z* temp2 = 0;
			if (PREV != NEXT){
				do 
				{
					temp2 = (Z*)(temp->Next);
					temp->FObject->DestroyObject(Flag);
					temp = temp2;
				} while (temp2 != NEXT);
			}
		};

		template <typename Z = RNodeF<T,Y>,typename Y = RNodeH<int>>
		class LinkedNodeListB:Y{
		public:

			LinkedNodeListB(){this->Next = this; this->Previous = this;}
			~LinkedNodeListB()
			{
				Z* temp = (Z*)Next;
				Z* temp2 = 0;
				if ((Z*)this !=(Z*) Next){
					do 
					{
						temp2 = (Z*)(temp->Next);
						temp->Previous = 0;		
						temp->Next = 0;
						temp = temp2;


					} while ((Z*)temp2 != (Z*)this);
				}


			}
		

			//T Have Should have non virtual method OnRNodeHClear, whi

			inline void Clear(){
				Z* temp = (Z*)Next;
				Z* temp2 = 0;
				if ((Z*)this != (Z*)Next){ //Just Do twice for fun later
					do 
					{
						temp2 = (Z*)(temp->Next);		
						temp2->FObject->OnRNodeHClear();
						temp = temp2;
	
					} while ((Z*)temp2 != (Z*)this);
				}

			}

			//used in Component destructor :


		};




	
	};
};




//NEW ONE


