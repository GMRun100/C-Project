//��ϰc++�ļ��ĵĶ�д
#include<iostream>
#include<fstream>
using namespace std;


int main()
{
	//��ϰofstream������ļ�
	ofstream o;
	o.open("1.txt", ios::out);//ÿһ�ζ��������һ�ε����ݣ�������һ���ļ�
	o << "hello";
	o.write("world!", strlen("world!"));
	o.close();

	//��ϰifstream��ȡ�ļ�
	ifstream i;
	i.open("1.txt", ios::in);
	char buf[100] = {0};
	//��ȡ��ʽһ
	//i.read(buf, 100);
	//��ȡ��ʽ��
	i >> buf;
	cout << buf << endl;
	//��ʾʵ�ʶ�ȡ���ֽ���
	cout << "ʵ�ʶ�ȡ:" << i.gcount() << endl;   //gcount()��Ҫ��read()��������ʹ��
	i.close();


	//fstream���Զ�д�ļ�
	fstream f;
	f.open("2.txt", ios::in | ios::out|ios::trunc);
	//������ļ�
	f << "hello";
	f << 100;
	f << 1.234;
	//���ļ�ָ��ŵ���ͷ
	f.seekg(0, ios::beg);  //0��ʾ���ļ���ͷ��ƫ�Ƶ�ַ

	char buf2[100] = {0};

	f >> buf2;
	cout << buf2 << endl;
	f.close();

	return 0;
}