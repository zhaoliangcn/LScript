// 这段 MFC 示例源代码演示如何使用 MFC Microsoft Office Fluent 用户界面
// (“Fluent UI”)。该示例仅供参考，
// 用以补充《Microsoft 基础类参考》和
// MFC C++ 库软件随附的相关电子文档。
// 复制、使用或分发 Fluent UI 的许可条款是单独提供的。
// 若要了解有关 Fluent UI 许可计划的详细信息，请访问
// https://go.microsoft.com/fwlink/?LinkId=238214.
//
// 版权所有(C) Microsoft Corporation
// 保留所有权利。

// ScriptIDEView.cpp: CScriptIDEView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "ScriptIDE.h"
#endif

#include "ScriptIDEDoc.h"
#include "ScriptIDEView.h"
#include "ChildFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CScriptIDEView

IMPLEMENT_DYNCREATE(CScriptIDEView, CView)

BEGIN_MESSAGE_MAP(CScriptIDEView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScriptIDEView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CScriptIDEView 构造/析构

CScriptIDEView::CScriptIDEView() 
{
	// TODO: 在此处添加构造代码

}

CScriptIDEView::~CScriptIDEView()
{
}

BOOL CScriptIDEView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CScriptIDEView 绘图

void CScriptIDEView::OnDraw(CDC* /*pDC*/)
{
	CScriptIDEDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	// TODO: 在此处为本机数据添加绘制代码
}


// CScriptIDEView 打印


void CScriptIDEView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CScriptIDEView::OnPreparePrinting(CPrintInfo* pInfo)
{
	//Validate our parameters
	ASSERT(pInfo != nullptr);
	ASSERT(pInfo->m_pPD != nullptr);

	//Determine if we should allow selection printing
	CChildFrame * child = (CChildFrame *)GetParentFrame();
	const int nStartChar = child->GetSelectionStart();
	const int nEndChar = child->GetSelectionEnd();
	if (nStartChar != nEndChar)
	{
		//Enable the Selection button
#pragma warning(suppress: 26489)
		pInfo->m_pPD->m_pd.Flags &= ~PD_NOSELECTION;

		//Check the Selection button
#pragma warning(suppress: 26489)
		pInfo->m_pPD->m_pd.Flags |= PD_SELECTION;
	}

	//Let the base class do its thing
	return DoPreparePrinting(pInfo);
}

void CScriptIDEView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	//Validate our parameters
	ASSERT_VALID(this);
	ASSERT(pInfo != nullptr);
	ASSERT(pInfo->m_pPD != nullptr);

	CChildFrame * child = (CChildFrame *)GetParentFrame();

	//initialize page start vector
	ASSERT(m_PageStart.size() == 0);
#pragma warning(suppress: 26486)
	if (pInfo->m_pPD->PrintSelection())
		m_PageStart.push_back(child->GetSelectionStart());
	else
		m_PageStart.push_back(0);
	ASSERT(m_PageStart.size() > 0);

	ASSERT_VALID(this);
}

void CScriptIDEView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	//Validate our parameters
	ASSERT_VALID(this);

	m_PageStart.clear();
}

void CScriptIDEView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CScriptIDEView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CScriptIDEView 诊断

#ifdef _DEBUG
void CScriptIDEView::AssertValid() const
{
	CView::AssertValid();
}

void CScriptIDEView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CScriptIDEDoc* CScriptIDEView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CScriptIDEDoc)));
	return (CScriptIDEDoc*)m_pDocument;
}
#endif //_DEBUG


// CScriptIDEView 消息处理程序


void CScriptIDEView::OnPrint(CDC* pDC, CPrintInfo* pInfo)
{
	// TODO: 在此添加专用代码和/或调用基类
	  //Validate our parameters
	ASSERT_VALID(this);
	ASSERT_VALID(pDC);
#pragma warning(suppress: 26496)
	AFXASSUME(pInfo != nullptr);
	ASSERT(pInfo->m_pPD != nullptr);
	ASSERT(pInfo->m_bContinuePrinting);

	const UINT nPage = pInfo->m_nCurPage;
	ASSERT(nPage <= static_cast<UINT>(m_PageStart.size()));
#pragma warning(suppress: 26446)
	int nIndex = m_PageStart[nPage - 1];

	//Determine where we should end the printing
	int nEndPrint = 0;
#pragma warning(suppress: 26486)

	CChildFrame * child = (CChildFrame *)GetParentFrame();

	if (pInfo->m_pPD->PrintSelection())
		nEndPrint = child->GetSelectionEnd();
	else
		nEndPrint = child->GetTextLength();

	//print as much as possible in the current page.
	nIndex = PrintPage(pDC, pInfo, nIndex, nEndPrint);
	
	
	if (nIndex >= nEndPrint)
	{
		TRACE(_T("End of Document\n"));
		pInfo->SetMaxPage(nPage);
	}

	//update pagination information for page just printed
#pragma warning(suppress: 26472)
	if (nPage == static_cast<UINT>(m_PageStart.size()))
	{
		if (nIndex < nEndPrint)
			m_PageStart.push_back(nIndex);
	}
	else
	{
		ASSERT((nPage + 1) <= static_cast<UINT>(m_PageStart.size()));
#pragma warning(suppress: 26446)
		ASSERT(nIndex == m_PageStart[nPage]);
	}
	//CView::OnPrint(pDC, pInfo);
}


