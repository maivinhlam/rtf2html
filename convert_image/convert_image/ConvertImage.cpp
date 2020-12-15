#include "stdafx.h"
#include "ConvertImage.h"


ConvertImage::ConvertImage(CString format, CString linkInput, CString linkOutput) {
	m_Format = format;
	m_LinkInput = linkInput;
	m_LinkOutput = linkOutput;
	find_files();
}

ConvertImage::ConvertImage( CString linkInput) {
	m_Format = L"image/jpeg";
	m_LinkInput = linkInput;
	m_LinkOutput = L"";
	find_files();
}

ConvertImage::~ConvertImage() {
}

int ConvertImage::GetEncoderClsid(CLSID * pClsid) {
	UINT  num = 0;          // number of image encoders
	UINT  size = 0;         // size of the image encoder array in bytes

	Gdiplus::ImageCodecInfo* pImageCodecInfo = NULL;

	Gdiplus::GetImageEncodersSize(&num, &size);
	if (size == 0)
		return -1;  // Failure

	pImageCodecInfo = (Gdiplus::ImageCodecInfo*)(malloc(size));
	if (pImageCodecInfo == NULL) return -1;  // Failure

	Gdiplus::GetImageEncoders(num, size, pImageCodecInfo);
	for (UINT j = 0; j < num; j++) {
		if (wcscmp(pImageCodecInfo[j].MimeType, m_Format) == 0) {
			*pClsid = pImageCodecInfo[j].Clsid;
			free(pImageCodecInfo);
			return j;  // Success
		}
	}

	free(pImageCodecInfo);
	return -1;  // Failure
}

void ConvertImage::SaveImage() {
	// Initialize GDI+.
	for (int i = 0; i < m_listFile.GetSize(); i++) {
		Gdiplus::GdiplusStartupInput gdiplusStartupInput;

		ULONG_PTR gdiplusToken;

		Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

		CLSID   encoderClsid;
		GetEncoderClsid(&encoderClsid);


		Gdiplus::Status  stat;

		CString strImage = m_LinkInput + L"\\" + m_listFile.GetAt(i);
		Gdiplus::Image* image = new Gdiplus::Image(strImage);

		// Get the CLSID of the PNG encoder.
		CString fileNameSave = m_LinkInput + L"\\" + m_listFile.GetAt(i) ;
		if (m_Format.Compare(L"image/jpeg") == 0) {
			fileNameSave += L".jpg";
		}
		else if (m_Format.Compare(L"image/png") == 0) {
			fileNameSave += L".png";
			
		}
		stat = image->Save(fileNameSave, &encoderClsid, NULL);

		if (stat == Gdiplus::Status::Ok) {
			//printf("image was saved successfully\n");
		}
		else {
			//printf("Failure: stat = %d\n", stat);
		}
		delete image;
		
		Gdiplus::GdiplusShutdown(gdiplusToken);
	}
	

	
}


bool ConvertImage::find_files() {
	WIN32_FIND_DATA FindFileData;
	//CString img = L"C:\\Users/MaiVinhLam/Desktop/test.rtf.html_image/*.wmf";
	CString img = m_LinkInput + L"\\*.wmf";
	HANDLE hFind = FindFirstFile(img, &FindFileData);
	if (hFind == INVALID_HANDLE_VALUE) {
		return false;
	}
	else do {
		auto str = FindFileData.cFileName;
		m_listFile.Add(str);
	} while (FindNextFile(hFind, &FindFileData));
	FindClose(hFind);
	return true;
}