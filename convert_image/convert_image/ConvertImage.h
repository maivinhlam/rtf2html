#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <Windows.h>
#include <gdiplus.h>
#include "string.h"
class ConvertImage {
public:
	ConvertImage(CString format, CString linkInput, CString linkOutput);
	ConvertImage(CString linkInput);
	~ConvertImage();

	CString m_Format;
	CString m_LinkInput;
	CString m_LinkOutput;
	CString m_Encode;
	int GetEncoderClsid(CLSID* pClsid);
	void SaveImage();
	CArray<CString> m_listFile;
	bool find_files();
};

