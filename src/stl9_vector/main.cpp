//ѧϰvector���÷�
//2019.10.31 GM

#include<iostream>
using namespace std;
#include<vector>

void main()
{
	//������Vector
	vector<int> v1;
	cout << "����Ϊ��" << v1.capacity() << "	Ԫ�ظ�����" << v1.size() << endl;

	//�ռ�Ϊ5��Ԫ�ظ���Ϊ5
	vector<int> v2(5);
	cout << "����Ϊ��" << v2.capacity() << "	Ԫ�ظ�����" << v2.size() <<"	V2[0]:"<<v2[0] <<endl;

	//�ռ�Ϊ5��Ԫ�ظ���Ϊ5��ÿ��Ԫ�صĳ�ʼֵ��Ϊ111
	vector<int> v3(5,111);
	cout << "����Ϊ��" << v3.capacity() << "	Ԫ�ظ�����" << v3.size() << "	V3[0]:" << v3[0] << endl;

	//��������Vector
	vector<int> v4(v3);
	cout << "����Ϊ��" << v4.capacity() << "	Ԫ�ظ�����" << v4.size() << "	V4[0]:" << v4[0] << endl;

	//vector������[]�����
	v2[0] = 1;
	v2[1] = 2;
	v2[2] = 3;
	v2.at(3) = 4;
	v2.at(4) = 5;
	for (size_t i = 0; i < v2.size(); i++)
	{
		//cout << v2[i] << "	";
		cout << v2.at(i) << "	";
	}

	cout << endl;


	//��֤vector���ڴ�ṹ
	for (size_t i = 0; i < v2.size(); i++)
	{
		//cout << v2[i] << "	";
		cout << &v2.at(i) << "	";
	}
	cout << endl;


	//vector�ĵ�����Ϊ������ʵ�����
	cout << typeid(vector<int>::iterator::iterator_category).name() << endl;

	vector<int>::iterator it = v2.begin();
	cout << "��ͷ������ָ���Ԫ�أ�"<<*it << endl;

	++it;
	cout << "�ڶ���Ԫ�أ�" << *it << endl;

	cout << "���ĸ�Ԫ�أ�" << *(it+2) << endl;  //it����ָ��ڶ���Ԫ��

	it -= 1;
	cout << "��һ��Ԫ�أ�" << *it << endl;

	cout << "�����Ԫ�أ�" << it[4] << endl;   //itû��


	//ʹ�õ���������Ԫ��
	for (vector<int>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout  << *it <<"	";
	}
	cout << endl;
	
	//��������ָ���Ԫ��ֵ���ɸı�,����const int* p
	vector<int>::const_iterator it2 = v2.cbegin();
	//*it2 = 111;  //��ʾ���ʽ�����ǿ��޸ĵ���ֵ


	//���������
	for (vector<int>::reverse_iterator it = v2.rbegin(); it != v2.rend(); it++)
	{
		cout << *it << "	";
	}
	cout << endl;


	//����Ԫ��

	vector<int> v;
	cout << "v����Ϊ��" << v.capacity() << "	vԪ�ظ�����" << v.size() << endl;

	//β������
	v.push_back(1);
	cout << "v����Ϊ��" << v.capacity() << "	vԪ�ظ�����" << v.size() << endl;
	v.push_back(2);
	cout << "v����Ϊ��" << v.capacity() << "	vԪ�ظ�����" << v.size() << endl;

	//��ĳһ��������ָ���λ�ò���
	v.insert(v.begin(), 3);  //v:3 1 2
	cout << "v����Ϊ��" << v.capacity() << "	vԪ�ظ�����" << v.size() << endl;

	v.insert(v.end(),2,4);  //v:3 1 2 4 4
	cout << "v����Ϊ��" << v.capacity() << "	vԪ�ظ�����" << v.size() << endl;

	for (vector<int>::const_iterator it = v.cbegin(); it != v.cend(); it++)
	{
		cout << *it << "	";
	}
	cout << endl;

	//���ʵ�һ��Ԫ��
	cout << "front:" << v.front() << endl;
	cout << "back:" << v.back() << endl;
	cout << "at3:" << v.at(3) << endl;



	//ɾ��Ԫ��

	//ɾ�����һ��Ԫ��
	v.pop_back(); //3 1 2 4
	cout << "v����Ϊ��" << v.capacity() << "	vԪ�ظ�����" << v.size() << endl;

	//ɾ����ͷ��Ԫ��
	v.erase(v.begin());   // 1 2 4
	cout << "v����Ϊ��" << v.capacity() << "	vԪ�ظ�����" << v.size() << endl;

	//ɾ�����һ��Ԫ��
	v.erase(v.end()-1);  // 1 2
	cout << "v����Ϊ��" << v.capacity() << "	vԪ�ظ�����" << v.size() << endl;

	for (vector<int>::const_iterator it = v.cbegin(); it != v.cend(); it++)
	{
		cout << *it << "	";
	}
	cout << endl;

	//ɾ������Ԫ�أ�����ı�������Ԫ�ظ���Ϊ0
	v.clear();
	cout << "v����Ϊ��" << v.capacity() << "	vԪ�ظ�����" << v.size() << endl;

	//��size��capacity���ʱ����������ݣ�����vector�����ݣ�ÿ�����ݶ������ӵ�ǰ�ռ��1/2(��һ�γ���)

	//����Vector�����ݹ���
	cout << "����Vector�����ݹ���" << endl;
	vector<int> v6;
	for (size_t i = 0; i < 50; i++)
	{
		v6.push_back(i);
		cout << "v6����Ϊ��" << v6.capacity() << "	v6Ԫ�ظ�����" << v6.size() << endl;
	}

	

}