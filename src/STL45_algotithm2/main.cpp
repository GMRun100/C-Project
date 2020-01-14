//ѧϰ�޸������㷨  GM 2020.1.4

#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

struct Is3_FO
{
	bool operator()(int x)
	{
		return x == 3;
	}
};

void Print(int x)
{
	cout << x << "   ";
}

int Add2(int x)
{
	return x + 2;
}

void main()
{
	//���ݶ�����������
	vector<int> v = { 1, 2, 3, 4, 5 };

	{
		//�������λ��
		random_shuffle(v.begin(), v.end());
		for_each(v.begin(), v.end(), Print);
		cout << endl;

		random_shuffle(v.begin(), v.end());
		for_each(v.begin(), v.end(), Print);
		cout << endl;

	}

	{
		vector<int> v = { 1, 2, 3, 4,3, 5 };
		replace(v.begin(), v.end(), 3, 333);
		for_each(v.begin(), v.end(), Print);
		cout << endl;
	}

	{
		//�滻v������Ԫ��ΪIs3_FO()(x)����Ϊtrue��ֵ�滻Ϊ333
		vector<int> v = { 1, 2, 3, 4,3, 5 };
		replace_if(v.begin(), v.end(), Is3_FO(), 333);
		for_each(v.begin(), v.end(), Print);
		cout << endl;

	}

	{
		//��replaceһ�������ǲ��ı�v�����У�ֻ�ǽ��滻��Ľ��copy��v2��
		vector<int> v = { 1, 2, 3, 4,3, 5 };
		vector<int> v2(6);
		replace_copy(v.begin(), v.end(),v2.begin(),3,333);
		for_each(v.begin(), v.end(), Print);
		cout << endl;
		for_each(v2.begin(), v2.end(), Print);
		cout << endl;

	}


	{
		//������v��ÿ��Ԫ��ֵ���Ϊ111
		vector<int> v(5);
		fill(v.begin(), v.end(), 111);

		for_each(v.begin(), v.end(), Print);
		cout << endl;

	}

	{
		vector<int> v = { 1, 2, 3, 3,4,5 };

		//ɾ���ض�Ԫ�أ����ǲ���ı������Ĵ�С��ֻ�Ὣ�����Ԫ����ǰ�ƶ�
		//������ɾ�������һ��Ԫ�صĽ���λ��
		vector<int>::iterator itNewEnd=remove(v.begin(), v.end(), 3);

		for_each(v.begin(), itNewEnd, Print);
		cout << endl;
	}


	{
		vector<int> v = { 1, 2, 3,4,5 };
		//��v��Ԫ�ط���
		reverse(v.begin(), v.end());
		for_each(v.begin(), v.end(), Print);
		cout << endl;
	}



	{
		vector<int> v = { 1, 2,3,3,3,3,3,4,5,3 };
		//ɾ����������ͬԪ�ء���ֻ����һ�������ǲ���ı������Ĵ�С��ֻ�Ὣ�����Ԫ����ǰ�ƶ�
		//������ɾ�������һ��Ԫ�صĽ���λ��
		vector<int>::iterator itNewEnd=unique(v.begin(), v.end());
		for_each(v.begin(), itNewEnd, Print);
		cout << endl;
	}



	{

		vector<int> v = { 1, 2, 3,4,5 };
		vector<int> v2(5);
		//��V��ÿ��Ԫ�ش��뵽Add2��ִ�к󿽱���v2��
		transform(v.begin(), v.end(), v2.begin(), Add2);//���뺯��ָ��

		for_each(v.begin(), v.end(), Print);
		cout << endl;
		for_each(v2.begin(), v2.end(), Print);
		cout << endl;

	}

}