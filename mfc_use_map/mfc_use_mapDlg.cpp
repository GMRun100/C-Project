
// mfc_use_mapDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "mfc_use_map.h"
#include "mfc_use_mapDlg.h"
#include "afxdialogex.h"
#include <map>

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


// CmfcusemapDlg 对话框



CmfcusemapDlg::CmfcusemapDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_USE_MAP_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmfcusemapDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CmfcusemapDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CmfcusemapDlg 消息处理程序

BOOL CmfcusemapDlg::OnInitDialog()
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

	use_map();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CmfcusemapDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CmfcusemapDlg::OnPaint()
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
HCURSOR CmfcusemapDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
//学习map容器
//map容器组织元素的方式为平衡二叉树
//map<K，T> 中的每个元素都是同时封装了对象及其键的 pair<const K，T> 类型对象
void CmfcusemapDlg::use_map()
{
	//构造map容器
	//在map容器中每种元素类型都为pair<const K，T> 类型的元素
	//std::map<std::string, size_t> people{ {"guooujie",22},{"benliu",35},{"yangzengxiao",25}};
	std::map<std::string, size_t> people{};

	//构造map容器:可以利用make_pair函数将分别T1和T2对象组合成一个对象
	//char* tmp_pchr[] = { "yuanyuan" };
	size_t tmp_size{ 19 };
	auto m_tmp_pair = std::make_pair("yuanyuan", tmp_size);    //这里m_tmp_pair的类型为std::pair<char const *,unsigned int>

	//插入元素
	people.insert(m_tmp_pair);   //在执行插入操作时，会将对象的类型隐式转换为容器所需的类型

	char  *tmp_pchr1 = {"guooujie"};    //此处不能写成char *[],char *[]表示字符数组
	auto m_tmp_pair2 = std::make_pair(tmp_pchr1, 22); //std::pair<char *,int>
	auto m_pr=people.insert(m_tmp_pair2);   //插入的时候会将22隐式转换为unsigned int,函数返回一个pair<iterator,bool> 对象
	auto m_iter = m_pr.first;  //对象的成员 first 是一个迭代器，它要么指向插入元素，要么指向阻止插入的元素
	auto ret = m_pr.second;   //成员变量 second (布尔型)是返回对象，如果插入成功，返回值为 true，否则为 false

	//遍历map容器中的所有元素
	//在map容器中元素是以键的升序排列的，因为 map 中默认使用 less<string> 函数对象对它们进行排序。
	for (const auto& p : people)
		TRACE("name:%s   age:%d\n", p.first.c_str(), p.second);

	//插入重复元素
	m_tmp_pair = std::make_pair("yuanyuan", 88);
	m_pr = people.insert(m_tmp_pair);    //如果存在重复元素，m_pr的成员变量 first 指向 map 中已有的和键匹配的元素，成员变量 second 为 false，表明元素没有插入成功
	//如果插入失败，说明元素重复
	if (!m_pr.second)
		m_pr.first->second = 88;   //修改重复元素的年龄
	
	//插入元素：利用pair构造函数生成的对象作为insert()的参数
	people.insert(std::pair<const std::string, size_t>{"benliu", 48});   //在监视窗口中，benliu排在第一个，因为map默认按键值的升序进行排列

	//插入元素：通过提示符来指定元素插入的位置
	m_pr = people.insert(std::make_pair("lihualong",36));
	//下一个 insert() 函数的第一个参数和上面的提示符有关，所以这里就是插入元素的地方。insert() 的第二个参数指定的新元素会被插入到提示符的前面，并尽可能地靠近它。如果提示符不能以这种方式使用，那么将忽略它
	//这样做的好处是可以提高元素的插入速度
	people.insert(m_pr.first, std::make_pair("huahua", 33));

	//插入元素：在插入元素之前可以通过count函数来判断来判断map容器中是否存在该元素
	size_t m_count = people.count("guooujie");   //m_count=1

	//插入元素：直接赋值法
	if (!people.count("tianchun"))
	{
		people[std::string("tianchun")] = 66;
	}

	//插入元素：insert参数为初始化列表
	people.insert({ "zhangbo",10 });

	//插入元素：insert参数为多个初始化列表
	std::map<std::string, size_t> people2{{"guooujie",22},{"benliu",35},{"yangzengxiao",25}};
	people2.insert({ {"zhengtianchun",10 },{ "luyanwei",10 } });

	//插入元素：利用初始化列表插入元素
	//新建一个初始化列表
	//此处必须要加入const关键字，因为map中的每个元素都是pair<const K,T>类型对象
	//如果不加const的话，initializer_list <string,size_t> 无法隐式转换为 initializer_list<const string, size_t>，所以前者类型的对象不能作为 insert() 函数的参数
	std::initializer_list<std::pair<const std::string, size_t>> m_init{{"chenghua",12} ,{"luyu",11}};   
	std::map<std::string, size_t> people2_2{{"guooujie",22},{"benliu",35},{"yangzengxiao",25}};
	people2_2.insert(m_init);

	//插入元素：将另一个容器中的元素插入
	std::map<std::string, size_t> crowd{};

	auto iter = std::begin(people);
	std::advance(iter, 4);   //此时iter将指向第五个元素
	crowd.insert(++std::begin(people),iter);   //插入people的第2,3,4个元素


	//构造元素
	//emplace和insert的区别可以参见https://www.cnblogs.com/narjaja/p/10039509.html文档，此处待后续学习
	std::map<std::string, size_t> people3_1{ {"guooujie",22},{"benliu",35},{"yangzengxiao",25} };
	auto iter3 = std::make_pair("benliu2", 12);
	auto pr3=people3_1.emplace(iter3);      



}