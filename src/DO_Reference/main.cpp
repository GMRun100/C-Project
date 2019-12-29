//本实例主要是学习引用的使用技巧
#include<iostream>
using namespace std;

//函数声明
//形参为普通引用
void Swap(int& x, int& y);  

void Foo(int& i);
//形参为常量
void Foo1(const int i);
//形参为常量引用
void Foo2(const int& i);


int main()
{


	//********************普通引用********************
	int itmp;
	itmp = 10;
	//定义普通引用
	int& itmp_r = itmp;		//引用必须在定义的时候就要初始化

	//输出地址和值
	cout << "itmp=" << itmp <<"	address="<<&itmp<< endl;
	cout << "itmp_r=" << itmp_r << "	address=" << &itmp_r <<endl;    //引用指向了同一个地址

	//引用作为参数
	int a = 10;
	int b = 20;
	
	cout << "交换前a的值，a:" << a << endl;
	cout << "交换前b的值，b:" << b << endl;
	swap(a, b);
	cout << "交换后a的值，a:" << a << endl;
	cout << "交换后b的值，b:" << b << endl;

	//****************************常量引用***************************

	int itemp2 = 10;

	//double& dtemp2_r = itemp2;    //编译器会报错，引用的类型必须与其所引用对象的类型一致

	/*解释
		const double &dtemp2_r = itemp2;
		由于类型不匹配，实际相当于：
		const double inner_tmp = (double)itemp2;  //这里就产生了一个临时变量
		const double &dtemp2_r = inner_tmp;
		临时的中间变量都是const，所有没有const的引用会失败。
	*/

	//常量引用的初始值可以是任意表达式，只要该表达式的结果能转换成引用的类型即可
	const int& itemp2_r = itemp2;
	const double& dtemp2_r = itemp2;  //编译通过

	cout << "the value of itemp2 : " << itemp2 << endl;
	cout << "the value of itemp2_r : " << itemp2_r << endl;
	cout << "the value of dtemp2_r : " << dtemp2_r << endl;

	//改变被引用对象的值
	itemp2 = itemp2 * 2;
	cout << "the value of itemp2 : " << itemp2 << endl;			//output:20
	//当对象类型与常量引用类型相同时，常量引用会绑定到实际对象
	cout << "the value of itemp2_r : " << itemp2_r << endl;		//output:20
	//对于一般表达式，常量引用绑定到临时变量上
	cout << "the value of dtemp2_r : " << dtemp2_r << endl;		//output:10 

	
	cout << "the address of itemp2 : " << &itemp2 << endl;  //output:003AF7A4
	
	Foo(itemp2);	//output:003AF7A4
	Foo1(itemp2);	//output: 003AF6A8
	Foo2(itemp2);	//output:003AF7A4

	//Foo(1);	//编译器报错，非常量引用的初始值必须为左值
	Foo2(1);	//编译通过

	getchar();

	return 0;

}
/********************************************
* @brief  :交换参数x和y的值
* @param  :int& x, int& y
* @note	  :此处采用的形参为非常量引用，一般形参为非常量引用时，表示引用的值在函数内部可以被修改
* @output :none
* @time   :2019-07-27
*********************************************/
void Swap(int& x, int& y)
{
	int tmp;
	tmp = x;
	x = y;
	y = tmp;

	return;
}

void Foo(int& i)
{
	cout << "the address of i in Foo : " << &i << endl;
}

void Foo1(const int i)
{
	cout << "the address of i in Foo1 : " << &i << endl;
}

void Foo2(const int& i)
{
	cout << "the address of i in Foo2 : " << &i << endl;
}