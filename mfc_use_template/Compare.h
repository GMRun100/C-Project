#pragma once

//练习使用类模板
template <class T>
class Compare
{
public:
	Compare();
	~Compare();
public:
	T compareAandB(T const&, T const&);
};

template <class T>
Compare<T>::Compare()
{
}

template <class T>
Compare<T>::~Compare()
{
}
template <class T>
T Compare<T>::compareAandB(T const& a, T const& b)
{
	return a < b ? b : a;
}