#include<iostream>
using namespace std;
#include<list>

int main()
{
	//创建
	list<int> l;
	cout << "元素个数：" << l.size() << endl;

	list<int> l2(5);   //默认值为类型的默认值
	cout << "元素个数：" << l2.size() <<"	"<<*(l2.begin())<< endl;


	list<int> l3(5,111);   
	cout << "元素个数：" << l3.size() << "	" << *(l3.begin()) << endl;

	list<int> l4(l3);  //拷贝构造
	cout << "元素个数：" << l4.size() << "	" << *(l4.begin()) << endl;

	//验证list内存空间不连续
	for (list<int>::iterator it = l3.begin(); it != l3.end(); it++)
	{
		cout << &(*it) << "	";
	}
	cout << endl;

	//list的迭代器为双向迭代器
	cout << typeid(list<int>::iterator::iterator_category).name() << endl;

	//双向迭代器支持： ++ -- != == =*
	//双向迭代器不支持: []	+n	-n +=n -=n

	//迭代器的好处：可以使算法不需要知道容器的内存结构

	//list插入元素
	list<int> l5;
	//头部插入
	l5.push_front(111);

	l5.push_back(444);
	l5.push_back(555);

	//在某个迭代器的位置插入
	l5.insert(l5.begin(), 222);

	//插入n个相同的元素
	l5.insert(l5.begin(), 3,333);

	for (list<int>::iterator it = l5.begin(); it != l5.end(); it++)
	{
		cout << (*it) << "	";
	}
	cout << endl;

	//访问链表第一个元素
	l5.front() = 1;  //front函数返回的是一个引用
	cout <<"访问链表第一个元素" <<l5.front() << endl;
	//访问链表最后一个元素
	cout << "访问链表最后一个元素" <<l5.back() << endl;


	//删除元素
	//删除最后一个元素
	l5.pop_back();
	//删除第一个元素
	l5.pop_front();
	//删除某个迭代器指定的元素
	l5.erase(l5.begin());

	//清空链表
	//l5.clear();

	for (list<int>::iterator it = l5.begin(); it != l5.end(); it++)
	{
		cout << (*it) << "	";
	}
	cout << endl;

}