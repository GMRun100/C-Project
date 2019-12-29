#include"client.h"

int Client::connect_to_server()
{
	//��ʼ���������������
	ACE_DEBUG((LM_DEBUG,"(%P|%t) Starting connect to %s:%d\n",
		remote_addr_.get_host_name(),remote_addr_.get_port_number()));
	if (connector_.connect(client_stream_, remote_addr_) == -1)
	{
		ACE_ERROR_RETURN((LM_ERROR, "(%P|%t) %p\n", "connection failed"), -1);
	}
	else
		ACE_DEBUG((LM_DEBUG,"(%P|%t) connected to %s\n",remote_addr_.get_host_name()));

	return 0;
}

int Client::send_to_server()
{
	//Send data to server
	for (int i = 0; i < NO_ITERATIONS; i++)
	{
		if (client_stream_.send_n(data_buf_,
			ACE_OS::strlen(data_buf_)+1,0)==-1)
		{
			ACE_ERROR_RETURN((LM_ERROR, "(%P|%t) %p\n", "send_n"), 0);
			break;
		}
	}
	//�ر�����
	close();

}
//�ر���������
int Client::close()
{
	if (client_stream_.close() == -1)
	{
		ACE_ERROR_RETURN((LM_ERROR, "(%P|%t) %p\n", "close"), -1);
	}
	else
		return 0;
}