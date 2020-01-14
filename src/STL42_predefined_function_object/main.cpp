#include<iostream>
using namespace std;
#include<functional>


void main()
{

	//STL预定义函数对象

	//算数函数对象 + - * / %
	cout << "加法："<<plus<int>()(4, 2) << endl;
	cout << "减法：" <<minus<int>()(4, 2) << endl;
	cout << "乘法：" << multiplies<int>()(4, 2) << endl;
	cout << "除法：" << divides<int>()(4, 2) << endl;
	cout << "取模：" << modulus<int>()(4, 2) << endl;
	cout << "取负：" << negate<int>()(4) << endl;

	//比较函数对象 
	cout << "等于：" << equal_to<int>()(4, 2) << endl;
	cout << "不等于：" << not_equal_to<int>()(4, 2) << endl;
	cout << "大于：" << greater<int>()(4, 2) << endl;
	cout << "大于等于：" << greater_equal<int>()(4, 2) << endl;
	cout << "小于：" << less<int>()(4, 2) << endl;
	cout << "小于等于：" << less_equal<int>()(4,2) << endl;




	//逻辑函数对象
	cout << "与：" << logical_and<bool>()(1, 0) << endl;
	cout << "或：" << logical_or<bool>()(1, 0) << endl;
	cout << "非：" << logical_not<bool>()(1) << endl;



}
