#include<iostream>
#include<queue>
#include<list>

using namespace std;

void main()
{
	//queue<int> q;

	//����queue�ĵײ�����Ϊlist

	queue<int, list<int>> q;

	//�����������
	queue<int,list<int>> q2(q);

	//��ӡqueue�ڲ���������:deque
	cout << typeid(queue<int>::container_type).name() << endl;

	//�����
	q.push(1);
	q.push(2);
	q.push(3);

	//����ͷԪ��
	q.front();
	//����βԪ��
	q.back();

	//������
	while (!q.empty())
	{
		cout << "����ͷԪ�أ�" << q.front() << endl;
		q.pop();  //������
	}







}
