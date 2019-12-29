#pragma once
#include "Useful.h"
class Y
{
	int i;
	X x;    //Embedded object
public:
	Y(){ i = 0; };
	~Y();
	void f(int ii) { i = ii; }
	int g() const { return i; }
	void permute() { x.permute(); }
private:
};

Y::~Y()
{
}