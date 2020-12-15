
// convert_rtf_to_htmlDlg.cpp : implementation file
//

#include "stdafx.h"
#include "convert_rtf_to_html.h"
#include "convert_rtf_to_htmlDlg.h"
#include "afxdialogex.h"
#include "Un_RTF.h"
#include "ConvertImage.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Cconvert_rtf_to_htmlDlg dialog



Cconvert_rtf_to_htmlDlg::Cconvert_rtf_to_htmlDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CONVERT_RTF_TO_HTML_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cconvert_rtf_to_htmlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Cconvert_rtf_to_htmlDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &Cconvert_rtf_to_htmlDlg::OnClickedButton1)
END_MESSAGE_MAP()


// Cconvert_rtf_to_htmlDlg message handlers

BOOL Cconvert_rtf_to_htmlDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void Cconvert_rtf_to_htmlDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void Cconvert_rtf_to_htmlDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR Cconvert_rtf_to_htmlDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Cconvert_rtf_to_htmlDlg::OnClickedButton1() {

	const TCHAR szFilter[] = _T("RTF Files (*.rtf)|*.rtf|");

	CFileDialog dlg(TRUE, _T(""), _T(""), OFN_PATHMUSTEXIST, szFilter, this);

	if (dlg.DoModal() != IDOK) {
		return;
	}
	
	
	CT2A linkInput(dlg.GetPathName(), CP_UTF8);
	TRACE(_T("UTF8: %S\n"), linkInput.m_psz);

	//UnRTF *unrtf = new UnRTF("C:\\Users\\MaiVinhLam\\Desktop\\test.rtf");
	Un_RTF *unrtf = new Un_RTF(linkInput);
	auto link = unrtf->m_FolderOutput;
	ConvertImage *convertImage = new ConvertImage( CString(link));

	convertImage->SaveImage();
	
}
