// TCP_Server_Select.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<WinSock2.h>
#include<WS2tcpip.h>
using namespace std;

//指定动态库的lib文件
#pragma comment(lib,"ws2_32.lib")
int main()
{
    //std::cout << "Hello World!\n";
        //初始化winsock2.2相关的动态库
    WSADATA wd;  //获取socket相关信息
    if (WSAStartup(MAKEWORD(2, 2), &wd) != 0)  //0表示成功
    {
        cout << "WSAStartup error:" << WSAGetLastError() << endl;
        return 0;
    }

    //1.创建监听套接字
    SOCKET sListen = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sListen == INVALID_SOCKET)
    {
        cout << "socket error:" << WSAGetLastError() << endl;
        return 0;
    }

    //2.绑定socket到一个IP地址和端口
    sockaddr_in addr;//不建议用sockaddr，建议用sockaddr_in
    addr.sin_port = htons(8000);//网络字节序
    //addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");//网络字节序
    InetPton(AF_INET, TEXT("127.0.0.1"), &addr.sin_addr.S_un.S_addr);
    addr.sin_family = AF_INET; //地址族
    int len = sizeof(SOCKADDR);
    if (bind(sListen, (sockaddr*)&addr, len) == SOCKET_ERROR)
    {
        cout << "bind error:" << WSAGetLastError() << endl;
        return 0;
    }

    //3.监听，5代表正在等待完成相应的TCP三路握手过程的队列长度
    if (listen(sListen, 5) == SOCKET_ERROR)
    {
        cout << "listen error:" << WSAGetLastError() << endl;
        return 0;
    }

    //4.select
    fd_set readSet;  //定义一个读(接收消息)的集合
    FD_ZERO(&readSet);
    FD_SET(sListen, &readSet);

    //不停的select才可以读取套接字的状态改变
    while (true)
    {
        fd_set tmpSet;//定义一个临时的集合
        FD_ZERO(&tmpSet);  //初始化集合
        tmpSet = readSet;  //每次循环都是所有的套接字

        //利用select选择出集合中可以读写的套接字，有点像筛选
        int ret = select(0, &tmpSet, NULL, NULL, NULL);
        if (ret == SOCKET_ERROR)
        {
            continue;
        }

        //成功筛选出来可以发送或者接收的socket
        for (int i = 0; i < tmpSet.fd_count; ++i)
        {
            //获取到套接字
            SOCKET s = tmpSet.fd_array[i];
            //接收到客户端的链接
            if (s == sListen)
            {
                SOCKET c = accept(s, NULL, NULL);
                //fd_set集合的最大值为64
                if (readSet.fd_count < FD_SETSIZE)
                {
                    //往集合中添加客户端套接字
                    FD_SET(c, &readSet);
                    cout << "欢迎" << c << "进入聊天室!" << endl;
                    char buf[100] = { 0 };
                    sprintf_s(buf, "欢迎%d进入聊天室!", c);
                    send(c,buf,100,0);
                }
                else
                {
                    cout << "达到客户端容量上限！" << endl;
                }
            }
            else
            {
                //接收客户端的数据
                char buf[100] = { 0 };
                ret=recv(s, buf, 100, 0);
                if (ret == SOCKET_ERROR || ret == 0)
                {
                    closesocket(s);
                    FD_CLR(s, &readSet);
                    cout << s << "离开聊天室" << endl;
                }
                else
                {
                    cout << s << "说:" << buf << endl;
                }
            }
        }



    }

    //关闭监听套接字
    closesocket(sListen);



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
