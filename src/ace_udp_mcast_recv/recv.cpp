#include"recv.h"


int Receiver_Multicast::recv_multicast()
{
	if (mcast_dgram_.recv(&mcast_info, sizeof(mcast_info), remote_addr_) == -1)
	{
		return -1;
	}
	else
	{
		//%P打印出当前进程id,
		ACE_DEBUG((LM_DEBUG,"(%P|%t) Received multicast from %s:%d.\n",
			remote_addr_.get_host_name(),remote_addr_.get_port_number()));
		ACE_DEBUG((LM_DEBUG, "Successfully received %d\n", mcast_info));
		return 0;
	}
}