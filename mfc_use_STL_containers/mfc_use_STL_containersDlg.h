
// mfc_use_STL_containersDlg.h: 头文件
//

#pragma once


// CmfcuseSTLcontainersDlg 对话框
class CmfcuseSTLcontainersDlg : public CDialogEx
{
// 构造
public:
	CmfcuseSTLcontainersDlg(CWnd* pParent = nullptr);	// 标准构造函数
	void use_vector();
	void use_array();
	void use_deque();
	void use_list();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_USE_STL_CONTAINERS_DIALOG };
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
