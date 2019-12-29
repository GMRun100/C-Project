//练习map的使用技巧
//2019.09.07 GM

#include<map>
#include<string>
using namespace std;

int main()
{
	map<string, int*> map1;
	int *p_i=new int(2);
	int i_tmp;
	//p_i = &i_tmp;
	i_tmp = 1;
	map1.insert(make_pair("1", p_i));

	i_tmp = 2;
	map1.insert(make_pair("2", p_i));

	i_tmp = 3;
	map1.insert(make_pair("3", p_i));

	auto it = map1.begin();
	it++;

	auto iter_ = map1.find("2");

	if (iter_ != map1.end())
	{
		delete iter_->second;
	}
	
	map<string, int*> map2;
	map2.clear();




}