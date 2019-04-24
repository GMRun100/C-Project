#pragma once
#include <string>
using namespace std;
class Name
{
public:
	Name(std::string first, std::string second) :firstname{ first }, secondname{ second }{};
	Name()=default;   //表示默认存在构造函数
	~Name();
	
	//重载操作符
	bool operator<(const Name& name)
	{
		return secondname < name.secondname || ((secondname == name.secondname) && (firstname == name.firstname));
	}


private:
	std::string firstname{};
	std::string secondname{};

};

