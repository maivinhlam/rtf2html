
// convert_rtf_to_htmlDlg.h : header file
//

#pragma once


// Cconvert_rtf_to_htmlDlg dialog
class Cconvert_rtf_to_htmlDlg : public CDialogEx
{
// Construction
public:
	Cconvert_rtf_to_htmlDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONVERT_RTF_TO_HTML_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedButton1();
};
