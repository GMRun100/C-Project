
// mfc_class_composition_inheritanceDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "mfc_class_composition_inheritance.h"
#include "mfc_class_composition_inheritanceDlg.h"
#include "afxdialogex.h"
#include "Composition.h"
#include "inheritance.h"
#include "InheritanceAndComposition.h"
#include "order.h"
#include "order2.h"
#include "CEmployeeAndManager.h"
#include "CVirtualFunction.h"

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


// CmfcclasscompositioninheritanceDlg 对话框



CmfcclasscompositioninheritanceDlg::CmfcclasscompositioninheritanceDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_CLASS_COMPOSITION_INHERITANCE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmfcclasscompositioninheritanceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CmfcclasscompositioninheritanceDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CmfcclasscompositioninheritanceDlg 消息处理程序

BOOL CmfcclasscompositioninheritanceDlg::OnInitDialog()
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


	//simple practice class' composition
	Y y;
	y.f(55);
	y.permute();

	//simple practice class inheritance
	//view the memory size of the class
	// the size of the memory occupied by the class is determined by the member variables
	size_t s_x = sizeof(X);     //X has variable int x, so X occupies 4 bytes  
	size_t s_y2 = sizeof(Y2);   //Y occupies 8 bytes. Y contains all data members and member functions of X

	Y2 m_y2;    //this will call construct function of Y2 and X
	m_y2.set(45);
	int r_y2=m_y2.read();    //here will call the member function of the base class
	r_y2=m_y2.change();


	//practice composition and inheritance
	//C is inherited from B,C has every member of B,just like C has a member of B. 
	C *c=new C(55);
	delete c;

	//
	Derived2 *d2=new Derived2(3);
	delete d2;

	//测试父类对象子类实例化
	Employee *m_manager = new Manager();
	//父类声明子类实例化产生的对象使用的是子类从父类继承的方法和属性
	m_manager->getType();      //此处调用的是子类的方法
	//此处我们无法使用 Manager的money成员函数，因为父类句柄指向子类对象空间，所以使用的属性和方法都是子类对象所有的。而因为是父类的句柄指向的只能是父类所拥有的属性和方法，所以指向的属性和方法实则又必须是是从父类继承而来的。

	delete m_manager;



	//第一次伤
	Base *m_base = new M1();    //会依次调用每个成员函数
	m_base->print();			//output:M1 print
	m_base->readOn();			//output:Derived2
	m_base->debug();			//output:M1 debug
	m_base->writeOn();			//output:Derived1 writeOn
	delete m_base;              //按着调用构造函数的顺序反向调用析构函数

	//测试继承虚函数
	v_base m_v_base;
	Fun pfun = NULL;
	TRACE("虚函数表地址：%d\n", (int *)(&m_v_base));
	TRACE("虚函数表--第一个虚函数地址：%d\n", (int*)*(int*)(&m_v_base));

	//指针指向第一个虚函数
	pfun = (Fun)*((int*)*(int*)(&m_v_base));
	pfun();		//v_base::g()
	pfun = (Fun)*((int*)*(int*)(&m_v_base)+1);
	pfun();		//v_base::f()
	pfun = (Fun)*((int*)*(int*)(&m_v_base) + 2);
	pfun();		//v_base::h()

	//一般继承，无虚函数覆盖情况
	v_Drived m_v_drived;
	//一般继承：显示基类虚函数
	//虚函数按照其声明顺序放于表中
	//父类的虚函数在子类的虚函数前面
	pfun = (Fun)*((int*)*(int*)(&m_v_drived));
	pfun();		//v_base::g()
	pfun = (Fun)*((int*)*(int*)(&m_v_drived) + 1);
	pfun();		//v_base::f()
	pfun = (Fun)*((int*)*(int*)(&m_v_drived) + 2);
	pfun();		//v_base::h()
	pfun = (Fun)*((int*)*(int*)(&m_v_drived)+3);
	pfun();		//v_Drived::g()
	pfun = (Fun)*((int*)*(int*)(&m_v_drived) + 4);
	pfun();		//v_Drived::f()
	pfun = (Fun)*((int*)*(int*)(&m_v_drived) + 5);
	pfun();		//v_Drived::h()
	
	//一般继承，有虚函数覆盖的情况
	v_base *m_Drived2 = new v_Drived2();
	m_Drived2->g();   //调用的为子类的成员函数

	pfun = (Fun)*((int*)*(int*)m_Drived2);
	pfun();		//v_Drived2::g()
	pfun = (Fun)*((int*)*(int*)m_Drived2 + 1);
	pfun();		//v_base::f()
	pfun = (Fun)*((int*)*(int*)m_Drived2 + 2);
	pfun();		//v_base::h()
	pfun = (Fun)*((int*)*(int*)m_Drived2 + 3);
	pfun();		//v_Drived2::f2()
	pfun = (Fun)*((int*)*(int*)m_Drived2 + 4);
	pfun();		//v_Drived2::h2()





	

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CmfcclasscompositioninheritanceDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CmfcclasscompositioninheritanceDlg::OnPaint()
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
HCURSOR CmfcclasscompositioninheritanceDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

