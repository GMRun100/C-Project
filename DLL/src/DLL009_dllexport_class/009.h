#pragma once

//ѧϰDLL ����C++��
//2020.06.10 GM 

class _declspec(dllexport) Stu
{
public:
	Stu(int id);
	void Print();
private:
	int id;
};
