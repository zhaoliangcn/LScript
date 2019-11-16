#pragma once


// CDialogReplace 对话框

class CDialogReplace : public CDialogEx
{
	DECLARE_DYNAMIC(CDialogReplace)

public:
	CDialogReplace(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CDialogReplace();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_REPLACE };
#endif

public:
	CString text;
	CString repText;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnBnClickedOk();
};
