#include<deque>
#include<iostream>
using namespace std;
 

void main()
{
	//构造双端队列
	deque<int> d;
	cout << "元素的个数" << d.size()<< endl;

	deque<int> d2(5);//指定元素个数
	cout << "元素的个数" << d2.size() <<"	"<<d2[0]<< endl;

	deque<int> d3(5,111); //指定元素个数，指定元素值111
	cout << "元素的个数" << d3.size() << "	" << d3[0] << endl;


	//拷贝构造
	deque<int> d4(d3);
	cout << "元素的个数" << d4.size() << "	" << d4[3] << endl;


	//像数组一样的访问元素(内存空间并不是连续的)
	d2[0] = 1;
	d2[1] = 2;
	d2.at(2) = 3;
	d2.at(3) = 4;
	d2.at(4) = 5;
	for (size_t i = 0; i < d2.size(); i++)
	{
		cout << d2[i] << "	";
	}
	cout << endl;


	//验证deque的内存空间不是连续的

	{
		deque<int> d5;
		for (size_t i = 0; i < 20; i++)
		{
			d5.push_back(i);
			cout << "元素：	" << d5[i] << "	" << &d5[i] << '\t';
			if ((i + 1) % 4 == 0)
				cout << endl;
		}
		cout << endl;
	}



	//deque的迭代器为随机访问迭代器
	cout << typeid(deque<int>::iterator::iterator_category).name() << endl;

	//支持++、--、+=n,-=n,[],+n,-n
	deque<int>::iterator it = d2.begin();
	*it = 111;
	cout << *it << endl;
	

	it++;
	cout << *it << endl;

	it += 2;
	cout << *it << endl;

	cout << *(it-3) << endl;  //it自身没变

	cout << it[1] << endl;  //指向最后一个元素

	//const itrater
	deque<int>::const_iterator it2 = d2.cbegin();
	//*it2 = 1111;   //类似于const int *

	{
		for (deque<int>::iterator it = d2.begin(); it != d2.end(); it++)
		{
			cout << *it << "	";
		}
		cout << endl;
	}


	//反向迭代器
	{
		for (deque<int>::reverse_iterator rit = d2.rbegin(); rit != d2.rend(); rit++)
		{
			cout << *rit << "	";
		}
		cout << endl;
	}


	//插入
	deque<int> d5;
	d5.push_back(1);
	d5.push_front(2);  //从头部插入，vector没有此方法
	d5.insert(d5.begin(), 3);   //在迭代器位置插入
	d5.insert(d5.end(), 2, 4);


	for (deque<int>::iterator it = d5.begin(); it != d5.end(); it++)
	{
		cout << *it << "	";
	}
	cout << endl;


	//访问元素

	d5.at(0) = 1111;
	d5[1] = 2222;

	cout << d5.front() << endl;   //返回第一个元素

	cout << d5.back() << endl;    //返回最后一个元素

	//删除

	d5.pop_back();  //尾部删除
	d5.pop_front();	//头部删除
	d5.erase(d5.begin());    //删除某个迭代器指定的元素

	for (deque<int>::iterator it = d5.begin(); it != d5.end(); it++)
	{
		cout << *it << "	";
	}
	cout << endl;

	d5.clear();	//全部清空

	cout << "元素个数:" << d5.size() << endl;







}
