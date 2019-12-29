#pragma once
#define WIN32
#include<ace/SOCK_Connector.h>
#include<ace/INET_Addr.h>
#include<ace/Log_Msg.h>
#include<ace/OS_NS_string.h>
#include<ace/OS_NS_stdlib.h>

#define SIZE_BUF 128
#define NO_ITERATIONS 5

class Client
{
public:
	Client(int port) :remote_addr_(port)
	{
		remote_addr_.set(50000, "127.0.0.1");
		data_buf_ = "Hello from Client";
	}

	int connect_to_server();
	int send_to_server();
	int close();

private:
	ACE_SOCK_Stream client_stream_;
	ACE_INET_Addr remote_addr_;
	ACE_SOCK_CONNECTOR connector_;
	const char *data_buf_;


};

