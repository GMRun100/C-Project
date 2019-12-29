#include<set>
#include<iostream>
using namespace std;


void main()
{
	//multiset与set的唯一区别就是键值是否重复
	multiset<int> m= { 3,2,5,1,4,3 };//两个3都可以重复插入
	cout << "m元素个数" << m.size() << endl;
	//插入成功，返回插入元素的迭代器
	m.insert(9);
	m.insert(9);

	m.erase(3);  //删除所有元素值为3的元素


	for (multiset<int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << *it << "	";
	}
	cout << endl;

	//查找某个元素，找到则返回指向该元素的迭代器，没找到则返回end()
	//只能找到一个元素为9 的迭代器
	multiset<int>::iterator it=m.find(9);  
	if (it != m.end())
	{
		cout << "查找成功！" <<*it<< endl;
	}
	else
	{
		cout << "查找成功！" << endl;
	}


	//查找所有元素值为9的迭代器,返回指向元素9 的迭代器区间
	pair<multiset<int>::iterator, multiset<int>::iterator> pit=m.equal_range(9);
	for (multiset<int>::iterator it = pit.first; it != pit.second; it++)
	{
		cout << *it << "	";
	}
	cout << endl;

	//迭代器：双向迭代器
	cout << typeid(multiset<int>::iterator::iterator_category).name() << endl;



}