//2019.12.31 GM  ѧϰ�º���
#include<iostream>
using namespace std;

int ncount = 0;

//�����Сֵ
int Min(const int& a, const int& b)
{
	ncount++;
	return a < b ? a:b;
}


//�º��� 1.����struct����class 2.()���������
struct Min2
{
	typedef int ret_type;  //�����ڲ�����

	int  operator()(const int& a, const int& b)
	{
		m_ncount++;
		return a < b ? a : b;
	}
	static int m_ncount;   //����Min2���ô���
};

int Min2::m_ncount = 0;


class Min3
{
public:
	int  operator()(const int& a, const int& b)
	{
		return a < b ? a : b;
	}
private:
	void(*pMin)(int a, int b);  //����ָ��

};


void main()
{
	//�����ĺ�������
	cout << "��Сֵ��:" << Min(111, 222) << endl;

	//�º�������
	Min2 min2;  //����һ���ṹ�����
	cout << "��Сֵ��:" << min2(111, 222) << endl;   //������������Ա����
	cout << "��Сֵ��:" << Min2()(111, 222) << endl;   //Min2()��������ֱ�ӵ���
	cout << "��Сֵ��:" << Min3()(111, 222) << endl;   //Min3()��������ֱ�ӵ���
}