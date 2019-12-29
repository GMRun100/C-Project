#include"server.h"

#pragma comment(lib,"G:\\02.Learning\\C++study\\Debug\\ACEd.lib")
int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		ACE_ERROR((LM_ERROR, "Usage %s <port_num>", argv[0]));
		ACE_OS::exit(1);
	}

	Server server(ACE_OS::atoi(argv[1]));
	server.accept_connections();
	return 1;
}