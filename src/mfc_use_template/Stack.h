#pragma once

#include<iostream>
#include<vector>
#include<cstdlib>
#include<string>
#include<stdexcept>

//��ϰʹ����ģ��
using namespace std;

//������ģ��
template <class T>
class Stack
{
public:
	Stack();
	~Stack();

private:
	vector<T> elems;    //Ԫ��

public:
	void push(T const&);    //��ջ
	void pop();				//��ջ
	T top() const;          //����ջ��Ԫ��
	bool empty() const 
	{
		return elems.empty();
	}
};


//����ģ���Ա�����������ͷ�ļ�����һ�𣬷���ᵼ��error LNK2019:�޷��������ⲿ���Ŵ���
//ÿ������ͷ��Ҫ����ͬ��ģ��������ͷ
//�����޶����ĳɣ�����<T>::������ʽ
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

	//ɾ�����һ��Ԫ��
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
