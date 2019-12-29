#include<set>
#include<iostream>
#include<vector>
#include<list>
using namespace std;

void main()
{
	//创建
	set<int> s;

	//通过初始化列表构造
	//set<int> s2 = { 3,2,5,1,4,3 };   //Set的元素个数唯一且有序

	//改为降序排列
	set<int,greater<int>> s2 = { 3,2,5,1,4,3 };

	cout << "s2元素个数" << s2.size() << endl;

	set<int> s3(s2.begin(),s2.end());
	cout << "s3元素个数" << s3.size() << endl;

	//插入元素
	cout << s2.insert(9).second << endl; //判断是否插入成功，插入成功second返回为1.失败为0

	//重复插入元素无效
	cout << s2.insert(9).second << endl;


	//插入一个迭代器区间
	vector<int> v = { 6,7,8,9 };
	s2.insert(v.begin(), v.end());

	list<int> l = { 11,12,13 };
	s2.insert(l.begin(), l.end());

	//遍历元素
	for (set<int>::iterator it = s2.begin(); it != s2.end(); it++)
	{
		cout << *it << "	";
	}
	cout << endl;



	//删除值为6的元素
	s2.erase(6);
	
	//删除迭代器指向的元素
	s2.erase(s2.begin());

	//遍历元素
	for (set<int>::iterator it = s2.begin(); it != s2.end(); it++)
	{
		cout << *it << "	";
	}
	cout << endl;

	//删除迭代器区间
	set<int>::iterator it = s2.begin();
	it++;
	it++;
	it++;

	s2.erase(s2.begin(), it);

	//查找集合中的元素
	//找到返回该元素的迭代器，否则返回end();
	set<int>::iterator it2=s2.find(9);   
	if (it2 != s2.end())
	{
		cout << "找到该元素"<<endl;
	}
	else
	{
		cout << "未找到该元素" << endl;
	}




	//遍历元素
	for (set<int>::iterator it = s2.begin(); it != s2.end(); it++)
	{
		cout << *it << "	";
	}
	cout << endl;


	//清空元素
	//s2.clear();

	//迭代器类型:双向跌迭代器 支持++ -- * != == = 不支持:[] += -= +n -n
	cout << typeid(set<int>::iterator::iterator_category).name() << endl;

	//获取第一个元素
	set<int>::iterator it3 = s2.begin();	//获取第一个元素
	cout << "第一个元素" << *it3 << endl;

	//*it3 = 111;   //set元素中的值不可修改

	++it3;
	cout << "第二个元素" << *it3 << endl;

	--it3;
	cout << "是否指向开头" << (it3 == s2.begin()) << endl;




}