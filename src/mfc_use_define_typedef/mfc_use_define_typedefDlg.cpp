
// mfc_use_define_typedefDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "mfc_use_define_typedef.h"
#include "mfc_use_define_typedefDlg.h"
#include "afxdialogex.h"
#include <string>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


//学习使用宏定义函数
//以下是宏定义的交换函数
//宏定义中允许包含两行以上命令的情形，此时必须在最右边加上”\”且该行”\”后不能再有任何字符，连注释部分都不能有，下面的每行最后的一定要是”\”,”\”后面加一个空格都会报错，更不能跟注释。
//#define swap(x,y)\
//	x=x+y;\
//	y=x-y;\
//	x = x - y;\


//另外一种方式是可以使用模板
template <typename T>
inline void swapT(T &a, T &b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}

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


// CmfcusedefinetypedefDlg 对话框



CmfcusedefinetypedefDlg::CmfcusedefinetypedefDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_USE_DEFINE_TYPEDEF_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmfcusedefinetypedefDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CmfcusedefinetypedefDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CmfcusedefinetypedefDlg 消息处理程序

BOOL CmfcusedefinetypedefDlg::OnInitDialog()
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
	//使用宏定义函数
	//宏定义函数的最大好处是可以不用关心变量的类型

	call_swap();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CmfcusedefinetypedefDlg::call_swap()
{

#define swap(x,y)\
	x=x+y;\
	y=x-y;\
	x = x - y;\

	int x = 10;
	int y = 50;
	TRACE("Before swap:x=%d,y=%d\n", x, y);
	swap(x, y);
	TRACE("After swap:x=%d,y=%d\n", x, y);

	float f1 = 12.345;
	float f2 = 45.789;
	TRACE("Before swap:f1=%f,f2=%f\n", f1, f2);
	swap(f1, f2);
	TRACE("After swap:f1=%f,f2=%f\n", f1, f2);
	//练习使用模板函数达到和宏定义函数一样的效果
	TRACE("Before swapT:x=%d,y=%d\n", x, y);
	swapT(x, y);
	TRACE("After swapT:x=%d,y=%d\n", x, y);

	TRACE("Before swapT:f1=%f,f2=%f\n", f1, f2);
	swapT(f1, f2);
	TRACE("After swapT:f1=%f,f2=%f\n", f1, f2);
}

void CmfcusedefinetypedefDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CmfcusedefinetypedefDlg::OnPaint()
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
HCURSOR CmfcusedefinetypedefDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

