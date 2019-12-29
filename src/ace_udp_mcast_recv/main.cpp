#include"recv.h"

#pragma comment(lib,"G:\\02.Learning\\C++study\\Debug\\ACEd.lib")

int main(int argc, char* argv[])
{
	Receiver_Multicast m(2000);

	while (m.recv_multicast() != -1)
	{
		ACE_DEBUG((LM_DEBUG,"Multicaster successful \n"));
	}

	ACE_DEBUG((LM_ERROR,"Multicaster failed \n"));
	exit(-1);
}