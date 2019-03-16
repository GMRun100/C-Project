
// mfc_use_STL_containersDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "mfc_use_STL_containers.h"
#include "mfc_use_STL_containersDlg.h"
#include "afxdialogex.h"
#include <vector>
#include <array>
#include <algorithm>
#include <numeric>
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
	use_array();

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
//vector属于一种序列式容器：只能在容器末尾高效的增加或删除元素
void CmfcuseSTLcontainersDlg::use_vector()
{
	vector<int> vec;  //vec是vector类的一个对象
	size_t v_size;
	v_size = vec.size();     //vector大小为0
	TRACE("vector size:%d and the vec capacity:%d\n", v_size, vec.capacity());

	//使用初始化列表来初始化向量
	vector<unsigned int> vec_ui { 2u, 3u, 4u };  //u后缀表示无符号整数

	//可以在初始化的时候在指定元素个数
	//参数一：元素个数    参数二：所有元素的初始值
	vector<unsigned int> vec_ui2(20,99u);  


	//vector初始化时，也可以直接拷贝其他的vector
	vector<std::string> vec_s{ "one","two","three","four","five" };
	vector<std::string> vec_copy {std::rbegin(vec_s),std::rend(vec_s) };   //反向拷贝

	//我们也可以使用移动迭代器
	//下面将元素从ves_copy移动到vec_copy2
	//vec_copy的size仍为5，只是都为空字符串，因为元素已经被移动到vec_copy2中
	vector<std::string> vec_copy2{ std::make_move_iterator(vec_copy.begin()),std::make_move_iterator(vec_copy.end()) };  


	vec_ui.front()=20;    //front()函数返回vector第一个元素的引用，所以我们可以直接对第一个元素进行赋值
	vec_ui.back() = 50;   //back()函数返回vector最后一个元素的引用，我们也可以直接进行赋值
	auto p_vec_ui = vec_ui.data();   //data()返回一个指向数组的指针，本例中返回unsigned int*类型


	//向容器中添加元素
	int i;
	for (i = 0; i < 5; i++)
	{
		vec.push_back(i);
	}

	std::string str{ "alleged" };

	//emplace_back函数的参数为是添加到容器中的对象的构造函数所需要的参数。emplace_back() 用它的参数作为构造函数的参数，在容器中生成对象。
	//可以在 emplace_back() 函数中使用尽可能多的参数，只要它们满足对象构造函数的要求
	//下面这个例子中，会调用接收三个参数的 string 构造函数，生成 string 对象，然后把它添加到 words 序列中。构造函数会生成一个从索引 2 开始、包含 str 中三个字符的子串。
	vec_s.emplace_back(str, 2, 3);   //添加的字符串为“leg”



	v_size = vec.size();      //vector大小为5
	TRACE("the extended vector size:%d and the vec capacity:%d\n", v_size,vec.capacity());     //capacity()返回容器当前能够容纳的元素数量

	size_t vec_size;
	vec_size = sizeof(vec);
	TRACE("vec size:%d\n", vec_size);

	size_t vector_size;
	vector_size = sizeof(vector<int>);
	TRACE("vector size:%d\n", vector_size);

	//使用迭代器访问向量中的值
	//可以用迭代器来遍历对象集合中的元素，属于广义指针
	//普通指针指向内存中的一个地址
	//迭代器可以指向容器中的一个位置
	vector<int>::iterator v = vec.begin();  //感觉迭代器有点类似于对象集合的指针
	//while (v!=vec.end())
	//{
	//	TRACE("value of v =%d\n", *v);
	//	v++;
	//}
	
	//更改容器数量
	vec.resize(10);//此处将容器重新分配大小，容器的可容纳数量也会随之增加

	//当我们更改vector的容器大小超过capacity的大小的时候，vector会重新配置内部的存储器，导致和vector元素相关的所有reference、pointers、iterator都会失效。
	//指针失效的原因是因为为了增加容器的容量，vector<T> 容器的元素可能已经被复制或移到了新的内存地址
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
	//前面我们resize(10)容器大小为10，并reserve(15)更改容器容量为15
	//更改容器容量之后，并不是说容器真的开辟出了那么大的内存空间，容器内的对象并没有真实的内存空间(空间是"野"的)
	try
	{
		//使用 [] 操作符访问容器内的对象，很可能出现数组越界的问题
		//tmp = vec[14];   //此时会报vector subscript out of range的错误，会导致程序崩溃
		//推荐使用at方法访问数组元素，当对象不存在时会抛出异常
		tmp=vec.at(14);
	}
	catch (const std::exception& e)
	{
		TRACE("error:%s",e.what());
	}


	//vector插入元素
	//在插入元素之前，最好确认一下向量的容量
	vec_s.reserve(50);   //此处我们先调整一下容量，防止后面向量自动调整容量，会导致指针失效


	//string str2(5, 'A');
	//emplace函数：第一个参数是一个迭代器，它确定了对象生成的位置。对象会被插入到迭代器所指定元素的后面。第一个参数后的参数，都作为插入元素的构造函数的参数传入
	//emplace() 会返回一个指向横入元素的迭代器
	auto vec_s_iter = vec_s.emplace(++std::begin(vec_s),5,'A');

	//++vec_s_iter;
	vec_s_iter=vec_s.emplace(++vec_s_iter, "$$$$");
	vec_s_iter=vec_s.emplace(vec_s_iter, "&&&&");


	//练习使用insert()插入元素
	std::vector<std::string> words{"one","three","eight"};
	words.reserve(30);

	auto iter = std::begin(words);
	iter++;
	//insert()函数会将新元素插入到当前iter所指向的元素的前面
	iter = words.insert(iter, "two");

	//批量插入元素
	std::string more[]{ "five","six","seven" };
	iter = std::end(words);			//end()函数返回一个数组中最后一个元素的下一个位置
	iter--;							//此时iter指向words最后一个元素
	iter = words.insert(iter, std::begin(more), std::end(more));	//返回的迭代器指向插入的第一个元素


	//向vector末尾插入一个元素
	iter = words.insert(std::end(words), "ten");

	//向vector中插入多次单个元素
	//参数二：表示元素插入的次数
	iter = words.insert(std::cend(words) - 1, 2, "nine");

	//可以直接插入初始化列表指定的元素
	iter = words.insert(std::cend(words), { std::string {"twelve"},std::string {"thirteen"} });   

	//insert()函数的第一个参数：需要一个标准的迭代器来指定插入点；它不接受一个反向迭代器
	auto iter_r = std::rbegin(words);  //此时指向反向的第一个元素

	iter_r = std::rend(words);
	iter_r--;    //指向反向的最后一个元素






	//使用vector的风险：当push_back时，有可能会超出vector的capacity，这样就会导致vector重新分配内存空间，导致和vector元素相关的所有reference、pointers、iterator都会失效
	//解决办法：
	//方法一：在创建容器后，第一时间为容器分配足够大的空间，避免重新分配内存：vec.reserve(10000);
	//方法二：该方法是创建容器时，利用构造函数初始化的出足够的空间，vector<int> vec(10000);
	//另外一个需要注意的事项：用[]访问，vector 退化为数组，不会进行越界的判断。此时推荐使用 at()，会先进行越界检查。（这一条明天再验证）
}

