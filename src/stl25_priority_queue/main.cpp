#include<queue>
#include<iostream>
#include<list>

using namespace std;

void main()
{
	//����
	//priority_queue<int> q;  //Ĭ�ϸ����ȼ��ȳ�����

	//priority_queue<int, vector<int>, greater<int>> q;  //�����ȼ��ȳ�����

	//���ײ���������Ϊdeque
	priority_queue<int, deque<int>> q;

	//priority_queue<int> q2(q);

	//���ȶ����ڲ�ʹ�õ�����
	cout << typeid(priority_queue<int>::container_type).name() << endl;

	//���ȶ������ȼ�ʹ�õıȽϷº�����less��������ȼ��ȳ�����
	cout << typeid(priority_queue<int>::value_compare).name() << endl;

	//�����,Ĭ����less�����ȼ��ߵ��ȳ�����
	q.push(9);
	q.push(3);
	q.push(1);
	q.push(2);

	//������
	while (!q.empty())
	{
		cout << "����ͷԪ�أ�" << q.top() << endl;
		q.pop();  //������
	}

	



}