#include<iostream>
using namespace std;
#include<stack>
#include<vector>
#include<list>
#include<array>
#include<forward_list>
void main()
{
	//����stack
	//stack<int> s;

	//����stack���ڲ�ʵ������Ϊvector,֧��push_back,pop_back,back
	stack<int,vector<int>> s;

	//����stack���ڲ�ʵ������Ϊlist,֧��push_back,pop_back,back
	//stack<int, list<int>> s;

	//stack<int, array<int,5>> s;  //����array��֧��pop_back

	//stack<int, forward_list<int>> s;  //����forward_list��֧��pop_back

	cout << "Ԫ�ظ�����" << s.size() << endl;
	
	//

	//stack<int> s2(s);   //���ÿ������캯��
	//cout << "Ԫ�ظ�����" << s2.size() << endl;

	//�鿴stack�ڲ�����������:deque
	cout << typeid(stack<int>::container_type).name() << endl;

	//��ջ
	s.push(1);
	s.push(2);
	s.push(3);
	
	
	//s[0];	//ջֻ����ȡջ�������������ӿڷ���Ԫ��

	//��ջ
	//ջ�ı���
	while (!s.empty())
	{
		cout << s.top() <<"  "<<s.size()<< endl;  //��ȡջ��Ԫ��
		s.pop();  //��ջ
	}

}