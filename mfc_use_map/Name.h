#pragma once
#include <string>
using namespace std;
class Name
{
public:
	Name(std::string first, std::string second) :firstname{ first }, secondname{ second }{};
	Name()=default;   //��ʾĬ�ϴ��ڹ��캯��
	~Name();
	
	//���ز�����
	bool operator<(const Name& name)
	{
		return secondname < name.secondname || ((secondname == name.secondname) && (firstname == name.firstname));
	}


private:
	std::string firstname{};
	std::string secondname{};

};

