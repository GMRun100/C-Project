//ѧϰSYL�е�array
//2019.10.29 GM 

#include<iostream>
#include<array>
#include<algorithm>
using namespace std;

void main()
{
	array<int, 5> arr;//Ԫ��Ĭ��ֵ���
	cout << arr.size() <<"   "<< arr[0] << endl;

	array<int, 5> arr2 = {1,2,3};  //����ֵ��ֵΪ0
	cout << arr2.size() << "   " << arr2[0] << endl;

	//��������
	array<int, 5> arr3(arr2);
	cout << arr3.size() << "   " << arr3[3] << endl;	
	arr[0] = 11;
	arr[1] = 22;
	arr[2] = 33;
	arr.at(3) = 44;
	arr.at(4) = 55;
	for (size_t i = 0; i < arr.size(); i++)
	{
		//cout << arr2[i] << "	";
		cout<<arr.at(i)<< "	";
	}
	cout << endl;

	cout <<"��ȡ��һ��Ԫ��" <<arr.front() << endl;
	cout << "��ȡ���һ��Ԫ��" << arr.back() << endl;
	cout << "������鳤���Ƿ�Ϊ0��" << arr.empty()<< endl;  
	array<int, 0> arr4;
	cout << "���arr4���鳤���Ƿ�Ϊ0��" << arr4.empty() << endl;
	cout << "�����ڲ�������׵�ַ��" << arr.data()<<","<<&arr[0] << endl;

	//array������Ӧ�ĵ���������
	using ArrayIterator = array<int, 5>::iterator;  
	//ArrayIterator::value_type    //��������ָ��Ԫ������
	//ArrayIterator::difference_type  //��������������õ���ֵ������
	//ArrayIterator::pointer //��������ָ��Ԫ�ص�ָ������
	//ArrayIterator::iterator_category  //����������������֮һ������
	//ArrayIterator::reference   //��������ָ��Ԫ�ص���������

	//array�ĵ���������Ϊrandom_access_iterator_tag
	cout << typeid(ArrayIterator::iterator_category).name() << endl;


	array<int, 5>::iterator it1 = arr.begin() + 3;
	cout << *it1 << endl;

	//++
	it1++; //������֧�������Լ�
	cout << *it1 << endl;

	//--
	it1--;
	it1--;
	cout << *it1 << endl;


	//[],�൱�ڵ�ǰλ�ü�1
	cout << it1[1] << endl;
	
	//������ʵ����������޸�ָ��Ԫ�ص�ֵ

	*it1 = 333;
	cout << *it1 << endl;

	//const iterator
	//���صĵ�������ֻ����
	array<int, 5>::const_iterator cit1 = arr.cbegin();
	cout << *cit1 << endl;


	//�������
	for (array<int, 5>::reverse_iterator it3 = arr.rbegin(); it3 < arr.rend(); it3++)
	{
		cout << *it3 << "	";
	}
	cout << endl;
}