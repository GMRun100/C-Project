//学习whar_t、long long类型、bool类型、auto类型的用法
//2019.09.13 GM
#include<iostream>
using namespace std;

int main()
{
	//wchar_t
	char c = 'b';
	cout << c << "	size=" << sizeof(c) << endl;

	wchar_t wc = L'w';
	//wcout用来输出宽字符
	wcout << wc << "	size=" << sizeof(wc) << endl;

	//C++默认的Locale是EN_US,而一般的终端不支持Unicode,需要将wchar_t转化为本地编码
	wcout.imbue(locale("chs"));
	wchar_t wc2 = L'中';
	wcout << wc2 << "	size=" << sizeof(wc2) << endl;


	//bool类型是C++中新增的类型，布尔值只有两种0和1,bool类型占一个字节
	//true和false为c++中新增的关键字
	bool b1 = true;
	bool b2 = false;
	bool b3 = 0;
	bool b4 = -1;

	cout << "sizeof bool:" << sizeof(bool) << endl;
	cout << b1 << endl;
	cout << b2 << endl;
	cout << b3 << endl;
	cout << b4 << endl;

	//long long 类型 占8个字节
	//‭/*‭4294967296‬为2的32次方0001 0000 0000 0000 0000 0000 0000 0000 0000‬*/
	long l1 = 4294967296; //long类型只占4个字节 表示的最大值为2的32次方-1
	long long l2 = 4294967296;
	cout << "l1=" << l1 << endl;
	cout << "l2=" << l2 << endl;

	//auto类型 c++11引入  编译器会自动判断变量类型


}

