#include<iostream>
#include<vector>
using namespace std;

//ʵ��һ������ģ�壬Ҫ����Դ��������ʱ�����ظõ�����ָ���Ԫ��ֵ

template<typename T>
typename T::value_type fun(T it)   //value_type��ʾ������������ָ���Ԫ�ص�����
/*����typename �ű�ʾ����*/
{
	return *it;
}


//����ģ���ƫ�ػ��ж��Ƿ����������ָ��
template<typename T>
struct IsPointer
{
	static const bool value = false;
};
template<typename T>
struct IsPointer<T *>   //ƫ�ػ�
{
	static const bool value = true;
};

//�ο�IsPointer,дһ���м��࣬ʵ�ֶ���ͨ������ָ�����Ͷ�����value_type�ڲ�����
template<class T>
struct my_traits  //����ָ������
{
	typedef typename T::value_type value_type;
	/*����typename �ű�ʾ����,�����������Ϊ��T�ľ�̬��Ա*/
};

template<class T>
struct my_traits<T *>  //��ָ������
{
	typedef T value_type;
};

//����my_traitsʵ��һ��fun2
template<class T>
typename my_traits<T>::value_type fun2(T it)   //value_type��ʾ������������ָ���Ԫ�ص�����
/*����typename �ű�ʾ����*/
{
	return *it;
}



void main()
{

	vector<int> v = { 1,2,3,4,5 };

	cout << fun<vector<int>::iterator>(v.begin()) << endl;

	//������Ϊԭʼָ��ʱ
	int v2[] = { 1,2,3,4,5 };
	int* pV = v2;
     //cout<<fun<int *>(pV)<<endl;   //int * û���ڲ�����value_type

	cout << fun2<int*>(pV) << endl;




}