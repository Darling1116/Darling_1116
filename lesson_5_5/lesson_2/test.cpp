#include "common.h"

//取出url中的协议名
string GetProtocol(const string& url){
	size_t pos = url.find("://");
	if (pos != string::npos){
		return url.substr(0, pos - 0);
	}
	else{
		return string();
	}
}

//取出url中的域名
string GetDomain(const string& url){
	size_t pos = url.find("://");
	if (pos != string::npos){
		size_t start = pos + 3;
		size_t end = url.find('/', start);
		return url.substr(start, end-start);
	}
	else{
		return string();
	}
}


int main(){
	string s1("my dream!");
	string s2(s1, 3, 5); //从s1的第3位开始，取5个字符构造s2
	cout << s2 << endl;

	s2.insert(0, 1, 'c'); //insert的第二个参数为插入字符的个数
	cout << s2 << endl;

	reverse(s2.begin(), s2.end());  //不是string类提供的接口
	cout << s2 << endl;
	
	////遍历方式1：下标 + s2.operator[](i)
	//for (int i = 0; i < s2.size(); i++){
	//	cout << s2[i] << " ";
	//}
	//cout << endl;

	////遍历方式2：迭代器
	//string::iterator it = s2.begin();
	//while (it != s2.end()){
	//	cout << *it << " ";
	//	++it;
	//}
	//cout << endl;

	////反向迭代器
	//string::reverse_iterator rit = s2.rbegin();
	//while (rit != s2.rend()){
	//	*rit += 1;
	//	cout << *rit << " ";
	//	++rit;
	//}
	//cout << endl;

	////const迭代器
	//string::const_iterator cit = s2.begin();
	//while (cit != s2.end()){
	//	//*cit += 1;
	//	cout << *cit << " ";
	//	++cit;
	//}
	//cout << endl;

	////遍历方式3：范围for
	//for (auto e : s2){  //依次取容器中的数据，赋值给e，会自动判断结束
	//	cout << e << " ";	//不能修改
	//}
	//cout << endl;

	//获取file的后缀
	string s_file("string.cpp");
	size_t pos = s_file.find('.');
	string str = s_file.substr(pos, s_file.size() - pos);
	cout << str << endl;
	string str_1 = s_file.substr(pos);
	cout << str_1 << endl;



	//取出url中的协议名和域名
	string url("http://www.cplusplus.com/reference/string/string/find/");
	cout << url << endl;
	cout << GetProtocol(url) << endl;
	cout << GetDomain(url) << endl;



	//cout << s2[3] << endl;
	//cout << s2.at(3) << endl;

	system("pause");
	return 0;
}