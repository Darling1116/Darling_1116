#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

bool isLetter(char c){
	if (c >= 'a'&&c <= 'z' || c >= 'A'&&c <= 'Z')
		return true;
	return false;
}

//1.仅仅翻转字符串
string reverseOnlyLetters(string s) {
	if (s.empty() || s.size() == 1)
		return s;

	int left = 0;
	int right = s.size() - 1;
	while (left < right){
		while (left<right && !isLetter(s[left])){
			left++;
		}
		while (left<right && !isLetter(s[right])){
			right--;
		}
		char tmp = s[left];
		s[left] = s[right];
		s[right] = tmp;
		left++;
		right--;
	}
	return s;
}


//2.字符串的最后一个单词的长度
void LastWordLen(){
	string str;
	getline(cin, str);
	int pos = str.rfind(" ");
	int n = str.size() - pos - 1;
	cout << n << endl;
}


//3.验证是否是文回串
bool isLetter_2(char c){
	if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0'&&c <= '9')
		return true;
	return false;
}

bool isUpLetter(char c){
	if (c >= 'A' && c <= 'Z')
		return true;
	return false;
}

bool isPalindrome(string s) {
	if (s.empty() || s == " ")
		return true;

	string res;
	for (int i = 0; i<s.size(); i++){
		if (isLetter_2(s[i])){
			if (isUpLetter(s[i]))
				res += (s[i] + 32);
			else
				res += s[i];
		}
	}

	int left = 0;
	int right = res.size() - 1;
	while (left < right){
		if (res[left] != res[right])
			return false;
		left++;
		right--;
	}
	return true;

}