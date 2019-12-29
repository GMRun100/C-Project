#include<set>
#include<iostream>
#include<vector>
#include<list>
using namespace std;

void main()
{
	//����
	set<int> s;

	//ͨ����ʼ���б���
	//set<int> s2 = { 3,2,5,1,4,3 };   //Set��Ԫ�ظ���Ψһ������

	//��Ϊ��������
	set<int,greater<int>> s2 = { 3,2,5,1,4,3 };

	cout << "s2Ԫ�ظ���" << s2.size() << endl;

	set<int> s3(s2.begin(),s2.end());
	cout << "s3Ԫ�ظ���" << s3.size() << endl;

	//����Ԫ��
	cout << s2.insert(9).second << endl; //�ж��Ƿ����ɹ�������ɹ�second����Ϊ1.ʧ��Ϊ0

	//�ظ�����Ԫ����Ч
	cout << s2.insert(9).second << endl;


	//����һ������������
	vector<int> v = { 6,7,8,9 };
	s2.insert(v.begin(), v.end());

	list<int> l = { 11,12,13 };
	s2.insert(l.begin(), l.end());

	//����Ԫ��
	for (set<int>::iterator it = s2.begin(); it != s2.end(); it++)
	{
		cout << *it << "	";
	}
	cout << endl;



	//ɾ��ֵΪ6��Ԫ��
	s2.erase(6);
	
	//ɾ��������ָ���Ԫ��
	s2.erase(s2.begin());

	//����Ԫ��
	for (set<int>::iterator it = s2.begin(); it != s2.end(); it++)
	{
		cout << *it << "	";
	}
	cout << endl;

	//ɾ������������
	set<int>::iterator it = s2.begin();
	it++;
	it++;
	it++;

	s2.erase(s2.begin(), it);

	//���Ҽ����е�Ԫ��
	//�ҵ����ظ�Ԫ�صĵ����������򷵻�end();
	set<int>::iterator it2=s2.find(9);   
	if (it2 != s2.end())
	{
		cout << "�ҵ���Ԫ��"<<endl;
	}
	else
	{
		cout << "δ�ҵ���Ԫ��" << endl;
	}




	//����Ԫ��
	for (set<int>::iterator it = s2.begin(); it != s2.end(); it++)
	{
		cout << *it << "	";
	}
	cout << endl;


	//���Ԫ��
	//s2.clear();

	//����������:˫��������� ֧��++ -- * != == = ��֧��:[] += -= +n -n
	cout << typeid(set<int>::iterator::iterator_category).name() << endl;

	//��ȡ��һ��Ԫ��
	set<int>::iterator it3 = s2.begin();	//��ȡ��һ��Ԫ��
	cout << "��һ��Ԫ��" << *it3 << endl;

	//*it3 = 111;   //setԪ���е�ֵ�����޸�

	++it3;
	cout << "�ڶ���Ԫ��" << *it3 << endl;

	--it3;
	cout << "�Ƿ�ָ��ͷ" << (it3 == s2.begin()) << endl;




}