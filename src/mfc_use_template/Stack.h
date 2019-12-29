#pragma once

#include<iostream>
#include<vector>
#include<cstdlib>
#include<string>
#include<stdexcept>

//练习使用类模板
using namespace std;

//定义类模板
template <class T>
class Stack
{
public:
	Stack();
	~Stack();

private:
	vector<T> elems;    //元素

public:
	void push(T const&);    //入栈
	void pop();				//出栈
	T top() const;          //返回栈顶元素
	bool empty() const 
	{
		return elems.empty();
	}
};


//定义模板成员函数，最好与头文件放在一起，否则会导致error LNK2019:无法解析的外部符号错误
//每个函数头都要以相同的模板声明打头
//将类限定符改成：类名<T>::这种形式
template <class T>
Stack<T>::Stack()
{
}
template <class T>
Stack<T>::~Stack()
{
}


template <class T>
void Stack<T>::push(T const& elem)
{
	elems.push_back(elem);
}

template <class T>
void Stack<T>::pop()
{
	if (elems.empty())
	{
		throw out_of_range("Stack<>::pop(): empty stack");
	}

	//删除最后一个元素
	elems.pop_back();
}

template <class T>
T Stack<T>::top() const
{
	if (elems.empty())
	{
		throw out_of_range("Stack<>::pop(): empty stack");
	}
	return elems.back();
}
