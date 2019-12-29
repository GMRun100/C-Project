
// mfc_exception_handlingDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "mfc_exception_handling.h"
#include "mfc_exception_handlingDlg.h"
#include "afxdialogex.h"
#include <exception>
#include "MyException.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


//练习抛出异常
double division(int a, int b)
{
	if (b == 0)
	{
		throw "Division by zero condition!!!!";			 //抛出一个异常,由catch去捕获
	}

	return (a/b);
}

//也可以通过结构体继承标准异常
struct MyException2:public exception
{
	//const throw() 表示what函数可以抛出异常的类型，类型说明放到 () 里，这里面没有类型，就是声明这个函数不抛出异常，通常函数不写后面的就表示函数可以抛出任何类型的异常。
	const char * what() const throw()
	{
		return "MyException2:C++ Exception";
	}
};
//调用自己定义的异常类
MyException myex;

//举例一个函数可以抛出不同的异常
void fun(int n) throw (int, MyException, MyException2)
{
	if (n==1)
	{
		throw 1;
	}
	else if (n==2)
	{
		throw myex;
	}
	else if (n == 3)
	{
		throw MyException2();
	}
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


// CmfcexceptionhandlingDlg 对话框



CmfcexceptionhandlingDlg::CmfcexceptionhandlingDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_EXCEPTION_HANDLING_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmfcexceptionhandlingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CmfcexceptionhandlingDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CmfcexceptionhandlingDlg 消息处理程序

BOOL CmfcexceptionhandlingDlg::OnInitDialog()
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

	//练习抛出异常
	int x = 50;
	int y = 0;
	double z = 0;
	try
	{
		z = division(x, y);
		TRACE("z=%f\n", z);
	}
	//在前面的代码中，我们抛出了一个类型为const char* 的异常，当捕获该异常时，我们同样在代码块中使用const char* 类型来捕获异常
	catch (const char* msg)     
	{
		TRACE("error:%s\n", msg);   //我们
	}


	try
	{
		//throw 1;
		throw "hello error";
	}
	catch (char *str)
	{
		TRACE("%s\n", str);
	}
	catch (int i)
	{
		TRACE("%d",i);
	}



	try
	{
		if (true)
		{
			throw myex;
		}
	}
	catch (exception& e)
	{
		TRACE("error:%s\n", e.what());
	}


	//调用标准异常类
	try
	{
		//int* myarray = new int[100000000];
		//int x = 1;
		//int y = 0;
		//double z;
		//z = x / y;
	}
	catch (const std::exception& e)
	{
		TRACE("Standard exception:%s", e.what());
	}

	//调用自定义的结构体异常
	try
	{
		throw MyException2();
	}
	catch (MyException2& e)
	{
		TRACE("MyException caught:%s\n",e.what());
	}
	catch (std::exception& e)
	{
		//处理其他错误
	}

	//测试某个函数可以抛出不同的异常
	try
	{
		//当n取不同的值时，抛出不同的异常
		//fun(1);
		//fun(2);
		fun(3);
	}
	catch (int n)
	{
		TRACE("catch int............\n");
		TRACE("n=%d\n", n);
	}
	catch (MyException &e)
	{
		TRACE("catch MyException............\n");
		TRACE("MyException:%s\n", e.what());
	}
	catch (MyException2 &e)
	{
		TRACE("catch MyException2............\n");
		TRACE("MyException2:%s\n", e.what());
	}

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CmfcexceptionhandlingDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CmfcexceptionhandlingDlg::OnPaint()
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
HCURSOR CmfcexceptionhandlingDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

