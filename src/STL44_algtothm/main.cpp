//ѧϰ���޸������㷨  GM 2020.1.4

#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

//�ж����ֵ�Ƿ�Ϊ3
bool Is3(int x)
{
	return x == 3;
}

void Print(int x)
{
	cout << x << "   ";
}


struct Is3_FO
{
	bool operator()(int x)
	{
		return x == 3;
	}
};


void main()
{
	//���ݶ�����������
	vector<int> v= {1, 2, 3, 4, 5};


	{
		//���ң��㷨��ֱ�Ӳ�����������ͨ������(��������������������)
		vector<int>::iterator it = find(v.begin(), v.end(), 3);
		if (it != v.end())
		{
			cout << "�ҵ���" << *it << endl;
		}
		else
		{
			cout << "û�ҵ���" << endl;
		}
	}


	{
		//��find���ƣ�ֻ������ҪһԪ�������󷵻�Ϊtrue
		//find_if�����ν�Ԫ��ֵ����Is3��ȥ��飬�������Ϊtureʱ����Ϊ�ҵ���
		vector<int>::iterator it = find_if(v.begin(), v.end(), Is3); //��ͨ����
		//vector<int>::iterator it = find_if(v.begin(), v.end(), Is3_FO());  //һԪ��������
		if (it != v.end())
		{
			cout << "�ҵ���" << *it << endl;
		}
		else
		{
			cout << "û�ҵ���" << endl;
		}
	}


	{
		//���ҵ�2,3�е��κ�һ��ֵ����Ϊ���ҵ���
		vector<int> v2 = { 2,3};
		vector<int>::iterator it=find_first_of(v.begin(), v.end(), v2.begin(), v2.end());
		if (it != v.end())
		{
			cout << "�ҵ���" << *it << endl;
		}
		else
		{
			cout << "û�ҵ���" << endl;
		}

	}


	{
		//��ÿ��Ԫ��������Ϊ�������뵽һԪ����Print��ִ��
		for_each(v.begin(), v.end(), Print);//���뺯��ָ��
		cout << endl;
	}


	{
		
		vector<int> v2 = { 1,2,2,2,2,2,3,4,5 };
		//ͳ��һ��Ԫ�س��ֵĴ���
		cout << "2���ֵĴ���" << count(v2.begin(), v2.end(), 2) << endl;;

	}


	{
		vector<int> v2 = { 1,2,2,2,2,2,3,3,3,4,5 };
		//ͳ��һ��Ԫ��ʹ��Is3����Ϊtrue�Ĵ���
		cout << "3���ֵĴ���" << count_if(v2.begin(), v2.end(), Is3) << endl;;
	}


	{
		vector<int> v2 = { 3,4 };

		//�����������У�����һ��������
		vector<int>::iterator it = search(v.begin(), v.end(), v2.begin(), v2.end());

		if (it != v.end())
		{
			cout << "�ҵ���" << *it << endl;
		}
		else
		{
			cout << "û�ҵ���" << endl;
		}

		{
			//��v2����������2����������Ԫ��4
			vector<int> v2 = {1,2,3,4,4,5,6};
			vector<int>::iterator it = search_n(v2.begin(), v2.end(), 2, 4);
			if (it != v2.end())
			{
				cout << "�ҵ���" << *it << endl;
			}
			else
			{
				cout << "û�ҵ���" << endl;
			}

		}


	}




}