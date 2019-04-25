#pragma once
//Interview question
#include <afx.h>
class base
{
public:
	base() { TRACE("Base\n"); };
	virtual ~base() { TRACE("~Base\n"); };
	virtual void print() { TRACE("Base print\n"); }
	virtual void debug() { TRACE("Base debug\n"); }
	virtual void readOn() { TRACE("Base readOn\n"); }
	virtual void writeOn() { TRACE("Base writeOn\n"); }
};

class base
{
public:
	base() { TRACE("Base\n"); };
	virtual ~base() { TRACE("~Base\n"); };
	virtual void print() { TRACE("Base print\n"); }
	virtual void debug() { TRACE("Base debug\n"); }
	virtual void readOn() { TRACE("Base readOn\n"); }
	virtual void writeOn() { TRACE("Base writeOn\n"); }
};


