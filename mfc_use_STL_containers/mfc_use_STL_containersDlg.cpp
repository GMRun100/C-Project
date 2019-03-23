
// mfc_use_STL_containersDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "mfc_use_STL_containers.h"
#include "mfc_use_STL_containersDlg.h"
#include "afxdialogex.h"
#include <vector>
#include <array>
#include <deque>
#include <list>
#include <algorithm>
#include <numeric>
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//重载operator
class my_greater
{
public:
	my_greater();
	~my_greater();

	bool operator() (std::string s1,std::string s2)
	{
		if(s1[0]==s2[0])
		{
			return s1.length() > s2.length();
		}
		else
		{
			return s1 > s2;
		}
	}

private:

};

my_greater::my_greater()
{
}

my_greater::~my_greater()
{
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
	use_deque();
	use_list();

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

	//通过find函数查找指定对象的最后一个元素，并在其后面插入一个新的元素
	std::vector<std::string> str_s{ "one","two","one","three" };
	//在向量中反向查找one这个字符串
	iter_r = std::find(std::rbegin(str_s),std::rend(str_s),"one");   //因为是反向查找，所以会返回一个反向迭代器

	//iter= str_s.insert(iter_r, "six");   //error:vector 的成员函数 insert()，需要一个标准的迭代器来指定插入点；它不接受一个反向迭代器——这无法通过编译

	//成员函数 base() 可以得到一个标准迭代器，从序列反方向来看，它指向 riter 前的一个位置，也是朝向序列结束的方向
	iter=str_s.insert(iter_r.base(), "five");   //此处返回一个正向迭代器



	//vector删除元素
	//只能通过容器的成员函数来删除元素
	//删除所有元素
	std::vector<int> data_i(100, 99);
	data_i.clear();
	//删除之后，vector的size会变为0，但是容量capasity仍为100

	//删除容器的最后一个元素
	std::vector<int> data_i2{1,2,3,4,5,6,7,8,9};
	data_i2.pop_back();


	//如果不在意元素在容器内部存储的顺序，都可以通过pop_back函数删除容器内部的任何一个元素
	//首先通过swap函数将需要删除的元素交换到容器末尾
	//假设删除容器中的第二个元素
	auto begin = std::begin(data_i2) + 1;
	auto end = std::end(data_i2) - 1;
	//std::swap(begin, end);			//这样的写法有问题只是将两个迭代器做了交换
	std::swap(data_i2.at(1), data_i2.at(data_i2.size()-1));
	data_i2.pop_back();

	//vector中也有成员函数swap,用来交换两个 vector 容器中的元素
	std::vector<int> data_i3{ 10,20,30,40,50,60,70,80,90};
	data_i2.swap(data_i3);  //两个vector互相交换了各自的元素


	//删除一个容器中的一个或多个元素
	auto i3_begin = data_i3.begin();
	i3_begin++;
	i3_begin=data_i3.erase(i3_begin);   //会返回一个迭代器，它指向被删除元素后的一个元素


	//删除容器中的多个元素
	auto i3_end = data_i3.end();
	i3_end= i3_end-2;
	//erase会删除第一个迭代器指向的元素和第二个迭代器指向的元素之间的元素（但是并不包括第二个迭代器指向的元素）
	i3_begin = data_i3.erase(i3_begin,i3_end);

	//删除容器中指定内容的元素
	std::vector<std::string> words_2{ "one","none","some","all","none","most","many" };
	auto iter_words_2 = std::remove(std::begin(words_2), std::end(words_2), "none");   //iter_words_2指向最后一个元素之后的位置

	//经过remove函数后,其他元素会顶替被删除元素的位置，多出来的位置会在最后用空字符串进行替代，所以vector的大小并没有发生变化
	//我们可以将空字符串删除
	iter_words_2 = words_2.erase(iter_words_2, std::end(words_2));    //此时words_2便不包括空字符串





	//使用vector的风险：当push_back时，有可能会超出vector的capacity，这样就会导致vector重新分配内存空间，导致和vector元素相关的所有reference、pointers、iterator都会失效
	//解决办法：
	//方法一：在创建容器后，第一时间为容器分配足够大的空间，避免重新分配内存：vec.reserve(10000);
	//方法二：该方法是创建容器时，利用构造函数初始化的出足够的空间，vector<int> vec(10000);
	//另外一个需要注意的事项：用[]访问，vector 退化为数组，不会进行越界的判断。此时推荐使用 at()，会先进行越界检查。

	//学习总结
	//1.只能通过容器的成员函数来操作容器：比如添加、插入、删除元素
	//2.迭代器属于容器中元素指针，可以遍历容器中的元素或者指向容器中的任何一个元素，通过两个迭代器配合使用，就可以指向容器中的一段元素，为后续的算法操作（比如容器拷贝，排序等等）提供方便
	//3.可以通过容器的成员函数返回指向不同位置的不同类型的迭代器
}

