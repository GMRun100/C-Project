#include<queue>
#include<iostream>
#include<list>

using namespace std;

void main()
{
	//创建
	//priority_queue<int> q;  //默认高优先级先出队列

	//priority_queue<int, vector<int>, greater<int>> q;  //低优先级先出队列

	//将底层容器更换为deque
	priority_queue<int, deque<int>> q;

	//priority_queue<int> q2(q);

	//优先队列内部使用的容器
	cout << typeid(priority_queue<int>::container_type).name() << endl;

	//优先队列优先级使用的比较仿函数，less代表高优先级先出队列
	cout << typeid(priority_queue<int>::value_compare).name() << endl;

	//入队列,默认是less，优先级高的先出队列
	q.push(9);
	q.push(3);
	q.push(1);
	q.push(2);

	//出队列
	while (!q.empty())
	{
		cout << "队列头元素：" << q.top() << endl;
		q.pop();  //出队列
	}

	



}