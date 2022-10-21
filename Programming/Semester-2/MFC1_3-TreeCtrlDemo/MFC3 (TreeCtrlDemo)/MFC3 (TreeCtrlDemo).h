
// MFC3 (TreeCtrlDemo).h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CDemoApp:
// See MFC3 (TreeCtrlDemo).cpp for the implementation of this class
//

class CDemoApp : public CWinApp
{
public:
	CDemoApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CDemoApp theApp;
