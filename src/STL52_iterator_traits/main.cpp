//ѧϰ��������ȡ��
//2020.1.27 GM 

#include<iostream>
#include<iterator>
#include<vector>

using namespace std;


//����ϵͳ��iterator_traitsʵ��fun3(fun1��fun2d��ʾ���μ�STL51��Ŀ��)
template<class T>
typename iterator_traits<T>::value_type fun3(T it)   //value_type��ʾ������������ָ���Ԫ�ص�����
/*����typename �ű�ʾ����*/
{
	return *it;
}



void main()
{
	/*������������
	vector<int>::iterator::value_type;
	vector<int>::iterator::iterator_category;
	vector<int>::iterator::pointer;
	vector<int>::iterator::reference;
	vector<int>::iterator::difference_type;
	*/



	//��ָ������
	cout << typeid(iterator_traits<vector<int>::iterator>::value_type).name() << endl;
	//ָ������(����ĵ���������)
	cout << typeid(iterator_traits<int *>::value_type).name() << endl;

	vector<int> v = { 1,2,3,4,5 };

	cout << fun3<vector<int>::iterator>(v.begin()) << endl;

	//������Ϊԭʼָ��ʱ
	int v2[] = { 1,2,3,4,5 };
	int* pV = v2;
	//cout<<fun<int *>(pV)<<endl;   //int * û���ڲ�����value_type

	cout << fun3<int*>(pV) << endl;


}