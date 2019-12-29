//��ʵ����Ҫ��ѧϰ���õ�ʹ�ü���
#include<iostream>
using namespace std;

//��������
//�β�Ϊ��ͨ����
void Swap(int& x, int& y);  

void Foo(int& i);
//�β�Ϊ����
void Foo1(const int i);
//�β�Ϊ��������
void Foo2(const int& i);


int main()
{


	//********************��ͨ����********************
	int itmp;
	itmp = 10;
	//������ͨ����
	int& itmp_r = itmp;		//���ñ����ڶ����ʱ���Ҫ��ʼ��

	//�����ַ��ֵ
	cout << "itmp=" << itmp <<"	address="<<&itmp<< endl;
	cout << "itmp_r=" << itmp_r << "	address=" << &itmp_r <<endl;    //����ָ����ͬһ����ַ

	//������Ϊ����
	int a = 10;
	int b = 20;
	
	cout << "����ǰa��ֵ��a:" << a << endl;
	cout << "����ǰb��ֵ��b:" << b << endl;
	swap(a, b);
	cout << "������a��ֵ��a:" << a << endl;
	cout << "������b��ֵ��b:" << b << endl;

	//****************************��������***************************

	int itemp2 = 10;

	//double& dtemp2_r = itemp2;    //�������ᱨ�����õ����ͱ������������ö��������һ��

	/*����
		const double &dtemp2_r = itemp2;
		�������Ͳ�ƥ�䣬ʵ���൱�ڣ�
		const double inner_tmp = (double)itemp2;  //����Ͳ�����һ����ʱ����
		const double &dtemp2_r = inner_tmp;
		��ʱ���м��������const������û��const�����û�ʧ�ܡ�
	*/

	//�������õĳ�ʼֵ������������ʽ��ֻҪ�ñ��ʽ�Ľ����ת�������õ����ͼ���
	const int& itemp2_r = itemp2;
	const double& dtemp2_r = itemp2;  //����ͨ��

	cout << "the value of itemp2 : " << itemp2 << endl;
	cout << "the value of itemp2_r : " << itemp2_r << endl;
	cout << "the value of dtemp2_r : " << dtemp2_r << endl;

	//�ı䱻���ö����ֵ
	itemp2 = itemp2 * 2;
	cout << "the value of itemp2 : " << itemp2 << endl;			//output:20
	//�����������볣������������ͬʱ���������û�󶨵�ʵ�ʶ���
	cout << "the value of itemp2_r : " << itemp2_r << endl;		//output:20
	//����һ����ʽ���������ð󶨵���ʱ������
	cout << "the value of dtemp2_r : " << dtemp2_r << endl;		//output:10 

	
	cout << "the address of itemp2 : " << &itemp2 << endl;  //output:003AF7A4
	
	Foo(itemp2);	//output:003AF7A4
	Foo1(itemp2);	//output: 003AF6A8
	Foo2(itemp2);	//output:003AF7A4

	//Foo(1);	//�����������ǳ������õĳ�ʼֵ����Ϊ��ֵ
	Foo2(1);	//����ͨ��

	getchar();

	return 0;

}
/********************************************
* @brief  :��������x��y��ֵ
* @param  :int& x, int& y
* @note	  :�˴����õ��β�Ϊ�ǳ������ã�һ���β�Ϊ�ǳ�������ʱ����ʾ���õ�ֵ�ں����ڲ����Ա��޸�
* @output :none
* @time   :2019-07-27
*********************************************/
void Swap(int& x, int& y)
{
	int tmp;
	tmp = x;
	x = y;
	y = tmp;

	return;
}

void Foo(int& i)
{
	cout << "the address of i in Foo : " << &i << endl;
}

void Foo1(const int i)
{
	cout << "the address of i in Foo1 : " << &i << endl;
}

void Foo2(const int& i)
{
	cout << "the address of i in Foo2 : " << &i << endl;
}