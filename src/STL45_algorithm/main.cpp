//ѧϰ���֡������㷨
//GM 2020.1.5

#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;
class A
{
public:
	A(int _a, int _b) :a(_a), b(_b) {}
	int a;
	int b;
};
void Print(int x)
{
	cout << x << "   ";
}

void PrintA(A x)
{
	cout << x.a<<"-"<<x.b << "   ";
}

struct Is2or3
{
	bool operator()(int x)
	{
		return x == 2 || x == 3;
	}

};

bool MyGreater(int a, int b)
{
	return a > b;
}


bool MyGreater2(A a, A b)
{
	return a.a > b.a;
}

void main()
{
	{

		vector<int> v = { 1,2,3,4,5 };

		//����������º������Ϊtrue�ŵ�ǰ�棬Ϊfalse�ŵ�����
		vector<int>::iterator itMid = partition(v.begin(), v.end(), Is2or3());

		for_each(v.begin(), itMid, Print);
		cout << endl;

		for_each(itMid, v.end(), Print);
		cout << endl;

	}


	{

		vector<int> v = { 1,2,3,4,5 };

		//����������º������Ϊtrue�ŵ�ǰ�棬Ϊfalse�ŵ�����
		//��partition�������ǻᱣ��ԭ����˳��
		vector<int>::iterator itMid = stable_partition(v.begin(), v.end(), Is2or3());

		for_each(v.begin(), itMid, Print);
		cout << endl;

		for_each(itMid, v.end(), Print);
		cout << endl;

	}


	{

		vector<int> v = { 1,2,3,4,5 };

		//����������º������Ϊtrue�ŵ�ǰ�棬Ϊfalse�ŵ�����
		//sort(v.begin(), v.end(),greater<int>());  //ʹ��STLԤ����ĺ�������
		sort(v.begin(), v.end(), MyGreater);
		for_each(v.begin(), v.end(), Print);
		cout << endl;
	}

	{


		vector<A> v = { A(1,111),A(2,222),A(3,331),A(3,332) };

		//���򣬱�֤��ͬԪ��ֵԭ��˳��
		stable_sort(v.begin(), v.end(), MyGreater2);
		for_each(v.begin(), v.end(), PrintA);
		cout << endl;
	}


	{

		vector<int> v = { 99,59,60,23,89,45,66 };
		//��֪���ɼ���ߵ�ǰ����������ĳɼ�˳������ν
		partial_sort(v.begin(),v.begin()+3 ,v.end(), greater<int>());
		for_each(v.begin(), v.end(), Print);
		cout << endl;
	}


	{

		vector<int> v = { 99,59,60,23,89,45,66 };
		//�ѵ�n���Ԫ���ŵ���n��λ�ã�����������Ԫ��
		nth_element(v.begin(), v.begin() + 3, v.end(), greater<int>());
		for_each(v.begin(), v.end(), Print);
		cout << endl;
	}

}