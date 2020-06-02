#include<iostream>
#include<vector>
using namespace std;

//实现一个函数模板，要求可以传入迭代器时，返回该迭代器指向的元素值

template<typename T>
typename T::value_type fun(T it)   //value_type表示该容器迭代器指向的元素的类型
/*加了typename 才表示类型*/
{
	return *it;
}


//利用模板的偏特化判断是否这个类型是指针
template<typename T>
struct IsPointer
{
	static const bool value = false;
};
template<typename T>
struct IsPointer<T *>   //偏特化
{
	static const bool value = true;
};

//参考IsPointer,写一个中间类，实现对普通类型与指针类型都具有value_type内部类型
template<class T>
struct my_traits  //不是指针类型
{
	typedef typename T::value_type value_type;
	/*加了typename 才表示类型,否则编译器以为是T的静态成员*/
};

template<class T>
struct my_traits<T *>  //是指针类型
{
	typedef T value_type;
};

//利用my_traits实现一个fun2
template<class T>
typename my_traits<T>::value_type fun2(T it)   //value_type表示该容器迭代器指向的元素的类型
/*加了typename 才表示类型*/
{
	return *it;
}



void main()
{

	vector<int> v = { 1,2,3,4,5 };

	cout << fun<vector<int>::iterator>(v.begin()) << endl;

	//当参数为原始指针时
	int v2[] = { 1,2,3,4,5 };
	int* pV = v2;
     //cout<<fun<int *>(pV)<<endl;   //int * 没有内部类型value_type

	cout << fun2<int*>(pV) << endl;




}