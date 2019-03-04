#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;
void Print_vector(const vector <int>& v)
{
	vector <int>::const_iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}

int main()
{
	vector <int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);

		for (size_t i = 0; i < v1.size(); i++)
		{
			cout << v1[i] << " ";
		}
		cout << endl;
		cout << v1.size() << endl;
		cout << v1.capacity() << endl;
		//v1.clear();
		vector <int> tmp;
		v1.swap(tmp);
		cout << v1.size() << endl;
		cout << v1.capacity() << endl;
	

	//int a[] = { 1, 2, 3, 4, 5 };
	//vector <int> v2 (a, a+sizeof(a) / sizeof(int));
	//vector <int>::iterator it = v2.begin();
	//while (it != v2.end())
	//{
	//	if (*it % 2 == 0)
	//		it = v2.erase(it);
	//	else
	//		it++;
	//}
	//Print_vector(v2);

	//v2.insert(v2.begin(), 10);
	//v2.insert(v2.end(), 10);
	//Print_vector(v2);

	//vector <int>::iterator pos = find(v2.begin(), v2.end(), 3);
	//v2.insert(pos, 100);
	//Print_vector(v2);

	//v2.erase(pos);
	//Print_vector(v2);
	/*v2.insert(pos, 100);
	Print_vector(v2);*/






	


	//vector <int>::iterator it = v1.begin();
	//while (it != v1.end())
	//{
	//	*it = 10;
	//	cout << *it << " ";
	//	it++;
	//}
	//cout << endl;

	//vector <int>::iterator it = v1.begin();
	//while (it != v1.end())
	//{
	//	cout << *it << " ";
	//	it++;
	//}
	//cout << endl;

	//vector <int> :: reverse_iterator it = v1.rbegin();
	//while (it != v1.rend())
	//{
	//	cout << *it << " ";
	//	it++;
	//}
	//cout << endl;

	//for (auto e : v1)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;

	system("pause");
	return 0;

}