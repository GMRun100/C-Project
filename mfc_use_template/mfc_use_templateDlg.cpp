
// mfc_use_templateDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "mfc_use_template.h"
#include "mfc_use_templateDlg.h"
#include "afxdialogex.h"
#include <iostream>
#include <string>
#include"Stack.h"
#include"Compare.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace std;

//学习模板的使用方法
//定义一个普通的模板函数
template <typename T>
inline T const& Max(T const& a, T const& b)
{
	return a < b ? b : a;
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


// CmfcusetemplateDlg 对话框



CmfcusetemplateDlg::CmfcusetemplateDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_USE_TEMPLATE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmfcusetemplateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CmfcusetemplateDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CmfcusetemplateDlg 消息处理程序

BOOL CmfcusetemplateDlg::OnInitDialog()
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

	//调用函数模板
	int i = 30;
	int j = 50;
	TRACE("MAX(i,j):%d\n", Max(i, j));

	double f1 = 12.45;
	double f2 = 34.789;
	TRACE("MAX(f1,f2):%f\n", Max(f1, f2));

	string str1 = "Hello";
	string str2 = "World";
	string str3;
	str3 = Max(str1, str2);
	//在c语言的标准I/O输入输出系统中，%s，表示输出字符串中的字符直至字符串中的空字符（字符串以'\0‘结尾，这个'\0'即空字符）
	//所以替代%s的应为char * 型指针
	TRACE("MAX(s1,s2):%s\n", Max(str1, str2).c_str());   //.c_str()函数返回一个const char*型字符常量指针



	//练习使用模板类
	try
	{
		Stack<int>		intStack;
		Stack<string>	stringStack;

		//操作int类型的栈
		intStack.push(7);
		TRACE("intStack:%d\n", intStack.top());

		//操作string 类型的栈
		stringStack.push("hello");
		TRACE("stringStack:%s\n", stringStack.top().c_str());
		stringStack.pop();
		//stringStack.pop();
		
	}
	catch (exception const& ex)
	{
		cerr << "Exception:" << ex.what() << endl;
		return -1;
	}

	//练习一下自己写的类模板
	Compare<int> c_i;
	TRACE("Compare int: %d\n", c_i.compareAandB(10, 50));

	Compare<double> c_f;
	TRACE("Compare double: %f\n", c_f.compareAandB(10.134, 50.789));

	Compare<string> c_s;
	str1 = "hello";
	str2 = "World";
	TRACE("Compare string: %s\n", c_s.compareAandB(str1, str2).c_str());


	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CmfcusetemplateDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CmfcusetemplateDlg::OnPaint()
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
HCURSOR CmfcusetemplateDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

