#include"box.h"

int main()
{
	Box box;
	BigBox big;
	box.setWidth(10.0);

	//ʹ����Ԫ����������
	printWidth(box);

	//ʹ����Ԫ���еķ������ÿ��
	big.print(20, box);

	getchar();

	return 0;
}