#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool com(vector<int>& v1, vector<int>& v2){
	return v1[1] < v2[1];  //������������ʱ������
}

//�ѡ������ѡ�����ʱ�����Ļ
int activity_nums(vector<vector<int>> vv){
	sort(vv.begin(), vv.end(), com);

	int i = 0;  //��ִ�е�һ���---����ʱ������Ļ
	int count = 1;

	for (int j = 1; j < vv.size(); j++){
		if (vv[j][0] >= vv[i][1]){  //��֤��һ����Ŀ�ʼʱ����ڵ��ڵ�ǰ��Ľ���ʱ��
			count++;
			i = j;  //������һ���
		}
	}

	return count;

}

void test3_1(){
	//��¼������Ŀ�ʼ�ͽ���ʱ��
	vector<vector<int>> vv = { { 2, 5 }, { 3, 4 }, { 1, 6 }, { 5, 8 }, { 5, 7 }, { 3, 9 }, { 7, 10 } };
	int ret = activity_nums(vv);
	cout << ret << endl;
}