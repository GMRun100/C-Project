#pragma once
//ACE UDP–≠“È server∂À
#define WIN32
#include<ace/OS.h>
#include<ace/SOCK_Dgram.h>
#include<ace/INET_Addr.h>
#include<ace/Log_Msg.h>

#define DATA_BUFFER_SIZE 1024
#define SIZE_DATA 19

class Server
{
public:
	Server(int local_port) :local_addr_(local_port), local_(local_addr_)
	{
		remote_addr_.set(local_port, "127.0.0.1");
		data_buf = new char[DATA_BUFFER_SIZE];
	}
	int accept_data();
	int send_data();
	~Server()
	{
		delete data_buf;
	}

private:
	char *data_buf;
	ACE_INET_Addr remote_addr_;
	ACE_INET_Addr local_addr_;
	ACE_SOCK_Dgram local_;
};