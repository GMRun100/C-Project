#include<iostream>
using namespace std;
#include<list>

int main()
{
	//����
	list<int> l;
	cout << "Ԫ�ظ�����" << l.size() << endl;

	list<int> l2(5);   //Ĭ��ֵΪ���͵�Ĭ��ֵ
	cout << "Ԫ�ظ�����" << l2.size() <<"	"<<*(l2.begin())<< endl;


	list<int> l3(5,111);   
	cout << "Ԫ�ظ�����" << l3.size() << "	" << *(l3.begin()) << endl;

	list<int> l4(l3);  //��������
	cout << "Ԫ�ظ�����" << l4.size() << "	" << *(l4.begin()) << endl;

	//��֤list�ڴ�ռ䲻����
	for (list<int>::iterator it = l3.begin(); it != l3.end(); it++)
	{
		cout << &(*it) << "	";
	}
	cout << endl;

	//list�ĵ�����Ϊ˫�������
	cout << typeid(list<int>::iterator::iterator_category).name() << endl;

	//˫�������֧�֣� ++ -- != == =*
	//˫���������֧��: []	+n	-n +=n -=n

	//�������ĺô�������ʹ�㷨����Ҫ֪���������ڴ�ṹ

	//list����Ԫ��
	list<int> l5;
	//ͷ������
	l5.push_front(111);

	l5.push_back(444);
	l5.push_back(555);

	//��ĳ����������λ�ò���
	l5.insert(l5.begin(), 222);

	//����n����ͬ��Ԫ��
	l5.insert(l5.begin(), 3,333);

	for (list<int>::iterator it = l5.begin(); it != l5.end(); it++)
	{
		cout << (*it) << "	";
	}
	cout << endl;

	//���������һ��Ԫ��
	l5.front() = 1;  //front�������ص���һ������
	cout <<"���������һ��Ԫ��" <<l5.front() << endl;
	//�����������һ��Ԫ��
	cout << "�����������һ��Ԫ��" <<l5.back() << endl;


	//ɾ��Ԫ��
	//ɾ�����һ��Ԫ��
	l5.pop_back();
	//ɾ����һ��Ԫ��
	l5.pop_front();
	//ɾ��ĳ��������ָ����Ԫ��
	l5.erase(l5.begin());

	//�������
	//l5.clear();

	for (list<int>::iterator it = l5.begin(); it != l5.end(); it++)
	{
		cout << (*it) << "	";
	}
	cout << endl;

}