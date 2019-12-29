//学习vector的用法
//2019.10.31 GM

#include<iostream>
using namespace std;
#include<vector>

void main()
{
	//创建空Vector
	vector<int> v1;
	cout << "容量为：" << v1.capacity() << "	元素个数：" << v1.size() << endl;

	//空间为5，元素个数为5
	vector<int> v2(5);
	cout << "容量为：" << v2.capacity() << "	元素个数：" << v2.size() <<"	V2[0]:"<<v2[0] <<endl;

	//空间为5，元素个数为5，每个元素的初始值均为111
	vector<int> v3(5,111);
	cout << "容量为：" << v3.capacity() << "	元素个数：" << v3.size() << "	V3[0]:" << v3[0] << endl;

	//拷贝构造Vector
	vector<int> v4(v3);
	cout << "容量为：" << v4.capacity() << "	元素个数：" << v4.size() << "	V4[0]:" << v4[0] << endl;

	//vector重载了[]运算符
	v2[0] = 1;
	v2[1] = 2;
	v2[2] = 3;
	v2.at(3) = 4;
	v2.at(4) = 5;
	for (size_t i = 0; i < v2.size(); i++)
	{
		//cout << v2[i] << "	";
		cout << v2.at(i) << "	";
	}

	cout << endl;


	//验证vector的内存结构
	for (size_t i = 0; i < v2.size(); i++)
	{
		//cout << v2[i] << "	";
		cout << &v2.at(i) << "	";
	}
	cout << endl;


	//vector的迭代器为随机访问迭代器
	cout << typeid(vector<int>::iterator::iterator_category).name() << endl;

	vector<int>::iterator it = v2.begin();
	cout << "开头迭代器指向的元素："<<*it << endl;

	++it;
	cout << "第二个元素：" << *it << endl;

	cout << "第四个元素：" << *(it+2) << endl;  //it还是指向第二个元素

	it -= 1;
	cout << "第一个元素：" << *it << endl;

	cout << "第五个元素：" << it[4] << endl;   //it没变


	//使用迭代器遍历元素
	for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout  << *it <<"	";
	}
	cout << endl;
	
	//常迭代器指向的元素值不可改变,类似const int* p
	vector<int>::const_iterator it2 = v2.cbegin();
	//*it2 = 111;  //提示表达式必须是可修改的左值


	//反向迭代器
	for (vector<int>::reverse_iterator it = v2.rbegin(); it != v2.rend(); it++)
	{
		cout << *it << "	";
	}
	cout << endl;


	//插入元素

	vector<int> v;
	cout << "v容量为：" << v.capacity() << "	v元素个数：" << v.size() << endl;

	//尾部插入
	v.push_back(1);
	cout << "v容量为：" << v.capacity() << "	v元素个数：" << v.size() << endl;
	v.push_back(2);
	cout << "v容量为：" << v.capacity() << "	v元素个数：" << v.size() << endl;

	//向某一个迭代器指向的位置插入
	v.insert(v.begin(), 3);  //v:3 1 2
	cout << "v容量为：" << v.capacity() << "	v元素个数：" << v.size() << endl;

	v.insert(v.end(),2,4);  //v:3 1 2 4 4
	cout << "v容量为：" << v.capacity() << "	v元素个数：" << v.size() << endl;

	for (vector<int>::const_iterator it = v.cbegin(); it != v.cend(); it++)
	{
		cout << *it << "	";
	}
	cout << endl;

	//访问第一个元素
	cout << "front:" << v.front() << endl;
	cout << "back:" << v.back() << endl;
	cout << "at3:" << v.at(3) << endl;



	//删除元素

	//删除最后一个元素
	v.pop_back(); //3 1 2 4
	cout << "v容量为：" << v.capacity() << "	v元素个数：" << v.size() << endl;

	//删除开头的元素
	v.erase(v.begin());   // 1 2 4
	cout << "v容量为：" << v.capacity() << "	v元素个数：" << v.size() << endl;

	//删除最后一个元素
	v.erase(v.end()-1);  // 1 2
	cout << "v容量为：" << v.capacity() << "	v元素个数：" << v.size() << endl;

	for (vector<int>::const_iterator it = v.cbegin(); it != v.cend(); it++)
	{
		cout << *it << "	";
	}
	cout << endl;

	//删除所有元素，不会改变容量，元素个数为0
	v.clear();
	cout << "v容量为：" << v.capacity() << "	v元素个数：" << v.size() << endl;

	//当size和capacity相等时继续添加数据，否则vector会扩容，每次扩容都是增加当前空间的1/2(第一次除外)

	//测试Vector的扩容规律
	cout << "测试Vector的扩容规律" << endl;
	vector<int> v6;
	for (size_t i = 0; i < 50; i++)
	{
		v6.push_back(i);
		cout << "v6容量为：" << v6.capacity() << "	v6元素个数：" << v6.size() << endl;
	}

	

}