#pragma once

#include "Project.h"
#include "RCObject.h"
#include <Sox/Memory/IDestructible.h>




namespace Chao{
	namespace CSD{


	 
	//No INFO so empty
	template <typename T>
	class CResourceBase	
		{
		public:
			CResourceBase(void);
			~CResourceBase(void);

			virtual void DestroyObject(unsigned int flag);	
			virtual void CResourceBase0x4(void*) = 0;

			//https://github.com/blueskythlikesclouds/BlueBlur/blob/master/CSD/Manager/csdmResourceBase.h
		protected:
			//i guess IT <T> at least should be
			Chao::CSD::RCObject<T> FCRBDATA; //  Chao::CSD::RCObject<unsigned char>
			size_t m_DataSize; // 
			unsigned int FCRB0xC;	// no idea
	};

	template <typename T>
	Chao::CSD::CResourceBase<T>::~CResourceBase(void)
	{

	}

	template <typename T>
	Chao::CSD::CResourceBase<T>::CResourceBase(void)
	{

	}

	template <typename T>
	void Chao::CSD::CResourceBase<T>::DestroyObject(unsigned int flag)
	{
		Sonicteam::SoX::Memory::IUDestructible::DestroyObject(this,flag);
	}

	};
};