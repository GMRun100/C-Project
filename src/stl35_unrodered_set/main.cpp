#include<unordered_set>
#include<iostream>
using namespace std;


void main()
{
	//Ԫ��ֵΨһ������ļ��ϣ��ڲ�ͨ����ϣ��ʵ�֣�����Ч�ʱ�set��
	unordered_set<int> s = {3,1,2,5,4,3};  //�ظ�Ԫ���޷�����


	//����
	cout << s.insert(9).second << endl;
	cout << s.insert(9).second << endl; //�ظ�����ʧ�ܣ�����λ�����ɹ�ϣ���λ��ȷ���ģ�������Ϊ���Կ��Ƶ�


	//ɾ��
	s.erase(3);

	//����
	unordered_set<int>::iterator it = s.find(2);  //���ҵ�һ��keyΪ1��Ԫ��

	if (it != s.end())
	{
		cout << "�ҵ�" << *it << endl;
	}
	else
	{
		cout << "δ�ҵ���Ԫ��";
	}

	for (unordered_set<int>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << "	";
	}
	cout << endl;


	//����������
	//˫�������:֧��++ -- == != = *  ��֧�֣�[] += -= +n -n
	cout << typeid(unordered_set<int>::iterator::iterator_category).name() << endl;
	unordered_set<int>::iterator it2 = s.begin();
	//setԪ��ֵ���������
	//��Ϊ��Ԫ�ص�λ����������ֵ�����ģ�������������Ԫ��ֵ���ᵼ��λ�ò���ȷ
	//*it2 = 111;

	unordered_set<int>::const_iterator cit = s.cbegin();
	//*cit = 111;

	//set��unordered_set����������ͬһ����
	cout << typeid(unordered_set<int>::iterator::iterator_category).name() << endl;
	cout << typeid(unordered_set<int>::const_iterator::iterator_category).name() << endl;


}