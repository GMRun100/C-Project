//Reuse code with composition
#include "Useful.h"
class Y
{
	int i;
public:
	Y() { i = 0; };
	~Y();
	X x;
	void f(int ii) { i = ii; }
	int g() const { return i;}

private:


};

Y::Y()
{
}

Y::~Y()
{
}