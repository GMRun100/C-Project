//学习traits的用法
//2019.10.26 GM

#include<iostream>
#include<type_traits>
using namespace std;

struct A {};
struct B :A {};
void main()
{
	//判断是否为void类型
	cout << boolalpha;
	cout << is_void<void>::value << endl;
	cout << is_void<int>::value << endl;

	//判断是否是指针
	cout << "is_pointer:" << endl;
	cout << "int:" << is_pointer<int>::value << endl;
	cout << "int*:" << is_pointer<int*>::value << endl;
	cout << "int**:" << is_pointer<int**>::value << endl;
	cout << "int(*)(int):" << is_pointer<int(*)(int)>::value << endl;

	//判断是否是数组
	cout << "int:" << is_array<int>::value << endl;
	cout << "int[3]:" << is_array<int[3]>::value << endl;
	cout << "array<int,3>:" << is_array<array<int, 3>>::value << endl;  //模板类
	cout << "string:" << is_array<string>::value << endl;
	cout << "string[3]:" << is_array<string[3]>::value << endl;

	//判断是否是基类
	cout << "is_base_of:" << endl;
	cout << "int,int:" << is_base_of<int, int>::value << endl;
	cout << "A,A:" << is_base_of<A, A>::value << endl;
	cout << "A,B:" << is_base_of<A, B>::value << endl;
	cout << "A,const B:" << is_base_of<A, const B>::value << endl;
	cout << "A&,B&:" << is_base_of<A&, B&>::value << endl;
	cout << "B,A:" << is_base_of<B, A>::value << endl;


	//判断是否是const
	cout << is_const<int>::value << endl;
	cout << is_const<const int>::value << endl;
	//*前面的是修饰被指向的内容，*后面是修饰指针
	cout << is_const<const int*>::value << endl;
	cout << is_const<int* const>::value << endl;
	//常量引用，则不能修改引用的内容
	cout << is_const<const int&>::value << endl;

	//判断是否是object(对象)
	cout << "is_object:" << endl;
	cout << is_object<int>::value << endl;
	cout << is_object<int&>::value << endl;
	cout << is_object<A>::value << endl;
	cout << is_object<A&>::value << endl;
}