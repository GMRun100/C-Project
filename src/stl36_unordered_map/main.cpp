#include<unordered_map>
#include<iostream>
using namespace std;

void main()
{
	//�洢��ֵ��keyֵΨһ������
	//�ڴ�ṹ����hash��Ԫ�ص�λ���ɹ�ϣֵ��������push_back��
	unordered_map<int, string>  m = { {1,"AAA"},{3,"CCC"} ,{2,"BBB"}, {1,"aaa"} };


	//����Ԫ��
	m.insert(make_pair(4, "DDD"));
	m.insert(make_pair(4, "ddd"));

	m[5] = "EEE";  //���key�����ڣ����ǲ���5->"EEE"
	m[5] = "eee";  //���key���ڣ������޸�value


	//����
	//unordered_map���ң�Ч�ʱ�map��
	unordered_map<int,string>::iterator it = m.find(5);
	if (it != m.end())
	{
		cout << "�ҵ�:"<<it->second.c_str()<< endl;
	}
	else
	{
		cout << "δ�ҵ���Ԫ��";
	}




	for (unordered_map<int, string>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << "->" << it->second.c_str() << "	";
	}
	cout << endl;


	cout << typeid(unordered_map<int,string>::iterator::iterator_category).name() << endl;

	unordered_map<int, string>::iterator it = m.begin();
	//it->first = 111;  //keyֵ�޷��޸ģ���ΪԪ�ص�λ����key�������������keyֵ���õ���hashֵ��洢��λ�ò�����
	it->second = "aaa";  //valueֵ���Ը���

	unordered_map<int, string>::const_iterator cit = m.cbegin();
	//cit->second = "aaa";  //const_iteratorָ���Ԫ�����ݲ����޸�





}
