//学习STL六大组件之空间配置器allocator
//2020.01.27 GM 

#include<iostream>
using namespace std;
void main()
{
	{
		//STL 默认空间配置器  allocator


		//定义一个int类型空间配置器
		allocator<int> allo;
		//分配一个int的空间，4Byte
		int* pA = allo.allocate(1);
		//构造，对于int来说就是赋初始值
		allo.construct(pA, 111);

		cout << *pA << endl;
		*pA = 222;

		//根据元素值获取地址
		const int* pB = allo.address(*pA);
		cout << (pA == pB) << endl;


		cout << allo.max_size() << endl;
	}


	{
		//定义类A
		class A
		{
		public:
			A(int _a) :a(_a)
			{
					cout << "调用A的构造函数" << endl;
			}
			~A()
			{
				cout << "调用A的析构函数" << endl;
			}
			int a;
		};

		//定义一个类A的空间配置器
		allocator<A> allo;

		//分配一个A的空间
		A *pA=allo.allocate(1);
		
		//构造对象
		allo.construct(pA, 222);
		cout << pA->a << endl;

		//调用析构对象
		allo.destroy(pA);

		//回收内存
		allo.deallocate(pA,1);


	}

}