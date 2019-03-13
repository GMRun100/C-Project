
// mfc_use_STL_containersDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "mfc_use_STL_containers.h"
#include "mfc_use_STL_containersDlg.h"
#include "afxdialogex.h"
#include <vector>
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


// CmfcuseSTLcontainersDlg 对话框



CmfcuseSTLcontainersDlg::CmfcuseSTLcontainersDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_USE_STL_CONTAINERS_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmfcuseSTLcontainersDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CmfcuseSTLcontainersDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CmfcuseSTLcontainersDlg 消息处理程序

BOOL CmfcuseSTLcontainersDlg::OnInitDialog()
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

	use_vector();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CmfcuseSTLcontainersDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CmfcuseSTLcontainersDlg::OnPaint()
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
HCURSOR CmfcuseSTLcontainersDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//练习使用STL中的vector
//STL提供了功能强大的模板类
void CmfcuseSTLcontainersDlg::use_vector()
{
	vector<int> vec;  //vec是vector类的一个对象
	size_t v_size;
	v_size = vec.size();     //vector大小为0
	TRACE("vector size:%d and the vec capacity:%d\n", v_size, vec.capacity());
	int i;
	for (i = 0; i < 5; i++)
	{
		vec.push_back(i);
	}

	v_size = vec.size();      //vector大小为5
	TRACE("the extended vector size:%d and the vec capacity:%d\n", v_size,vec.capacity());     //capacity()返回容器当前能够容纳的元素数量

	size_t vec_size;
	vec_size = sizeof(vec);
	TRACE("vec size:%d\n", vec_size);

	size_t vector_size;
	vector_size = sizeof(vector<int>);
	TRACE("vector size:%d\n", vector_size);






	//使用迭代器访问向量中的值
	//可以用迭代器来遍历对象集合中的元素
	vector<int>::iterator v = vec.begin();  //感觉迭代器有点类似于对象集合的指针
	//while (v!=vec.end())
	//{
	//	TRACE("value of v =%d\n", *v);
	//	v++;
	//}
	
	//更改容器数量
	vec.resize(10);//此处将容器重新分配大小，容器的可容纳数量也会随之增加

	//当我们更改vector的容器大小超过capacity的大小的时候，vector会重新配置内部的存储器，导致和vector元素相关的所有reference、pointers、iterator都会失效。
	//内存重新分配以后，需要重新获取指针，避免指针失效。
	v = vec.begin();
	TRACE("the extended vector size:%d and the vec capacity:%d\n", vec.size(), vec.capacity());     

	//更改容器容量
	vec.reserve(15);    //如果为了避免迭代器
	TRACE("the extended vector size:%d and the vec capacity:%d\n", vec.size(), vec.capacity());
	//更改容器容量之后也需要重新配置迭代器指针地址
	v = vec.begin();
	
	//直接访问向量中的值
	for (i = 0; i < vec.size(); i++)
	{
		TRACE("the value of vec[%d]=%d\n", i, vec[i]);
	}

	while (v != vec.end())
	{
		TRACE("value of v =%d\n", *v);
		v++;
	}


	int tmp;

	try
	{
		tmp = vec[14];
		//tmp=vec.at(14);
	}
	catch (const std::exception& e)
	{
		TRACE("error:%s",e.what());
	}

	//使用vector的风险：当push_back时，有可能会超出vector的capacity，这样就会导致vector重新分配内存空间，导致和vector元素相关的所有reference、pointers、iterator都会失效
	//解决办法：
	//方法一：在创建容器后，第一时间为容器分配足够大的空间，避免重新分配内存：vec.reserve(10000);
	//方法二：该方法是创建容器时，利用构造函数初始化的出足够的空间，vector<int> vec(10000);
	//另外一个需要注意的事项：用[]访问，vector 退化为数组，不会进行越界的判断。此时推荐使用 at()，会先进行越界检查。（这一条明天再验证）
}
