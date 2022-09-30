#pragma once
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;


	//定义边结构体
	template <class W>
	struct Edge{
		int _dsti;
		W _w;
		Edge<W>* _next;

		Edge(int dsti, W w)  //初始化参数列表
			:_dsti(dsti)
			, _w(w)
			, _next(nullptr){
		}

	};


	template <class V, class W, bool Direction=false>
	struct graph_tables{
	public:
		typedef Edge<W> Edge;

		graph_tables(const V* array, size_t n){
			_vertex.reserve(n);
			for (size_t i = 0; i < n; i++){
				_vertex.push_back(array[i]);
				_indexMap[array[i]] = i;
			}

			_tables.resize(n, nullptr);
		}


		int getVertexIndex(const V& v){
			auto ret = _indexMap.find(v);
			if (ret != _indexMap.end()){
				return ret->second;
			}
			else{
				throw invalid_argument("顶点不存在...\n");
				return -1;
			}
		}


		void addEdge(const V& src, const V& dst, const W& w){
			int srci = getVertexIndex(src);
			int dsti = getVertexIndex(dst);

			Edge* edge = new Edge(dsti, w);  //构造一条边
			//把边头插到对应的链表中
			edge->_next = _tables[srci];
			_tables[srci] = edge;

			if (Direction == false){
				Edge* edge = new Edge(srci, w);
				edge->_next = _tables[dsti];
				_tables[dsti] = edge;
			}
		}


		void print(){
			for (size_t i = 0; i < _vertex.size(); i++){
				cout << "[" << _vertex[i] << "] -> " << i << endl;
			}

			for (size_t i = 0; i < _tables.size(); i++){
				Edge* cur = _tables[i];
				cout << "[" << _vertex[i] << "] -> ";
				while (cur != nullptr){
					cout << cur->_dsti << ": " << cur->_w << "-> ";
					cur = cur->_next;
				}
				cout << "nullptr" << endl;
			}
		}



	private:
		vector<V> _vertex;
		unordered_map<V, int> _indexMap;
		vector<Edge*> _tables;  //邻接表
	};



void test_2(){
	graph_tables<char, int, true> g("ABCD", 4);
	g.addEdge('A', 'B', 1);
	g.addEdge('A', 'C', 4);
	g.addEdge('B', 'C', 2);
	g.addEdge('B', 'D', 9);
	g.print();
}