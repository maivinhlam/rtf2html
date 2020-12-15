
// convert_image.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// Cconvert_imageApp:
// See convert_image.cpp for the implementation of this class
//

class Cconvert_imageApp : public CWinApp
{
public:
	Cconvert_imageApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern Cconvert_imageApp theApp;