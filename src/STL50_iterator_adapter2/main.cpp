//ѧϰ������������������
//2020.1.24 GM 

#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;

void main()
{
	//ΪʲôҪʹ�õ���������Ϊ�㷨ֻ���ܵ�����


	/*
	{

	istream_iterator<int> iit(cin);
	istream_iterator<int> iit_end;
	
	
		//���ַ�����Ҫ��ָ�������Ĵ�С
		//vector<int> v(3);   
		//copy(iit, iit_end, v.begin());//��ʾ���û������뿽����vector��
	}
	//���ַ������Բ�ָ�������Ĵ�С
	vector<int> v;  
	back_insert_iterator<vector<int>> bit(v);
	//*bit=333; //��ʵ����push_back(333);
    copy(iit, iit_end, bit);//��ʾ���û������뿽����vector��


	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << "   ";
	}
	cout << endl;
	*/


	//{
	//	//�����������
	//	vector<int> v = { 1,2,3,4,5 };
	//	ostream_iterator<int> oit(cout, "   ");
	// *oit=333; //��ʵ����cout<<333
	//	copy(v.begin(),v.end(),oit);
	//	//copy�ı��ʾ��� *oit=*it   
	//	//ostream_iterator��=��������أ����ܾ���cout<<
	//}


	{
		//�㷨���ǲ�����������
		//�����ʾ���ǽ��������������е�����������������������

		istream_iterator<int> iit(cin);
		istream_iterator<int> iit_end;

		ostream_iterator<int> oit(cout, "   ");
		copy(iit, iit_end, oit);
		//copy�ı��ʾ��� *oit=*it   
		//ostream_iterator��=��������أ����ܾ���cout<<


	}

}