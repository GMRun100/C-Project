
// mfc_use_strTypeDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "mfc_use_strType.h"
#include "mfc_use_strTypeDlg.h"
#include "afxdialogex.h"
#include <iostream>

//string 是STL标准的C++操作类型.使用的话要在文件上面添加以下代码:
#include <string>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

typedef int *pint;    //此处相当于定义了一个int型的指针类型

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


// CmfcusestrTypeDlg 对话框



CmfcusestrTypeDlg::CmfcusestrTypeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_USE_STRTYPE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmfcusestrTypeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CmfcusestrTypeDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CmfcusestrTypeDlg 消息处理程序

BOOL CmfcusestrTypeDlg::OnInitDialog()
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
	practice_using_str();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CmfcusestrTypeDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CmfcusestrTypeDlg::OnPaint()
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
HCURSOR CmfcusestrTypeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CmfcusestrTypeDlg::practice_using_str()
{

	pint m_pint;   //此处练习typedef的使用
	int n;
	n = 10;
	m_pint = &n;
	std::cout << "m_pint =" << *m_pint << "\n";

	use_char();
	use_lpstr();
	use_cstr();

	

}

//功能：char*转换为
void CmfcusestrTypeDlg::use_char()
{
	//char
	char greeting[6] = { 'H','e','l','l','o','\0' };
	char greeting2[] = "hello";  //字符串实际上是使用 null 字符 '\0' 终止的一维字符数组

	//使用sizeof计算字符串数组长度
	int num_greeting;
	num_greeting = sizeof(greeting);
	int num_greeting2;
	num_greeting2 = sizeof(greeting2);   //由于在数组的末尾存储了空字符，所以字符数组的大小比单词 "Hello" 的字符数多一个,输出为6

	//使用strlen计算字符串长度
	int strlen_greeting;
	strlen_greeting = strlen(greeting);		//此处返回的是字符串的长度，并不包括空字符，所以返回5
	int strlen_greeting2;
	strlen_greeting2 = strlen(greeting2);


	//WCHAR：一个字节占有两个字节的
	//官方定义：typedef wchar_t WCHAR;    // wc,   16-bit UNICODE character
	WCHAR wgreeting[6] = { 'H','e','l','l','o','\0' };
	WCHAR wgreeting2[] = L"hello";  //字符串实际上是使用 null 字符 '\0' 终止的一维字符数组

	//使用sizeof计算字符串数组长度
	int num_wgreeting;
	num_wgreeting = sizeof(wgreeting);      //因为是宽字符，所以会占用12个字节
	int num_wgreeting2;
	num_wgreeting2 = sizeof(wgreeting2);   //因为是宽字符，所以会占用12个字节

	int strlen_wgreeting;
	strlen_wgreeting = strlen((LPSTR)wgreeting);		//此处返回的是字符串的长度，并不包括空字符，所以返回5

	//char* 转换为CString
	//方法一
	CString m_str(greeting);  //CString为宽字符串,初始化之后CString会自动将char *中的每个字符变成占两个字节
	WCHAR tmp;
	LPWSTR m_lpwstr=m_str.GetBuffer();  //GetBuffer返回的是一个LPWSTR型指针
	m_lpwstr++;
	tmp = *m_lpwstr;
	//方法二 直接等于即可
	CString m_str2;
	m_str2=greeting;

	//char* 转为string
	//方法一，直接复制即可
	string m_s;				//使用string时，需包含相应的头文件
	m_s = greeting;
	//方法二：利用构造函数
	string m_s2(greeting);   //string属于窄字符   而CString属于宽字符，而且CString是MFC中的字符串操作类

	//char* 转换成LPSTR,LPCSTR
	LPSTR m_lpstr;
	m_lpstr = greeting;   

	LPCSTR m_lpcstr;
	m_lpcstr = greeting;  //char型的数组名就是一个LPCSTR型指针

	//char *转换为WCHAR
	//typedef wchar_t WCHAR;    // wc,   16-bit UNICODE character
	//typedef unsigned short wchar_t;
	//通过官方定义可知WCHAR是一个无符号短整型，占两个字节
	WCHAR *m_wchar;

	size_t m_len = strlen(greeting) + 1;
	size_t converted = 0;
	m_wchar = (WCHAR*)malloc(m_len * sizeof(WCHAR));   //动态内存分配，如果分配成功，则返回指向被分配内存空间的指针
	mbstowcs_s(&converted, m_wchar, m_len, greeting, _TRUNCATE);

	free(m_wchar);


}

