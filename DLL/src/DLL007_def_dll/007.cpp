//学习DLL中.def文件的使用
//2020.6.8 GM 

//利用.def文件导出
int fun()
{
	return 1000;
}

int Min(int a, int b)
{
	return a < b ? a : b;
}
int Max(int a, int b)
{
	return a > b ? a : b;
}