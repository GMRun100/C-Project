//练习c++文件的的读写
#include<iostream>
#include<fstream>
using namespace std;


int main()
{
	//练习ofstream输出到文件
	ofstream o;
	o.open("1.txt", ios::out);//每一次都将清除上一次的内容，新生成一个文件
	o << "hello";
	o.write("world!", strlen("world!"));
	o.close();

	//练习ifstream读取文件
	ifstream i;
	i.open("1.txt", ios::in);
	char buf[100] = {0};
	//读取方式一
	//i.read(buf, 100);
	//读取方式二
	i >> buf;
	cout << buf << endl;
	//显示实际读取的字节数
	cout << "实际读取:" << i.gcount() << endl;   //gcount()需要与read()函数配套使用
	i.close();


	//fstream可以读写文件
	fstream f;
	f.open("2.txt", ios::in | ios::out|ios::trunc);
	//输出到文件
	f << "hello";
	f << 100;
	f << 1.234;
	//将文件指针放到开头
	f.seekg(0, ios::beg);  //0表示与文件开头的偏移地址

	char buf2[100] = {0};

	f >> buf2;
	cout << buf2 << endl;
	f.close();

	return 0;
}