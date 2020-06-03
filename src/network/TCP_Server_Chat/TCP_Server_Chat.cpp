// TCP_Server_Chat.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
//网络聊天室服务端
//2020.02.04 GM 

#include <iostream>
#include<WinSock2.h>
#include<WS2tcpip.h>
using namespace std;

//指定动态库的lib文件
#pragma comment(lib,"ws2_32.lib")

//声明线程函数
//stdcall的线程处理函数
DWORD WINAPI ThreadFun(LPVOID lpThreadParameter);

int main()
{
    //初始化winsock2.2相关的动态库
    WSADATA wd;  //获取socket相关信息
    if (WSAStartup(MAKEWORD(2, 2), &wd) != 0)  //0表示成功
    {
        cout << "WSAStartup error:" << WSAGetLastError() << endl;
        return 0;
    }

    //1.创建流式套接字
    SOCKET s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (s == INVALID_SOCKET)
    {
        cout << "socket error:" << WSAGetLastError() << endl;
        return 0;
    }

    //2.绑定socket到一个IP地址和端口
    sockaddr_in addr;//不建议用sockaddr，建议用sockaddr_in
    memset(&addr, 0, sizeof(addr));
    addr.sin_port = htons(8000);//网络字节序
    //addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");//网络字节序
    InetPton(AF_INET, TEXT("127.0.0.1"), &addr.sin_addr.S_un.S_addr);
    addr.sin_family = AF_INET; //地址族
    int len = sizeof(SOCKADDR);
    if (bind(s, (sockaddr*)&addr, len) == SOCKET_ERROR)
    {
        cout << "bind error:" << WSAGetLastError() << endl;
        return 0;
    }

    //3.监听，5代表正在等待完成相应的TCP三路握手过程的队列长度
    if (listen(s, 5) == SOCKET_ERROR)
    {
        cout << "listen error:" << WSAGetLastError() << endl;
        return 0;
    }

    //4.接收客户端请求，并且返回和客户端通讯的套接字
    //主线程循环接收客户端的链接
    while (true)
    {
        sockaddr_in addrClient; //保存客户端IP地址端口
        memset(&addrClient, 0, sizeof(sockaddr_in));
        len = sizeof(sockaddr_in);
        SOCKET c = accept(s, (sockaddr*)&addrClient, &len);
        if (c != INVALID_SOCKET)
        {
            //创建线程，并且传入与client通讯的套接字
            HANDLE hThread = CreateThread(NULL, 0,ThreadFun,(LPVOID)c,0,NULL );
            if (hThread != NULL)
            {
                CloseHandle(hThread);  //关闭对线程的引用
            }
           
        }
    }

    //6.关闭套接字
    closesocket(s);

    //清理winsock环境
    WSACleanup();

    return 0;
}

DWORD WINAPI ThreadFun(LPVOID lpThreadParameter)
{
    //5.与客户端通讯 发送或者接收数据
    SOCKET c = (SOCKET)lpThreadParameter;
    cout << "欢迎" << c << "进入聊天室!" << endl;
    char buf[100] = { 0 };
    sprintf_s(buf, "欢迎%d进入聊天室！", c);
    send(c, buf, 100, 0);

    //循环接收客户端数据
    int ret = 0;
    do
    {
        char buf[100] = { 0 };
        ret=recv(c, buf, 100, 0);

        cout << c << " 说:" << buf << endl;
    } while (ret != SOCKET_ERROR && ret != 0);

    cout << c << "离开了聊天室" << endl;
    return 0;
}



// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
