#include<functional>
#include<iostream>
using namespace std;

//使用适配器改变接口，符合用户需求
struct LessThan3
{
	bool operator()(int x)
	{
		return less<int>()(x, 3);
	}

};

//模拟binder1st,binder2nd
struct LessThan4
{
	LessThan4(less<int> _fn,int _val):fn(_fn),val(_val)
	{}
	bool operator()(int x)
	{
		return fn(x, val);
	}
	int val;
	less<int> fn;
};





void main()
{

	cout << LessThan3()(2) << endl;

	//STL将2元函数转换为1元函数对象的适配器类,内部填充第一个参数
	//相当于less<T>(3,?)
	binder1st<less<int>> uf(less<int>()/*真正实现功能的仿函数*/,3);

	cout << "是否比3大:" << uf(2) << endl;

	//内部填充第二个参数
	binder2nd<less<int>> uf2(less<int>()/*真正实现功能的仿函数*/, 3);
	//相当于less<T>(?,3)
	cout << "是否比3小:" << uf2(2) << endl;

	//直接写,构造无名对象
	cout << "无名仿函数对象:"<<binder2nd<less<int>>(less<int>(), 3)(2) << endl;

	//模拟binder1st
	LessThan4  lt(less<int>(), 4);
	cout << "是否比4小" << lt(5) << endl;

	//直接使用【函数模板bind1st】产生【仿函数适配器binder1st】
	cout << "返回binder1st仿函数对象，是否比3大:"<<bind1st(less<int>(), 3)(4) << endl;

}