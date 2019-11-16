#pragma once


// CDialogFind 对话框

class CDialogFind : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogFind)

public:
	CDialogFind(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialogFind();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_FIND };
#endif
public:
	CString text;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
};
