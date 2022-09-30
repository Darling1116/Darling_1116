#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>

#include <queue>
#include <functional>
#include "union_find_set.h"

using namespace std;


//ͼ���ڽӾ���洢
template <class V, class W, W MAX_W=INT_MAX, bool Direction = false>
//ģ���������Ϊ�����㡢Ȩ�ء��Ƿ�����
struct Graph_matrix{
public:
	//����self���󣬱�ʾ��ͼ
	typedef Graph_matrix<V, W, MAX_W, Direction> Self;

	Graph_matrix() = default;  //����Ĭ�Ϲ��캯��

	Graph_matrix(const V* _array, size_t n){
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

	
	//�Զ����±����ʽ��ӱ߼�Ȩ��
	void _addEdge(const int srci, const int dsti, const W& w){
		_matrix[srci][dsti] = w;
		//����ͼҪ����ԳƵĵط�
		if (Direction == false){
			_matrix[dsti][srci] = w;
		}
	}

	//�Զ������ʽ��ӱ߼�Ȩ��
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


	//��ĳһ���㿪ʼ�����������
	void BFS(const V& src){
		size_t n = _vertex.size();
		queue<V> qu;
		vector<bool> visited(n, false);  //��Ƿ��ʹ��Ķ���
		
		int srci = getVertexIndex(src);
		qu.push(srci);
		visited[srci] = true;

		int count = 0;  //��¼BSF�������Ķ��������
		while (!qu.empty()){
			int cur = qu.front();
			qu.pop();
			cout << cur << "-> ";
			count++;
			for (size_t i = 0; i < n; i++){  //��src���ڽӶ����������
				if (_matrix[cur][i] != MAX_W && visited[i] == false){
					qu.push(i);
					visited[i] = true;
				}
			}
		}
		cout << "ending" << endl;
		cout << "count: " << count << endl;
		
	}


	//��ĳһ���㿪ʼ�����������
	void _DFS(int srci, vector<bool>& visited){
		size_t n = _vertex.size();

		cout << srci << "-> ";
		visited[srci] = true;

		//����src������û�б����ʹ��Ķ��㣬�ݹ�
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


	//����Kruskal�㷨�е�ѡ��
	struct Edge{
		int _srci;
		int _dsti;
		W _w;

		Edge(int srci, int dsti, W& w)
			:_srci(srci)
			, _dsti(dsti)
			, _w(w){

		}

		//�˴����ص�operator>Ϊ��ĳ�Ա����
		bool operator>(const Edge& e)const {
			return _w > e._w;
		}
	};


	//ʵ�ֿ�³˹�����㷨
	W Kruskal(Self& minTree){
		//��ʼ����С������
		size_t n = _vertex.size();

		minTree._vertex = _vertex;
		minTree._indexMap = _indexMap;
		minTree._matrix.resize(n);
		for (size_t i = 0; i < n; i++){
			minTree._matrix[i].resize(n, MAX_W);
		}

		//ʹ�����ȼ����н���ѡ�ߣ���ΪС��
		priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
		for (size_t i = 0; i < n; i++){
			for (size_t j = 0; j < n; j++){
				//ֻ����������Ǿ��󼴿�
				if (i>j && _matrix[i][j] != MAX_W){  //���ñ߶�������
					pq.push(Edge(i, j, _matrix[i][j]));
				}
			}
		}
		//ѡ��n-1������ͬһ�������еı�
		int count = 0;
		W total = W();
		UnionFindSet<int> ufs(n);  //���鼯�д�ŵ��Ƕ�����±�

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
	unordered_map<V, int> _indexMap;  //�������±��ӳ���ϵ
	vector<vector<W>> _matrix;  //�ö����±��ʾ�ߵĹ�ϵ
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