//ѧϰ���㷨  GM 2020.1.5
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void Print(int x)
{
	cout << x << "   ";
}
void main()
{
	//�ṩһ�����ҵ�����
	vector<int> v = { 5,2,1,4,3 };

	{
		//�������е�Ԫ����ϳɶѽṹ(Ĭ�ϴ����)
		//make_heap(v.begin(), v.end());  //Ĭ���Ǵ����
		make_heap(v.begin(), v.end(),greater<int>()); //����С����
		for_each(v.begin(), v.end(), Print);
		cout << endl;

		//����һ��Ԫ�ص����У�ʹ����Ȼ��һ����
		//1.���һ����Ԫ�ص�����ĩβ
		//2.����push_heap������Ȼ�Ƕ�
		v.push_back(0);
		push_heap(v.begin(), v.end(),greater<int>());
		for_each(v.begin(), v.end(), Print);
		cout << endl;



		//�Ӷ���ɾ��һ��Ԫ�أ�ʹ����Ȼ��һ����
		//1.����pop_heap�Ὣɾ���ĶѶ�Ԫ���ƶ���������β��
		pop_heap(v.begin(), v.end(), greater<int>());
		//2.ɾ��ĩβԪ�أ���֤����������һ��С����
		v.pop_back();
		for_each(v.begin(), v.end(), Print);
		cout << endl;

		//vector�����С���ѣ�Ԫ��˳�򲢲��ǴӴ�С
		//����sort_heap֮ǰ���뱣֤��һ���ѽṹ���У�������֮�󣬲����Ƕ���
		sort_heap(v.begin(), v.end(),greater<int>());//�������е�Ԫ������
		for_each(v.begin(), v.end(), Print);
		cout << endl;




	}









}


