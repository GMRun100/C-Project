#include<winsock2.h>//winsock2的头文件
#include<WS2tcpip.h>
#include<iostream>
using  namespace std;

//勿忘，链接dll的lib
#pragma comment(lib, "ws2_32.lib")

int  main()
{

	//加载winsock2的环境
	WSADATA  wd;
	if (WSAStartup(MAKEWORD(2, 2), &wd) != 0)
	{
		cout << "WSAStartup  error：" << GetLastError() << endl;
		return 0;
	}

	//1.创建流式套接字
	SOCKET  s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (s == INVALID_SOCKET)
	{
		cout << "socket  error：" << GetLastError() << endl;
		return 0;
	}

	//2.链接服务器
	sockaddr_in   addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8000);
	//addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	InetPton(AF_INET, TEXT("127.0.0.1"), &addr.sin_addr.S_un.S_addr);
	int len = sizeof(sockaddr_in);
	if (connect(s, (SOCKADDR*)&addr, len) == SOCKET_ERROR)
	{
		cout << "connect  error：" << GetLastError() << endl;
		return 0;
	}

	//3接收服务端的消息
	char buf[100] = { 0 };
	recv(s, buf, 100, 0);
	cout << buf << endl;

	//3随时给服务端发消息
	int  ret = 0;
	do
	{
		char buf[64] = { 0 };
		cout << "请输入聊天内容:";
		cin >> buf;
		ret = send(s, buf, 64, 0);
	} while (ret != SOCKET_ERROR && ret != 0);


	//4.关闭监听套接字
	closesocket(s);

	//清理winsock2的环境
	WSACleanup();



	return 0;
}

