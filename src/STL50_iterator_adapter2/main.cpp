//学习迭代器适配器的运用
//2020.1.24 GM 

#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;

void main()
{
	//为什么要使用迭代器，因为算法只接受迭代器


	/*
	{

	istream_iterator<int> iit(cin);
	istream_iterator<int> iit_end;
	
	
		//此种方法需要先指定容器的大小
		//vector<int> v(3);   
		//copy(iit, iit_end, v.begin());//表示将用户的输入拷贝到vector中
	}
	//此种方法可以不指定容器的大小
	vector<int> v;  
	back_insert_iterator<vector<int>> bit(v);
	//*bit=333; //其实就是push_back(333);
    copy(iit, iit_end, bit);//表示将用户的输入拷贝到vector中


	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << "   ";
	}
	cout << endl;
	*/


	//{
	//	//输出流迭代器
	//	vector<int> v = { 1,2,3,4,5 };
	//	ostream_iterator<int> oit(cout, "   ");
	// *oit=333; //其实就是cout<<333
	//	copy(v.begin(),v.end(),oit);
	//	//copy的本质就是 *oit=*it   
	//	//ostream_iterator的=运算符重载，功能就是cout<<
	//}


	{
		//算法就是操作迭代器的
		//下面的示例是将输入流迭代器中的内容输出到输出流迭代器中

		istream_iterator<int> iit(cin);
		istream_iterator<int> iit_end;

		ostream_iterator<int> oit(cout, "   ");
		copy(iit, iit_end, oit);
		//copy的本质就是 *oit=*it   
		//ostream_iterator的=运算符重载，功能就是cout<<


	}

}