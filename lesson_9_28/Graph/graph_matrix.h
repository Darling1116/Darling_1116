#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//ͼ���ڽӾ���洢
template <class V, class W, W MAX_W=INT_MAX, bool Direction=false>
//ģ���������Ϊ�����㡢Ȩ�ء��Ƿ�����
struct Graph{
public:
	Graph(const V* _array, size_t n){
		//��ʼ��_vertex����¼���������±��ӳ���ϵ
		_vertex.reserve(n);
		for (size_t i = 0; i < n; i++){
			_vertex.push_back(_array[i]);
			_indexMap[_array[i]] = i;
		}

		//��ʼ���ڽӾ���
		_matrix.resize(n);
	/*	for (auto& e : _matrix){
			e.resize(n, MAX_W);
		}*/
		for (size_t i = 0; i < n; i++){
			_matrix[i].resize(n);
			for (size_t j = 0; j < n; j++){
				_matrix[i][j] = MAX_W;
			}
		}
	}


	//�õ�ĳһ������±�
	size_t getVertexIndex(const V& v){
		auto ret = _indexMap.find(v);
		if (ret != _indexMap.end()){
			return ret->second;
		}
		else{
			//throw invalid_argument("�Ƿ�����");
			return -1;
		}
	}


	//��ӱ߼�Ȩ��
	void addEdge(const V& src, const V& dst, const W& w){
		int srcindex = getVertexIndex(src);
		int dstindex = getVertexIndex(dst);
		_matrix[srcindex][dstindex] = w;
		//����ͼҪ����ԳƵĵط�
		if (Direction == false){
			_matrix[dstindex][srcindex] = w;
		}
	}


	void print(){
		for (auto e : _indexMap){
			cout << e.first << "->" << e.second << endl;
		}

		cout << "  ";
		for (size_t i = 0; i < _vertex.size(); i++){
			cout << i << " ";
		}
		cout << endl;

		for (size_t i = 0; i < _matrix.size(); i++){
			cout << i << " ";
			for (size_t j = 0; j < _matrix[0].size(); j++){
				if (_matrix[i][j] == MAX_W){
					cout << "* ";
				}
				else{
					cout << _matrix[i][j] << " ";
				}
			}
			cout << endl;
		}
	}


private:
	vector<V> _vertex;
	unordered_map<V, int> _indexMap;  //�������±��ӳ���ϵ
	vector<vector<W>> _matrix;  //�ö����±��ʾ�ߵĹ�ϵ
};


void test_1(){
	Graph<char, int, true> g("0123", 4);
	g.addEdge('0', '1', 1);
	g.addEdge('0', '3', 4);
	g.addEdge('1', '3', 2);
	g.addEdge('1', '2', 9);
	g.addEdge('2', '3', 8);
	g.addEdge('2', '1', 5);
	g.addEdge('2', '0', 3);
	g.addEdge('3', '2', 6);
	g.print();
}