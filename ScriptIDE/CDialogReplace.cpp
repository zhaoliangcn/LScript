// CDialogReplace.cpp: 实现文件
//

#include "stdafx.h"
#include "ScriptIDE.h"
#include "CDialogReplace.h"
#include "afxdialogex.h"


// CDialogReplace 对话框

IMPLEMENT_DYNAMIC(CDialogReplace, CDialogEx)

CDialogReplace::CDialogReplace(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CDialogReplace::~CDialogReplace()
{
}

void CDialogReplace::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialogReplace, CDialogEx)
	ON_WM_SHOWWINDOW()
	ON_BN_CLICKED(IDOK, &CDialogReplace::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialogReplace 消息处理程序


void CDialogReplace::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialogEx::OnShowWindow(bShow, nStatus);
	GetDlgItem(IDC_EDIT1)->SetFocus();
	// TODO: 在此处添加消息处理程序代码
}


void CDialogReplace::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(text);
	GetDlgItem(IDC_EDIT2)->GetWindowTextW(repText);
	CDialogEx::OnOK();
}
