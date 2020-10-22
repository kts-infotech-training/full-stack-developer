#pragma once


// CEntryDlg dialog

class CEntryDlg : public CDialog
{
	DECLARE_DYNAMIC(CEntryDlg)

public:
	CEntryDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CEntryDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ENTRY };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CString m_strName;
	CString m_strAddress;
	afx_msg void OnBnClickedOk();
};
