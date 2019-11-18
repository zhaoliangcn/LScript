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

// ChildFrm.cpp: CChildFrame 类的实现
//

#include "stdafx.h"
#include "ScriptIDE.h"
#include "MainFrm.h"
#include "ChildFrm.h"
#include "../include/ScriptEngineDll.h"
#pragma comment(lib,"ScriptEngineDll.lib")
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWndEx)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWndEx)
	ON_COMMAND(ID_FILE_PRINT, &CChildFrame::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CChildFrame::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CChildFrame::OnFilePrintPreview)
	ON_UPDATE_COMMAND_UI(ID_FILE_PRINT_PREVIEW, &CChildFrame::OnUpdateFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()

// CChildFrame 构造/析构


#define UWM_SIMPLECREATED       (WM_APP + 0x0001)
#include "stdstringext.hpp"


void EditorUIMessage(void * uiclass, const wchar_t * message)
{
	((CMainFrame *)uiclass)->m_wndOutput.AppendDebugOutput(message);
}
sptr_t CChildFrame::SendEditor(unsigned int iMessage, uptr_t wParam , sptr_t lParam)
{
	if (m_fnDirect &&m_ptrDirect)
		return m_fnDirect(m_ptrDirect, iMessage, wParam, lParam);
	return 0;
}
void CChildFrame::UpdateLineNumberWidth(void)
{
	//start 显示行号
	long  iLineMarginWidthNow;
	long  iLineMarginWidthFit;
	long iLineNum = SendEditor(SCI_GETLINECOUNT, 0, 0);
	long iLineNumCount = 1;
	while (iLineNum != 0)
	{
		++iLineNumCount;
		iLineNum /= 10;
	}
	iLineMarginWidthNow = SendEditor(SCI_GETMARGINWIDTHN, 0, 0);
	long charWidth = SendEditor(SCI_TEXTWIDTH, STYLE_LINENUMBER, (LPARAM)("9"));
	iLineMarginWidthFit = charWidth * iLineNumCount;
	if (iLineMarginWidthNow != iLineMarginWidthFit)
	{
		SendEditor(SCI_SETMARGINWIDTHN, 0, iLineMarginWidthFit);
	}
	//end of 显示行号
}

void CChildFrame::InitEditor()
{
	const char* g_szKeywords = "清空 保留 关闭 重启 弹出 打印 显示 打开 运行 捕获 删除 读取 写入 复制 定位 执行 比较 计算 连接 申请 释放 定义 如果 开始 结束 调用 查找 替换 取子串 插入 匹配 导入 当 移动 取大小 取长度 注册 发送 接收 监听 设置 睡眠 等待 枚举 否则 刷新 生成 休眠 取元素 遍历 排序 格式化 克隆 获取 继承 加密 解密 求哈希 转换 分割 提交 加载 退出 画 压入 继续 跳出 开关 若 锁定 解锁 压缩 解压 创建 循环 公开 私有 保存 返回 编码 解码 输出 查询 执行 关闭 上传 下载 播放 停止 说 "
		"invalid clear reserved shutdown reboot popup print show open run capture delete read write copy seek do compare compute connect acquire release define test if start end call find replace getsubstring insert match import while move getsize getlength register send receive watch set sleep wait enum otherwise else refresh generate suspend getelement traverse sort format clone get inherit encrypt decrypt hash transform split post load exit draw push continue break switch case lock unlock compress uncompress create loop public private save return encode decode put query execute close upload download erase play stop speak";
	const char* g_szKeywords2 = "计算机 电脑 文件 注册表 网络 代码 消息框 进程 程序 脚本 字符串 数值 内存 状态 结果 函数 整数 浮点数 算式 表 列表 栈 队列 元素 正则表达式 类 类实例 成员 库 映射 三元映射 空 枚举值 指针 句柄 C整数 C字符指针 C宽字符指针 C无符号整数 C函数 全局命令 地址 网络连接 时间 当前时间 定时器 图片 音频 视频 目录 子目录 XML 线程 画布 窗体 点 直线 曲线 椭圆 圆 矩形 多边形 消息处理 用户输入 随机数 Sqlite数据库 属性 环境变量 管道 HTTP连接 JSON BSON PYTHON 扩展 结构体 GPIO 表达式 数组 循环 类型 静态整数 静态浮点数 静态字符串 条件语句 主函数 相等 不相等 大于 小于 真 假 匹配 不匹配 找到 没找到 命令行参数 当前目录 调用堆栈 大整数 OLEWORD OLEEXCEL OLEPPT 单元格 操作系统信息 整数矩阵 套接字 HTTP请求 HTTP响应 异步TCP服务器 异步TCP客户端 WMI ftpserver ftpclient 邮件客户端 扩展对象 "
		"computer computer file registry network code messagebox process process script string stringarray number memory state result function int double expression table list stack queue element regexp class classinstance member library map threeelementmap  enum void color int64 OLEWORD  OLEPPT  osinfo intmatrix socket httprequest httpresponse asynctcpserver asynctcpclient WMI ftpserver ftpclient smtpclient pointer handle Cint Cpchar Cpwchar Cuint Cfunction Cchar Cunsignedchar Cshort Cunsignedshort Clong Cunsignedlong globalcommand  address netconnection time currenttime timer picture voice video directory subdirectory  thread canvas window point line arc ellipse circle rect polygon msgprocessor userinput randomnumber sqlitedb attribute value node environmentvariable pipe httpconnection httpserver json bson python extensionmodule struct structinstance gpio expressions array while type staticint staticdouble staticstring if main sharememory database recordset fieldname fieldvalue nextline   big lessthan true false matched notmatched finded notfinded readonly readwrite append begin end readonly hide  archive system temporary createtime accesstime modifytime drive filename path extension message hour minute second upper lower reverse  ip port pid commandparameter currentscriptfile currentscriptpath currentdirectory callstack package line extobj";//字符串数组
	SendEditor(SCI_SETCODEPAGE, SC_CP_UTF8);
	SendEditor(SCI_STYLESETFONT, STYLE_DEFAULT, (sptr_t)"Courier New");
	SendEditor(SCI_STYLESETSIZE, STYLE_DEFAULT, 14);
	SendEditor(SCI_STYLECLEARALL);
	SendEditor(SCI_SETCARETLINEVISIBLE, TRUE);
	//C++语法解析 
	SendEditor(SCI_SETLEXER, SCLEX_CPP);
	SendEditor(SCI_SETKEYWORDS, 0, (sptr_t)STDSTRINGEXT::AToU(g_szKeywords).c_str());//设置关键字 
	SendEditor(SCI_SETKEYWORDS, 1, (sptr_t)STDSTRINGEXT::AToU(g_szKeywords2).c_str());//设置关键字 
	// 下面设置各种语法元素风格 
	SendEditor(SCI_STYLESETFORE, SCE_C_WORD, 0x00FF0000);   //关键字 
	SendEditor(SCI_STYLESETFORE, SCE_C_WORD2, 0x00800080);   //关键字 
	SendEditor(SCI_STYLESETBOLD, SCE_C_WORD2, TRUE);   //关键字 
	SendEditor(SCI_STYLESETFORE, SCE_C_STRING, 0x001515A3); //字符串 
	SendEditor(SCI_STYLESETFORE, SCE_C_CHARACTER, 0x001515A3); //字符 
	SendEditor(SCI_STYLESETFORE, SCE_C_PREPROCESSOR, 0x00808080);//预编译开关 
	SendEditor(SCI_STYLESETFORE, SCE_C_COMMENT, 0x00008000);//块注释 
	SendEditor(SCI_STYLESETFORE, SCE_C_COMMENTLINE, 0x00008000);//行注释 
	SendEditor(SCI_STYLESETFORE, SCE_C_COMMENTDOC, 0x00008000);//文档注释（/**开头） 
	SendEditor(SCI_USEPOPUP, TRUE);
	UpdateLineNumberWidth();
	//SendEditor(SCI_SETMARGINWIDTHN, 1,30);
	//SendEditor(SCI_SETMARGINMASKN, 1, 0x06);

	SendEditor(SCI_SETMARGINTYPEN, 1, SC_MARGIN_SYMBOL);
	SendEditor(SCI_SETMARGINWIDTHN,1, 30);
	SendEditor(SCI_SETMARGINMASKN, 1, 0x01);
	SendEditor(SCI_SETMARGINSENSITIVEN, 1, TRUE); //响应鼠标消息

}


CChildFrame::CChildFrame() 
{
	// TODO: 在此添加成员初始化代码
	m_fnDirect = NULL;
	m_ptrDirect = NULL;
	hthreadDebug = NULL;
	bUTF8 = true;
}

CChildFrame::~CChildFrame()
{
}



BOOL CChildFrame::OnCreateClient(LPCREATESTRUCT /*lpcs*/, CCreateContext* pContext)
{
	return m_wndSplitter.Create(this,
		2, 2,			// TODO: 调整行数和列数
		CSize(10, 10),	// TODO: 调整最小窗格大小
		pContext);
}

BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改 CREATESTRUCT cs 来修改窗口类或样式
	if( !CMDIChildWndEx::PreCreateWindow(cs) )
		return FALSE;

	cs.style = WS_CHILD | WS_VISIBLE | WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU
		| FWS_ADDTOTITLE | WS_THICKFRAME;

	return TRUE;
}

