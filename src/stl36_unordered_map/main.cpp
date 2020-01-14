#include<unordered_map>
#include<iostream>
using namespace std;

void main()
{
	//存储键值对key值唯一，无序
	//内存结构采用hash表，元素的位置由哈希值决定，无push_back等
	unordered_map<int, string>  m = { {1,"AAA"},{3,"CCC"} ,{2,"BBB"}, {1,"aaa"} };


	//插入元素
	m.insert(make_pair(4, "DDD"));
	m.insert(make_pair(4, "ddd"));

	m[5] = "EEE";  //如果key不存在，就是插入5->"EEE"
	m[5] = "eee";  //如果key存在，就是修改value


	//查找
	//unordered_map查找，效率比map高
	unordered_map<int,string>::iterator it = m.find(5);
	if (it != m.end())
	{
		cout << "找到:"<<it->second.c_str()<< endl;
	}
	else
	{
		cout << "未找到该元素";
	}




	for (unordered_map<int, string>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << "->" << it->second.c_str() << "	";
	}
	cout << endl;


	cout << typeid(unordered_map<int,string>::iterator::iterator_category).name() << endl;

	unordered_map<int, string>::iterator it = m.begin();
	//it->first = 111;  //key值无法修改，因为元素的位置由key决定，如果更改key值，得到的hash值与存储的位置不符合
	it->second = "aaa";  //value值可以更改

	unordered_map<int, string>::const_iterator cit = m.cbegin();
	//cit->second = "aaa";  //const_iterator指向的元素内容不可修改





}
