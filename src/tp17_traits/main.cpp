//ѧϰtraits���÷�
//2019.10.26 GM

#include<iostream>
#include<type_traits>
using namespace std;

struct A {};
struct B :A {};
void main()
{
	//�ж��Ƿ�Ϊvoid����
	cout << boolalpha;
	cout << is_void<void>::value << endl;
	cout << is_void<int>::value << endl;

	//�ж��Ƿ���ָ��
	cout << "is_pointer:" << endl;
	cout << "int:" << is_pointer<int>::value << endl;
	cout << "int*:" << is_pointer<int*>::value << endl;
	cout << "int**:" << is_pointer<int**>::value << endl;
	cout << "int(*)(int):" << is_pointer<int(*)(int)>::value << endl;

	//�ж��Ƿ�������
	cout << "int:" << is_array<int>::value << endl;
	cout << "int[3]:" << is_array<int[3]>::value << endl;
	cout << "array<int,3>:" << is_array<array<int, 3>>::value << endl;  //ģ����
	cout << "string:" << is_array<string>::value << endl;
	cout << "string[3]:" << is_array<string[3]>::value << endl;

	//�ж��Ƿ��ǻ���
	cout << "is_base_of:" << endl;
	cout << "int,int:" << is_base_of<int, int>::value << endl;
	cout << "A,A:" << is_base_of<A, A>::value << endl;
	cout << "A,B:" << is_base_of<A, B>::value << endl;
	cout << "A,const B:" << is_base_of<A, const B>::value << endl;
	cout << "A&,B&:" << is_base_of<A&, B&>::value << endl;
	cout << "B,A:" << is_base_of<B, A>::value << endl;


	//�ж��Ƿ���const
	cout << is_const<int>::value << endl;
	cout << is_const<const int>::value << endl;
	//*ǰ��������α�ָ������ݣ�*����������ָ��
	cout << is_const<const int*>::value << endl;
	cout << is_const<int* const>::value << endl;
	//�������ã������޸����õ�����
	cout << is_const<const int&>::value << endl;

	//�ж��Ƿ���object(����)
	cout << "is_object:" << endl;
	cout << is_object<int>::value << endl;
	cout << is_object<int&>::value << endl;
	cout << is_object<A>::value << endl;
	cout << is_object<A&>::value << endl;
}