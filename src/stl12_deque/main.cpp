#include<deque>
#include<iostream>
using namespace std;
 

void main()
{
	//����˫�˶���
	deque<int> d;
	cout << "Ԫ�صĸ���" << d.size()<< endl;

	deque<int> d2(5);//ָ��Ԫ�ظ���
	cout << "Ԫ�صĸ���" << d2.size() <<"	"<<d2[0]<< endl;

	deque<int> d3(5,111); //ָ��Ԫ�ظ�����ָ��Ԫ��ֵ111
	cout << "Ԫ�صĸ���" << d3.size() << "	" << d3[0] << endl;


	//��������
	deque<int> d4(d3);
	cout << "Ԫ�صĸ���" << d4.size() << "	" << d4[3] << endl;


	//������һ���ķ���Ԫ��(�ڴ�ռ䲢����������)
	d2[0] = 1;
	d2[1] = 2;
	d2.at(2) = 3;
	d2.at(3) = 4;
	d2.at(4) = 5;
	for (size_t i = 0; i < d2.size(); i++)
	{
		cout << d2[i] << "	";
	}
	cout << endl;


	//��֤deque���ڴ�ռ䲻��������

	{
		deque<int> d5;
		for (size_t i = 0; i < 20; i++)
		{
			d5.push_back(i);
			cout << "Ԫ�أ�	" << d5[i] << "	" << &d5[i] << '\t';
			if ((i + 1) % 4 == 0)
				cout << endl;
		}
		cout << endl;
	}



	//deque�ĵ�����Ϊ������ʵ�����
	cout << typeid(deque<int>::iterator::iterator_category).name() << endl;

	//֧��++��--��+=n,-=n,[],+n,-n
	deque<int>::iterator it = d2.begin();
	*it = 111;
	cout << *it << endl;
	

	it++;
	cout << *it << endl;

	it += 2;
	cout << *it << endl;

	cout << *(it-3) << endl;  //it����û��

	cout << it[1] << endl;  //ָ�����һ��Ԫ��

	//const itrater
	deque<int>::const_iterator it2 = d2.cbegin();
	//*it2 = 1111;   //������const int *

	{
		for (deque<int>::iterator it = d2.begin(); it != d2.end(); it++)
		{
			cout << *it << "	";
		}
		cout << endl;
	}


	//���������
	{
		for (deque<int>::reverse_iterator rit = d2.rbegin(); rit != d2.rend(); rit++)
		{
			cout << *rit << "	";
		}
		cout << endl;
	}


	//����
	deque<int> d5;
	d5.push_back(1);
	d5.push_front(2);  //��ͷ�����룬vectorû�д˷���
	d5.insert(d5.begin(), 3);   //�ڵ�����λ�ò���
	d5.insert(d5.end(), 2, 4);


	for (deque<int>::iterator it = d5.begin(); it != d5.end(); it++)
	{
		cout << *it << "	";
	}
	cout << endl;


	//����Ԫ��

	d5.at(0) = 1111;
	d5[1] = 2222;

	cout << d5.front() << endl;   //���ص�һ��Ԫ��

	cout << d5.back() << endl;    //�������һ��Ԫ��

	//ɾ��

	d5.pop_back();  //β��ɾ��
	d5.pop_front();	//ͷ��ɾ��
	d5.erase(d5.begin());    //ɾ��ĳ��������ָ����Ԫ��

	for (deque<int>::iterator it = d5.begin(); it != d5.end(); it++)
	{
		cout << *it << "	";
	}
	cout << endl;

	d5.clear();	//ȫ�����

	cout << "Ԫ�ظ���:" << d5.size() << endl;







}
