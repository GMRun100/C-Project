//ѧϰSTL����ȡ������ص���
#include<iostream>
using namespace std;

int fun(int a)
{
	return a;
}

typedef int(*PFUN)(int a);   //����ָ������
PFUN pfun; //����ָ��


//�º���
struct FUNO
{
	void operator()(int a)
	{}
};

class A {};
class B:A{};
class C :B {};
void main()
{

	//�ж�һ�������Ƿ�Ϊ��
	cout << is_void<void>::value << endl;
	cout << is_void<int>::value << endl;

	//�ж��Ƿ���ָ��

	cout << is_pointer<int*>::value << endl;
	cout << is_pointer<void (*)(int,int)>::value << endl;  //����ָ��

	//�ж��Ƿ��Ǻ�������
	//decltype���ر���������
	cout << is_function<decltype(fun)>::value << endl;
	cout << is_function<PFUN>::value << endl;  //����ָ��
	cout << is_function<decltype(pfun)>::value << endl;
	cout << is_function<FUNO>::value << endl;   //�º�������

	//�ж��Ƿ�����������
	cout << is_array<int[3]>::value << endl;
	cout << is_array<array<int,3>>::value << endl;  //array���������� ����

	//�ж�һ�������Ƿ�����һ�����͵Ļ���
	cout << is_base_of<int, int>::value << endl;
	cout << is_base_of<A, B>::value << endl;  //A�Ƿ���B�Ļ���
	cout << is_base_of<A, C>::value << endl;  //A�Ƿ���C�Ļ���


	//�ж�һ�������Ƿ��Ƕ�������
	//������������������Ĵ洢���ͣ����������������ú�void֮�����������
	cout << is_object<int>::value << endl;
	cout << is_object<int(*)(int)>::value << endl;
	cout << is_object<int&>::value << endl;



}