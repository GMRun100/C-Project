//ѧϰ������������

#include<vector>
#include<iterator>
#include<iostream>
#include<deque>
using namespace std;

void main()
{
	{   
	vector<int> v = { 1,2,3,4,5 };

	//�������������������ģ��
	reverse_iterator<vector<int>::iterator> rit(v.end());
	cout << *rit << endl;
	++rit;//��ͨ�������Ĳ���
	cout << *rit << endl;

	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
	{
		cout << *it << "   ";
	}
	cout << endl;

	}
	//�������࣬�ӿ��ǵ�����������ʵ��ͷ�����빦��
	//�û���ʹ�õ�����һ���Ĳ���Ԫ��

	{
		//����������push_front�ĳ�Ա����
		deque<int> d = { 1,2,3,4,5 };

		front_insert_iterator<deque<int>> fit(d);
		*fit = 111;
		for (deque<int>::iterator it = d.begin(); it != d.end(); ++it)
		{
			cout << *it << "   ";   
		}
		cout << endl;

	}


	{
		vector<int> v= { 1, 2, 3, 4, 5 };
		back_insert_iterator<vector<int>> fit(v);
		*fit = 111;
		for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		{
			cout << *it << "   ";
		}
		cout << endl;

	}

	{
		//ʵ����ָ��λ�ò���
		vector<int> v = { 1, 2, 3, 4, 5 };
		insert_iterator<vector<int>> fit(v,v.begin()+2);
		*fit = 111;//�ڵڶ���Ԫ�غ������111
		*fit = 222;
		*fit = 333;
		for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		{
			cout << *it << "   ";
		}
		cout << endl;

	}

	{

		//��ʹ�õ�����һ�������롢���
		//�ṩһ�����������ӿھ��ǵ������Ľӿڣ��ڲ�ʵ����Ȼ��cin,cout
		istream_iterator<int> itEnd;//��ʾ�������
		istream_iterator<int> it(std::cin); //���Կ�ʼ������,����ctrl+z��ʾ�������
		int num1 = *it;//��ȡ��һ�������ֵ��
		it++;
		int num2 = *it;//��ȡ����ĵڶ���ֵ
		it++;
		cout << num1 << endl;
		cout << num2 << endl;

		if (it == itEnd)
			cout << "�Ѿ�û������" << endl;
	}
	cout << "---------------------------" << endl;
	{
		ostream_iterator<int> it(std::cout, "\n");
		*it = 111;   //�ȼ���cout<<111<<"\n"
		*it = 222;	//�ȼ���cout<<222<<"\n"

	}

}