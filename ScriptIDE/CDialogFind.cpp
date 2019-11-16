// CDialogFind.cpp: 实现文件
//

#include "stdafx.h"
#include "ScriptIDE.h"
#include "CDialogFind.h"
#include "afxdialogex.h"


// CDialogFind 对话框

IMPLEMENT_DYNAMIC(CDialogFind, CDialogEx)

CDialogFind::CDialogFind(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_FIND, pParent)
{

}

CDialogFind::~CDialogFind()
{
}

void CDialogFind::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialogFind, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDialogFind::OnBnClickedOk)
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()


// CDialogFind 消息处理程序


void CDialogFind::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(text);
	CDialogEx::OnOK();
}


BOOL CDialogFind::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDialogFind::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialogEx::OnShowWindow(bShow, nStatus);

	GetDlgItem(IDC_EDIT1)->SetFocus();
	//GetDlgItem(IDC_EDIT1)->SetCapture();
}
