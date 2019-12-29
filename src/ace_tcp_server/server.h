#pragma once
#define WIN32
//��ϰACE TCP����server��
#include<ace/SOCK_Acceptor.h>
#include<ace/SOCK_Stream.h>
#include<ace/Log_Msg.h>
#include<ace/OS_NS_stdlib.h>
#include<ace/Time_Value.h>


#define SIZE_DATA 18
#define SIZE_BUF 1024
#define NO_ITERATIONS 5

class Server
{
public:
	Server(int port) :server_addr_(port), peer_acceptor_(server_addr_)
	{
		//server_addr_.set(50000);      //Ҳ���ڳ�ʼ��ʱ���ö˿ں�
		data_buf_ = new char[SIZE_BUF];
	}
	int handle_connection();
	int accept_connections();

	~Server(){}

private:
	char *data_buf_;
	ACE_INET_Addr server_addr_;
	ACE_INET_Addr client_addr_;
	ACE_SOCK_Acceptor 	peer_acceptor_; //���ڱ��������ӽ���������BSD accept()��listen()����
	ACE_SOCK_Stream new_stream_;

};



