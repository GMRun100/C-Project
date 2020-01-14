//学习非修改序列算法  GM 2020.1.4

#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

//判断这个值是否为3
bool Is3(int x)
{
	return x == 3;
}

void Print(int x)
{
	cout << x << "   ";
}


struct Is3_FO
{
	bool operator()(int x)
	{
		return x == 3;
	}
};


void main()
{
	//数据都放在容器中
	vector<int> v= {1, 2, 3, 4, 5};


	{
		//查找，算法不直接操作容器，他通过桥梁(容器迭代器来操作容器)
		vector<int>::iterator it = find(v.begin(), v.end(), 3);
		if (it != v.end())
		{
			cout << "找到了" << *it << endl;
		}
		else
		{
			cout << "没找到！" << endl;
		}
	}


	{
		//与find类似，只不过需要一元函数对象返回为true
		//find_if会依次将元素值放入Is3中去检查，结果返回为ture时，认为找到了
		vector<int>::iterator it = find_if(v.begin(), v.end(), Is3); //普通函数
		//vector<int>::iterator it = find_if(v.begin(), v.end(), Is3_FO());  //一元函数对象
		if (it != v.end())
		{
			cout << "找到了" << *it << endl;
		}
		else
		{
			cout << "没找到！" << endl;
		}
	}


	{
		//查找到2,3中的任何一个值就认为查找到了
		vector<int> v2 = { 2,3};
		vector<int>::iterator it=find_first_of(v.begin(), v.end(), v2.begin(), v2.end());
		if (it != v.end())
		{
			cout << "找到了" << *it << endl;
		}
		else
		{
			cout << "没找到！" << endl;
		}

	}


	{
		//将每个元素依次作为参数传入到一元函数Print中执行
		for_each(v.begin(), v.end(), Print);//传入函数指针
		cout << endl;
	}


	{
		
		vector<int> v2 = { 1,2,2,2,2,2,3,4,5 };
		//统计一个元素出现的次数
		cout << "2出现的次数" << count(v2.begin(), v2.end(), 2) << endl;;

	}


	{
		vector<int> v2 = { 1,2,2,2,2,2,3,3,3,4,5 };
		//统计一个元素使得Is3返回为true的次数
		cout << "3出现的次数" << count_if(v2.begin(), v2.end(), Is3) << endl;;
	}


	{
		vector<int> v2 = { 3,4 };

		//在容器序列中，查找一段子序列
		vector<int>::iterator it = search(v.begin(), v.end(), v2.begin(), v2.end());

		if (it != v.end())
		{
			cout << "找到了" << *it << endl;
		}
		else
		{
			cout << "没找到！" << endl;
		}

		{
			//在v2中连续查找2两个连续的元素4
			vector<int> v2 = {1,2,3,4,4,5,6};
			vector<int>::iterator it = search_n(v2.begin(), v2.end(), 2, 4);
			if (it != v2.end())
			{
				cout << "找到了" << *it << endl;
			}
			else
			{
				cout << "没找到！" << endl;
			}

		}


	}




}