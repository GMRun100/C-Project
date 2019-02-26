
// useStructDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "useStruct.h"
#include "useStructDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���
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
//һ��Ϊ1000�Ĵ��벿��
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

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CuseStructDlg �Ի���



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


// CuseStructDlg ��Ϣ�������

BOOL CuseStructDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	Books book1;
	strcpy_s(book1.title, "C++�̳�");
	strcpy_s(book1.author, "benliu");
	strcpy_s(book1.subject, "�������");
	book1.book_id = 12345;

	//���book1����Ϣ
	cout << "��һ����ı���" << book1.title << endl;
	cout << "��һ���������" << book1.author << endl;
	cout << "��һ����ı������" << book1.subject << endl;
	cout << "��һ�����id" << book1.book_id << endl;

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



	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CuseStructDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CuseStructDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

