#include<iostream>
using namespace std;

_declspec(dllimport) int Max(int a, int b);
_declspec(dllimport) int fun666();
#pragma comment(lib,"DLL007_def_dll.lib")
int main()
{

	cout << Max(111, 222) << endl;
	cout << fun666() << endl;
	return 0;
}