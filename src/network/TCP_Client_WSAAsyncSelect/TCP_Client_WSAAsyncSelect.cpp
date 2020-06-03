// TCP_Client.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<WinSock2.h>
#include<WS2tcpip.h>
using namespace std;

//指定动态库的lib文件
#pragma comment(lib,"ws2_32.lib")
int main()
{
    //初始化winsock2.2相关的动态库
    WSADATA wd;  //获取socket相关信息
    if (WSAStartup(MAKEWORD(2, 2), &wd) != 0)  //0表示成功
    {
        cout << "WSAStartup error:" << WSAGetLastError() << endl;
        return 0;
    }

    //1.创建TCP socket  流式套接字
    SOCKET s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (s == INVALID_SOCKET)
    {
        cout << "socket error:" << WSAGetLastError() << endl;
        return 0;
    }

    //2.链接服务端
    sockaddr_in addr;//不建议用sockaddr，建议用sockaddr_in
    addr.sin_port = htons(8000);//网络字节序
    //addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");//网络字节序
    InetPton(AF_INET, TEXT("127.0.0.1"), &addr.sin_addr.S_un.S_addr);
    addr.sin_family = AF_INET; //地址族
    int len = sizeof(SOCKADDR);

    if (connect(s, (sockaddr*)&addr, len) == SOCKET_ERROR)
    {
        cout << "connect error:" << WSAGetLastError() << endl;
        return 0;
    }

    //接收服务端消息
    char buf[100] = { 0 };
    recv(s, buf, 100, 0);
    cout << buf << endl;

    //随时给服务端发送消息
    int ret = 0;
    do
    {
        char buf[100] = { 0 };
        cout << "请输入聊天内容:";
        cin >> buf;
        ret = send(s, buf, 100, 0);


    } while (ret != SOCKET_ERROR && ret != 0);

    //4.关闭套接字
    closesocket(s);



    //清理winsock环境
    WSACleanup();
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
