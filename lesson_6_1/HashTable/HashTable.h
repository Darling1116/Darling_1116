#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace GXR{
	template <class  K, class V>
	struct HashNode{
		HashNode<K, V>* _next;
		pair<K, V> _kv;

		HashNode(const pair<K, V>& kv)
			:_next(nullptr),
			_kv(kv){
		}
	};

	template <class  K, class V, class HashFunc>
	class HashTable{
	public:
		typedef HashNode<K, V> node;

		bool insert(const pair<K, V>& kv){
			//先判断是否表中已有该元素，若已存在，就不用插入
			node* ret = find(kv.first);
			if (ret != nullptr){
				return false;
			}
			HashFunc hf;
			//当负载因子等于1时，进行增容处理
			if (_n == _table.size()){
				//新建一个table表，里面存放结点的指针
				vector<node*> newtable;
				newtable.resize(_table.size() == 0 ? 8 : _table.size() * 2,nullptr);
				//依次遍历哈希表，把各个桶中的元素重新计算映射位置
				for (int i = 0; i < _table.size(); i++){
					if (_table[i] != nullptr){
						node* cur = _table[i];
						while (cur){
							node* curnext = cur->_next;

							int index = hf(cur->_kv.first) % newtable.size();
							cur->_next = newtable[index];
							newtable[index] = cur;

							cur = curnext;
						}
						_table[i] = nullptr;  //旧表中的元素置空
					}
				}
				swap(_table, newtable);
			}

			//计算散列地址
			size_t index = hf(kv.first) % _table.size();
			//把结点头插进相应的桶中，更新_n
			node* newnode = new node(kv);
			newnode->_next = _table[index];
			_table[index] = newnode;
			_n++;
			return true;
		}

		node* find(const K& key){
			if (_table.size() == 0)
				return nullptr;
			HashFunc hf;
			size_t index = hf(key) % _table.size();
			node* cur = _table[index];  //去相应的桶里遍历

			while (cur != nullptr){
				if (cur->_kv.first == key)
					return cur;
				cur = cur->_next;
			}
			return nullptr;
		}

		bool erase(const K& key){
			//node* ret = find(key);
			//if (ret == nullptr)
			//	return false;

			//去桶里找待删除元素
			HashFunc hf;
			size_t index = hf(key) % _table.size();
			node* prev = nullptr;
			node* cur = _table[index];
			while (cur != nullptr){
				if (cur->_kv.first == key){
					if (cur == _table[index]){
						_table[index] = cur->_next;
					}
					else{
						prev->_next = cur->_next;
					}
					delete cur;
					--_n;
					return true;
				}
				else{
					prev = cur;
					cur = cur->_next;
				}
			}
			return false;

		}

	private:
		vector<HashNode<K, V>*> _table;
		size_t _n; //哈希表中的有效数据个数
	};

	struct intHashFunc{
		int operator()(int i){
			return i;
		}
	};


	struct stringHashFunc{
		size_t operator()(const string& s){
			size_t count = 0;
			for (auto &e : s){
				count += e;
			}
			return count;
		}
	};


	void test_1(){
		HashTable<int, int, intHashFunc> ht;
		ht.insert(make_pair(5, 0));
		ht.insert(make_pair(1, 0));
		ht.insert(make_pair(20, 0));
		ht.insert(make_pair(3, 0));
		ht.insert(make_pair(24, 0));
		ht.insert(make_pair(2, 0));
		
		HashNode<int, int>* ret = ht.find(20);
		if (ret != nullptr)
			cout << "找到啦" << endl;
		else
			cout << "没找到" << endl;

		if (ht.erase(3)){
			cout << "元素已删除" << endl;
		}
		else{
			cout << "删除失败" << endl;
		}
		
	}

	void test_2(){
		HashTable<string, int, stringHashFunc> ht;
		ht.insert(make_pair("插入", 1));
		ht.insert(make_pair("删除", 2));
		ht.insert(make_pair("新增", 3));
		ht.insert(make_pair("扩大", 4));
		ht.insert(make_pair("更新", 5));
	}
}