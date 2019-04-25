#pragma once
class A 
{
	int i;
public:
	A(int ii) :i(ii) {}
	~A() {}
	void f() const {}
};

class B
{
	int i;
public:
	B(int ii) :i(ii) {}
	~B() {}
	void f() const {}
};

class C:public B
{
	int i;
	A a;
public:
	C(int ii) :B(ii - 1), a(ii - 2) {}     //call B() first; call A() second
	//call the destructors from the origin then last to the top
	~C() {}								   //call ~A()first;call ~B() second
	void f() const   //Redefination
	{
		a.f();
		B::f();
	}

};