//功能：研究LPSTR转换为其他类型的用法
void CmfcusestrTypeDlg::use_lpstr()
{
	//char
	char greeting[6] = { 'H','e','l','l','o','\0' };
	char greeting2[] = "hello";  //字符串实际上是使用 null 字符 '\0' 终止的一维字符数组
	//LPSTR:长指针字符串，L代表长，P代表指针，STR表示字符串
	//我们通过查找官方的定义：typedef _Null_terminated_ CHAR *NPSTR, *LPSTR, *PSTR; 
	//通过官方的定义可以LPSTR为以NULL为终止的字符串指针
	LPSTR m_LPSTR;
	int len_LPSTR;
	len_LPSTR = sizeof(m_LPSTR);  //在x86平台下，指针长度为4个字节，在x64平台下，指针长度为8个字节
	m_LPSTR = greeting;
	std::cout << "m_LPSTR =" << *m_LPSTR << "\n";   //此处m_LPSTR指向字符串的首地址，所以只打印H

	//LPSTR 转化为cstring 
	CString str(m_LPSTR);    //在VS2017中CString类型为宽字符型
	CString str2("WORLD");

	//LPSTR转换成LPCSTR
	//LPSTR m_LPSTR2 = "Test";
	LPCSTR m_lpcstr = m_LPSTR;   //typedef _Null_terminated_ CONST CHAR *LPCSTR, *PCSTR;

	//LPSTR和LPCSTR区别：定义的指针可以变化，内容
	*m_LPSTR = 's';
	//*m_lpcstr = 'h';  //此句话会报错，LPCSTR定义的指针可以变化，内容不可修改
	m_lpcstr++;

	//LPSTR转换成LPWSTR
	//typedef _Null_terminated_ WCHAR *NWPSTR, *LPWSTR, *PWSTR;
	//LPWSTR为WCHAR的指针
	LPWSTR m_lpwstr = (LPWSTR)m_LPSTR;   //此时m_LPSTR表示"sello"
	int len_lpwstr = sizeof(m_lpwstr);  //x86平台，指针都是四个字节
	int len_lpstr = sizeof(m_LPSTR);	//x86平台，指针都是四个字节
	WCHAR m_wchar;
	//这里我们发现将窄字符串直接付给宽字符串是有问题的，因为一个宽字符对应两个窄字符
	// 通过监视, 我们发现m_wchar的值为0x6573 '敳'，其中0x73正好是ascii码表中的‘s’, 0x65正好是ascii码表中的‘e’
	m_wchar = *m_lpwstr;

	//LPSTR转换成LPCWSTR
	LPCWSTR m_lpcwstr = (LPCWSTR)m_LPSTR;

	//const定义指针时的一些区别
	WCHAR const *m_str_LPWSTR2;   //定义相当于LPCWSTR：typedef _Null_terminated_ CONST WCHAR *LPCWSTR  即指针可以修改，指针的内容不能修改
	m_str_LPWSTR2 = (LPCWSTR)str;
	m_str_LPWSTR2++;
	//*m_str_LPWSTR = s;
	char temp;
	temp = *m_str_LPWSTR2;   //宽字符串指针只需要移动一次即可

	WCHAR* const m_str_LPWSTR3 = (LPWSTR)(LPCWSTR)str2;    //指针是常量，指针不可以变化指针指向的内容可以变化。
	//m_str_LPWSTR3 = (LPCWSTR)str2;
	*m_str_LPWSTR3 = 's';
	temp = *m_str_LPWSTR3;

	//PSTR:窄指针字符串
	PSTR m_PSTR;
	int len_PSTR;
	len_PSTR = sizeof(m_PSTR);	//在x86平台下，指针长度为4个字节，在x64平台下，指针长度为8个字节，没感觉出跟LPSTR有啥区别
	m_PSTR = greeting2;
	std::cout << "m_PSTR =" << *m_PSTR << "\n";

}

void CmfcusestrTypeDlg::use_cstr()
{
	CString str("Hello");    //在VS2017中CString类型为宽字符型
	CString str2("WORLD");

	//CString 转化为LPSTR
	LPSTR m_str_LPSTR;
	//LPCWSTR:宽字符串指针
	m_str_LPSTR = (LPSTR)(LPCWSTR)str;
	char temp;
	m_str_LPSTR++;
	m_str_LPSTR++;
	temp = *m_str_LPSTR;    //因为m_str_LPSTR是一个窄字符串指针，所以一次只能移动一个字节，而CString一个字符占两个字节，所以需要移动两次
	//下面试一下宽字符串指针
	LPCWSTR m_str_LPWSTR;    //
	m_str_LPWSTR = (LPCWSTR)str;
	m_str_LPWSTR++;
	//*m_str_LPWSTR = s;
	temp = *m_str_LPWSTR;   //宽字符串指针只需要移动一次即可

}


