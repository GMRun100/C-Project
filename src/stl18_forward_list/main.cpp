#include<iostream>
#include<forward_list>
using namespace std;

void main()
{
	//����
	forward_list<int> l;
	//���ṩsize�ĳ�Ա������ʹ���㷨distance()��ȡ
	cout << l.max_size() << endl;  //����Ԫ�ظ���

	forward_list<int> l2(5);   //����5��Ԫ�صĵ�������
	cout << "Ԫ��ֵ:" << *l2.begin() << endl;

	forward_list<int> l3(5,111);   //����5��Ԫ�صĵ�������,��ʼֵΪ111
	cout << "Ԫ��ֵ:" << *l3.begin() << endl;

	//��������
	forward_list<int> l4(l3);   //����5��Ԫ�صĵ�������,��ʼֵΪ111
	cout << "Ԫ��ֵ:" << *l4.begin() << endl;

	//��֤forward_list���ڴ�ṹ:������
	for (forward_list<int>::iterator it = l3.begin(); it != l3.end(); it++)
	{
		cout << &(*it) << "	";
	}
	cout << endl;

	//������
	//��֤����������:ǰ�������
	cout<<typeid(forward_list<int>::iterator::iterator_category).name() << endl;

	//ǰ���������˫����������ܸ���һЩ��֧��++��=����=��==��* ��֧��--

	//++
	forward_list<int>::iterator it = l3.begin();
	*(++it)=222;
	*(++it) = 333;
	*(++it) = 444;
	*(++it) = 555;

	//�������
	for (forward_list<int>::iterator it = l3.begin(); it != l3.end(); it++)
	{
		cout << *it << "	";
	}
	cout << endl;

	++it;  //ָ�����һ������һ��
	cout << "�Ƿ�ָ�����һ������һ��" << (it == l3.end()) << endl;

	//const_iterator:ָ���Ԫ�ز��ɸ�ֵ
	forward_list<int>::const_iterator it2 = l3.cbegin();
	//*it2 = 1;  //���ɸ�ֵ


	//����Ԫ��
	forward_list<int> l5;
	l5.push_front(111);  //ͷ������

	l5.push_front(222);

	l5.insert_after(l5.begin(), 333);
	for (forward_list<int>::iterator it = l5.begin(); it != l5.end(); it++)
	{
		cout << *it << "	";
	}
	cout << endl;

	//����Ԫ��
	cout << l5.front() << endl;  //���ʵ�һ��Ԫ��

	//ɾ��Ԫ��
	l5.pop_front();   //ɾ��ͷ���
	/*erase_afterɾ�����߼�
	pTemp = pDelete->next;
	pDelete->next=pDelete->next->next;
	delete pTemp;
	*/
	l5.erase_after(l5.begin());  //ɾ���������ڵ����һ��






	for (forward_list<int>::iterator it = l5.begin(); it != l5.end(); it++)
	{
		cout << *it << "	";
	}
	cout << endl;

	l5.clear();  //���



}