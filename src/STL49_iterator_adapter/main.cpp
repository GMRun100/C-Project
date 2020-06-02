//学习迭代器适配器

#include<vector>
#include<iterator>
#include<iostream>
#include<deque>
using namespace std;

void main()
{
	{   
	vector<int> v = { 1,2,3,4,5 };

	//反向迭代器适配器，类模板
	reverse_iterator<vector<int>::iterator> rit(v.end());
	cout << *rit << endl;
	++rit;//普通迭代器的操作
	cout << *rit << endl;

	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
	{
		cout << *it << "   ";
	}
	cout << endl;

	}
	//适配器类，接口是迭代器，功能实现头部插入功能
	//用户像使用迭代器一样的插入元素

	{
		//容器必须有push_front的成员方法
		deque<int> d = { 1,2,3,4,5 };

		front_insert_iterator<deque<int>> fit(d);
		*fit = 111;
		for (deque<int>::iterator it = d.begin(); it != d.end(); ++it)
		{
			cout << *it << "   ";   
		}
		cout << endl;

	}


	{
		vector<int> v= { 1, 2, 3, 4, 5 };
		back_insert_iterator<vector<int>> fit(v);
		*fit = 111;
		for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		{
			cout << *it << "   ";
		}
		cout << endl;

	}

	{
		//实现在指定位置插入
		vector<int> v = { 1, 2, 3, 4, 5 };
		insert_iterator<vector<int>> fit(v,v.begin()+2);
		*fit = 111;//在第二个元素后面插入111
		*fit = 222;
		*fit = 333;
		for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		{
			cout << *it << "   ";
		}
		cout << endl;

	}

	{

		//像使用迭代器一样的输入、输出
		//提供一个适配器，接口就是迭代器的接口，内部实现依然用cin,cout
		istream_iterator<int> itEnd;//表示输入结束
		istream_iterator<int> it(std::cin); //可以开始输入了,按下ctrl+z表示输入结束
		int num1 = *it;//获取第一个输入的值，
		it++;
		int num2 = *it;//获取输入的第二个值
		it++;
		cout << num1 << endl;
		cout << num2 << endl;

		if (it == itEnd)
			cout << "已经没输入了" << endl;
	}
	cout << "---------------------------" << endl;
	{
		ostream_iterator<int> it(std::cout, "\n");
		*it = 111;   //等价于cout<<111<<"\n"
		*it = 222;	//等价于cout<<222<<"\n"

	}

}