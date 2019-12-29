#include"server.h"
#pragma comment(lib,"G:\\02.Learning\\C++study\\Debug\\ACEd.lib")

//参数：argc 输入的参数个数  argv 存储输入的参数      
int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		ACE_DEBUG((LM_DEBUG,"Usage %s <Port Number>",argv[0]));
		ACE_OS::exit(1);
	}
	Server server(ACE_OS::atoi(argv[1]));
	server.accept_data();
	return 1;
}

