//ѧϰtypeid���÷�
//2019.09.13 GM 

#include <iostream>
using namespace std;

struct A
{

};
int main()
{
	//ֱ���������
	cout << typeid(int).name() << endl;

	//����ṹ������
	cout << typeid(A).name() << endl;

	//����ַ�������
	cout << typeid("abcde").name() << endl;   //���char const [6]

	//���ָ������
	int* p = NULL;
	cout << typeid(p).name() << endl;

	//������ʽ����
	cout << typeid(1.234*456).name() << endl;

}
