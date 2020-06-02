//学习迭代器萃取类
//2020.1.27 GM 

#include<iostream>
#include<iterator>
#include<vector>

using namespace std;


//利用系统的iterator_traits实现fun3(fun1和fun2d的示例参见STL51项目中)
template<class T>
typename iterator_traits<T>::value_type fun3(T it)   //value_type表示该容器迭代器指向的元素的类型
/*加了typename 才表示类型*/
{
	return *it;
}



void main()
{
	/*迭代器的特性
	vector<int>::iterator::value_type;
	vector<int>::iterator::iterator_category;
	vector<int>::iterator::pointer;
	vector<int>::iterator::reference;
	vector<int>::iterator::difference_type;
	*/



	//非指针类型
	cout << typeid(iterator_traits<vector<int>::iterator>::value_type).name() << endl;
	//指针类型(特殊的迭代器类型)
	cout << typeid(iterator_traits<int *>::value_type).name() << endl;

	vector<int> v = { 1,2,3,4,5 };

	cout << fun3<vector<int>::iterator>(v.begin()) << endl;

	//当参数为原始指针时
	int v2[] = { 1,2,3,4,5 };
	int* pV = v2;
	//cout<<fun<int *>(pV)<<endl;   //int * 没有内部类型value_type

	cout << fun3<int*>(pV) << endl;


}