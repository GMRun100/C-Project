#include<map>
#include<iostream>
using namespace std;
#include<vector>

void main()
{
	//mapӳ�䣬ÿ��Ԫ�ض���key-value��ֵ�ԣ�key�����ظ���value�����ظ�������

	map<int, string> m;
	cout << "Ԫ�ظ���:" << m.size() << endl;

	//��ʼ���б���map
	map<int, string> m2 = { {3,"ccc"},{1,"AAA"},{2,"BBB"} };
	cout << "Ԫ�ظ���:" << m2.size() << endl;

	//��������
	map<int, string> m3(m2);
	cout << "Ԫ�ظ���:" << m3.size() << endl;


	//��֤�����е�Ԫ������
	cout << typeid(map<int, string>::value_type).name() << endl;


	//һ��ֵpair��ģ��
	pair<int, float> p1;
	p1.first = 1;
	p1.second = 2.34f;
	cout << "first:" << p1.first << " second:" << p1.second << endl;
	//���ù��캯��
	pair<int, float> p2(2, 3.45);
	cout << "first:" << p2.first << " second:" << p2.second << endl;

	//ʹ��make_pair�㷨����pair
	pair<short, char> p3 = make_pair<short, char>(3, 'A');
	cout << "first:" << p3.first << " second:" << p3.second << endl;

	map<int, string> m4 = { pair<int,string>(3,"CCC"),make_pair(2,"BBB"),make_pair(1,"AAA") };
	cout << "Ԫ�ظ���:" << m4.size() << endl;




	//����Ԫ��
	map<int, string> m5;
	m5.insert(pair<int, string>(1, "AAA"));

	pair<int, string> p22(2, "BBB");
	m5.insert(p22);

	//����ͨ��insert����ֵ�ĳ�Ա.second�鿴�Ƿ����ɹ���true�ɹ���false��ʧ��
	cout<<"�鿴�����Ƿ�ɹ�:"<<m5.insert(make_pair<int, string>(2, "BBB")).second<<endl;   //�����ظ���Ԫ��,����ʧ��


	m5.insert(make_pair(3, "CCC"));



	//�������������е�Ԫ��
	vector<pair<int, string>> v = { {4,"DDD"},{5,"EEE"},{6,"FFF"} };

	m5.insert(v.begin(), v.end());

	//[key]=value
	m5[7] = "ggg";

	m5[8];   //Ҳ�����������룬�൱��(8,"")
	m5[2] = "bbb";   //�����Ѿ����ڵ�key,�൱�����޸�Ԫ�ص��value

	for (map<int, string>::iterator it = m5.begin(); it != m5.end(); it++)
	{
		cout << it->first << "->" << it->second.c_str() << "     ";
	}
	cout << endl;

	//����Ԫ��:�ҵ�����ָ���Ԫ�صĵ����������򷵻�end()
	auto it2 = m5.find(3);
	if (it2 != m5.end())
	{
		cout << "�ҵ�:" << it2->first << "->" << it2->second.c_str() << endl;
	}
	else
	{
		cout << "δ�ҵ�!" << endl;
	}
	it2 = m5.find(33);
	if (it2 != m5.end())
	{
		cout << "�ҵ�:" << it2->first << "->" << it2->second.c_str() << endl;
	}
	else
	{
		cout << "δ�ҵ�!" << endl;
	}


	//[key]:ͨ��key��ȡ��Ӧ��valueֵ��������Ҫע�⣬����д�����key�����ڣ�������һ��(key-Ĭ��ֵ)��Ԫ��
	cout << "[key]" << m[3].c_str() << endl;






	//ɾ��Ԫ��
	//ɾ��keyΪ3��Ԫ��
	m5.erase(3);

	//ɾ��ĳ��������ָ���Ԫ��
	m5.erase(m5.begin());
	for (map<int, string>::iterator it = m5.begin(); it != m5.end(); it++)
	{
		cout << it->first << "->" << it->second.c_str() << "     ";
	}
	cout << endl;
	//ɾ������������[)��Ԫ��
	map<int, string>::iterator it = m5.begin();
	it++; it++; it++;
	m5.erase(m5.begin(), it);  //��ʱit��ָ���Ԫ��û��ɾ��������֮ǰ��Ԫ�ر�ɾ��






	for (map<int, string>::iterator it = m5.begin(); it != m5.end(); it++)
	{
		cout << it->first << "->" << it->second.c_str() << "     ";
	}
	cout << endl;


	//�������Ԫ��
	m5.clear();

	//������

	map<int, string> m6;
	m6.insert(make_pair(3, "CCC"));
	m6.insert(make_pair(1, "AAA"));
	m6.insert(make_pair(2, "BBB"));

	//�鿴����������:˫���������֧��++ -- * = != ==   ��֧��:[] += -= +n -n
	cout << typeid(map<int,string>::iterator::iterator_category).name() << endl;
	map<int, string>::iterator it6 = m6.begin();
	//it6->first = 111;   //keyֵ�������޸ģ�map�ǰ���key�ź���ģ��������keyֵ�����˳��
	it6->second = "aaa";    //value�����޸�

	++it6;
	cout << it6->first << "->" << it6->second << endl;
	--it6;
	cout << it6->first << "->" << it6->second << endl;
	cout << "�ص���ͷ" << (it6 == m6.begin()) << endl;


	//const_iterator:ָ���Ԫ�����ݲ����޸�
	map<int, string>::const_iterator cit6 = m6.begin();
	//cit6->first = 111;
	//cit6->second = "aa";  //valueֵҲ�����޸�



	//����Ԫ��
	for (map<int, string>::iterator it = m6.begin(); it != m6.end(); it++)
	{
		cout << it->first << "->" << it->second <<"   ";
	}
	cout << endl;

}
