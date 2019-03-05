
// mfc_use_strTypeDlg.h: 头文件
//

#pragma once


// CmfcusestrTypeDlg 对话框
class CmfcusestrTypeDlg : public CDialogEx
{
// 构造
public:
	CmfcusestrTypeDlg(CWnd* pParent = nullptr);	// 标准构造函数
	void practice_using_str();
	void use_char();
	void use_lpstr();
	void use_cstr();
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_USE_STRTYPE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
