#include<map>
#include<iostream>
using namespace std;

ostream& operator<<(ostream& os, multimap<int, string>::value_type &p)
{
	cout << p.first << "->" << p.second.c_str();
	return os;
}

template <class T>
void Print(T begin, T end)
{
	for (T p = begin; p != end; ++p)
	{
		cout << *p << "  ";
	}
	cout << endl;
}






void main()
{

	//class map : public _Tree<_Tmap_traits<_Kty, _Ty, _Pr, _Alloc, false>>
	//false表示key不可以重复
	map<int, string> m;
	//class multimap : public _Tree<_Tmap_traits<_Kty, _Ty, _Pr, _Alloc, true>>
	//true表示key可以重复
	//可以插入key相同的键值对pair，但依然是有序的
	multimap<int, string> mm = { {1,"AAA"},{2,"BBB"},{1,"aaa"} };
	mm.insert(make_pair<int, string>(3, "CCC"));
	mm.insert(make_pair<int, string>(3, "CCC"));

	//查找元素

	multimap<int, string>::iterator it = mm.find(1);  //查找第一个key为1的元素

	if (it != mm.end())
	{
		cout << "找到" << it->second.c_str() << endl;
	}
	else
	{
		cout << "未找到该元素";
	}

	//查找所有key为1元素的迭代器范围

	auto pa = mm.equal_range(1);

	//key为1元素的迭代器范围的遍历
	for (multimap<int, string>::iterator it = pa.first; it != pa.second; it++)
	{
		cout << it->first << "->" << it->second.c_str() << "	";
	}
	cout << endl;


	mm.erase(1);//删除所有key为1的元素

	//不支持[]运算符重载，因为我们的key是可以重复的，m[1]不知道返回哪个value
	//mm[1] = "aa";

	for (multimap<int, string>::iterator it = mm.begin(); it != mm.end(); it++)
	{
		cout << it->first<<"->" <<it->second.c_str()<< "	";
	}
	cout << endl;

	//验证迭代器的类型
	//双向迭代器：不支持[] += -= +n -n 
	cout << typeid(multimap<int, string>::iterator::iterator_category).name() << endl;

	multimap<int, string>::iterator it2 = mm.begin();
	//it2->first = 111;  //key不可更改，因为multimap是有序的
	it2->second = "AAAAAA";   //value可以改变



	Print<multimap<int, string>::reverse_iterator>(mm.rbegin(), mm.rend());





}