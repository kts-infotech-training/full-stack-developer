
// NameAndAddressView.cpp : implementation of the CNameAndAddressView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "NameAndAddress.h"
#endif

#include "NameAndAddressDoc.h"
#include "NameAndAddressView.h"
#include "CEntryDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CNameAndAddressView

IMPLEMENT_DYNCREATE(CNameAndAddressView, CView)

BEGIN_MESSAGE_MAP(CNameAndAddressView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_SETUP_NAME, &CNameAndAddressView::OnSetupName)
END_MESSAGE_MAP()

// CNameAndAddressView construction/destruction

CNameAndAddressView::CNameAndAddressView() noexcept
{
	// TODO: add construction code here

}

CNameAndAddressView::~CNameAndAddressView()
{
}

BOOL CNameAndAddressView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CNameAndAddressView drawing

void CNameAndAddressView::OnDraw(CDC* pDC)
{
	CNameAndAddressDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC->TextOut(100, 100, pDoc->m_strName);
	pDC->TextOut(300, 100, pDoc->m_strAddress);

	//pDC->MoveTo(200, 400);
	//pDC->LineTo(300, 400);


	// TODO: add draw code for native data here
}


// CNameAndAddressView printing

BOOL CNameAndAddressView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CNameAndAddressView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CNameAndAddressView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CNameAndAddressView diagnostics

#ifdef _DEBUG
void CNameAndAddressView::AssertValid() const
{
	CView::AssertValid();
}

void CNameAndAddressView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CNameAndAddressDoc* CNameAndAddressView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CNameAndAddressDoc)));
	return (CNameAndAddressDoc*)m_pDocument;
}
#endif //_DEBUG


// CNameAndAddressView message handlers



void CNameAndAddressView::OnSetupName()
{
	// TODO: Add your command handler code here
	//AfxMessageBox(_T("Name and Address"));
	CEntryDlg Dlg;
	if (Dlg.DoModal() == IDOK)
	{
		//Get the Values form the Dialog
		CNameAndAddressDoc* pDoc = GetDocument();
		pDoc->m_strName = Dlg.m_strName;
		pDoc->m_strAddress = Dlg.m_strAddress;
		Invalidate();
	}
}
