#include<iostream>
#include<queue>
#include<list>

using namespace std;

void main()
{
	//queue<int> q;

	//更改queue的底层容器为list

	queue<int, list<int>> q;

	//拷贝构造队列
	queue<int,list<int>> q2(q);

	//打印queue内部容器类型:deque
	cout << typeid(queue<int>::container_type).name() << endl;

	//入队列
	q.push(1);
	q.push(2);
	q.push(3);

	//队列头元素
	q.front();
	//队列尾元素
	q.back();

	//出队列
	while (!q.empty())
	{
		cout << "队列头元素：" << q.front() << endl;
		q.pop();  //出队列
	}







}
