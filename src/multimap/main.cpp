#include<map>
#include<iostream>
using namespace std;

ostream& operator<<(ostream& os, multimap<int, string>::value_type &p)
{
	cout << p.first << "->" << p.second.c_str();
	return os;
}

template <class T>
void Print(T begin, T end)
{
	for (T p = begin; p != end; ++p)
	{
		cout << *p << "  ";
	}
	cout << endl;
}






void main()
{

	//class map : public _Tree<_Tmap_traits<_Kty, _Ty, _Pr, _Alloc, false>>
	//false��ʾkey�������ظ�
	map<int, string> m;
	//class multimap : public _Tree<_Tmap_traits<_Kty, _Ty, _Pr, _Alloc, true>>
	//true��ʾkey�����ظ�
	//���Բ���key��ͬ�ļ�ֵ��pair������Ȼ�������
	multimap<int, string> mm = { {1,"AAA"},{2,"BBB"},{1,"aaa"} };
	mm.insert(make_pair<int, string>(3, "CCC"));
	mm.insert(make_pair<int, string>(3, "CCC"));

	//����Ԫ��

	multimap<int, string>::iterator it = mm.find(1);  //���ҵ�һ��keyΪ1��Ԫ��

	if (it != mm.end())
	{
		cout << "�ҵ�" << it->second.c_str() << endl;
	}
	else
	{
		cout << "δ�ҵ���Ԫ��";
	}

	//��������keyΪ1Ԫ�صĵ�������Χ

	auto pa = mm.equal_range(1);

	//keyΪ1Ԫ�صĵ�������Χ�ı���
	for (multimap<int, string>::iterator it = pa.first; it != pa.second; it++)
	{
		cout << it->first << "->" << it->second.c_str() << "	";
	}
	cout << endl;


	mm.erase(1);//ɾ������keyΪ1��Ԫ��

	//��֧��[]��������أ���Ϊ���ǵ�key�ǿ����ظ��ģ�m[1]��֪�������ĸ�value
	//mm[1] = "aa";

	for (multimap<int, string>::iterator it = mm.begin(); it != mm.end(); it++)
	{
		cout << it->first<<"->" <<it->second.c_str()<< "	";
	}
	cout << endl;

	//��֤������������
	//˫�����������֧��[] += -= +n -n 
	cout << typeid(multimap<int, string>::iterator::iterator_category).name() << endl;

	multimap<int, string>::iterator it2 = mm.begin();
	//it2->first = 111;  //key���ɸ��ģ���Ϊmultimap�������
	it2->second = "AAAAAA";   //value���Ըı�



	Print<multimap<int, string>::reverse_iterator>(mm.rbegin(), mm.rend());





}