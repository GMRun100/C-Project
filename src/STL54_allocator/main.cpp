//ѧϰSTL�������֮�ռ�������allocator
//2020.01.27 GM 

#include<iostream>
using namespace std;
void main()
{
	{
		//STL Ĭ�Ͽռ�������  allocator


		//����һ��int���Ϳռ�������
		allocator<int> allo;
		//����һ��int�Ŀռ䣬4Byte
		int* pA = allo.allocate(1);
		//���죬����int��˵���Ǹ���ʼֵ
		allo.construct(pA, 111);

		cout << *pA << endl;
		*pA = 222;

		//����Ԫ��ֵ��ȡ��ַ
		const int* pB = allo.address(*pA);
		cout << (pA == pB) << endl;


		cout << allo.max_size() << endl;
	}


	{
		//������A
		class A
		{
		public:
			A(int _a) :a(_a)
			{
					cout << "����A�Ĺ��캯��" << endl;
			}
			~A()
			{
				cout << "����A����������" << endl;
			}
			int a;
		};

		//����һ����A�Ŀռ�������
		allocator<A> allo;

		//����һ��A�Ŀռ�
		A *pA=allo.allocate(1);
		
		//�������
		allo.construct(pA, 222);
		cout << pA->a << endl;

		//������������
		allo.destroy(pA);

		//�����ڴ�
		allo.deallocate(pA,1);


	}

}