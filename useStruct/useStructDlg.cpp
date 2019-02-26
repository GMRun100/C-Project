
// useStructDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "useStruct.h"
#include "useStructDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框
#include <iostream>

#include <cstring>

using namespace std;
struct Books
{
	char title[50];
	char author[50];
	char subject[100];
	int book_id;
};
//一下为1000的代码部分
typedef unsigned char		__u8;
typedef unsigned short		__u16;
typedef unsigned int		__u32;
typedef unsigned __int64 __u64;
typedef __u8	f8_u8;
typedef __u16 f8_u16;
typedef __u32 f8_u32;
typedef __u64 f8_u64;
typedef __u64 f8_uuid;

struct mem_addr_t {
	f8_u16	addr;
	f8_u8	section;
	f8_u8	padding_0;
}PACKED;

struct var_def_t {
	f8_uuid uuid;//f8_vm
	struct mem_addr_t addr;//f8_binary
};

struct X {
	char a;			// 1 bytes
	char padding1[3];	// 3 bytes
	float b;		// 4 bytes
	int c;			// 4 bytes
	char padding2[4];	// 4 bytes
	double d;		// 8 bytes
	unsigned e;		// 4 bytes
	char padding3[4];	// 4 bytes
};


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


// CuseStructDlg 对话框



CuseStructDlg::CuseStructDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_USESTRUCT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CuseStructDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CuseStructDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CuseStructDlg 消息处理程序

BOOL CuseStructDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	Books book1;
	strcpy_s(book1.title, "C++教程");
	strcpy_s(book1.author, "benliu");
	strcpy_s(book1.subject, "编程语言");
	book1.book_id = 12345;

	//输出book1的信息
	cout << "第一本书的标题" << book1.title << endl;
	cout << "第一本书的作者" << book1.author << endl;
	cout << "第一本书的编程语言" << book1.subject << endl;
	cout << "第一本书的id" << book1.book_id << endl;

	char BinaryAddress[64];
	var_def_t * def;
	for(int i = 0; i < 64; i++)
	{
		BinaryAddress[i] = '\0';
	}
	BinaryAddress[0] = '?';
	BinaryAddress[1] = '?';
	BinaryAddress[2] = '\x10';
	BinaryAddress[3] = '[';
	BinaryAddress[4] = '}';
	BinaryAddress[5] = '?';
	BinaryAddress[6] = '\f';
	BinaryAddress[7] = '?';
	BinaryAddress[8] = '\f';
	BinaryAddress[9] = '\0';
	BinaryAddress[10] = '\x2';


	def = (var_def_t*)BinaryAddress;
	int n_mem_addr_t = sizeof(mem_addr_t);
	int n_var_def_t = sizeof(var_def_t);
	int n_def = sizeof(def);
	int n_BinaryAddress = sizeof(BinaryAddress);
	
	f8_uuid m_64 = def->uuid;
	
	f8_u16	m_addr= def->addr.addr;
	f8_u8	m_section=def->addr.section;
	f8_u8	m_padding_0=def->addr.padding_0;

	int n_X = sizeof(X);



	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CuseStructDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CuseStructDlg::OnPaint()
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
HCURSOR CuseStructDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

