
// CalculatorAppDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "CalculatorApp.h"
#include "CalculatorAppDlg.h"
#include "afxdialogex.h"

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


// CCalculatorAppDlg dialog



CCalculatorAppDlg::CCalculatorAppDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATORAPP_DIALOG, pParent)
	, m_iInput1(0)
	, m_iInput2(0)
	, m_iOutput(0)
	, m_strSymbol(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_OPERATION, m_ctrlOperations);
	DDX_Text(pDX, IDC_EDIT_INPUT1, m_iInput1);
	DDX_Text(pDX, IDC_EDIT_INPUT2, m_iInput2);
	DDX_Text(pDX, IDC_EDIT_OUTPUT, m_iOutput);
	DDX_Text(pDX, IDC_STATIC_SYMBOL, m_strSymbol);
}

BEGIN_MESSAGE_MAP(CCalculatorAppDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_CALCULATE, &CCalculatorAppDlg::OnBnClickedButtonCalculate)
	ON_CBN_SELCHANGE(IDC_COMBO_OPERATION, &CCalculatorAppDlg::OnCbnSelchangeComboOperation)
	ON_BN_CLICKED(IDOK, &CCalculatorAppDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CCalculatorAppDlg message handlers

BOOL CCalculatorAppDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

void CCalculatorAppDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCalculatorAppDlg::OnPaint()
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
HCURSOR CCalculatorAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalculatorAppDlg::OnBnClickedButtonCalculate()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	int iSel = m_ctrlOperations.GetCurSel();
	if (iSel == 0)
	{
		m_iOutput = m_iInput1 + m_iInput2;

	}
	else if (iSel == 1)
	{
		m_iOutput = m_iInput1 - m_iInput2;
	}
	else if (iSel == 2)
	{
		m_iOutput = m_iInput1 * m_iInput2;
	}
	UpdateData(FALSE);

}


void CCalculatorAppDlg::OnCbnSelchangeComboOperation()
{
	// TODO: Add your control notification handler code here
	int iSel = m_ctrlOperations.GetCurSel();
	if (iSel == 0)
	{
		m_strSymbol = "+";

	}
	else if (iSel == 1)
	{
		m_strSymbol = "-";
	}
	else if (iSel == 2)
	{
		m_strSymbol = "X";
	}
	UpdateData(FALSE);

}


void CCalculatorAppDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}
