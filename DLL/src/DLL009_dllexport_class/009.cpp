#include"009.h"
#include<iostream>
using namespace std;

Stu::Stu(int id)
{
	this->id = id;
}

void Stu::Print()
{
	cout << id << endl;
}