// CChildFrame 诊断

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
	CMDIChildWndEx::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWndEx::Dump(dc);
}
#endif //_DEBUG

// CChildFrame 消息处理程序
//

void CChildFrame::OnFilePrint()
{
	if (m_dockManager.IsPrintPreviewValid())
	{
		PostMessage(WM_COMMAND, AFX_ID_PREVIEW_PRINT);
	}
}

void CChildFrame::OnFilePrintPreview()
{
	if (m_dockManager.IsPrintPreviewValid())
	{
		PostMessage(WM_COMMAND, AFX_ID_PREVIEW_CLOSE);  // 强制关闭“打印预览”模式
	}
}

void CChildFrame::OnUpdateFilePrintPreview(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_dockManager.IsPrintPreviewValid());
}


BOOL CChildFrame::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CMDIFrameWnd* pParentWnd, CCreateContext* pContext)
{
	// TODO: 在此添加专用代码和/或调用基类

	return CMDIChildWndEx::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, pContext);
}


int CChildFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIChildWndEx::OnCreate(lpCreateStruct) == -1)
		return -1;
	CRect rect;
	GetClientRect(rect);
		hEdit = ::CreateWindow(_T("Scintilla"),
			NULL, WS_CHILD | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE,
			rect.left, rect.top, rect.right- rect.left, rect.bottom- rect.top,
			this->m_hWnd,
			(HMENU)SCINT_ID, lpCreateStruct->hInstance, NULL);
		m_fnDirect = (SciFnDirect)::SendMessage(hEdit, SCI_GETDIRECTFUNCTION, 0, 0);
		m_ptrDirect = (sptr_t)::SendMessage(hEdit, SCI_GETDIRECTPOINTER, 0, 0);
		InitEditor();

		
	return 0;
}


