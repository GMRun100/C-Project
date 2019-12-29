#pragma once
#include<ace/SOCK_Dgram_Mcast.h>
#include<ace/OS.h>
#define DEFAULT_MULTICAST_ADDR "224.9.9.2"
#define TIMEOUT 5

class Sender_Multicast
{
public:
	Sender_Multicast(int port) :local_addr_((u_short)0), dgram_(local_addr_),
		multicast_addr_(port, DEFAULT_MULTICAST_ADDR)
	{
	}
	int send_to_multicast_group();
private:
	ACE_INET_Addr multicast_addr_;
	ACE_INET_Addr local_addr_;
	ACE_SOCK_Dgram dgram_;
	int mcast_info;   //存放广播的信息，为一个整数
};