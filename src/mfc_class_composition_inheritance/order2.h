#pragma once
//Interview question
#include <afx.h>
class Base
{
public:
	Base() { TRACE("Base\n"); };
	virtual ~Base() { TRACE("~Base\n"); };
	virtual void print() { TRACE("Base print\n"); }
	virtual void debug() { TRACE("Base debug\n"); }
	virtual void readOn() { TRACE("Base readOn\n"); }
	virtual void writeOn() { TRACE("Base writeOn\n"); }
};

class Derived12: virtual public Base    //Ðé¼Ì³Ð
{
public:
	Derived12() { TRACE("Derived1\n"); };
	virtual ~Derived12() { TRACE("~Derived1\n"); };
	virtual void writeOn() { TRACE("Derived1 writeOn\n"); }
};

class Derived22 :virtual public Base    //Ðé¼Ì³Ð
{
public:
	Derived22() { TRACE("Derived2\n"); };
	virtual ~Derived22() { TRACE("~Derived2\n"); };
	virtual void readOn() { TRACE("Derived2 readOn\n"); }
};

class M1:public Derived12,public Derived22
{
public:
	M1() { TRACE("M1\n"); };
	virtual ~M1() { TRACE("~M1\n"); };
	virtual void print() { TRACE("M1 print\n"); }
	virtual void debug() { TRACE("M1 debug\n"); }
};


