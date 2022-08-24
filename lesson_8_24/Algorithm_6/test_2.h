#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//����������⣺����ִ�л���ʱ�䳤�Ļ
int finish_time(vector<int>& v, int m){
	sort(v.begin(), v.end());  //Ĭ������

	int n = v.size();  //��n�������Ҫ��m��������ִ��

	//��¼m̨�������ԵĹ���ʱ��
	vector<int> machines(m, 0);

	if (n <= m){
		return v[n - 1];  //���ػ���ʱ����Ļ
	}
	else{
		for (int i = n - 1; i >= 0; i--){  //n���
			int finish = 0;  //0�Ż���
			int machinetime = machines[finish];  //��ǰ�����Ľ���ʱ��
			for (int j = 1; j < m; j++){
				if (machines[j] < machinetime){
					finish = j;
					machinetime = machines[finish];
				}
			}
			machines[finish] += v[i];  //�������������Ļ���ִ�е�ǰ����
		}
	}

	//�ҹ���ʱ����Ļ���
	int finishtime = machines[0];
	for (int i = 1; i < m; i++){
		if (machines[i] > finishtime)
			finishtime = machines[i];
	}
	return finishtime;
}


void test2_1(){
	//6������3̨���������������Ҫ������ʱ��
	vector<int> v = { 10, 5, 3, 7, 2, 1 };  

	int ret = finish_time(v, 3);
	cout << ret << endl;
	

}