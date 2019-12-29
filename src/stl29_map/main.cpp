#include<map>
#include<iostream>
using namespace std;
#include<vector>

void main()
{
	//map映射，每个元素都是key-value键值对，key不能重复，value可以重复，有序

	map<int, string> m;
	cout << "元素个数:" << m.size() << endl;

	//初始化列表构造map
	map<int, string> m2 = { {3,"ccc"},{1,"AAA"},{2,"BBB"} };
	cout << "元素个数:" << m2.size() << endl;

	//拷贝构造
	map<int, string> m3(m2);
	cout << "元素个数:" << m3.size() << endl;


	//验证容器中的元素类型
	cout << typeid(map<int, string>::value_type).name() << endl;


	//一对值pair类模板
	pair<int, float> p1;
	p1.first = 1;
	p1.second = 2.34f;
	cout << "first:" << p1.first << " second:" << p1.second << endl;
	//利用构造函数
	pair<int, float> p2(2, 3.45);
	cout << "first:" << p2.first << " second:" << p2.second << endl;

	//使用make_pair算法构造pair
	pair<short, char> p3 = make_pair<short, char>(3, 'A');
	cout << "first:" << p3.first << " second:" << p3.second << endl;

	map<int, string> m4 = { pair<int,string>(3,"CCC"),make_pair(2,"BBB"),make_pair(1,"AAA") };
	cout << "元素个数:" << m4.size() << endl;




	//插入元素
	map<int, string> m5;
	m5.insert(pair<int, string>(1, "AAA"));

	pair<int, string> p22(2, "BBB");
	m5.insert(p22);

	//可以通过insert返回值的成员.second查看是否插入成功，true成功，false是失败
	cout<<"查看插入是否成功:"<<m5.insert(make_pair<int, string>(2, "BBB")).second<<endl;   //插入重复的元素,插入失败


	m5.insert(make_pair(3, "CCC"));



	//插入其他容器中的元素
	vector<pair<int, string>> v = { {4,"DDD"},{5,"EEE"},{6,"FFF"} };

	m5.insert(v.begin(), v.end());

	//[key]=value
	m5[7] = "ggg";

	m5[8];   //也可以正常插入，相当于(8,"")
	m5[2] = "bbb";   //对于已经存在的key,相当于是修改元素点的value

	for (map<int, string>::iterator it = m5.begin(); it != m5.end(); it++)
	{
		cout << it->first << "->" << it->second.c_str() << "     ";
	}
	cout << endl;

	//查找元素:找到返回指向该元素的迭代器，否则返回end()
	auto it2 = m5.find(3);
	if (it2 != m5.end())
	{
		cout << "找到:" << it2->first << "->" << it2->second.c_str() << endl;
	}
	else
	{
		cout << "未找到!" << endl;
	}
	it2 = m5.find(33);
	if (it2 != m5.end())
	{
		cout << "找到:" << it2->first << "->" << it2->second.c_str() << endl;
	}
	else
	{
		cout << "未找到!" << endl;
	}


	//[key]:通过key获取相应的value值，但是需要注意，这样写，如果key不存在，则会插入一个(key-默认值)的元素
	cout << "[key]" << m[3].c_str() << endl;






	//删除元素
	//删除key为3的元素
	m5.erase(3);

	//删除某个迭代器指向的元素
	m5.erase(m5.begin());
	for (map<int, string>::iterator it = m5.begin(); it != m5.end(); it++)
	{
		cout << it->first << "->" << it->second.c_str() << "     ";
	}
	cout << endl;
	//删除迭代器区间[)的元素
	map<int, string>::iterator it = m5.begin();
	it++; it++; it++;
	m5.erase(m5.begin(), it);  //此时it所指向的元素没有删除，而是之前的元素被删除






	for (map<int, string>::iterator it = m5.begin(); it != m5.end(); it++)
	{
		cout << it->first << "->" << it->second.c_str() << "     ";
	}
	cout << endl;


	//清空所有元素
	m5.clear();

	//迭代器

	map<int, string> m6;
	m6.insert(make_pair(3, "CCC"));
	m6.insert(make_pair(1, "AAA"));
	m6.insert(make_pair(2, "BBB"));

	//查看迭代器类型:双向迭代器：支持++ -- * = != ==   不支持:[] += -= +n -n
	cout << typeid(map<int,string>::iterator::iterator_category).name() << endl;
	map<int, string>::iterator it6 = m6.begin();
	//it6->first = 111;   //key值不允许修改，map是按着key排好序的，如果更改key值会打乱顺序
	it6->second = "aaa";    //value允许修改

	++it6;
	cout << it6->first << "->" << it6->second << endl;
	--it6;
	cout << it6->first << "->" << it6->second << endl;
	cout << "回到开头" << (it6 == m6.begin()) << endl;


	//const_iterator:指向的元素内容不可修改
	map<int, string>::const_iterator cit6 = m6.begin();
	//cit6->first = 111;
	//cit6->second = "aa";  //value值也不可修改



	//遍历元素
	for (map<int, string>::iterator it = m6.begin(); it != m6.end(); it++)
	{
		cout << it->first << "->" << it->second <<"   ";
	}
	cout << endl;

}
