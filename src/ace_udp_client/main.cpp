#include"client.h"

#pragma comment(lib,"G:\\02.Learning\\C++study\\Debug\\ACEd.lib")

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		ACE_OS::printf("Usage: %s <port_number> \n", argv[0]);
		ACE_OS::exit(1);
	}
	Client client(ACE_OS::atoi(argv[1]));
	client.send_data();
	getchar();
	return 1;
}