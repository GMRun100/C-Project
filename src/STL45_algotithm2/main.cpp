//学习修改序列算法  GM 2020.1.4

#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

struct Is3_FO
{
	bool operator()(int x)
	{
		return x == 3;
	}
};

void Print(int x)
{
	cout << x << "   ";
}

int Add2(int x)
{
	return x + 2;
}

void main()
{
	//数据都放在容器中
	vector<int> v = { 1, 2, 3, 4, 5 };

	{
		//随机打乱位置
		random_shuffle(v.begin(), v.end());
		for_each(v.begin(), v.end(), Print);
		cout << endl;

		random_shuffle(v.begin(), v.end());
		for_each(v.begin(), v.end(), Print);
		cout << endl;

	}

	{
		vector<int> v = { 1, 2, 3, 4,3, 5 };
		replace(v.begin(), v.end(), 3, 333);
		for_each(v.begin(), v.end(), Print);
		cout << endl;
	}

	{
		//替换v中所有元素为Is3_FO()(x)返回为true的值替换为333
		vector<int> v = { 1, 2, 3, 4,3, 5 };
		replace_if(v.begin(), v.end(), Is3_FO(), 333);
		for_each(v.begin(), v.end(), Print);
		cout << endl;

	}

	{
		//与replace一样，但是不改变v的序列，只是将替换后的结果copy到v2中
		vector<int> v = { 1, 2, 3, 4,3, 5 };
		vector<int> v2(6);
		replace_copy(v.begin(), v.end(),v2.begin(),3,333);
		for_each(v.begin(), v.end(), Print);
		cout << endl;
		for_each(v2.begin(), v2.end(), Print);
		cout << endl;

	}


	{
		//将容器v中每个元素值填充为111
		vector<int> v(5);
		fill(v.begin(), v.end(), 111);

		for_each(v.begin(), v.end(), Print);
		cout << endl;

	}

	{
		vector<int> v = { 1, 2, 3, 3,4,5 };

		//删除特定元素，但是不会改变容器的大小，只会将后面的元素往前移动
		//并返回删除后最后一个元素的结束位置
		vector<int>::iterator itNewEnd=remove(v.begin(), v.end(), 3);

		for_each(v.begin(), itNewEnd, Print);
		cout << endl;
	}


	{
		vector<int> v = { 1, 2, 3,4,5 };
		//将v中元素反序
		reverse(v.begin(), v.end());
		for_each(v.begin(), v.end(), Print);
		cout << endl;
	}



	{
		vector<int> v = { 1, 2,3,3,3,3,3,4,5,3 };
		//删除【连续相同元素】，只保留一个，但是不会改变容器的大小，只会将后面的元素往前移动
		//并返回删除后最后一个元素的结束位置
		vector<int>::iterator itNewEnd=unique(v.begin(), v.end());
		for_each(v.begin(), itNewEnd, Print);
		cout << endl;
	}



	{

		vector<int> v = { 1, 2, 3,4,5 };
		vector<int> v2(5);
		//把V中每个元素传入到Add2中执行后拷贝到v2，
		transform(v.begin(), v.end(), v2.begin(), Add2);//传入函数指针

		for_each(v.begin(), v.end(), Print);
		cout << endl;
		for_each(v2.begin(), v2.end(), Print);
		cout << endl;

	}

}