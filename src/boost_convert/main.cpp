//学习boost的数值转换

#include<boost/lexical_cast.hpp>
#include<iostream>

using namespace std;
using namespace boost;


int main()
{
	//字符串转整型
	int a = lexical_cast<int>("12");
	int b = lexical_cast<int>("56");
	cout << "a+b=" << a + b << endl;
	
	//字符串转浮点型
	float pi = lexical_cast<float>("3.1415926");
	cout << "pi=" << pi << endl;
	string s_f = "123.456";
	float f = lexical_cast<float>(s_f);
	cout << "f=" << f << endl;

	//浮点数转字符串
	string s1 = lexical_cast<string>(333.789);
	cout << "s1=" << s1 << endl;

	//在转换的过程中，可能会出现异常情况，需要用try...catch进行异常捕获
	
	try
	{
		//int err = lexical_cast<int>("789edc");   //如果未指明转换的长度会抛出异常
		int err = lexical_cast<int>("789edc",2);   //指明仅转换前两个字符
		cout << "err=" << err << endl;
	}
	//使用bad_lexical_cast异常捕获
	catch (const bad_lexical_cast& e)
	{
		cout << e.what() << endl;
	}







	getchar();

}

