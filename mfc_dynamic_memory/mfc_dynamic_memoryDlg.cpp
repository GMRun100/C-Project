
// mfc_dynamic_memoryDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "mfc_dynamic_memory.h"
#include "mfc_dynamic_memoryDlg.h"
#include "afxdialogex.h"
#include "Test.h"

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


// CmfcdynamicmemoryDlg 对话框



CmfcdynamicmemoryDlg::CmfcdynamicmemoryDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_DYNAMIC_MEMORY_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmfcdynamicmemoryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CmfcdynamicmemoryDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CmfcdynamicmemoryDlg 消息处理程序

BOOL CmfcdynamicmemoryDlg::OnInitDialog()
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

	//练习动态分配内存
	double *pvalue;    //此时vs会提示无法读取内存
	if (!(pvalue = new double))
	{
		TRACE("Error: out of memory.");
		exit(1);
	}

	*pvalue = 123.456;
	TRACE("Value of pvalue:%f\n", *pvalue);

	delete pvalue;   //此时vs会提示无法读取内存

	//一维数组动态分配内存
	//如果希望自己定义的指针始终指向新申请的内存空间，可以将指针定义成指针常量
	char * const m_c = new char[6];    //此时m_c指向内存中的地址为0x00000000 <NULL>
	//m_c = "hello";      //这样写是有问题的，我的本意是想给字符串数组中的每个变量赋值，结果实际是改变了m_c指针指向的地址

	m_c[0] = 'h';
	m_c[1] = 'e';
	m_c[2] = 'l';
	m_c[3] = 'l';
	m_c[4] = 'o';
	m_c[5] = '\0';

	//如果在实际编程过程中不小心将m_c指向了一个常量字符串，此处释放m_c指向的内存地址会导致程序出错	
	delete[] m_c;


	//二维数组动态分配内存
	int **array;//第一维长度为m,第二维长度为n
	int m = 5;
	int n = 4;
	int i, j;
	array = new int *[m];
	
	for (i = 0; i < m; i++)
	{
		array[i] = new int[n];
	}

	//数组赋值
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			array[i][j] = i * j;

	//释放数组
	for (i = 0; i < m; i++)
		delete[] array[i];   

	delete[] array;


	//用malloc申请内存空间和用new申请内存空间的区别
	//首先是用malloc申请内存空间
	//用malloc申请内存空间仅仅是在堆中申请了一片内存空间，并将这片内存空间的类型强制转换为需要的类型
	//但是并没有真正的新建一个对象，因为并没有调用该对象的构造函数。
	Test *m_Test = (Test *)malloc(sizeof(Test));
	m_Test->print();  //输出为垃圾值

	//用new的方式申请内存空间
	//new的方式：在开辟内存空间的同时，相当于新建一个对象，会调用对象的构造函数
	Test *n_Test = new Test;
	n_Test->print();


	//利用动态内存实现链表的功能

	

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

//利用结构体，实现一个不断增长的数据链表
//用户一直输入数据，直到用户输入数据0停止
void CmfcdynamicmemoryDlg::struct_link()
{

}

void CmfcdynamicmemoryDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CmfcdynamicmemoryDlg::OnPaint()
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
HCURSOR CmfcdynamicmemoryDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

