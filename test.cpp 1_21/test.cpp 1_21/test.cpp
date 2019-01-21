#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

void stringTest1()
{
	string s1();
	string s2("hello");
	cout << s2 << endl;
	string s3(6, 'a');
	cout << s3 << endl;
	string s4(s2);
	cout << s4 << endl;
	string s5(s2, 2);
	cout << s5 << endl;

	s2.resize(10, 'b');
	cout << s2 << endl;

}

void stringTest2()
{
	string s("hello world");
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;
	cout << s.empty() << endl;

	//s.clear();
	//cout << s.length() << endl;
	//cout << s.capacity() << endl;
	
	//s.resize(15);
	//cout << s << endl;

	s.resize(18, 'b');
	cout << s << endl;
}

void stringTest3()
{
	//string s ("hello world");
	string s("A man, a plan, a canal : Panama");
	
	size_t begin = 0;
	size_t end = s.size() - 1;
	while (begin < end)
	{
		swap(s[begin], s[end]);
		begin++;
		end--;
	}
	cout << s << endl;
	
	//for (size_t i = 0; i < s.size(); i++)
	//{
	//	cout << s[i] << endl;
	//}

	//string::iterator it = s.begin();
	//while (it != s.end())
	//{
	//	cout << *it;
	//	++it;
	//}
	//cout << endl;

	//for (auto &ch : s)
	//{
	//	ch = 'b';
	//	cout << ch;
	//}
	//cout << s << endl;
	//for (size_t i = s.size(); i > 0; i--)
	//{
	//	cout << s[i - 1];
	//}
	//cout << endl;

	//string::reverse_iterator it = s.rbegin();
	//while (it != s.rend())
	//{
	//	cout << *it;
	//	++it;
	//}
	//cout << endl;

	//cout << s << endl;

	//string ret;
	//string::reverse_iterator it = s.rbegin();
	//while (it != s.rend())
	//{
	//	ret += *it;
	//	++it;
	//}
	//cout << ret << endl;
}

void stringTest4()
{
	string s("hello world");
	string s1;
	//s1.assign(s);
	//cout << s1 << endl;

	//s.insert(0,"bit");
	//cout << s << endl;

	//s.erase(2, 3);
	//cout << s << endl;

	//s.push_back('s');
	//cout << s << endl;
	
	//s.replace(4, 2, "cd");
	//cout << s << endl;

	s.swap(s1);
	cout << s << endl;
	cout << s1 << endl;

}

void stringTest5()
{
	//string s("main.cpp");
	//size_t pos = s.find('.');
	//string s1(s.substr(pos));
	//cout << s1 << endl;
	//string s2(s.substr(pos, 2));
	//cout << s2 << endl;
	string url("http://www.cplusplus.com/reference/string/string/find/");
	cout << url << endl;
	size_t pos = url.find("://");
	string s1(url.substr(pos, 3));
	cout << s1 << endl;

	size_t pos1 = url.find('/', pos + 3);
	string s2(url.substr(pos + 3, pos1-pos-3));
	cout << s2 << endl;

	url.erase(pos, 3);
	cout << url << endl;

}
void stringTest6()
{
	string s;
	while (getline(cin, s))
	{

		size_t pos = s.rfind(' ');
		cout << s.size() - pos - 1 << endl;
	}
	
	
}

int main()
{
	stringTest6();


	system("pause");
	return 0;
}
