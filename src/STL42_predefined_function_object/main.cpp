#include<iostream>
using namespace std;
#include<functional>


void main()
{

	//STLԤ���庯������

	//������������ + - * / %
	cout << "�ӷ���"<<plus<int>()(4, 2) << endl;
	cout << "������" <<minus<int>()(4, 2) << endl;
	cout << "�˷���" << multiplies<int>()(4, 2) << endl;
	cout << "������" << divides<int>()(4, 2) << endl;
	cout << "ȡģ��" << modulus<int>()(4, 2) << endl;
	cout << "ȡ����" << negate<int>()(4) << endl;

	//�ȽϺ������� 
	cout << "���ڣ�" << equal_to<int>()(4, 2) << endl;
	cout << "�����ڣ�" << not_equal_to<int>()(4, 2) << endl;
	cout << "���ڣ�" << greater<int>()(4, 2) << endl;
	cout << "���ڵ��ڣ�" << greater_equal<int>()(4, 2) << endl;
	cout << "С�ڣ�" << less<int>()(4, 2) << endl;
	cout << "С�ڵ��ڣ�" << less_equal<int>()(4,2) << endl;




	//�߼���������
	cout << "�룺" << logical_and<bool>()(1, 0) << endl;
	cout << "��" << logical_or<bool>()(1, 0) << endl;
	cout << "�ǣ�" << logical_not<bool>()(1) << endl;



}
