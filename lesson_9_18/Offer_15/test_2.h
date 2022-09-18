#pragma once
#include <iostream>
#include <vector>

using namespace std;

//��ΪS��������������(��������+�Ȳ�������͹�ʽ)
vector<vector<int>> FindContinuousSequence(int sum) {
	vector<vector<int>> res;
	if (sum == 0)
		return res;

	int begin = 1;
	int end = 2;
	while (begin < end){
		if ((begin + end)*(end - begin + 1) / 2 == sum){
			vector<int> v;
			for (int i = begin; i <= end; i++){
				v.push_back(i);
			}
			res.push_back(v);
			begin++;  //�������
		}
		else if ((begin + end)*(end - begin + 1) / 2 < sum)
			end++;
		else
			begin++;
	}
	return res;

}

void test2_1(){
	vector <vector<int>> res = FindContinuousSequence(9);
	for (int i = 0; i < res.size(); i++){
		for (auto& e : res[i]){
			cout << e << " ";
		}
		cout << endl;
	}
}