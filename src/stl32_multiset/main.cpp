#include<set>
#include<iostream>
using namespace std;


void main()
{
	//multiset��set��Ψһ������Ǽ�ֵ�Ƿ��ظ�
	multiset<int> m= { 3,2,5,1,4,3 };//����3�������ظ�����
	cout << "mԪ�ظ���" << m.size() << endl;
	//����ɹ������ز���Ԫ�صĵ�����
	m.insert(9);
	m.insert(9);

	m.erase(3);  //ɾ������Ԫ��ֵΪ3��Ԫ��


	for (multiset<int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << *it << "	";
	}
	cout << endl;

	//����ĳ��Ԫ�أ��ҵ��򷵻�ָ���Ԫ�صĵ�������û�ҵ��򷵻�end()
	//ֻ���ҵ�һ��Ԫ��Ϊ9 �ĵ�����
	multiset<int>::iterator it=m.find(9);  
	if (it != m.end())
	{
		cout << "���ҳɹ���" <<*it<< endl;
	}
	else
	{
		cout << "���ҳɹ���" << endl;
	}


	//��������Ԫ��ֵΪ9�ĵ�����,����ָ��Ԫ��9 �ĵ���������
	pair<multiset<int>::iterator, multiset<int>::iterator> pit=m.equal_range(9);
	for (multiset<int>::iterator it = pit.first; it != pit.second; it++)
	{
		cout << *it << "	";
	}
	cout << endl;

	//��������˫�������
	cout << typeid(multiset<int>::iterator::iterator_category).name() << endl;



}