#pragma once

//学习DLL 导出C++类
//2020.06.10 GM 

class _declspec(dllexport) Stu
{
public:
	Stu(int id);
	void Print();
private:
	int id;
};
