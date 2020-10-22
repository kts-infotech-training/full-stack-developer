
// NameAndAddress.h : main header file for the NameAndAddress application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CNameAndAddressApp:
// See NameAndAddress.cpp for the implementation of this class
//

class CNameAndAddressApp : public CWinApp
{
public:
	CNameAndAddressApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CNameAndAddressApp theApp;
