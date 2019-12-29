//ѧϰSTL��iterator��
#include<iostream>
using namespace std;

//ʵ���Լ��������������
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
	//�ڲ����ͣ�iterator_category����������������
	cout << typeid(iterator<input_iterator_tag, int>::iterator_category).name() << endl;

	//������ָ��Ԫ�ص�����
	cout << typeid(iterator<input_iterator_tag, int>::value_type).name() << endl;

	//������ָ��Ԫ�ص�ָ������
	cout << typeid(iterator<input_iterator_tag, int>::pointer).name() << endl;

	//������ָ��Ԫ�ص���������
	cout << typeid(iterator<input_iterator_tag, int>::reference).name() << endl;

	//������ָ��Ԫ�ص�ָ������ ����õ��Ĳ�ֵ����
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

	//�����Զ���ĵ�����
	int numbers[] = { 10,20,30,40,50 };
	MyIterator from(numbers);
	MyIterator until(numbers + 5);
	for (MyIterator it = from; it != until; it++)
		std::cout << *it << ' ';
	std::cout << '\n';



}