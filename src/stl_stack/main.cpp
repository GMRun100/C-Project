#include<iostream>
using namespace std;
#include<stack>
#include<vector>
#include<list>
#include<array>
#include<forward_list>
void main()
{
	//创建stack
	//stack<int> s;

	//更换stack的内部实现容器为vector,支持push_back,pop_back,back
	stack<int,vector<int>> s;

	//更换stack的内部实现容器为list,支持push_back,pop_back,back
	//stack<int, list<int>> s;

	//stack<int, array<int,5>> s;  //报错：array不支持pop_back

	//stack<int, forward_list<int>> s;  //报错：forward_list不支持pop_back

	cout << "元素个数：" << s.size() << endl;
	
	//

	//stack<int> s2(s);   //采用拷贝构造函数
	//cout << "元素个数：" << s2.size() << endl;

	//查看stack内部的容器类型:deque
	cout << typeid(stack<int>::container_type).name() << endl;

	//入栈
	s.push(1);
	s.push(2);
	s.push(3);
	
	
	//s[0];	//栈只允许取栈顶，不给其他接口访问元素

	//出栈
	//栈的遍历
	while (!s.empty())
	{
		cout << s.top() <<"  "<<s.size()<< endl;  //获取栈顶元素
		s.pop();  //出栈
	}

}