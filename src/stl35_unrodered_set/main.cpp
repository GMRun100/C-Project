#include<unordered_set>
#include<iostream>
using namespace std;


void main()
{
	//元素值唯一，无序的集合，内部通过哈希表实现，查找效率比set高
	unordered_set<int> s = {3,1,2,5,4,3};  //重复元素无法插入


	//插入
	cout << s.insert(9).second << endl;
	cout << s.insert(9).second << endl; //重复插入失败，插入位置是由哈希表的位置确定的，不是人为可以控制的


	//删除
	s.erase(3);

	//查找
	unordered_set<int>::iterator it = s.find(2);  //查找第一个key为1的元素

	if (it != s.end())
	{
		cout << "找到" << *it << endl;
	}
	else
	{
		cout << "未找到该元素";
	}

	for (unordered_set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << "	";
	}
	cout << endl;


	//迭代器类型
	//双向迭代器:支持++ -- == != = *  不支持：[] += -= +n -n
	cout << typeid(unordered_set<int>::iterator::iterator_category).name() << endl;
	unordered_set<int>::iterator it2 = s.begin();
	//set元素值不允许更改
	//因为的元素的位置是由它的值决定的，如果你改了它的元素值，会导致位置不正确
	//*it2 = 111;

	unordered_set<int>::const_iterator cit = s.cbegin();
	//*cit = 111;

	//set、unordered_set中这两个是同一类型
	cout << typeid(unordered_set<int>::iterator::iterator_category).name() << endl;
	cout << typeid(unordered_set<int>::const_iterator::iterator_category).name() << endl;


}