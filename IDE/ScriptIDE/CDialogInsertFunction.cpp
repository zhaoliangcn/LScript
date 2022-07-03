// CDialogInsertFunction.cpp: 实现文件
//

#include "stdafx.h"
#include "ScriptIDE.h"
#include "CDialogInsertFunction.h"
#include "afxdialogex.h"


// CDialogInsertFunction 对话框

IMPLEMENT_DYNAMIC(CDialogInsertFunction, CDialogEx)

CDialogInsertFunction::CDialogInsertFunction(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_INSERT_FUNCTION, pParent)
{

}

CDialogInsertFunction::~CDialogInsertFunction()
{
}

void CDialogInsertFunction::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDialogInsertFunction, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDialogInsertFunction::OnBnClickedOk)
	ON_WM_SHOWWINDOW()
END_MESSAGE_MAP()


// CDialogInsertFunction 消息处理程序


void CDialogInsertFunction::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_EDIT1)->GetWindowTextW(funcname);
	CDialogEx::OnOK();
}


BOOL CDialogInsertFunction::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CDialogInsertFunction::OnShowWindow(BOOL bShow, UINT nStatus)
{
	CDialogEx::OnShowWindow(bShow, nStatus);

	GetDlgItem(IDC_EDIT1)->SetFocus();
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(L"myfunc");
	((CEdit*)GetDlgItem(IDC_EDIT1))->SetSel(0, -1);
}
