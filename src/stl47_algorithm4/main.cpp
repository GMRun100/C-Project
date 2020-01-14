//学习堆算法  GM 2020.1.5
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void Print(int x)
{
	cout << x << "   ";
}
void main()
{
	//提供一组凌乱的数据
	vector<int> v = { 5,2,1,4,3 };

	{
		//让数组中的元素组合成堆结构(默认大根堆)
		//make_heap(v.begin(), v.end());  //默认是大根堆
		make_heap(v.begin(), v.end(),greater<int>()); //构造小根堆
		for_each(v.begin(), v.end(), Print);
		cout << endl;

		//放入一个元素到堆中，使其依然是一个堆
		//1.添加一个新元素到容器末尾
		//2.调用push_heap让其依然是堆
		v.push_back(0);
		push_heap(v.begin(), v.end(),greater<int>());
		for_each(v.begin(), v.end(), Print);
		cout << endl;



		//从堆中删除一个元素，使其依然是一个堆
		//1.调用pop_heap会将删除的堆顶元素移动到容器的尾部
		pop_heap(v.begin(), v.end(), greater<int>());
		//2.删除末尾元素，保证容器正好是一个小根堆
		v.pop_back();
		for_each(v.begin(), v.end(), Print);
		cout << endl;

		//vector保存的小根堆，元素顺序并不是从大到小
		//调用sort_heap之前必须保证是一个堆结构序列，排序完之后，不再是堆了
		sort_heap(v.begin(), v.end(),greater<int>());//将容器中的元素排序
		for_each(v.begin(), v.end(), Print);
		cout << endl;




	}









}


