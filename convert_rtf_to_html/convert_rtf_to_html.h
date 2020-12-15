
// convert_rtf_to_html.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Cconvert_rtf_to_htmlApp:
// See convert_rtf_to_html.cpp for the implementation of this class
//

class Cconvert_rtf_to_htmlApp : public CWinApp
{
public:
	Cconvert_rtf_to_htmlApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern Cconvert_rtf_to_htmlApp theApp;