#include<functional>
#include<iostream>
using namespace std;

//ʹ���������ı�ӿڣ������û�����
struct LessThan3
{
	bool operator()(int x)
	{
		return less<int>()(x, 3);
	}

};

//ģ��binder1st,binder2nd
struct LessThan4
{
	LessThan4(less<int> _fn,int _val):fn(_fn),val(_val)
	{}
	bool operator()(int x)
	{
		return fn(x, val);
	}
	int val;
	less<int> fn;
};





void main()
{

	cout << LessThan3()(2) << endl;

	//STL��2Ԫ����ת��Ϊ1Ԫ�����������������,�ڲ�����һ������
	//�൱��less<T>(3,?)
	binder1st<less<int>> uf(less<int>()/*����ʵ�ֹ��ܵķº���*/,3);

	cout << "�Ƿ��3��:" << uf(2) << endl;

	//�ڲ����ڶ�������
	binder2nd<less<int>> uf2(less<int>()/*����ʵ�ֹ��ܵķº���*/, 3);
	//�൱��less<T>(?,3)
	cout << "�Ƿ��3С:" << uf2(2) << endl;

	//ֱ��д,������������
	cout << "�����º�������:"<<binder2nd<less<int>>(less<int>(), 3)(2) << endl;

	//ģ��binder1st
	LessThan4  lt(less<int>(), 4);
	cout << "�Ƿ��4С" << lt(5) << endl;

	//ֱ��ʹ�á�����ģ��bind1st���������º���������binder1st��
	cout << "����binder1st�º��������Ƿ��3��:"<<bind1st(less<int>(), 3)(4) << endl;

}