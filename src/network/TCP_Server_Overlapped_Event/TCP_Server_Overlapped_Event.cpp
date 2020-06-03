#include <WinSock2.h>  
#include <iostream>  
using namespace std;

#pragma comment(lib,"Ws2_32.lib")  


//全局数组，不方便
WSAEVENT   eventArray[WSA_MAXIMUM_WAIT_EVENTS];  // 事件对象数组64  
SOCKET         sockArray[WSA_MAXIMUM_WAIT_EVENTS]; // 事件对应的SOCKET句柄数组
WSAOVERLAPPED* overArray[WSA_MAXIMUM_WAIT_EVENTS]; // 事件对应的重叠结构数组
WSABUF     bufArray[WSA_MAXIMUM_WAIT_EVENTS];//WSARecv中的buf，完成后直接可获取数据

//我建议，大家封装一个结构体，把他们作为成员，方便管理
/*
//自定义结构体方便WSARecv操作所需的参数
typedef struct  _MY_WSAOVERLAPPED
{
WSAOVERLAPPED overlap;
WSABUF Buffer;
DWORD NumberOfBytesRecvd;
DWORD Flags;

_MY_WSAOVERLAPPED()
{
Buffer.buf = new char[64]{0};
Buffer.len = 64;
Flags = 0;//设置为0
}
~_MY_WSAOVERLAPPED()
{
delete []Buffer.buf ;
Buffer.buf = NULL;
Buffer.len =0;
}

} MY_WSAOVERLAPPED ,*PMY_WSAOVERLAPPED;


WSAEVENT eventArray[WSA_MAXIMUM_WAIT_EVENTS];  // 事件对象数组64
SOCKET sockArray[WSA_MAXIMUM_WAIT_EVENTS]; // 事件对应的SOCKET句柄数组
PMY_WSAOVERLAPPED   overlappedArray[WSA_MAXIMUM_WAIT_EVENTS]; // 重叠结构指针数组
int  N = 0;//事件对象的个数


*/



int  N = 0;//记录对象事件的个数


DWORD WINAPI  ThreadProc(LPVOID lpParameter);

int main()
{
	// 初始化Winsock 2.2
	WSAData wsaData;
	if (0 != WSAStartup(MAKEWORD(2, 2), &wsaData))
	{
		cout << "WSAStartup  error:" << WSAGetLastError() << endl;
		return -1;
	}

	//创建监听套接字,socket函数会默认设置 WSA_FLAG_OVERLAPPED 标志，WSASocket()需要手动设置标志
	SOCKET  sListen = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sListen == INVALID_SOCKET)
	{
		cout << "socket() Error: " << WSAGetLastError() << endl;
		return  0;
	}

	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(8000);
	sin.sin_addr.S_un.S_addr = htonl(ADDR_ANY);
	//绑定到本机任意地址
	if (SOCKET_ERROR == bind(sListen, (sockaddr*)&sin, sizeof(sin)))
	{
		cout << "bind  error:" << WSAGetLastError() << endl;
		return 0;
	}

	//监听套接字
	if (listen(sListen, 5) == SOCKET_ERROR)
	{
		cout << " listen() Error:" << WSAGetLastError() << endl;
		return  0;
	}


	// 创建线程，来检测事件信号的到来
	HANDLE hThread = CreateThread(NULL, 0, ThreadProc, NULL, 0, NULL);
	CloseHandle(hThread);//关闭对线程的引用 


	while (true)
	{
		// 接受客户端连接请求  
		SOCKET  sClient = accept(sListen, NULL, NULL);

		if (sClient == INVALID_SOCKET)
		{
			cout << " accept() Error:" << WSAGetLastError() << endl;
			continue;
		}

		cout << sClient << "	进入聊天室！" << endl;
		char tmp[64];
		sprintf_s(tmp, "欢迎%d进入聊天室！", sClient);
		send(sClient, tmp, strlen(tmp), 0);

		//开始基于事件的重叠io步骤

		//创建事件对象
		WSAEVENT  event = WSACreateEvent();
		//创建重叠结构
		WSAOVERLAPPED* pOver = new WSAOVERLAPPED;
		pOver->hEvent = event;


		eventArray[N] = event;
		overArray[N] = pOver;
		sockArray[N] = sClient;



		//投递WSARecv请求，想接收客户端数据
		WSABUF buf;
		buf.buf = new char[100];
		ZeroMemory(buf.buf, 100);
		buf.len = 100;

		bufArray[N] = buf;

		++N;


		DWORD numberOfBytesRecvd = 0;
		DWORD  flags = 0;
		int  ret = WSARecv(sClient, &buf, 1, &numberOfBytesRecvd, &flags, pOver, NULL);
		if (ret == SOCKET_ERROR)//异步的所以立即返回SOCKET_ERROR，并且错误码WSA_IO_PENDING
		{


			int  err = WSAGetLastError();
			if (err == WSA_IO_PENDING)//证明投递的请求成功，IO操作会在后面的时间完成
			{

			}
			else
			{
				cout << "WSARecv 失败！" << endl;
			}
		}
	}


	//关闭套接字
	closesocket(sListen);

	// 最后应该做一些清除工作
	if (WSACleanup() == SOCKET_ERROR)
	{
		cout << "WSACleanup 出错！" << endl;
	}


}




//7实现线程函数（可以是全局的，也可以是类的静态方法）
DWORD WINAPI  ThreadProc(LPVOID lpParameter)
{
	//检测是否事件有信号
	while (TRUE)
	{
		//1秒钟超时就返回，如果用WSA_INFINITE,则后面的event加入数组时，这里的函数由于阻塞，不会及时检测到
		int  ret = WSAWaitForMultipleEvents(N, eventArray, false, 1000, false);
		if (ret == WSA_WAIT_FAILED || ret == WSA_WAIT_TIMEOUT)
		{
			continue;
		}

		//返回事件对象在数组中的下标
		int  index = ret - WSA_WAIT_EVENT_0;

		//此刻事件为有信号，需要WSAReset将事件设置为无信号，以便下次使用
		WSAResetEvent(eventArray[index]);

		WSAOVERLAPPED* pOver = overArray[index];

		//	本次重叠操作的实际接收(或发送)的字节数
		DWORD lpcbTransfer = 0;
		DWORD lpdwFlags = 0;
		//检测重叠IO操作是否完成,  
		int ret2 = WSAGetOverlappedResult(sockArray[index], pOver, &lpcbTransfer, true, &lpdwFlags);

		if (ret2 && lpcbTransfer > 0)
		{
			//直接在WSABUF中获取数据
			cout << sockArray[index] << "	说: " << bufArray[index].buf << endl;

			//清空缓存数据
			ZeroMemory(bufArray[index].buf, 100);

			DWORD numberOfBytesRecvd = 0;
			DWORD  flags = 0;
			// 进行另一个异步操作  
			WSARecv(sockArray[index],
				&bufArray[index],
				1,
				&numberOfBytesRecvd,
				&flags,
				pOver,
				NULL);
		}
		else
		{
			cout << sockArray[index] << "离开了！" << endl;
			closesocket(sockArray[index]);
			WSACloseEvent(eventArray[index]);
			delete overArray[index];
			delete  bufArray[index].buf;

			//需要把数组的index元素删除，把后面的元素前移动
			while (index < N - 1)
			{
				sockArray[index] = sockArray[index + 1];
				overArray[index] = overArray[index + 1];
				eventArray[index] = eventArray[index + 1];
				bufArray[index] = bufArray[index + 1];
				++index;
			}

			--N;

		}



	}


	return 0;
}