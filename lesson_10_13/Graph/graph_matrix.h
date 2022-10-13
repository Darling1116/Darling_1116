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
			//否则的话构成了回路
		}
		if (count == n - 1){
			return total;
		}
		else{  
			return -1;
		}	
	}

	//实现普里姆算法
	W Prime(Self& minTree, const V& src){
		//初始化最小生成树
		size_t n = _vertex.size();

		minTree._vertex = _vertex;
		minTree._indexMap = _indexMap;
		minTree._matrix.resize(n);
		for (size_t i = 0; i < n; i++){
			minTree._matrix[i].resize(n, MAX_W);
		}

		//每次从B集合中挑选合适的顶点到A集合中
		vector<bool> A(n, false);
		vector<bool> B(n, true);
		int srci = getVertexIndex(src);
		A[srci] = true;
		B[srci] = false;

		priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

		//把与src相连的边都加入到队列中
		for (size_t i = 0; i < n; i++){
			if (_matrix[srci][i] != MAX_W){
				pq.push(Edge(srci, i, _matrix[srci][i]));
			}
		}

		int count = 0;  //记录最小生成树中边的数量
		W total = W();
		while (!pq.empty()){
			Edge min = pq.top();
			pq.pop();

			if (A[min._dsti]){
				cout << "产生回路：" << _vertex[min._srci] << "->" << _vertex[min._dsti] << ": " << _matrix[min._srci][min._dsti] << endl;
			}
			else{
				minTree._addEdge(min._srci, min._dsti, min._w);
				count++;
				total += min._w;
				A[min._dsti] = true;
				B[min._dsti] = false;

				if (count == n - 1){
					break;
				}
				for (size_t i = 0; i < n; i++){
					if (_matrix[min._dsti][i] != MAX_W && B[i] == true){
						pq.push(Edge(min._dsti, i, _matrix[min._dsti][i]));
					}
				}
			}
		}
		if (count == n - 1){
			return total;
		}
		else
			return -1;
	}


	//单源最短路径---迪杰斯特拉算法:选起始边
	//要求图中所有边的权重非负
	void Dijkstra(const V& src, vector<W>& dist, vector<int>& parentPath){
		size_t n = _vertex.size();
		dist.resize(n, MAX_W);
		parentPath.resize(n, -1);

		int srci = getVertexIndex(src);
		dist[srci] = 0;
		parentPath[srci] = srci;  //起点并不一定是第一个顶点

		vector<bool> set(n, false);  //存放已经确定最短路径的顶点
		set[srci] == true;

		for (size_t i = 0; i< n; i++){
			if (i != srci){ //计算每一个顶点的最短路径
				W min = MAX_W;
				size_t u = srci;

				//找不在S中且路径长度最短的顶点u
				for (size_t j = 0; j < n; j++){
					if (set[j] == false && dist[j] < min){
						min = dist[j];
						u = j;
					}
				}
				set[u] = true;  //找到了该顶点

				//松弛更新u连接顶点v
				for (size_t v = 0; v < n; v++){
					if (_matrix[u][v] != MAX_W && dist[u] + _matrix[u][v] < dist[v]){
						dist[v] = dist[u] + _matrix[u][v];
						parentPath[v] = u;
					}
				}

			}
		}
	}

	//打印单源最短路径
	void PrintShotPath(const V& src, vector<W>& dist, vector<int>& parentPath){
		size_t n = _vertex.size();
		int srci = getVertexIndex(src);
		for (size_t i = 0; i < n; i++){
			if (i == srci){
				continue;
			}

			vector<int> path;  //存放当前结点的最短路径
			int parenti = i;
			while (parenti != srci){
				path.push_back(parenti);
				parenti = parentPath[parenti];
			}
			//把源结点也要记录下来
			path.push_back(srci);
			reverse(path.begin(), path.end());

			for (auto pos : path){
				cout << _vertex[pos] << "->";
			}
			cout << ":" << dist[i] << endl;  //输出当前结点的最短路径
		}

	}


	//单源最短路径---贝尔曼福特算法:选终止边
	//可以解决图中边的权值为负的情况
	void Bellman_Ford(const V& src, vector<W>& dist, vector<int>& parentPath){
		size_t n = _vertex.size();
		int srci = getVertexIndex(src);

		dist.resize(n, MAX_W);
		parentPath.resize(n, -1);

		dist[srci] = W(); //初始化起点的最短路径为缺省值

		//暴力更新
		for (size_t k = 0; k < n; k++){
			bool flag = false;
			//依次处理图中的每一条边
			for (size_t i = 0; i < n; i++){
				for (size_t j = 0; j < n; j++){
					if (_matrix[i][j] != MAX_W && dist[i] + _matrix[i][j] < dist[j]){
						dist[j] = dist[i] + _matrix[i][j];
						parentPath[j] = i;
						flag = true;
					}
				}
			}
			if (flag == false){
				break;
			}
		}
	}


	//多源最短路径---弗洛伊德算法
	//解决图中任意两点之间的最短路径问题
	void FloydWarShall(vector<vector<W>>& vvdist, vector<vector<int>>& vvparentPath){
		size_t n = _vertex.size();

		//初始化两个矩阵
		vvdist.resize(n);
		vvparentPath.resize(n);
		for (size_t i = 0; i < n; i++){
			vvdist[i].resize(n, MAX_W);
			vvparentPath[i].resize(n, -1);
		}

		//更新直接相连的两条边，与matrix数组有关
		for (size_t i = 0; i < n; i++){
			for (size_t j = 0; j < n; j++){
				if (i == j){
					vvdist[i][j] = 0;
				}
				if (_matrix[i][j] != MAX_W){
					vvdist[i][j] = _matrix[i][j];
					vvparentPath[i][j] = i;
				}
			}
		}

		//更新最短路径（动规的思想）
		for (size_t k = 0; k < n; k++){
			for (size_t i = 0; i < n; i++){
				for (size_t j = 0; j < n; j++){
					//若i->j路径上，经过k时路径更小，则更新
					if (vvdist[i][k] != MAX_W && vvdist[k][j] != MAX_W 
						&& vvdist[i][k] + vvdist[k][j] < vvdist[i][j]){
						vvdist[i][j] = vvdist[i][k] + vvdist[k][j];
						//若k->j相连，上一个结点为k，vvparentPath[k][j]==k；
						//若不相连，k->..->x->j，上一个结点为x，vparentPath[k][j]==x
						vvparentPath[i][j] = vvparentPath[k][j];
					}
				}
			}
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


void test_Kruskal(){
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

	Graph_matrix<char, int> kminTree;
	cout << g.Kruskal(kminTree) << endl;
	kminTree.print();
}


void test_Prime(){
	const char* str = "abcdefghi";
	Graph_matrix<char, int, INT_MAX> g(str, strlen(str));
	g.addEdge('a', 'b', 4);
	g.addEdge('a', 'h', 8);
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
	//g.print();

	Graph_matrix<char, int> kminTree;
	cout << g.Kruskal(kminTree) << endl;
	kminTree.print();

	Graph_matrix<char, int> pminTree;
	cout << g.Prime(pminTree, 'a') << endl;
	pminTree.print();
}


void test_Dijkstra(){
	const char* str = "syztx";
	Graph_matrix<char, int, INT_MAX, true> g(str, strlen(str));
	g.addEdge('s', 't', 10);
	g.addEdge('s', 'y', 5);
	g.addEdge('y', 't', 3);
	g.addEdge('y', 'x', 9);
	g.addEdge('y', 'z', 2);
	g.addEdge('z', 's', 7);
	g.addEdge('z', 'x', 6);
	g.addEdge('t', 'y', 2);
	g.addEdge('t', 'x', 1);
	g.addEdge('x', 'z', 4);
	vector<int> dist;
	vector<int> parentPath; 
	g.Dijkstra('s', dist, parentPath);
	g.PrintShotPath('s', dist, parentPath);
}


void test_Bellman_Ford(){
	const char* str = "syztx";
	Graph_matrix<char, int, INT_MAX, true> g(str, strlen(str));
	g.addEdge('s', 't', 6);
	g.addEdge('s', 'y', 7);
	g.addEdge('y', 'z', 9);
	g.addEdge('y', 'x', -3);
	g.addEdge('z', 's', 2);
	g.addEdge('z', 'x', 7);
	g.addEdge('t', 'x', 5);
	g.addEdge('t', 'y', 8);
	g.addEdge('t', 'z', -4);
	g.addEdge('x', 't', -2);
	vector<int> dist;
	vector<int> parentPath;
	g.Bellman_Ford('s', dist, parentPath);
	g.PrintShotPath('s', dist, parentPath);
}


void test_FloydWarShall(){
	const char* str = "12345";
	Graph_matrix<char, int, INT_MAX, true> g(str, strlen(str));
	g.addEdge('1', '2', 3);
	g.addEdge('1', '3', 8);
	g.addEdge('1', '5', -4);
	g.addEdge('2', '4', 1);
	g.addEdge('2', '5', 7);
	g.addEdge('3', '2', 4);
	g.addEdge('4', '1', 2);
	g.addEdge('4', '3', -5);
	g.addEdge('5', '4', 6);
	vector<vector<int>> vvDist;
	vector<vector<int>> vvParentPath;
	g.FloydWarShall(vvDist, vvParentPath);
	//打印任意两点之间的最短路径
	for (size_t i = 0; i < strlen(str); ++i)
	{
		g.PrintShotPath(str[i], vvDist[i], vvParentPath[i]);
		cout << endl;
	}
}