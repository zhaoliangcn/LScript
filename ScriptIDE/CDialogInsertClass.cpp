// CDialogInsertClass.cpp: 实现文件
//

#include "stdafx.h"
#include "ScriptIDE.h"
#include "CDialogInsertClass.h"
#include "afxdialogex.h"


// CDialogInsertClass 对话框

IMPLEMENT_DYNAMIC(CDialogInsertClass, CDialogEx)

CDialogInsertClass::CDialogInsertClass(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_INSERT_ClASS, pParent)
{

}

CDialogInsertClass::~CDialogInsertClass()
{
}

void CDialogInsertClass::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialogInsertClass, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDialogInsertClass::OnBnClickedOk)
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()


// CDialogInsertClass 消息处理程序


void CDialogInsertClass::OnBnClickedOk()
{
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(classname);
	CDialogEx::OnOK();
}


void CDialogInsertClass::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialogEx::OnShowWindow(bShow, nStatus);

	GetDlgItem(IDC_EDIT1)->SetFocus();
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(L"myclass");
	((CEdit*)GetDlgItem(IDC_EDIT1))->SetSel(0, -1);
}
