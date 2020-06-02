#include <winsock2.h>
#include <tchar.h> //_T头文件
#include <stdio.h>  
#include<WS2tcpip.h>
#pragma comment(lib,"WS2_32") 

//1.自定义消息
#define     WM_SOCKET      WM_USER+101 


//----------------窗口过程函数的声明，处理windows消息------------- 
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);


//输出到编辑框显示
HWND  hwndEdit = NULL;//全局编辑框句柄
void AppendEdit(const char* strOutputString, ...);

/*
1.进入project->setting->c/c++,在category中选择preprocessor,在processor definitions中删除_CONSOLE,添加_WINDOWS

2.进入project->setting->Link, 在Projectoptions中将 /subsystem:console选择为窗口/subsystem:windows.
*/
//----------------win32窗口程序，WinMain()函数------------------ 
int  WINAPI  WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	WNDCLASS wc;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WindowProc;//窗口处理函数
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);

	HBRUSH  hbrush = CreateSolidBrush(RGB(255, 0, 0));
	//wc.hbrBackground=(HBRUSH)GetStockObject(BLACK_BRUSH); 
	wc.hbrBackground = hbrush;

	wc.lpszMenuName = NULL;
	wc.lpszClassName = _T("Test");
	//---注册窗口类---- 
	RegisterClass(&wc);
	//---创建窗口---- 
	HWND hwnd = CreateWindow(_T("Test"), _T("窗口标题"), WS_SYSMENU, 300, 100, 600, 400, NULL, NULL, hInstance, NULL);
	if (hwnd == NULL)
	{
		//AppendEdit("创建窗口出错！\n");
		return 1;
	}
	//---显示窗口---- 
	ShowWindow(hwnd, SW_SHOWNORMAL);
	UpdateWindow(hwnd);


	//---初始化socket环境----- 
	WSADATA wsaData;
	WORD wVersionRequested = MAKEWORD(2, 2);
	if (WSAStartup(wVersionRequested, &wsaData) != 0)
	{
		AppendEdit("WSAStartup() Failed: %d", WSAGetLastError());
		return 1;
	}

	//1. 创建监听套接字
	SOCKET s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (s == INVALID_SOCKET)
	{
		AppendEdit("socket() Failed: %d", WSAGetLastError());
		return 1;
	}

	//2.绑定到ip与端口
	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(8000);
	//sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	InetPton(AF_INET, TEXT("127.0.0.1"), &sin.sin_addr.S_un.S_addr);
	if (bind(s, (sockaddr*)&sin, sizeof(sin)) == SOCKET_ERROR)
	{
		AppendEdit("bind() Failed: %d", WSAGetLastError());
		return 1;
	}


	//3.监听
	if (listen(s, 5) == SOCKET_ERROR)
	{
		AppendEdit("listen() Failed: %d", WSAGetLastError());
		return 1;
	}
	else
	{
		AppendEdit("进入监听状态！");
	}


	//4.  用WSAAsyncSelect将监听套接字注册消息，在消息处理函数接到消息通知
	int ret = WSAAsyncSelect(s, hwnd, WM_SOCKET, FD_ACCEPT | FD_CLOSE);
	if (ret != 0)
	{
		AppendEdit("WSAAsyncSelect Failed: %d", WSAGetLastError());
		return 1;
	}
	else
	{
		AppendEdit("WSAAsyncSelect succes！");
	}


	//---消息循环，除非消息队列结束---- 
	MSG msg;
	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}



	return msg.wParam;
}



LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		//-----自定义消息
	case WM_SOCKET:
	{
		SOCKET ss = wParam;   //wParam参数标志了网络事件发生的套接口 

		int     error = WSAGETSELECTERROR(lParam); // 错误码    
		if (error)
		{
			closesocket(ss);
			AppendEdit("%d   离开聊天室！", ss);
			return 0;
		}

		long event = WSAGETSELECTEVENT(lParam); // 事件    
		switch (event)
		{
			//-----①连接客户端请求到来
		case FD_ACCEPT:
		{
			sockaddr_in Cadd;
			int Cadd_len = sizeof(Cadd);
			SOCKET sClient = accept(ss, (sockaddr*)&Cadd, &Cadd_len);
			if (sClient != INVALID_SOCKET)
			{
				AppendEdit("欢迎%d进入聊天室!", sClient);

				char tmp[64];
				sprintf_s(tmp, "欢迎%d进入聊天室！", sClient);
				send(sClient, tmp, strlen(tmp), 0);

				//将与客户端通讯的套接字注册消息(读取)
				WSAAsyncSelect(sClient, hwnd, WM_SOCKET, FD_READ | FD_CLOSE);
			}
		}  break;


		//-----②数据可以接受
		case FD_READ:
		{
			char cbuf[256];
			memset(cbuf, 0, 256);
			int cRecv = recv(ss, cbuf, 256, 0);
			if ((cRecv == SOCKET_ERROR && WSAGetLastError() == WSAECONNRESET) || cRecv == 0)
			{
				AppendEdit("recv  error: %d", WSAGetLastError());
				closesocket(ss);
			}
			else if (cRecv > 0)
			{
				AppendEdit("%d   说   %s", ss, cbuf);
			}
		}break;

		//----③关闭连接 
		case  FD_CLOSE:
		{
			closesocket(ss);
		}break;
		}


	} break;




	case WM_CLOSE:
		if (IDYES == MessageBox(hwnd, _T("是否确定退出？"), _T("提示"), MB_YESNO))
			DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_CREATE:
		hwndEdit = CreateWindow(L"EDIT", NULL, WS_VISIBLE | WS_CHILD | WS_BORDER | ES_MULTILINE | ES_AUTOVSCROLL,
			10, 10, 500, 200, hwnd, (HMENU)1111, ((LPCREATESTRUCT)lParam)->hInstance, NULL);//创建编辑框  
		break;

	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
	return 0;
}




void AppendEdit(const char* strOutputString, ...)
{
	char strBuffer[4096] = { 0 };
	va_list vlArgs;
	va_start(vlArgs, strOutputString);
	_vsnprintf_s(strBuffer, sizeof(strBuffer) - 1, strOutputString, vlArgs);
	va_end(vlArgs);

	strcat_s(strBuffer, "\r\n");

	/* 以下两条语句为在edit中追加字符串 */
	SendMessageA(hwndEdit, EM_SETSEL, -2, -1);
	SendMessageA(hwndEdit, EM_REPLACESEL, true, (long)strBuffer);

	/* 设置滚轮到末尾，这样就可以看到最新信息 */
	SendMessageA(hwndEdit, WM_VSCROLL, SB_BOTTOM, 0);
}
