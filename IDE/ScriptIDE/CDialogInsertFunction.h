#pragma once


// CDialogInsertFunction 对话框

class CDialogInsertFunction : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogInsertFunction)

public:
	CDialogInsertFunction(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialogInsertFunction();

public:
	CString funcname;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_INSERT_FUNCTION };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
};
