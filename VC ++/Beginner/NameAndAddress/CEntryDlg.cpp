// CEntryDlg.cpp : implementation file
//

#include "pch.h"
#include "NameAndAddress.h"
#include "CEntryDlg.h"
#include "afxdialogex.h"


// CEntryDlg dialog

IMPLEMENT_DYNAMIC(CEntryDlg, CDialog)

CEntryDlg::CEntryDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG_ENTRY, pParent)
	, m_strName(_T(""))
	, m_strAddress(_T(""))
{

}

CEntryDlg::~CEntryDlg()
{
}

void CEntryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_ADDRESS, m_strAddress);
}


BEGIN_MESSAGE_MAP(CEntryDlg, CDialog)
	ON_BN_CLICKED(IDOK, &CEntryDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CEntryDlg message handlers


void CEntryDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CDialog::OnOK();
}
