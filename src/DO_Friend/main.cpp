#include"box.h"

int main()
{
	Box box;
	BigBox big;
	box.setWidth(10.0);

	//使用友元函数输出宽度
	printWidth(box);

	//使用友元类中的方法设置宽度
	big.print(20, box);

	getchar();

	return 0;
}