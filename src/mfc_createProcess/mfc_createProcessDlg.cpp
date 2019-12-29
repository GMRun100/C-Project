
// mfc_createProcessDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "mfc_createProcess.h"
#include "mfc_createProcessDlg.h"
#include "afxdialogex.h"
#include<afxwin.h>

#include<string>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CmfccreateProcessDlg 对话框



CmfccreateProcessDlg::CmfccreateProcessDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_CREATEPROCESS_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmfccreateProcessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CmfccreateProcessDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CmfccreateProcessDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CmfccreateProcessDlg 消息处理程序

BOOL CmfccreateProcessDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CmfccreateProcessDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CmfccreateProcessDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CmfccreateProcessDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

static bool _exec_command(const char * cmd, ...)
{
	PROCESS_INFORMATION pi;
	STARTUPINFO si;
	char cmdLine[1024];
	va_list va;

	va_start(va, cmd);
	_vsnprintf_s(cmdLine, sizeof(cmdLine), cmd, va);
	cmdLine[sizeof(cmdLine) - 1] = 0;
	memset(&si, 0, sizeof(si));
	memset(&pi, 0, sizeof(pi));
	TCHAR *str;
	str=_T("osk.exe");

	//if (CreateProcess(NULL, (LPWSTR)cmdLine, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
	if (CreateProcess(NULL, (LPWSTR)str, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
	{
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
	else
	{
		return false;
	}
	return true;
}

void CmfccreateProcessDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	//启动软键盘 方法一
	HINSTANCE hInstance=ShellExecute(NULL, _T("open"), _T("C:\\Windows\\System32\\osk.exe"), NULL, NULL, SW_SHOWNORMAL);
	int temp = (int)hInstance;
	TRACE("temp=%d\n", temp);


	//方法二
	string tmp;
	//tmp="C:\\Windows\\System32\\osk.exe";

	//string temp2;
	//temp2 = "不能启动软键盘";
	//if (!_exec_command(tmp.c_str()))
	//{
	//	AfxMessageBox(_T("不能启动软键盘"));
	//}

}