//数组容器
void CmfcuseSTLcontainersDlg::use_array()
{
	array<double, 50> data_d{};  //数组元素被初始化为0

	data_d.fill(3.1415926);   //fill函数可以将数组中的所有元素都设定为传入的实参值
	try
	{
		data_d.at(1000) = 1000;    //当索引越界时，会抛出一个std::out_of_rang异常
	}
	catch (const std::exception& e)
	{
		TRACE("error:%s\n", e.what());
	}

	size_t size_a;
	size_a = sizeof(data_d);   //返回长度为8000，一个double类型占8个字节，一共1000个数

	size_t size_d;
	size_d = data_d.size();
	TRACE("The size of the array:%d\n", size_d);

	int i;
	for (i = 0; i < data_d.size();i++)
	{
		data_d.at(i) = i;
	}

	//auto可以根据初始化表达式自动推断该变量的类型
	//用auto声明的变量必须初始化,否则编译器无法判断变量的类型
	auto first= data_d.begin();  //first的类型为iterator

	//当然我们也可以直接定义
	array<double, 50>::iterator first2;
	first2= data_d.begin();

	//通过对比我们可以发现使用auto声明变量，可以有效的简化代码
	//另外一种初始化的方法
	auto end = std::end(data_d);

	//重新对数组元素赋值
	i = 1;
	while (first!=end)
	{
		*first = i;			//对数组元素进行赋值
		i = i + 1;
		first++;			//可以像使用普通指针那样使用迭代器对象
	}

	//在C++中算法和容器类型是独立的
	//而使用迭代器,可以指定容器中的一段元素
	//下面使用iota函数来初始化数组
	array<int, 10> data_i{};  //{}表示被初始化为0
	std::iota(std::begin(data_i), std::end(data_i), 1);   //注意包含#include<numeric> 

	//证明算法和容器类型独立
	array<double, 5> data_d2{};
	std::iota(std::begin(data_d2), std::end(data_d2), 5.0);   //最后一个参数为累加的初始值，值每次自动加1


	//我们也可以使用反向迭代器对某一段数组元素赋初值
	array<double, 5> data_d3{};
	std::iota(std::rbegin(data_d3), std::rend(data_d3), 3.0);

	//以上语句等同于如下
	double tmp_d;
	tmp_d = 3.0;
	array<double, 5> data_d4{};
	auto first_d = data_d4.rbegin();     //迭代器的类型为std::reverse_iterator<std::_Array_iterator<double,5> >
	for (; first_d != data_d4.rend(); first_d++)
	{
		*first_d = tmp_d;
		tmp_d = tmp_d + 1;
	}

	//数组容器比较
	if (data_d2> data_d4)    //容器会被逐元素的进行比较
	{
		TRACE("data_d2> data_d4!\n");
	}
	else
	{
		TRACE("data_d2< data_d4!\n");
	}

	//两个数组容器只要它们存放的是相同类型、相同个数的元素，就可以将一个数组容器赋给另一个
	data_d2 = data_d4;

	//数组容器的元素个数已经固定，无法使用插入迭代器
}