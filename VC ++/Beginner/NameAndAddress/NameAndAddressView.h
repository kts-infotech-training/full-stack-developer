
// NameAndAddressView.h : interface of the CNameAndAddressView class
//

#pragma once


class CNameAndAddressView : public CView
{
	

protected: // create from serialization only
	CNameAndAddressView() noexcept;
	DECLARE_DYNCREATE(CNameAndAddressView)

// Attributes
public:
	CNameAndAddressDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CNameAndAddressView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnSetupName();
};

#ifndef _DEBUG  // debug version in NameAndAddressView.cpp
inline CNameAndAddressDoc* CNameAndAddressView::GetDocument() const
   { return reinterpret_cast<CNameAndAddressDoc*>(m_pDocument); }
#endif

