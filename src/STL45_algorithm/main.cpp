//学习划分、排序算法
//GM 2020.1.5

#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;
class A
{
public:
	A(int _a, int _b) :a(_a), b(_b) {}
	int a;
	int b;
};
void Print(int x)
{
	cout << x << "   ";
}

void PrintA(A x)
{
	cout << x.a<<"-"<<x.b << "   ";
}

struct Is2or3
{
	bool operator()(int x)
	{
		return x == 2 || x == 3;
	}

};

bool MyGreater(int a, int b)
{
	return a > b;
}


bool MyGreater2(A a, A b)
{
	return a.a > b.a;
}

void main()
{
	{

		vector<int> v = { 1,2,3,4,5 };

		//分区域，满足仿函数结果为true放到前面，为false放到后面
		vector<int>::iterator itMid = partition(v.begin(), v.end(), Is2or3());

		for_each(v.begin(), itMid, Print);
		cout << endl;

		for_each(itMid, v.end(), Print);
		cout << endl;

	}


	{

		vector<int> v = { 1,2,3,4,5 };

		//分区域，满足仿函数结果为true放到前面，为false放到后面
		//与partition的区别是会保留原来的顺序
		vector<int>::iterator itMid = stable_partition(v.begin(), v.end(), Is2or3());

		for_each(v.begin(), itMid, Print);
		cout << endl;

		for_each(itMid, v.end(), Print);
		cout << endl;

	}


	{

		vector<int> v = { 1,2,3,4,5 };

		//分区域，满足仿函数结果为true放到前面，为false放到后面
		//sort(v.begin(), v.end(),greater<int>());  //使用STL预定义的函数对象
		sort(v.begin(), v.end(), MyGreater);
		for_each(v.begin(), v.end(), Print);
		cout << endl;
	}

	{


		vector<A> v = { A(1,111),A(2,222),A(3,331),A(3,332) };

		//降序，保证相同元素值原有顺序
		stable_sort(v.begin(), v.end(), MyGreater2);
		for_each(v.begin(), v.end(), PrintA);
		cout << endl;
	}


	{

		vector<int> v = { 99,59,60,23,89,45,66 };
		//想知道成绩最高的前三名，后面的成绩顺序无所谓
		partial_sort(v.begin(),v.begin()+3 ,v.end(), greater<int>());
		for_each(v.begin(), v.end(), Print);
		cout << endl;
	}


	{

		vector<int> v = { 99,59,60,23,89,45,66 };
		//把第n大的元素排到第n个位置，不关心其他元素
		nth_element(v.begin(), v.begin() + 3, v.end(), greater<int>());
		for_each(v.begin(), v.end(), Print);
		cout << endl;
	}

}