//学习双端队列
//vector只能在尾部高效的插入或删除元素
//deque可以在头部和尾部高效的插入或删除元素：比如像处理先入先出事务
//deque的大小和容量总是相等,所以在deque中只有size()成员函数
void CmfcuseSTLcontainersDlg::use_deque()
{
	//生成容器
	std::deque<int> a_deque;   //由于未指定大小，因此容器大小为0

	//指定容器大小
	std::deque<int> my_deque(10);   //容器大小为10

	//通过初始化列表生成容器
	std::deque<std::string> words{ "one","none","some","all","none","most","many" };

	//deque容器的拷贝构造函数
	std::deque<std::string> words_copy{ words };

	//只拷贝某一部分元素
	std::deque<std::string> words_part{ std::begin(words),std::begin(words) + 5 };


	//获取容器中的元素
	try
	{
		auto tmp = words.at(100);     //使用at成员函数可以进行边界检查
	}
	catch (const std::exception& e)
	{
		TRACE("error:%s", e.what());     //输出：error:invalid deque<T> subscript 
	}


	//deque添加和删除元素
	//deque：添加元素
	std::deque<int> numbers{ 2,3,4 };

	numbers.push_front(11);
	numbers.push_back(12);
	auto first_number = numbers.front();   //返回第一个元素
	//deque:删除元素
	numbers.pop_front();
	numbers.pop_back();

	//deque插入元素
	//insert用法与vector类似
	auto iter=numbers.insert(std::end(numbers),13);  //返回指向插入元素的迭代器

	iter = std::find(std::begin(numbers), std::end(numbers), 100);    //如果未查找到，返回的迭代器指向参数二所指向的元素的下一个元素
	//iter--;
	iter = std::find(std::begin(numbers), std::end(numbers), 2);   //指向查找到的第一个元素
	iter=numbers.insert(iter,15);  //插入到所指向的元素的前面

	//插入多个元素
	//批量插入其他deque数组
	std::deque<int> numbers_tmp{ 10,20,30 };
	iter = numbers.insert(std::begin(numbers),std::begin(numbers_tmp), std::end(numbers_tmp));   //返回指向插入的第一个元素的迭代器
	//利用初始化列表插入多个元素
	iter = numbers.insert(iter, { 100,200,300 });

	//替换元素
	std::deque<std::string> words2{ "one","two","three","four" };
	//auto init_list = { "seven","eight","nine" };   //这样写init_list的类型为char const*类型
	auto init_list = { std::string{ "seven"},std::string{"eight"},std::string{"nine"} };
	words2.assign(init_list);   //words中的元素被整体替换

	//替换元素：直接通过初始化列表替换
	words2.assign({ "11","12","13" });

	//替换元素：通过迭代器替换
	std::vector<std::string> wordset{ "this","that","these","those" };
	words2.assign(std::begin(wordset) + 1, std::end(wordset));   //替换范围：参数一指向的元素，参数二指向的元素的前一个元素之间的元素

	//替换元素：使用重复的对象
	//参数一：替换的个数  参数二：替换的元素
	words2.assign(8, "8");

	//替换元素：通过重载赋值运算符
	words2 = { "12","13","14" };


	//如果不提前给deque分配好空间的话，deque的size是实时随着元素的增减而变化的
}

