
// MFC4 (DocViewTest).h : main header file for the MFC4 (DocViewTest) application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CTestApp:
// See MFC4 (DocViewTest).cpp for the implementation of this class
//

class CTestApp : public CWinApp
{
public:
	CTestApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CTestApp theApp;
