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

// ChildFrm.h: CChildFrame 类的接口
//

#pragma once
#include "../ThirdParty\\scintilla\\include\\Scintilla.h"
#include "../ThirdParty\\scintilla\\include\\SciLexer.h"
#include <string>
extern HINSTANCE g_ins;
typedef sptr_t(*SciFnDirect)(sptr_t ptr, unsigned int iMessage, uptr_t wParam, sptr_t lParam);

#define SCINT_ID                        2008
class CChildFrame : public CMDIChildWndEx
{
	DECLARE_DYNCREATE(CChildFrame)
public:
	CChildFrame() ;

// 特性
protected:
	CSplitterWndEx m_wndSplitter;
public:

// 操作
public:

// 重写
	public:
	public:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

	HWND hEdit;

// 实现
public:
	virtual ~CChildFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// 生成的消息映射函数
protected:

	afx_msg void OnFilePrint();
	afx_msg void OnFilePrintPreview();
	afx_msg void OnUpdateFilePrintPreview(CCmdUI* pCmdUI);
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle = WS_CHILD | WS_VISIBLE | WS_OVERLAPPEDWINDOW, const RECT& rect = rectDefault, CMDIFrameWnd* pParentWnd = NULL, CCreateContext* pContext = NULL);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	virtual LPCTSTR GetDocumentName(CObject** pObj);
	virtual CString GetFrameText() const;
	void SetContent(void * Content, size_t ContentLength);
	bool GetContent(void ** Content, size_t &ContentLength);
	bool GetSelContent(void**Content, size_t &ContentLength);
	bool CopySelection();
	bool CutSelection();
	bool Paste();
	bool SelectAll();
	bool Find(const char * text);
	bool FindNext();
	bool Replace(const char * text, const char* repText);
	bool RunScript();
	bool DebugScript();
	bool SetCurrentLine(int line);
	bool InsertFunctiondef();
	bool InsertClassDef();
	int GetSelectionStart();
	int GetSelectionEnd();
	int GetTextLength();
	int FormatRange(BOOL draw, Sci_RangeToFormat *rfPrint);
	SciFnDirect m_fnDirect;
	sptr_t m_ptrDirect;
	sptr_t SendEditor(unsigned int iMessage, uptr_t wParam = 0, sptr_t lParam = 0);
	void UpdateLineNumberWidth(void);
	void InitEditor();
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	static DWORD WINAPI DebugThread(void*param);
	static DWORD WINAPI RunThread(void*param);
	HANDLE hthreadDebug;
	HANDLE hthreadRun;
	std::string lastFindText;
	std::string lastReplaceText;
	std::string lastReplaceToText;
	bool bUTF8;
};
