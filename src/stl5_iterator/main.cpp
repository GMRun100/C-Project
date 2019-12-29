//学习STL的iterator类
#include<iostream>
using namespace std;

//实现自己的数组迭代器类
class MyIterator : public std::iterator<std::input_iterator_tag, int>
{
	int* p;
public:
	MyIterator(int* x) :p(x) {}
	MyIterator(const MyIterator& mit) : p(mit.p) {}
	MyIterator& operator++() { ++p; return *this; }
	MyIterator operator++(int) { MyIterator tmp(*this); operator++(); return tmp; }
	bool operator==(const MyIterator& rhs) const { return p == rhs.p; }
	bool operator!=(const MyIterator& rhs) const { return p != rhs.p; }
	int& operator*() { return *p; }
};


void main()
{
	//内部类型：iterator_category代表迭代器类别类型
	cout << typeid(iterator<input_iterator_tag, int>::iterator_category).name() << endl;

	//迭代器指向元素的类型
	cout << typeid(iterator<input_iterator_tag, int>::value_type).name() << endl;

	//迭代器指向元素的指针类型
	cout << typeid(iterator<input_iterator_tag, int>::pointer).name() << endl;

	//迭代器指向元素的引用类型
	cout << typeid(iterator<input_iterator_tag, int>::reference).name() << endl;

	//迭代器指向元素的指针类型 相减得到的差值类型
	cout << typeid(iterator<input_iterator_tag, int>::difference_type).name() << endl;


	iterator<input_iterator_tag, int>::value_type a = 100;
	iterator<input_iterator_tag, int>::pointer pA = &a;
	iterator<input_iterator_tag, int>::reference b = a;

	cout << a <<"    "<<*pA<< endl;
	b = 200;
	cout << a << "    " << b << endl;

	iterator<input_iterator_tag, int>::pointer pB = &a+2;

	iterator<input_iterator_tag, int>::difference_type c = pB - pA;
	cout << c << endl;

	//测试自定义的迭代器
	int numbers[] = { 10,20,30,40,50 };
	MyIterator from(numbers);
	MyIterator until(numbers + 5);
	for (MyIterator it = from; it != until; it++)
		std::cout << *it << ' ';
	std::cout << '\n';



}