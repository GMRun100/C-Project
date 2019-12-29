#include "stdafx.h"
#include "Test.h"


Test::Test()
{
	num1 = 10;
	num2 = 20;
}


Test::~Test()
{
}

void Test::print()
{
	TRACE("num1=%d\n", num1);
	TRACE("num2=%d\n", num2);
}