void CScriptIDEView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo)
{
	//Validate our parameters
	ASSERT_VALID(this);
	ASSERT_VALID(pDC);
	if (pInfo)
	{
#pragma warning(suppress: 26496)
		AFXASSUME(pInfo != nullptr);

#pragma warning(suppress: 26486)
		if (pInfo->m_nCurPage <= pInfo->GetMaxPage())
		{
#pragma warning(suppress: 26472)
			if ((pInfo->m_nCurPage > static_cast<UINT>(m_PageStart.size())) && !PaginateTo(pDC, pInfo))
			{
				//can't paginate to that page, thus cannot print it.
				pInfo->m_bContinuePrinting = FALSE;
			}
			ASSERT_VALID(this);
		}
		else
		{
			//Reached the max page to print
			pInfo->m_bContinuePrinting = FALSE;
		}
	}


	CView::OnPrepareDC(pDC, pInfo);
}

BOOL CScriptIDEView::PaginateTo(CDC * pDC, CPrintInfo * pInfo)
{
	//Validate our parameters
	ASSERT_VALID(this);
	ASSERT_VALID(pDC);

	const CRect rectSave = pInfo->m_rectDraw;
	const UINT nPageSave = pInfo->m_nCurPage;
	ASSERT(nPageSave > 1);
	ASSERT(nPageSave >= static_cast<UINT>(m_PageStart.size()));
	VERIFY(pDC->SaveDC() != 0);
	pDC->IntersectClipRect(0, 0, 0, 0);
#pragma warning(suppress: 26472)
	pInfo->m_nCurPage = static_cast<UINT>(m_PageStart.size());
	while (pInfo->m_nCurPage < nPageSave)
	{
		ASSERT(pInfo->m_nCurPage == static_cast<UINT>(m_PageStart.size()));
		OnPrepareDC(pDC, pInfo);
		ASSERT(pInfo->m_bContinuePrinting);
		pInfo->m_rectDraw.SetRect(0, 0, pDC->GetDeviceCaps(HORZRES), pDC->GetDeviceCaps(VERTRES));
		OnPrint(pDC, pInfo);
#pragma warning(suppress: 26472)
		if (pInfo->m_nCurPage == static_cast<UINT>(m_PageStart.size()))
			break;
		++pInfo->m_nCurPage;
	}
	const BOOL bResult = pInfo->m_nCurPage == nPageSave;
	pDC->RestoreDC(-1);
	pInfo->m_nCurPage = nPageSave;
	pInfo->m_rectDraw = rectSave;
	ASSERT_VALID(this);
	return bResult;
}

int CScriptIDEView::PrintPage(CDC * pDC, CPrintInfo * pInfo, int nIndexStart, int nIndexStop)
{
	//Validate our parameters
	ASSERT_VALID(this);
	ASSERT_VALID(pDC);

	Sci_RangeToFormat rfPrint;
	rfPrint.hdc = pDC->m_hDC;
	rfPrint.hdcTarget = pDC->m_hAttribDC;

	//Take into account the specified margins
	CRect rMargins ;
	rMargins.SetRectEmpty();
	//if ((m_rMargin.left) != 0 || (m_rMargin.right) != 0 || (m_rMargin.top) != 0 || (m_rMargin.bottom != 0))
	//{
	//	//Get printer resolution
	//	CPoint pDpi;
	//	pDpi.x = pDC->GetDeviceCaps(LOGPIXELSX); //DPI in X direction
	//	pDpi.y = pDC->GetDeviceCaps(LOGPIXELSY); //DPI in Y direction

	//	//Convert the hundredths of millimeters or thousandths of inches margin values
	//	//from the Page Setup dialog to device units.
	//	const int iScale = m_bUsingMetric ? 2540 : 1000; //scale factor for margin scaling;
	//	rMargins.left = MulDiv(m_rMargin.left, pDpi.x, iScale);
	//	rMargins.top = MulDiv(m_rMargin.top, pDpi.y, iScale);
	//	rMargins.right = MulDiv(m_rMargin.right, pDpi.x, iScale);
	//	rMargins.bottom = MulDiv(m_rMargin.bottom, pDpi.y, iScale);
	//}
	//else
	//	rMargins = m_rMargin;

	//We take the page size from the pInfo member variable (decrement the right and
	//bottom values by 1 to suit Scintilla)
	rfPrint.rcPage.left = pInfo->m_rectDraw.left;
	rfPrint.rcPage.top = pInfo->m_rectDraw.top;
	rfPrint.rcPage.right = pInfo->m_rectDraw.right - 1;
	rfPrint.rcPage.bottom = pInfo->m_rectDraw.bottom - 1;

	//Fill in the area to print
	rfPrint.rc.left = rfPrint.rcPage.left + rMargins.left;
	rfPrint.rc.top = rfPrint.rcPage.top + rMargins.top;
	rfPrint.rc.right = rfPrint.rcPage.right - rMargins.right;
	rfPrint.rc.bottom = rfPrint.rcPage.bottom - rMargins.bottom;

	//Fill in the text to print
#pragma warning(suppress: 26472)
	rfPrint.chrg.cpMin = static_cast<LONG>(nIndexStart);
#pragma warning(suppress: 26472)
	rfPrint.chrg.cpMax = static_cast<LONG>(nIndexStop);

	//Print the header (if requested to)
	//if (m_bPrintHeader)
		PrintHeader(pDC, pInfo, rfPrint);

	//Print the footer (if requested to)
	//if (m_bPrintFooter)
		PrintFooter(pDC, pInfo, rfPrint);

	//Finally ask the control to print the text
	CChildFrame * child = (CChildFrame *)GetParentFrame();
	return child->FormatRange(TRUE, &rfPrint);
}

