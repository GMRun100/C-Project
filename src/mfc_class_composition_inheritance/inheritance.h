#pragma once
//simple inheritance
#include "Useful.h"
class Y2:public X     //if the public is omitted, all members if the base class will be private.
{
	int i;
public:
	//initialization list of the constructors 
	Y2() :X(3),i(5)     //this will initial base class first,and here can also initial the members
	{ 
		//i = 2;     //after initial base class
	};    
	~Y2();
	int change()
	{
		i = permute();
		return i;
	}
	void set(int ii)
	{
		i = ii;
		X::set(ii+1);
	}
private:
	 
};



Y2::~Y2()
{
}