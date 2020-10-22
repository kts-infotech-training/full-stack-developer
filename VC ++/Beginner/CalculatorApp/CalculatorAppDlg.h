
// CalculatorAppDlg.h : header file
//

#pragma once


// CCalculatorAppDlg dialog
class CCalculatorAppDlg : public CDialogEx
{
// Construction
public:
	CCalculatorAppDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATORAPP_DIALOG };
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
	CComboBox m_ctrlOperations;
	int m_iInput1;
	int m_iInput2;
	afx_msg void OnBnClickedButtonCalculate();
	int m_iOutput;
	afx_msg void OnCbnSelchangeComboOperation();
	CString m_strSymbol;
	afx_msg void OnBnClickedOk();
};
