#include <WinSock2.h>  
#include <iostream>  
using namespace std;

#pragma comment(lib,"Ws2_32.lib")  


int main()
{
	// 初始化Winsock 2.2
	WSAData wsaData;
	if (0 != WSAStartup(MAKEWORD(2, 2), &wsaData))
	{
		cout << "WSAStartup  error:" << WSAGetLastError() << endl;
		return -1;
	}

	//1创建监听套接字
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
	//2绑定到本机任意地址、端口
	if (SOCKET_ERROR == bind(sListen, (sockaddr*)&sin, sizeof(sin)))
	{
		cout << "bind  error:" << WSAGetLastError() << endl;
		return -1;
	}

	//3监听套接字
	if (listen(sListen, 5) == SOCKET_ERROR)
	{
		cout << " listen() Error:" << WSAGetLastError() << endl;
		return  0;
	}


	WSAEVENT eventArray[WSA_MAXIMUM_WAIT_EVENTS];  // 事件对象数组64  
	SOCKET      sockArray[WSA_MAXIMUM_WAIT_EVENTS]; // 事件对应的SOCKET句柄数组  
	int  N = 0;//事件对象的个数，初始化为0


	//创建第一个事件对象，用于监听socket 关联，注册事件
	WSAEVENT event = ::WSACreateEvent();
	::WSAEventSelect(sListen, event, FD_ACCEPT | FD_CLOSE);
	sockArray[N] = sListen;
	eventArray[N++] = event;//放了第一个事件对象


	while (true)
	{
		//等待事件，false只要有一个对象被触发就返回， 无限等待
		int   ret = ::WSAWaitForMultipleEvents(N, eventArray, false, WSA_INFINITE, false);
		if (ret == WSA_WAIT_FAILED)
		{
			cout << "WSAWaitForMultipleEvents  error：" << WSAGetLastError() << endl;
			continue;
		}

		//它在数组中的下标为：  （返回值  -  WSA_WAIT_EVENT_0 ） 
		int  index = ret - WSA_WAIT_EVENT_0;


		SOCKET sock = sockArray[index];//对应关系，通过索引获取相应的socket

		WSANETWORKEVENTS  netEvents;//返回发生的时间
		//检测发生的事件
		::WSAEnumNetworkEvents(sock, eventArray[index], &netEvents);
		//接受到客户端的请求事件
		if (netEvents.lNetworkEvents & FD_ACCEPT)
		{
			//无错误
			if (netEvents.iErrorCode[FD_ACCEPT_BIT] == 0)
			{
				if (N >= WSA_MAXIMUM_WAIT_EVENTS)
				{
					cout << "事件对象数组已满！" << endl;
					continue;
				}

				SOCKET client = ::accept(sock, NULL, NULL);
				if (client != INVALID_SOCKET)
				{
					cout << client << "	进入聊天室！" << endl;
					char tmp[64];
					sprintf_s(tmp, "欢迎%d进入聊天室！", client);
					send(client, tmp, strlen(tmp), 0);

					//关联一个客户端套接字，并注册读事件
					WSAEVENT e = ::WSACreateEvent();
					::WSAEventSelect(client, e, FD_READ | FD_WRITE | FD_CLOSE);
					sockArray[N] = client;
					eventArray[N++] = e;//放到事件数组中
				}
			}
		}
		//读事件
		else if (netEvents.lNetworkEvents & FD_READ)
		{
			if (netEvents.iErrorCode[FD_READ_BIT] == 0)
			{
				char buf[64] = { 0 };
				int ret = recv(sock, buf, 64, 0);
				if (ret > 0)
				{
					cout << sock << "	说: " << buf << endl;
				}
			}
		}
		else if (netEvents.lNetworkEvents & FD_CLOSE)
		{
			//关闭事件对象
			::WSACloseEvent(eventArray[index]);
			::closesocket(sock);
			cout << sock << "	离开了！" << endl;

			//减少数组元素，删除关闭的套接字
			for (int j = index; j < N - 1; j++) {
				eventArray[j] = eventArray[j + 1];
				sockArray[j] = sockArray[j + 1];
			}
			--N;//总数量减一
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
