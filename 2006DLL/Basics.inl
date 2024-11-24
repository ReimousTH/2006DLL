



template <typename T>
void ShowXenonMessage(LPCWSTR Title,T value){

	PushXenonMessage(Title,value);
}

template <typename T>
void PushXenonMessage(LPCWSTR Title,T value)
{

	LPCWSTR g_pwstrButtonsX_INL[1] = { L"------------OK----------------" };

	std::wstringstream ss;
	ss <<std::hex << value;


	MESSAGEBOX_RESULT result;
	XOVERLAPPED m_Overlapped; 

	XShowMessageBoxUI(ATG::SignIn::GetSignedInUser(),Title,ss.str().c_str(),1,g_pwstrButtonsX_INL,1,XMB_ALERTICON,&result,&m_Overlapped);
}



template <typename T>
void PushXenonMessage(LPCWSTR Title,T value,MESSAGEBOX_RESULT* oute)
{
	LPCWSTR g_pwstrButtonsX_INL[1] = { L"------------OK----------------" };
	std::wstringstream ss;
	ss <<std::hex << value;

	XShowMessageBoxUI(ATG::SignIn::GetSignedInUser(),Title,ss.str().c_str(),1,g_pwstrButtonsX_INL,1,XMB_ALERTICON,oute,NULL);

}
