#pragma once


// CDialogInsertClass 对话框

class CDialogInsertClass : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogInsertClass)

public:
	CDialogInsertClass(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialogInsertClass();
public:
	CString classname;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_INSERT_ClASS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
};
