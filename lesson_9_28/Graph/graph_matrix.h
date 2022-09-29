#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

//图的邻接矩阵存储
template <class V, class W, W MAX_W=INT_MAX, bool Direction=false>
//模板参数依次为：顶点、权重、是否有向
struct Graph{
public:
	Graph(const V* _array, size_t n){
		//初始化_vertex，记录各顶点与下标的映射关系
		_vertex.reserve(n);
		for (size_t i = 0; i < n; i++){
			_vertex.push_back(_array[i]);
			_indexMap[_array[i]] = i;
		}

		//初始化邻接矩阵
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


	//得到某一顶点的下标
	size_t getVertexIndex(const V& v){
		auto ret = _indexMap.find(v);
		if (ret != _indexMap.end()){
			return ret->second;
		}
		else{
			//throw invalid_argument("非法顶点");
			return -1;
		}
	}


	//添加边及权重
	void addEdge(const V& src, const V& dst, const W& w){
		int srcindex = getVertexIndex(src);
		int dstindex = getVertexIndex(dst);
		_matrix[srcindex][dstindex] = w;
		//无向图要处理对称的地方
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
	unordered_map<V, int> _indexMap;  //顶点与下标的映射关系
	vector<vector<W>> _matrix;  //用顶点下标表示边的关系
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