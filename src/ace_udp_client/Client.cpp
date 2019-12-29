#include"client.h"

int Client::accept_data()
{
	if (local_.recv(data_buf, SIZE_DATA, remote_addr_) != -1)
	{
		data_buf[SIZE_DATA] = 0;
		ACE_DEBUG((LM_DEBUG, "Data received from remote server %s was: %s \n",
			remote_addr_.get_host_name(), data_buf));
		return 0;
	}
	else
	{
		ACE_DEBUG((LM_DEBUG, "Data received from remote server error"));
		return -1;
	}

		
}

int Client::send_data()
{
	ACE_DEBUG((LM_DEBUG,"Preparing to send data to server %s:%d\n",
		remote_addr_.get_host_name(),remote_addr_.get_port_number()));
	//sprintf()�����ݴ�ӡ���ַ�����
	ACE_OS::sprintf(data_buf, "Client says hello");

	while (local_.send(data_buf,ACE_OS::strlen(data_buf),remote_addr_)!=-1)
	{
		//�ȴ�1��
		ACE_OS::sleep(1);    //�ȴ�������������������Ϣ
		if (accept_data() == -1)
			break;
	}
	return -1;
}