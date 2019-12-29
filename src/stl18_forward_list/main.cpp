#include<iostream>
#include<forward_list>
using namespace std;

void main()
{
	//构造
	forward_list<int> l;
	//不提供size的成员方法，使用算法distance()获取
	cout << l.max_size() << endl;  //最大的元素个数

	forward_list<int> l2(5);   //创造5个元素的单向链表
	cout << "元素值:" << *l2.begin() << endl;

	forward_list<int> l3(5,111);   //创造5个元素的单向链表,初始值为111
	cout << "元素值:" << *l3.begin() << endl;

	//拷贝构造
	forward_list<int> l4(l3);   //创造5个元素的单向链表,初始值为111
	cout << "元素值:" << *l4.begin() << endl;

	//验证forward_list的内存结构:不连续
	for (forward_list<int>::iterator it = l3.begin(); it != l3.end(); it++)
	{
		cout << &(*it) << "	";
	}
	cout << endl;

	//迭代器
	//验证迭代器类型:前向迭代器
	cout<<typeid(forward_list<int>::iterator::iterator_category).name() << endl;

	//前向迭代器比双向迭代器功能更少一些，支持++、=、！=、==、* 不支持--

	//++
	forward_list<int>::iterator it = l3.begin();
	*(++it)=222;
	*(++it) = 333;
	*(++it) = 444;
	*(++it) = 555;

	//正向遍历
	for (forward_list<int>::iterator it = l3.begin(); it != l3.end(); it++)
	{
		cout << *it << "	";
	}
	cout << endl;

	++it;  //指向最后一个的下一个
	cout << "是否指向最后一个的下一个" << (it == l3.end()) << endl;

	//const_iterator:指向的元素不可赋值
	forward_list<int>::const_iterator it2 = l3.cbegin();
	//*it2 = 1;  //不可赋值


	//插入元素
	forward_list<int> l5;
	l5.push_front(111);  //头部插入

	l5.push_front(222);

	l5.insert_after(l5.begin(), 333);
	for (forward_list<int>::iterator it = l5.begin(); it != l5.end(); it++)
	{
		cout << *it << "	";
	}
	cout << endl;

	//访问元素
	cout << l5.front() << endl;  //访问第一个元素

	//删除元素
	l5.pop_front();   //删除头结点
	/*erase_after删除的逻辑
	pTemp = pDelete->next;
	pDelete->next=pDelete->next->next;
	delete pTemp;
	*/
	l5.erase_after(l5.begin());  //删除迭代器节点的下一个






	for (forward_list<int>::iterator it = l5.begin(); it != l5.end(); it++)
	{
		cout << *it << "	";
	}
	cout << endl;

	l5.clear();  //清空



}