//list容器
//list属于双向链表
//优势：在序列已知的任何位置插入或删除元素
//劣势：由于list属于链表，因此无法索引元素
void CmfcuseSTLcontainersDlg::use_list()
{
	//创建list容器
	//创建一个空list容器
	std::list<std::string> words;

	//创建具有给定数量的list容器
	std::list<std::double_t> value(50,3.1415926);    //注意不能使用{50,3.1415926}，否则将仅包含两个元素

	//创建：利用拷贝构造函数
	std::list<double> values_copy{ value };     //相当于用value初始化values_copy

	//创建：利用迭代器
	std::list<double> samples {++std::begin(value),--std::end(value)};   //因为list的begin和end返回的是双向迭代器，因此无法用加减整数的办法移动迭代器，我觉得是无法判断迭代器的移动方向导致

	//增加元素
	std::list<std::string> names{ "benliu","guooujie","weiyongxin" };
	names.push_front("yuanyuan");
	names.push_back("yangzengxiao");

	//插入元素
	std::list<int> data(10, 55);

	data.insert(++std::begin(data), 66);

	//插入元素：在指定位置插入几个相同的元素
	auto iter = std::begin(data);
	//移动迭代器：不能直接使用+号或者－号
	std::advance(iter, 9);  //从当前指向的位置移动9个元素
	data.insert(iter, 3, 88);

	//插入元素：将其他容器的元素插入到当前容器中
	auto data_final = --(--std::end(data));

	std::vector<int> numbers(10, 5);
	data.insert(--(--std::end(data)), cbegin(numbers), cend(numbers));
	//我们发现再插入完元素后指向list容器倒数第二个元素的迭代器并没有失效，应为倒数第二个元素并没有发生移动
	//list 元素的迭代器只会在它所指向的元素被删除时才会失效

	//在list容器中直接构造元素
	std::list<std::string> names2{ "benliu","guooujie","weiyongxin" };
	names2.emplace_back("yuan");
	std::string tmp_name("zengxiao");
	names2.emplace_back(std::move(tmp_name));    //std::move() 函数将 tmp_name 的右值引用传入 emplace_back() 函数。这个操作执行后，tmp_name 变为空，因为它的内容已经被移到 list 中
	names2.emplace_front("hualong");
	names2.emplace(++std::begin(names2), "huahua");

	
	//list删除元素
	std::list<int> numbers2{ 2,5,2,3,6,7,8,2,9 };
	//删除指定位置的元素
	auto iter2=numbers2.erase(--(--std::end(numbers2)));    //删除倒数第二个元素,返回指向删除元素的后一个元素的指针

	//删除两个迭代器指向之间的元素
	iter2 = numbers2.erase(++(std::begin(numbers2)), --(std::end(numbers2)));  //只剩最后一个元素和第一个元素

	//删除指定的元素
	std::list<int> numbers3{ 2,5,2,3,6,7,8,2,9 };
	numbers3.remove(2);

	//其他容器没有remove成员函数
	//deque删除指定的元素
	std::deque<int> numbers3_deque{ 2,5,2,3,6,7,8,2,9 };
	//std::remove返回一个迭代器，该迭代器指向未移去的最后一个元素的下一个位置
	auto iter2_deque = std::remove(begin(numbers3_deque), end(numbers3_deque), 2);     //此时容器的大小并没有发生变化，被删除元素的位置会由后面的元素来顶替，
	iter2_deque = numbers3_deque.erase(iter2_deque, end(numbers3_deque));      //将多余的元素删除

	//remove_if:参数是一个 lambda 表达式，但也可以是一个函数对象。
	std::list<int> numbers4{ 2,5,2,3,6,7,8,2,9 };
	numbers4.remove_if([](int n) {return n % 2 == 0; });     


	//移除连续的重复元素
	std::list<std::string> words2{ "one","two","two" ,"two" ,"two" ,"three","two" ,"two" ,"four","four" };
	words2.unique();   //这里移除的是连续的重复元素，并不是移除所有的重复元素
	//list当中如果所指向的元素没有被删除，则其迭代器不会失效


	//list排序
	std::list<std::string> names3{ "benliu","guooujie","weiyongxin" };
	//排序：sort()使用operator()函数来进行比较，great()函数重载了operator()成员函数
	names3.sort(std::greater<std::string>());     //名字按降序进行排列

	//排序:自定义类重载operator函数
	std::list<std::string> names4{ "benliu","guooujie","weiyongxin" ,"yuan","yang","ping","yangzengxiao"};
	names4.sort(my_greater());

	//排序：使用lambda表达式
	std::list<std::string> names5{ "benliu","guooujie","weiyongxin" ,"yuan","yang","ping","yangzengxiao" };
	names5.sort([](const std::string s1, std::string s2)
	{
		if (s1[0] == s2[0])
		{
			return s1.length() > s2.length();
		}
		else
		{
			return s1 > s2;
		}
	});

	//合并元素
	//两个list都必须是升序排列
	std::list<int> my_values{2,4,6,14 };
	std::list<int> your_values{ -2,1,7,10 };
	my_values.merge(your_values);    //执行完此条语句后your_values的size为0

	//合并元素：提供合并的方法
	std::list<std::string> my_workmates{"benliu","guooujie","weiyongxin" };
	std::list<std::string> my_workmates2{ "yuan","yang","ping","yangzengxiao" };
	auto comp_str = [](const std::string s1, const std::string s2) {return s1[0] < s2[0]; };
	//排序之前先确保两个list已经按照相同的排序方式进行排序
	my_workmates.sort(comp_str);
	my_workmates2.sort(comp_str);
	my_workmates.merge(my_workmates2, comp_str);


	//拼接元素
	//拼接某一元素
	std::list<std::string> my_workmates3{ "benliu","guooujie","weiyongxin" };
	std::list<std::string> my_workmates4{ "yuan","yang","ping","yangzengxiao" };

	//splice() 的第一个参数是指向目的容器的迭代器。第二个参数是元素的来源。第三个参数是一个指向源list容器中被粘接元素的迭代器，它会被插入到第一个参数所指向位置之前
	my_workmates3.splice(std::begin(my_workmates3), my_workmates4, ++std::begin(my_workmates4));   //此时my_workmates4将只剩下三个元素

	//拼接一段元素
	std::list<std::string> my_workmates5{ "benliu","guooujie","weiyongxin" };
	std::list<std::string> my_workmates6{ "yuan","yang","ping","yangzengxiao" };
	my_workmates5.splice(++std::begin(my_workmates5), my_workmates6, ++std::begin(my_workmates6), std::end(my_workmates6)); //此时my_workmates6将只剩下第一个元素

	//拼接所有元素
	std::list<std::string> my_workmates7{ "benliu","guooujie","weiyongxin" };
	std::list<std::string> my_workmates8{ "yuan","yang","ping","yangzengxiao" };
	my_workmates7.splice(std::begin(my_workmates7), my_workmates8);				//此时my_workmates8将为空

	//访问list中的元素
	//获取第一个元素
	string my_first = my_workmates7.front();    //返回第一个元素的引用
	auto my_end = my_workmates7.back();			//返回最后一个元素的引用
	
	//遍历所有元素,使用基于范围的循环
	for (const auto& workmate : my_workmates7)
	{
		TRACE("my_workmates7:%s\n", workmate.c_str());
	}

	//使用迭代器遍历所有元素
	for (auto my_iter = std::begin(my_workmates7); my_iter != std::end(my_workmates7); my_iter++)
	{
		TRACE("my_workmates7 from iter:%s\n", my_iter->c_str());    //因为iter属于广义指针，所以此处需用->获取元素
	}
	//另一个遍历获取所有元素的例子
	list<int> sortlist;
	sortlist.push_back(3);
	sortlist.push_back(15);
	sortlist.push_back(8);
	sortlist.push_back(7);

	for (auto sortlist_iter = std::begin(sortlist); sortlist_iter != std::end(sortlist); sortlist_iter++)
	{
		TRACE("sortlist from iter:%d\n", *sortlist_iter);
	}



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