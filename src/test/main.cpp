#include<iostream>
using namespace std;
#include<array>
#include<vector>
#include<deque>
#include<list>
//对数组进行排序后输出
template<typename T>
void sortedSquares(T& a)
{
	T tmp = a;
	
	for (int i = 0; i < 5; i++)
	{
		*a = (*a) * (*a);
		a++;
	}
		
	for (int i = 0; i < 5; i++)
	{ 
		a = tmp++;
		for (int j = 0; j < 4; j++)
		{
			int tmp2;
			T b1 = a;
			T b2 = ++b1;
			if (*b1 > *b2)
			{
				tmp2 = *b2;
				*b1 = *b1;
				*b2 = tmp2;
			}
			a++;
		}
		
	}
}

template<typename T>
void input(T& a)
{
	for (int i = 0; i < 5; i++)
	{
		cin >> *a;
		a++;
	}		
}

template<typename T>
void output(T& a)
{
	for (int i = 0; i < 5; i++)
	{
		cout << *a << "   ";
		a++;
	}
		
	cout << endl;
}

void main()
{
	array<int,5> arr;
	//for (int i = 0; i < 5; i++)
	//	cin >> arr[i];
	//array<int, 5>::iterator ait = arr.begin();
	//input<array<int, 5>::iterator>(ait);
	//sortedSquares<array<int, 5>>(arr);
	//ait = arr.begin();
	//output<array<int, 5>::iterator>(ait);

	//vector<int> v(5);
	//vector<int>::iterator vit = v.begin();
	//input<vector<int>::iterator>(vit);
	//sortedSquares<vector<int>>(v);
	//vit= v.begin();
	//output<vector<int>::iterator>(vit);


	deque<int> d(5);
	deque<int>::iterator dit = d.begin();
	input<deque<int>::iterator>(dit);
	dit = d.begin();
	sortedSquares<deque<int>::iterator>(dit);
	dit = d.begin();
	output<deque<int>::iterator>(dit);


	//list<int> l(5);
	//list<int>::iterator lit = l.begin();
	//input<list<int>::iterator>(lit);
	//sortedSquares<list<int>>(l);
	//lit = l.begin();
	//output<list<int>::iterator>(lit);


}

