//ѧϰboost����ֵת��

#include<boost/lexical_cast.hpp>
#include<iostream>

using namespace std;
using namespace boost;


int main()
{
	//�ַ���ת����
	int a = lexical_cast<int>("12");
	int b = lexical_cast<int>("56");
	cout << "a+b=" << a + b << endl;
	
	//�ַ���ת������
	float pi = lexical_cast<float>("3.1415926");
	cout << "pi=" << pi << endl;
	string s_f = "123.456";
	float f = lexical_cast<float>(s_f);
	cout << "f=" << f << endl;

	//������ת�ַ���
	string s1 = lexical_cast<string>(333.789);
	cout << "s1=" << s1 << endl;

	//��ת���Ĺ����У����ܻ�����쳣�������Ҫ��try...catch�����쳣����
	
	try
	{
		//int err = lexical_cast<int>("789edc");   //���δָ��ת���ĳ��Ȼ��׳��쳣
		int err = lexical_cast<int>("789edc",2);   //ָ����ת��ǰ�����ַ�
		cout << "err=" << err << endl;
	}
	//ʹ��bad_lexical_cast�쳣����
	catch (const bad_lexical_cast& e)
	{
		cout << e.what() << endl;
	}







	getchar();

}

