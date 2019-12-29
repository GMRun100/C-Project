#pragma once
#define WIN32
#include<ace/SOCK_Dgram_Mcast.h>
#include<ace/OS.h>
#include<ace/Log_Msg.h>

#define DEFAULT_MULTICAST_ADDR "224.9.9.2"
#define TIMEOUT 5

//��Receiver_Multicast�������չ㲥��Ϣ

class Receiver_Multicast
{
public:
	Receiver_Multicast(int port) :
		mcast_addr_(port,DEFAULT_MULTICAST_ADDR),remote_addr_((u_short)0)
	{
		//���Ĺ㲥��ַ
		if (mcast_dgram_.join(mcast_addr_) == -1)
		{
			ACE_DEBUG((LM_DEBUG,"Error in subscribing to Multicast address \n"));
			exit(-1);
		}
	}
	~Receiver_Multicast()
	{
		if (mcast_dgram_.leave(mcast_addr_) == -1)
		{
			ACE_DEBUG((LM_ERROR, "Error in unsubscribing from Mcast group\n"));
		}
	}

	int recv_multicast();
		
private:
	ACE_INET_Addr mcast_addr_;
	ACE_INET_Addr remote_addr_;
	//��ACE�У���㴫�͹��ܱ���װ��ACE_SOCK_Dgram_Mcast�У����а����ڶ�㴫�����ϵ�Ԥ����ȡ��Ԥ���ͽ��չ���
	ACE_SOCK_Dgram_Mcast mcast_dgram_;
	int mcast_info;

};