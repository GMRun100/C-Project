//学习SYL中的array
//2019.10.29 GM 

#include<iostream>
#include<array>
#include<algorithm>
using namespace std;

void main()
{
	array<int, 5> arr;//元素默认值随机
	cout << arr.size() <<"   "<< arr[0] << endl;

	array<int, 5> arr2 = {1,2,3};  //其他值赋值为0
	cout << arr2.size() << "   " << arr2[0] << endl;

	//拷贝构造
	array<int, 5> arr3(arr2);
	cout << arr3.size() << "   " << arr3[3] << endl;	
	arr[0] = 11;
	arr[1] = 22;
	arr[2] = 33;
	arr.at(3) = 44;
	arr.at(4) = 55;
	for (size_t i = 0; i < arr.size(); i++)
	{
		//cout << arr2[i] << "	";
		cout<<arr.at(i)<< "	";
	}
	cout << endl;

	cout <<"获取第一个元素" <<arr.front() << endl;
	cout << "获取最后一个元素" << arr.back() << endl;
	cout << "检测数组长度是否为0：" << arr.empty()<< endl;  
	array<int, 0> arr4;
	cout << "检测arr4数组长度是否为0：" << arr4.empty() << endl;
	cout << "返回内部数组的首地址：" << arr.data()<<","<<&arr[0] << endl;

	//array容器对应的迭代器类型
	using ArrayIterator = array<int, 5>::iterator;  
	//ArrayIterator::value_type    //迭代器所指的元素类型
	//ArrayIterator::difference_type  //两个迭代器相减得到的值的类型
	//ArrayIterator::pointer //迭代器所指的元素的指针类型
	//ArrayIterator::iterator_category  //迭代器的五种类型之一的类型
	//ArrayIterator::reference   //迭代器所指的元素的引用类型

	//array的迭代器类型为random_access_iterator_tag
	cout << typeid(ArrayIterator::iterator_category).name() << endl;


	array<int, 5>::iterator it1 = arr.begin() + 3;
	cout << *it1 << endl;

	//++
	it1++; //迭代器支持自增自减
	cout << *it1 << endl;

	//--
	it1--;
	it1--;
	cout << *it1 << endl;


	//[],相当于当前位置加1
	cout << it1[1] << endl;
	
	//随机访问迭代器可以修改指向元素的值

	*it1 = 333;
	cout << *it1 << endl;

	//const iterator
	//返回的迭代器是只读的
	array<int, 5>::const_iterator cit1 = arr.cbegin();
	cout << *cit1 << endl;


	//反向遍历
	for (array<int, 5>::reverse_iterator it3 = arr.rbegin(); it3 < arr.rend(); it3++)
	{
		cout << *it3 << "	";
	}
	cout << endl;
}