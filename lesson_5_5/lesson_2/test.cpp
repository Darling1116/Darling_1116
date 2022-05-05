#include "common.h"

//ȡ��url�е�Э����
string GetProtocol(const string& url){
	size_t pos = url.find("://");
	if (pos != string::npos){
		return url.substr(0, pos - 0);
	}
	else{
		return string();
	}
}

//ȡ��url�е�����
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
	string s2(s1, 3, 5); //��s1�ĵ�3λ��ʼ��ȡ5���ַ�����s2
	cout << s2 << endl;

	s2.insert(0, 1, 'c'); //insert�ĵڶ�������Ϊ�����ַ��ĸ���
	cout << s2 << endl;

	reverse(s2.begin(), s2.end());  //����string���ṩ�Ľӿ�
	cout << s2 << endl;
	
	////������ʽ1���±� + s2.operator[](i)
	//for (int i = 0; i < s2.size(); i++){
	//	cout << s2[i] << " ";
	//}
	//cout << endl;

	////������ʽ2��������
	//string::iterator it = s2.begin();
	//while (it != s2.end()){
	//	cout << *it << " ";
	//	++it;
	//}
	//cout << endl;

	////���������
	//string::reverse_iterator rit = s2.rbegin();
	//while (rit != s2.rend()){
	//	*rit += 1;
	//	cout << *rit << " ";
	//	++rit;
	//}
	//cout << endl;

	////const������
	//string::const_iterator cit = s2.begin();
	//while (cit != s2.end()){
	//	//*cit += 1;
	//	cout << *cit << " ";
	//	++cit;
	//}
	//cout << endl;

	////������ʽ3����Χfor
	//for (auto e : s2){  //����ȡ�����е����ݣ���ֵ��e�����Զ��жϽ���
	//	cout << e << " ";	//�����޸�
	//}
	//cout << endl;

	//��ȡfile�ĺ�׺
	string s_file("string.cpp");
	size_t pos = s_file.find('.');
	string str = s_file.substr(pos, s_file.size() - pos);
	cout << str << endl;
	string str_1 = s_file.substr(pos);
	cout << str_1 << endl;



	//ȡ��url�е�Э����������
	string url("http://www.cplusplus.com/reference/string/string/find/");
	cout << url << endl;
	cout << GetProtocol(url) << endl;
	cout << GetDomain(url) << endl;



	//cout << s2[3] << endl;
	//cout << s2.at(3) << endl;

	system("pause");
	return 0;
}