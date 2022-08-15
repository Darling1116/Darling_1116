#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//ȡ��С��k����
//����1��ֱ������sort�⺯������
vector<int> GetLeastNumbers_Solution_1(vector<int>& input, int k) {
	sort(input.begin(), input.end());
	input.resize(k);
	return input;
}


//����2�����ö�����---�������ȼ�����
vector<int> GetLeastNumbers_Solution_2(vector<int> input, int k) {
	vector<int> result;
	if (k > input.size() || k <= 0)  //�ж�kֵ�ĺϷ���
		return result;

	priority_queue<int> pq;  //Ĭ��Ϊ����������
	int i = 0;
	for (i = 0; i<k; i++){
		pq.push(input[i]);
	}

	for (; i<input.size(); i++){
		if (input[i] < pq.top()){
			pq.pop();
			pq.push(input[i]);
		}
	}

	while (!pq.empty()){
		result.push_back(pq.top());
		pq.pop();
	}
	return result;

}
void test2_1(){
	vector<int> v = { 4, 5, 1, 6, 2, 7, 3, 8 };
	vector<int> result =  GetLeastNumbers_Solution_2(v, 5);
	for (auto e : result){
		cout << e << " ";
	}
	cout << endl;

	//priority_queue<int> pq;
	//for (auto e : v){
	//	pq.push(e);
	//}
	//while(!pq.empty()){
	//	cout << pq.top() << " ";
	//	pq.pop();
	//}

}