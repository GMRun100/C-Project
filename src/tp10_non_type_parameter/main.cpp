//ѧϰģ���βεķ����Ͳ���
//2019.10.24 GM

#include<iostream>
using namespace std;

template <int len> //lenΪ�����Ͳ���
void test()
{
	int arr[len];
	cout << sizeof(arr) << endl;
}

//�����ַ���
char strtmp[] = "hello world!";
template <char *str> 
void test2()
{
	
	cout << str << endl;
}

//������������
int i3 = 100;
template <int& i>
void test3()
{

	cout << i << endl;
}


//����ָ��
int i4 = 100;
template <int* i>
void test4()
{

	cout << *i << endl;
}

//���뺯��ָ��
void fun5(int a)
{
	cout << a << endl;
}
template <void(*pf)(int)>
void test5()
{

	pf(111);
}


void main()
{
	//ʵ���˶�̬���飬���û�ָ������
	test<10>();
	test<20>();

	
	test2<strtmp>();   //strtmp����Ϊ��̬�洢����ȫ�ֱ���Ϊ��̬�洢
	
	test3<i3>();

	test4<&i3>();

	test5<fun5>();


}
