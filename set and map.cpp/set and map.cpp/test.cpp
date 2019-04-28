#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <set>
#include <map>

using namespace std;

void Test_set()
{
	//set<int> s1;
	//s1.insert(6);
	//s1.insert(1);
	//s1.insert(4);
	//s1.insert(3);
	//s1.insert(9);
	//s1.insert(1);
	//s1.insert(2);
	//s1.insert(1);

	int array[9] = { 6, 1, 4, 3, 9, 1, 3, 2, 1 };
	set <int> s1(array, array+sizeof(array) / sizeof(int));
	cout << s1.count(3) << endl;

	for (auto it = s1.begin(); it != s1.end(); it++)
		cout << *it << " ";
	cout << endl;
	

	s1.erase(1);

	for (auto&e : s1)
	{
		cout << e << " ";
	}
	cout << endl;

	auto ret = s1.find(9);
	if (ret != s1.end())
		s1.erase(ret);

		std::set<int>::iterator it = s1.begin();
		while (it != s1.end())
		{
			cout << *it << " ";
			it++;
		}
		cout << endl;
	
}
void Test_map()
{
	//map<string, string> m1{
	//	{ "C", "小红" },
	//	{ "D", "小黑" }
 //   };
	//map<string, string> m;
	//m.insert(pair<string, string>("A", "小花"));
	//m.insert(make_pair("B", "小亮"));
	//m["E"] = "小蓝";

	int  str[] = { 1, 2, 2, 5, 6, 7, 5, 1 };
	map<int, int> countmap;
	for (const auto&e : str)
	{
		std::map<int, int>::iterator it = countmap.find(e);
		if (it != countmap.end())
			(it->second)++;
		else
			countmap.insert(make_pair(e, 1));
	}
	cout << countmap[5] << endl;



	//for (auto&e : m)
	//{
	//	cout << e.first << "--->" << e.second << endl;
	//}
	//cout << endl;

	//std::map<string, string>::iterator it = m.begin();
	//while (it != m.end())
	//{
	//	cout << (*it).first << "--->" << (*it).second << endl;
	//	++it;
	//}
}


int main()
{
	//Test_set();
	//Test_map();
	system("pause");
	return 0;
}