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

// ScriptIDEDoc.cpp: CScriptIDEDoc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "ScriptIDE.h"
#endif

#include "ScriptIDEDoc.h"
#include "MainFrm.h"
#include "ChildFrm.h"
#include <propkey.h>
#include "stdstringext.hpp"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CScriptIDEDoc

IMPLEMENT_DYNCREATE(CScriptIDEDoc, CDocument)

BEGIN_MESSAGE_MAP(CScriptIDEDoc, CDocument)
END_MESSAGE_MAP()


// CScriptIDEDoc 构造/析构

CScriptIDEDoc::CScriptIDEDoc() 
{
	// TODO: 在此添加一次性构造代码


}

CScriptIDEDoc::~CScriptIDEDoc()
{
}

BOOL CScriptIDEDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	CChildFrame * child = (CChildFrame *)((CMainFrame *)AfxGetMainWnd())->MDIGetActive();
	if (child)
	{
		static const char*Templete = "#scp\r\n#scpeng\r\n";
		child->SetContent((void*)Templete, strlen(Templete));
	}
	return TRUE;
}




// CScriptIDEDoc 序列化

void CScriptIDEDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void CScriptIDEDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void CScriptIDEDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void CScriptIDEDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CScriptIDEDoc 诊断

#ifdef _DEBUG
void CScriptIDEDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CScriptIDEDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CScriptIDEDoc 命令


BOOL CScriptIDEDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	BOOL bRet;
	//if (!CDocument::OnOpenDocument(lpszPathName))
	//	return FALSE;
	void * Content;
	Content = 0;
	size_t ContentLength;
	HANDLE hFile = CreateFileW(lpszPathName, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (INVALID_HANDLE_VALUE != hFile)
	{

		DWORD dwSize = 0;
		DWORD dwReadCount = 0;
		DWORD dwWriteCount = 0;
		dwSize = GetFileSize(hFile, NULL);
		Content = (unsigned char *)malloc(dwSize+10);
		if (Content)
		{
			memset(Content, 0, dwSize + 10);
			bRet = ReadFile(hFile, Content, dwSize, &dwReadCount, NULL);

			ContentLength = dwSize;
		}
		CloseHandle(hFile);
	}
	((CMainFrame *)AfxGetMainWnd())->m_wndFileView.UpdateOpenedFile(lpszPathName,TRUE);
	CChildFrame * child = (CChildFrame *)((CMainFrame *)AfxGetMainWnd())->MDIGetActive();
	if (child)
	{
		if (Content)
		{
			if (STDSTRINGEXT::IsTextUTF8((char*)Content, ContentLength))
			{
				child->bUTF8 = true;
				child->SetContent(Content, ContentLength);
			}			
			else
			{
				child->bUTF8 = false;
				std::string ContentU = STDSTRINGEXT::AToU((char*)Content);
				child->SetContent((void*)ContentU.c_str(), ContentU.length());
			}
				
			
		}			
		ContentLength = 0;
	}
	if(Content)
		free(Content);
	return bRet;
}


void CScriptIDEDoc::OnCloseDocument()
{
	// TODO: 在此添加专用代码和/或调用基类
	((CMainFrame *)AfxGetMainWnd())->m_wndFileView.UpdateOpenedFile(GetPathName(), FALSE);
	CDocument::OnCloseDocument();
}


BOOL CScriptIDEDoc::OnSaveDocument(LPCTSTR lpszPathName)
{
	// TODO: 在此添加专用代码和/或调用基类
	BOOL bRet;
	((CMainFrame *)AfxGetMainWnd())->m_wndFileView.UpdateOpenedFile(GetPathName(), FALSE);
	CChildFrame * child =(CChildFrame * )((CMainFrame *) AfxGetMainWnd())->MDIGetActive();
	if (child)
	{
		size_t ContentLen;
		void * Content=NULL;
		child->GetContent(&Content, ContentLen);
		if (Content)
		{
			HANDLE hFile = CreateFileW(lpszPathName, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
			if (INVALID_HANDLE_VALUE != hFile)
			{
				DWORD dwWriteCount = 0;
				if (child->bUTF8)
				{
					bRet = WriteFile(hFile, Content, ContentLen, &dwWriteCount, NULL);
				}					
				else
				{
					std::string ContentU = STDSTRINGEXT::UToA((char*)Content);
					bRet = WriteFile(hFile, ContentU.c_str(), ContentU.length(), &dwWriteCount, NULL);
				}
				CloseHandle(hFile);
			}
			free(Content);
			((CMainFrame *)AfxGetMainWnd())->m_wndFileView.UpdateOpenedFile(lpszPathName, TRUE);
			return bRet;
		}
	}
	return CDocument::OnSaveDocument(lpszPathName);
}