void CChildFrame::OnSize(UINT nType, int cx, int cy)
{
	CMDIChildWndEx::OnSize(nType, cx, cy);

	::MoveWindow(hEdit, 0, 0, cx, cy, FALSE);
}


LPCTSTR CChildFrame::GetDocumentName(CObject** pObj)
{
	// TODO: 在此添加专用代码和/或调用基类

	return CMDIChildWndEx::GetDocumentName(pObj);
}


CString CChildFrame::GetFrameText() const
{
	// TODO: 在此添加专用代码和/或调用基类

	return CMDIChildWndEx::GetFrameText();
}

void CChildFrame::SetContent(void * Content, size_t ContentLength)
{
	if(Content && ContentLength>0)
	SendEditor(SCI_APPENDTEXT, ContentLength, (sptr_t)Content);
}

bool CChildFrame::GetContent(void ** Content, size_t & ContentLength)
{
	ContentLength = SendEditor(SCI_GETLENGTH, 0, 0);
	if (ContentLength > 0)
	{
		*Content = (char *)malloc(ContentLength + 10);
		if (*Content)
		{
			memset(*Content, 0, ContentLength + 10);
			SendEditor(SCI_GETTEXT, ContentLength + 1, (sptr_t)*Content);
			return true;
		}
	}
	return false;
}
bool CChildFrame::GetSelContent(void ** Content, size_t & ContentLength)
{
	ContentLength = SendEditor(SCI_GETSELTEXT, 0, 0);
	int total = SendEditor(SCI_GETLENGTH, 0, 0);
	if (ContentLength <= total)
	{		
		*Content = (char *)malloc(ContentLength + 10);
		if (*Content)
		{
			memset(*Content, 0, ContentLength + 10);
			SendEditor(SCI_GETSELTEXT, 0, (sptr_t)*Content);
			return true;
		}
	}
	return false;
}
bool CChildFrame::CopySelection()
{	
	SendEditor(SCI_COPY);
	return true;
}
bool CChildFrame::CutSelection()
{
	SendEditor(SCI_CUT);
	return true;

}
bool CChildFrame::Paste()
{
	SendEditor(SCI_PASTE);
	return true;
}
bool CChildFrame::SelectAll()
{
	SendEditor(SCI_SELECTALL);
	
	return true;
}
bool CChildFrame::Find(const char * text)
{
	if (text)
	{
		lastFindText = text;
		Sci_TextToFind  ttf;
		ttf.chrg.cpMin = 0;
		ttf.chrg.cpMax = SendEditor(SCI_GETLENGTH, 0, 0);
		ttf.lpstrText = text;
		int line =SendEditor(SCI_FINDTEXT, SCFIND_REGEXP, (sptr_t)&ttf);
		if (line >= 0)
		{
			SendEditor(SCI_GOTOPOS, ttf.chrgText.cpMin);
			SendEditor(SCI_SETSELECTIONSTART, ttf.chrgText.cpMin);
			SendEditor(SCI_SETSELECTIONEND, ttf.chrgText.cpMax);
			CStringA message;
			message.Format("Find Text \"%s\" At  Pos %d", text, line);
			((CMainFrame *)AfxGetMainWnd())->m_wndOutput.AppendFindOutput(CString(message));
			return true;
		}

	}	
	return false;
}
bool CChildFrame::FindNext()
{
	Sci_TextToFind  ttf;
	ttf.chrg.cpMin = SendEditor(SCI_GETCURRENTPOS, 0, 0);
	ttf.chrg.cpMax = SendEditor(SCI_GETLENGTH, 0, 0);
	ttf.lpstrText = lastFindText.c_str();
	int line = SendEditor(SCI_FINDTEXT, SCFIND_REGEXP, (sptr_t)&ttf);
	if (line >= 0)
	{
		SendEditor(SCI_GOTOPOS, ttf.chrgText.cpMin);
		SendEditor(SCI_SETSELECTIONSTART, ttf.chrgText.cpMin);
		SendEditor(SCI_SETSELECTIONEND, ttf.chrgText.cpMax);
		CStringA message;
		message.Format("Find Text \"%s\" At Pos %d", lastFindText.c_str(), line);
		((CMainFrame *)AfxGetMainWnd())->m_wndOutput.AppendFindOutput(CString(message));
		return true;
	}
	return false;
}
bool CChildFrame::Replace(const char * text, const char * repText)
{
	if (text &&repText)
	{
		lastReplaceText = text;
		lastReplaceToText = repText;
		Sci_TextToFind  ttf;
		ttf.chrg.cpMin = 0;
		ttf.chrg.cpMax = SendEditor(SCI_GETLENGTH, 0, 0);
		ttf.lpstrText = text;
		int find=SendEditor(SCI_FINDTEXT, SCFIND_REGEXP, (sptr_t)&ttf);
		if (find >= 0)
		{
			SendEditor(SCI_GOTOPOS, ttf.chrgText.cpMin);
			SendEditor(SCI_SETSELECTIONSTART, ttf.chrgText.cpMin);
			SendEditor(SCI_SETSELECTIONEND, ttf.chrgText.cpMax);
			SendEditor(SCI_REPLACESEL, 0, (sptr_t)repText);
			SendEditor(SCI_SETSELECTIONSTART, ttf.chrgText.cpMin);
			SendEditor(SCI_SETSELECTIONEND, ttf.chrgText.cpMax);

			CStringA message;
			message.Format("Replace Text \"%s\" With \"%s\"At  Pos %d", lastReplaceText.c_str(), lastReplaceToText.c_str(), find);
			((CMainFrame *)AfxGetMainWnd())->m_wndOutput.AppendFindOutput(CString(message));
			return true;
		}
	}

	return false;
}
typedef struct _tag_THREAD_PARAM
{
	CMainFrame*mainframe;
	CChildFrame * child;
	CString filename;
	CStringA content;
}THREAD_PARAM,*PTHREAD_PARAM;
DWORD WINAPI CChildFrame::DebugThread(void*param)
{
	HANDLE hEngine = CreateScriptEngine();
	if (hEngine)
	{
		
		THREAD_PARAM* threadparam = (THREAD_PARAM *)param;
		if (threadparam->child)
		{
			
			CString filename = threadparam->filename;
			ScriptSetScriptFileName(hEngine, filename);
			ScriptSetDebugger(hEngine, &((CMainFrame *)threadparam->mainframe)->_scriptDbg);
			((CMainFrame *)threadparam->mainframe)->_scriptDbg.hEngine = hEngine;
			((CMainFrame *)threadparam->mainframe)->m_wndOutput.ClearDebugOutput();
			ScriptRegisterUICallBack(hEngine, (void *)threadparam->mainframe, (UICallBack)EditorUIMessage);
			ScriptDebugMemoryScript(hEngine, (wchar_t *)STDSTRINGEXT::UTF2W((const char *)threadparam->content).c_str());
		}
		CloseScriptEngine(hEngine);		
	}
	return 0;
}
bool CChildFrame::DebugScript()
{
	void *Content;
	size_t len = 0;
	THREAD_PARAM *param=new THREAD_PARAM;
	param->mainframe =(CMainFrame*) AfxGetMainWnd();
	param->child = this;
	param->filename = GetActiveView()->GetDocument()->GetPathName();
	param->child->GetContent(&Content, len);
	param->content = (char*)Content;
	free(Content);
	if (hthreadDebug == NULL)
	{
		hthreadDebug = CreateThread(NULL, 0, DebugThread, param, 0, NULL);
	}
	else
	{
		DWORD ExitCode;
		GetExitCodeThread(hthreadDebug, &ExitCode);
		if (ExitCode != STILL_ACTIVE)
		{
			hthreadDebug = CreateThread(NULL, 0, DebugThread, param, 0, NULL);
		}
	}
	return true;
}
bool CChildFrame::RunScript()
{
	HANDLE hEngine = CreateScriptEngine();
	if (hEngine)
	{
		void *Content;
		size_t len = 0;
		if (GetContent(&Content, len))
		{			
			CString filename = GetActiveView()->GetDocument()->GetPathName();
			ScriptSetScriptFileName(hEngine, filename);
			//ScriptSetDebugger(hEngine, &((CMainFrame *)AfxGetMainWnd())->_scriptDbg);
			((CMainFrame *)AfxGetMainWnd())->m_wndClassView.ClearClassView();
			((CMainFrame *)AfxGetMainWnd())->m_wndOutput.ClearDebugOutput();
			ScriptRegisterUICallBack(hEngine, (void *)AfxGetMainWnd(), (UICallBack)EditorUIMessage);
			ScriptDebugMemoryScript(hEngine, (wchar_t *)STDSTRINGEXT::UTF2W((const char *)Content).c_str());
			free(Content);
		}
		
		CloseScriptEngine(hEngine);
		return true;
	}
	return false;
}


