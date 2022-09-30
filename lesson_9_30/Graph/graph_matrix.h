#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>

#include <queue>
#include <functional>
#include "union_find_set.h"

using namespace std;


//图的邻接矩阵存储
template <class V, class W, W MAX_W=INT_MAX, bool Direction = false>
//模板参数依次为：顶点、权重、是否有向
struct Graph_matrix{
public:
	//构建self对象，表示子图
	typedef Graph_matrix<V, W, MAX_W, Direction> Self;

	Graph_matrix() = default;  //增加默认构造函数

	Graph_matrix(const V* _array, size_t n){
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

	
	//以顶点下标的形式添加边及权重
	void _addEdge(const int srci, const int dsti, const W& w){
		_matrix[srci][dsti] = w;
		//无向图要处理对称的地方
		if (Direction == false){
			_matrix[dsti][srci] = w;
		}
	}

	//以顶点的形式添加边及权重
	void addEdge(const V& src, const V& dst, const W& w){
		int srcindex = getVertexIndex(src);
		int dstindex = getVertexIndex(dst);
		_addEdge(srcindex, dstindex, w);
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


	//从某一顶点开始广度优先搜索
	void BFS(const V& src){
		size_t n = _vertex.size();
		queue<V> qu;
		vector<bool> visited(n, false);  //标记访问过的顶点
		
		int srci = getVertexIndex(src);
		qu.push(srci);
		visited[srci] = true;

		int count = 0;  //记录BSF搜索过的顶点个数据
		while (!qu.empty()){
			int cur = qu.front();
			qu.pop();
			cout << cur << "-> ";
			count++;
			for (size_t i = 0; i < n; i++){  //让src的邻接顶点依次入队
				if (_matrix[cur][i] != MAX_W && visited[i] == false){
					qu.push(i);
					visited[i] = true;
				}
			}
		}
		cout << "ending" << endl;
		cout << "count: " << count << endl;
		
	}


	//从某一顶点开始深度优先搜索
	void _DFS(int srci, vector<bool>& visited){
		size_t n = _vertex.size();

		cout << srci << "-> ";
		visited[srci] = true;

		//找与src相邻且没有被访问过的顶点，递归
		for (size_t i = 0; i < n; i++){
			if (_matrix[srci][i] != MAX_W && visited[i] == false){
				_DFS(i, visited);
			}
		}
	}

	void DFS(const V& src){
		int srci = getVertexIndex(src);
		vector<bool> visited(_vertex.size(), false);
		_DFS(srci, visited);
		cout << "ending" << endl;
	}


	//用于Kruskal算法中的选边
	struct Edge{
		int _srci;
		int _dsti;
		W _w;

		Edge(int srci, int dsti, W& w)
			:_srci(srci)
			, _dsti(dsti)
			, _w(w){

		}

		//此处重载的operator>为类的成员函数
		bool operator>(const Edge& e)const {
			return _w > e._w;
		}
	};


	//实现克鲁斯卡尔算法
	W Kruskal(Self& minTree){
		//初始化最小生成树
		size_t n = _vertex.size();

		minTree._vertex = _vertex;
		minTree._indexMap = _indexMap;
		minTree._matrix.resize(n);
		for (size_t i = 0; i < n; i++){
			minTree._matrix[i].resize(n, MAX_W);
		}

		//使用优先级队列进行选边，改为小堆
		priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
		for (size_t i = 0; i < n; i++){
			for (size_t j = 0; j < n; j++){
				//只需遍历上三角矩阵即可
				if (i>j && _matrix[i][j] != MAX_W){  //先让边都进队列
					pq.push(Edge(i, j, _matrix[i][j]));
				}
			}
		}
		//选择n-1条不在同一个集合中的边
		int count = 0;
		W total = W();
		UnionFindSet<int> ufs(n);  //并查集中存放的是顶点的下标

		while (!pq.empty()){
			Edge min = pq.top();
			pq.pop();
			
			if (!ufs.isOneSet(min._srci, min._dsti)){
				minTree._addEdge(min._srci, min._dsti, min._w);
				ufs.Union(min._srci, min._dsti);
				count++;
				total += min._w;
			}
		}
		if (count == n - 1){
			return total;
		}
		else{
			return -1;
		}
		
		
	}


private:
	vector<V> _vertex;
	unordered_map<V, int> _indexMap;  //顶点与下标的映射关系
	vector<vector<W>> _matrix;  //用顶点下标表示边的关系
};


void test1_1(){
	Graph_matrix<char, int, INT_MAX, true> g("0123", 4);
	g.addEdge('0', '1', 1);
	g.addEdge('0', '3', 4);
	g.addEdge('1', '3', 2);
	g.addEdge('1', '2', 9);
	g.addEdge('2', '3', 8);
	g.addEdge('2', '1', 5);
	g.addEdge('2', '0', 3);
	g.addEdge('3', '2', 6);
	g.print();
	g.BFS('2');
	g.DFS('2');
}


void test1_2(){
	const char* str = "abcdefghi";
	Graph_matrix<char, int, INT_MAX> g(str, strlen(str));
	g.addEdge('a', 'b', 4);
	g.addEdge('a', 'h', 8);
	//g.addEdge('a', 'h', 9);
	g.addEdge('b', 'c', 8);
	g.addEdge('b', 'h', 11);
	g.addEdge('c', 'i', 2);
	g.addEdge('c', 'f', 4);
	g.addEdge('c', 'd', 7);
	g.addEdge('d', 'f', 14);
	g.addEdge('d', 'e', 9);
	g.addEdge('e', 'f', 10);
	g.addEdge('f', 'g', 2);
	g.addEdge('g', 'h', 1);
	g.addEdge('g', 'i', 6);
	g.addEdge('h', 'i', 7);
	g.print();

	//Graph_matrix<char, int> kminTree;
	//cout << g.Kruskal(kminTree) << endl;
	//kminTree.print();
}