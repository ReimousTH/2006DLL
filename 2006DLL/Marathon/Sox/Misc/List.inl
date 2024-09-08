#pragma  once



namespace Sonicteam{
	namespace SoX{


		template <typename T>
		Sonicteam::SoX::LinkNodeList<T>::LinkNodeList()
		{

		}


		template <typename T>
		Sonicteam::SoX::LinkNode<T>::~LinkNode()
		{

			RemoveLink();
		}

		//should be 
		template <typename T>
		int Sonicteam::SoX::LinkNodeList<T>::Clear(int v)
		{
		
			Sonicteam::SoX::LinkNodeList<T>* NextNode = this->PThread;

			if (this->NThread != this){
				Sonicteam::SoX::LinkNodeList<T>* v10;
				T* v9;
				do
				{
					v9 = NextNode->TThread;
					v10 = NextNode->PThread;
					if ( v9 )
						v9->DestroyObject(1);
					NextNode = v10;
				}
				while ( v10 != this );

			}
			return v;
		
		}


		template <typename T>
		void Sonicteam::SoX::LinkNodeList<T>::Empty()
		{

			Sonicteam::SoX::LinkNodeList<Sonicteam::SoX::Component> *v1; // r11
			Sonicteam::SoX::LinkNodeList<Sonicteam::SoX::Component> *v2; // r10
			Sonicteam::SoX::LinkNodeList<Sonicteam::SoX::Component> *v3; // r11

			v1 = this->PThread;
			if ( v1 != this )
			{
				do
				{
					v2 = v1->PThread;
					v1->NThread = 0;
					v1->PThread = 0;
					v1 = v2;
				}
				while ( v2 != this );
			}
			if ( this->NThread )
				this->NThread->PThread = this->PThread;
			v3 = this->PThread;
			if ( v3 )
				v3->NThread = this->NThread;

		}
	};
};



//NEW ONE