void CScriptIDEView::PrintHeader(CDC * pDC, CPrintInfo * pInfo, Sci_RangeToFormat & frPrint)
{
	//Validate our parameters
	ASSERT(pDC != nullptr);

	//By Default we print "Document Name - Printed on Date" as well as a line separator below the text
	//Derived classes are of course free to implement their own version of PrintHeader
	CString sHeader;
	sHeader.Format(L"%s - Printed on %s", GetDocument()->GetTitle(), CTime::GetCurrentTime().Format(_T("%c")));

	//Setup the DC
	pDC->SetTextColor(RGB(0, 0, 0));
	const UINT nAlign = pDC->SetTextAlign(TA_LEFT | TA_TOP);

	//Draw the header
	const CSize sizeText = pDC->GetTextExtent(sHeader);
	const int nHeaderDepth = 2 * sizeText.cy;
	const CRect rLine(frPrint.rcPage.left, frPrint.rcPage.top, frPrint.rcPage.right, frPrint.rcPage.top + nHeaderDepth);
	pDC->ExtTextOut(frPrint.rcPage.left, frPrint.rcPage.top + nHeaderDepth / 3, 0, &rLine, sHeader, nullptr);

	//Draw a line underneath the text
	pDC->MoveTo(frPrint.rcPage.left, frPrint.rcPage.top + nHeaderDepth - 5);
	pDC->LineTo(frPrint.rcPage.right, frPrint.rcPage.top + nHeaderDepth - 5);

	//Restore the DC
	pDC->SetTextAlign(nAlign);

	//Adjust the place where scintilla will draw the text
	if (frPrint.rc.top < (frPrint.rcPage.top + nHeaderDepth))
		frPrint.rc.top = frPrint.rcPage.top + nHeaderDepth;
}

void CScriptIDEView::PrintFooter(CDC * pDC, CPrintInfo * pInfo, Sci_RangeToFormat & frPrint)
{
	//Validate our parameters
	ASSERT(pDC != nullptr);
	ASSERT(pInfo != nullptr);

	//By Default we print "Page X" as well as a line separator above the text
	//Derived classes are of course free to implement their own version of PrintFooter
	CString sPage;
	sPage.Format(_T("%u"), pInfo->m_nCurPage);
	CString sFooter;
	sFooter.Format(L"Page %s", sPage);

	//Setup the DC
	pDC->SetTextColor(RGB(0, 0, 0));
	const UINT nAlign = pDC->SetTextAlign(TA_LEFT | TA_TOP);

	//Draw the header
	const CSize sizeText = pDC->GetTextExtent(sFooter);
	const int nFooterDepth = 2 * sizeText.cy;
	const CRect rLine(frPrint.rcPage.left, frPrint.rcPage.bottom - nFooterDepth, frPrint.rcPage.right, frPrint.rcPage.bottom);
	pDC->ExtTextOut(frPrint.rcPage.left, frPrint.rcPage.bottom - nFooterDepth * 2 / 3, 0, &rLine, sFooter, nullptr);

	//Draw a line above the text
	pDC->MoveTo(frPrint.rcPage.left, frPrint.rcPage.bottom - nFooterDepth + 5);
	pDC->LineTo(frPrint.rcPage.right, frPrint.rcPage.bottom - nFooterDepth + 5);

	//Restore the DC
	pDC->SetTextAlign(nAlign);

	//Adjust the place where scintilla will draw the text
	if (frPrint.rc.bottom > (frPrint.rcPage.bottom - nFooterDepth))
		frPrint.rc.bottom = frPrint.rcPage.bottom - nFooterDepth;
}
