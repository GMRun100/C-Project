
// mfc_use_referenceDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "mfc_use_reference.h"
#include "mfc_use_referenceDlg.h"
#include "afxdialogex.h"

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


// CmfcusereferenceDlg 对话框



CmfcusereferenceDlg::CmfcusereferenceDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_USE_REFERENCE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmfcusereferenceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CmfcusereferenceDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CmfcusereferenceDlg 消息处理程序

BOOL CmfcusereferenceDlg::OnInitDialog()
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

	//学习引用的一些用法
	int i;
	i = 10;

	//变量i的引用
	//引用必须在创建的时候就要初始化,而指针可以在任意的时候初始化
	//引用就相当于是给变量起了一个别名
	int& i_r=i;   //i_r指向了变量i的内存地址

	//我们可以查看地址
	TRACE("the addr of i:%d\n", &i);
	TRACE("the addr of i_r:%d\n", &i_r);

	i = 30;
	int i2 = 0;
	//i_r = &i2;     //错误：一旦引用被初始化为一个对象，就不能被指向到另一个对象。指针可以在任何时候指向另外一个对象。
	i_r = 25;		 //i的值也会发生变化

	int x1 = 100;
	int y1 = 200;
	TRACE("Before swap x1=%d y1=%d\n",x1,y1);

	//因为形参是引用，所以形参会指向实参的地址单元，这样在函数内部对形参的修改，就会改变实参的值
	
	swap(x1, y1);
	TRACE("After swap x1=%d y1=%d\n", x1, y1);

	//练习引用作为返回值
	setdouble(1) = 30.0;   

	setint() = 5.0;

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CmfcusereferenceDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CmfcusereferenceDlg::OnPaint()
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
HCURSOR CmfcusereferenceDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CmfcusereferenceDlg::swap(int& x, int& y)
{
	int tmp;
	tmp = x;
	x = y;
	y = tmp;
}

double& CmfcusereferenceDlg::setdouble(int i)
{
	return d[i];
}

int& CmfcusereferenceDlg::setint()
{
	return s_i;
}
