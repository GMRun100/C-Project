#include"client.h"

#pragma comment(lib,"G:\\02.Learning\\C++study\\Debug\\ACEd.lib")

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		ACE_DEBUG((LM_DEBUG,"Usage %s <hostname> <port_number>\n",argv[0]));
		ACE_OS::exit(1);
	}
	Client client(ACE_OS::atoi(argv[1]));
	client.connect_to_server();
	client.send_to_server();
	return 0;
}
