#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <unordered_set>


using namespace std;

//����һ���ַ���s��һ�鵥��dict���ж�s�Ƿ�����ÿո�ָ��һ����������
//ʹ�õ������������еĵ��ʶ���dict�еĵ��ʣ����п��԰���һ���������ʣ�
bool wordBreak(string s, unordered_set<string> &dict) {
	if (s.empty())
		return true;  //���ַ���Ҳ����Ҫ��

	//array��ʾǰi���ַ����ܷ񱻷ָ�
	vector<bool> array(s.length() + 1, false);  
	array[0] = true;

	for (int i = 1; i <= s.length(); i++){
		for (int j = 0; j < i; j++){
			//ǰj���ַ����Ա��ָj-i�����е��ַ�����dict���ҵ�
			if (array[j] && (dict.find(s.substr(j, i - j)) != dict.end())){
				array[i] = true;
				break;
			}
		}
	}

	return array[s.length()];

}


void test1_1(){
	string s = "nowcode";
	unordered_set<string> dict = {"now", "code"};
	cout << wordBreak(s, dict) << endl;
}