LRESULT CChildFrame::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	// TODO: 在此添加专用代码和/或调用基类
	

	if (message == WM_NOTIFY)
	{
		SCNotification* notify = (SCNotification*)lParam;
		// 处理自动缩进 
		static int LastProcessedChar = 0;
		static int blockdepth = 0;
		if (notify->nmhdr.code == SCN_MARGINCLICK)
		{
			if (notify->nmhdr.code == SCN_MARGINCLICK &&
				notify->nmhdr.idFrom == SCINT_ID) {
				// 确定是页边点击事件
				const int line = SendEditor(SCI_LINEFROMPOSITION, notify->position);
				int pos0 = SendEditor(SCI_FINDCOLUMN, line, 0);			// 取得当前行的最左边位置的开始pos
				int nMask = SendEditor(SCI_MARKERGET, line);
				char word[1000] = { 0 }; //保存当前光标下的单词 
				TextRange tr;    //用于SCI_GETTEXTRANGE命令
				int line_length = SendEditor(SCI_LINELENGTH, line);		// 当前行长度
				tr.chrg.cpMin = pos0;  //设定单词区间，取出单词 
				tr.chrg.cpMax = pos0+ line_length;
				tr.lpstrText = word;
				SendEditor(SCI_GETTEXTRANGE, 0, sptr_t(&tr));
				std::string temp = word;
				STDSTRINGEXT::trim(temp);
				if (!temp.empty())
				{
					CString filename = GetActiveView()->GetDocument()->GetPathName();
					if (nMask)
					{
						SendEditor(SCI_MARKERDELETE, line);

						((CMainFrame *)AfxGetMainWnd())->_scriptDbg.SetBreakPoint(filename, line, false);
					}
					else
					{
						SendEditor(SCI_MARKERADD, line);
						((CMainFrame *)AfxGetMainWnd())->_scriptDbg.SetBreakPoint(filename, line, true);
					}
				}			
					
			}
			
		}
		//在CharAdded事件中记录最后输入的字符 
		if (notify->nmhdr.code == SCN_CHARADDED)
		{
			LastProcessedChar = notify->ch;
			if (notify->ch == ':')
			{
				char word[1000]; //保存当前光标下的单词 
				TextRange tr;    //用于SCI_GETTEXTRANGE命令 
				int pos = SendEditor(SCI_GETCURRENTPOS); //取得当前位置 
				int startpos = SendEditor(SCI_WORDSTARTPOSITION, pos - 1);//当前单词起始位置 
				int endpos = SendEditor(SCI_WORDENDPOSITION, pos - 1);//当前单词终止位置 
				tr.chrg.cpMin = startpos;  //设定单词区间，取出单词 
				tr.chrg.cpMax = endpos;
				tr.lpstrText = word;
				SendEditor(SCI_GETTEXTRANGE, 0, sptr_t(&tr));
				if (strcmp(word, "define:") == 0) //输入define.后提示可选对象 
				{
					SendEditor(SCI_AUTOCSHOW, 0,
						sptr_t(
							"array, "							
							"class,myclass\r\n\r\nend "
							"double, "
							"function,myfunc\r\n\r\nend "							
							"int, "							
							"int64, "
							"string, "
							"table, "
							"list, "
							"memory, "
							"regexp, "
							"file, "
							"directory, "
						));
				}
				else if (strcmp(word, STDSTRINGEXT::AToU("定义:").c_str()) == 0) //输入define.后提示可选对象 
				{
					SendEditor(SCI_AUTOCSHOW, 0,
						sptr_t(
							STDSTRINGEXT::AToU("数组, "
							"类,myclass\r\n\r\n结束 "
							"浮点数, "
							"函数,myfunc\r\n\r\n结束 "
							"整数, "
							"大整数, "
							"字符串, "
							"表, "
							"列表, "
							"内存, "
							"正则表达式, "
							"文件, "
							"目录, ").c_str()
						));
				}
			}
		}
		// 在UpdateUI事件中处理缩进 
		if (notify->nmhdr.code == SCN_UPDATEUI && LastProcessedChar != 0)
		{
			int pos = SendEditor(SCI_GETCURRENTPOS); //取得当前位置 
			int line = SendEditor(SCI_LINEFROMPOSITION, pos); //取得当前行 
			//如果最后输入的字符是右括号的话就自动让当前行缩进和它匹配的左括号所在行一致 
			if (strchr(")]", LastProcessedChar) &&
				isspace(SendEditor(SCI_GETCHARAT, pos - 2)) && //要求右括号左边是空白字符 
				LastProcessedChar != 0)
			{
				//找前一个单词起始位置，这里用它来确定右括号左边是否全是空白字符 
				int startpos = SendEditor(SCI_WORDSTARTPOSITION, pos - 1, false);
				int linepos = SendEditor(SCI_POSITIONFROMLINE, line); //当前行起始位置 
				if (startpos == linepos) //这样相当于判断右括号左边是否全是空白字符 
				{
					int othpos = SendEditor(SCI_BRACEMATCH, pos - 1); //得到对应的左括号所在的位置 
					int othline = SendEditor(SCI_LINEFROMPOSITION, othpos);  //左括号所在行 
					int nIndent = SendEditor(SCI_GETLINEINDENTATION, othline);//左括号所在行的缩进值 
					// 替换右括号前面的空白字符，使之与左括号缩进一致 
					char space[1024];
					memset(space, ' ', 1024);
					SendEditor(SCI_SETTARGETSTART, startpos);
					SendEditor(SCI_SETTARGETEND, pos - 1);
					SendEditor(SCI_REPLACETARGET, nIndent, (sptr_t)space);
				}
			}
			// 如果输入的是回车，则保持与上一行缩进一致 
			// 如果上一行最后有效字符为左括号，就多缩进四个空格 
			if (LastProcessedChar == '\n')
			{
				if (line > 0)
				{
					// 得到上一行缩进设置 
					int nIndent = SendEditor(SCI_GETLINEINDENTATION, line - 1);
					// 查找上一行最后一个有效字符（非空白字符） 
					int nPrevLinePos = SendEditor(SCI_POSITIONFROMLINE, line - 1);
					int c = ' ';
					for (int p = pos - 2;
						p >= nPrevLinePos && isspace(c);
						p--, c = SendEditor(SCI_GETCHARAT, p));
					// 如果是左括号，就多缩进四格 
					if (c && strchr("([", c)) nIndent += 4;
					// 缩进... 
					char space[1024];
					memset(space, ' ', 1024);
					space[nIndent] = 0;
					SendEditor(SCI_REPLACESEL, 0, (sptr_t)space);
				}
			}
			LastProcessedChar = 0;
		}
	}
	return CMDIChildWndEx::WindowProc(message, wParam, lParam);
}
