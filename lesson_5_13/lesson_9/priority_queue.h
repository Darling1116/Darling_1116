#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
//#include <queue>
#include <functional>
#include <vector>

using namespace std;

namespace GXR_2{
	//void test_priority_queue(){
	//	priority_queue<int> pq;  //�ײ���vector + ���㷨
	//	pq.push(3);
	//	pq.push(5);
	//	pq.push(1);
	//	pq.push(6);
	//	pq.push(9);

	//	while (!pq.empty()){
	//		cout << pq.top() << " ";  //Ĭ���Ǵ��
	//		pq.pop();
	//	}
	//	cout << endl;


	//	//�ĳ�С�ѣ�ʹ��º���ʹ��greater
	//	priority_queue<int, vector<int>, greater<int>> pq1;
	//	pq1.push(3);
	//	pq1.push(5);
	//	pq1.push(1);
	//	pq1.push(6);
	//	pq1.push(9);

	//	while (!pq1.empty()){
	//		cout << pq1.top() << " ";  
	//		pq1.pop();
	//	}
	//	cout << endl;
	//}


	//�º���---�������������Ķ����������һ��ȥʹ��
	template <class T>
	struct less{
		bool operator()(const T& l, const T& r){
			return l < r;
		}
	};

	template <class T>
	struct greater{
		bool operator()(const T& l, const T& r){
			return l > r;
		}
	};

	
	//С����>
	template <class T, class Containor=vector<T>, class Compare=greater<T>>
	class priority_queue
	{
	public:
		void adjust_up(size_t child){
			size_t parent = (child - 1) / 2;
			while (child > 0){
				//if (_con[child] < _con[parent]){
				if (com(_con[parent], _con[child])){
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;;
				}
				else{
					break;
				}
			}
		}


		void push(const T& x){
			_con.push_back(x);
			adjust_up(_con.size()-1);
		}


		void adjust_down(size_t parent){
			size_t child = parent * 2 + 1;
			while (child < _con.size()){
				//if (child + 1 < _con.size() && _con[child] > _con[child + 1]){
				if (child + 1 < _con.size() && com(_con[child], _con[child + 1])){
					child++;
				}
				//if (_con[child] < _con[parent]){
				if (com(_con[parent], _con[child])){
					swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else{
					break;
				}
			}
		}
		

		void pop(){
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			adjust_down(0);
		}

		//ȡ�Ѷ�Ԫ�أ�ÿ�ζ�Ϊ��Сֵ
		T top(){
			return _con[0];
		}

		size_t size(){
			return _con.size();
		}

		bool empty(){
			return _con.empty();
		}
		
	private:
		Containor _con;
		Compare com;
	};

	void test_4(){
		priority_queue<int> pq;
		pq.push(2);
		pq.push(1);
		pq.push(8);
		pq.push(5);
		pq.push(6);
		pq.push(3);
		
		//���ܱ����ײ������ȥȡpqԪ��
		//while (!pq.empty()){
		//	cout << pq.top() << " ";
		//	pq.pop();
		//}
		//cout << endl;

		//ѡ��ǰkС����
		int k = 5;
		while (!pq.empty() && k--){
			cout << pq.top() << " ";
			pq.pop();
		}
		cout << endl;
	}

}