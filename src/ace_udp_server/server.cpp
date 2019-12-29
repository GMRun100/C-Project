#include"server.h"

//从远程客户端接收数据
//在完成接收数据后，发送一些信息给远程客户端
int Server::accept_data()
{
	int byte_count = 0;

	while ((byte_count = local_.recv(data_buf, SIZE_DATA, remote_addr_)) != -1)
	{
		data_buf[byte_count] = 0;
		ACE_DEBUG((LM_DEBUG,"Data received from remote %s was %s \n",
			remote_addr_.get_host_name(),data_buf));
		ACE_OS::sleep(1);
		if (send_data() == -1)
		//{
		//	ACE_DEBUG((LM_DEBUG, "ACE server send break!"));
			break;
		//}
			
	}
	return -1;
}

int Server::send_data()
{
	ACE_DEBUG((LM_DEBUG, "Preparing to send reply to client %s:%d\n",
		remote_addr_.get_host_name(),remote_addr_.get_port_number()));

	ACE_OS::sprintf(data_buf, "Server says hello to you too");

	if (local_.send(data_buf, ACE_OS::strlen(data_buf)+1, remote_addr_) == -1)
	{
		ACE_DEBUG((LM_DEBUG,"ACE server send error!\n"));
		return -1;
	}
	else
	{
		ACE_DEBUG((LM_DEBUG, "ACE server send success!\n"));
		return 0;
	}

}
