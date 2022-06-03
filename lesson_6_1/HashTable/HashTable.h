#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace GXR{
	template <class T>
	struct HashNode{
		HashNode<T>* _next;
		T _data;

		HashNode(const T& data)
			:_next(nullptr),
			_data(data){
		}
	};

	//前置声明：以便在HTIterator中使用HashTable
	template <class  K, class T, class KeyOfT, class HashFunc>
	class HashTable;

	template <class  K, class T, class KeyOfT, class HashFunc>
	struct HTIterator{
		typedef HashNode<T> node;
		typedef HashTable<K, T, KeyOfT, HashFunc> HT;
		typedef HTIterator<K, T, KeyOfT, HashFunc> self;

		node* _node;
		HT* _pht;

		HTIterator(node* node, HT* pht)
			:_node(node),
			_pht(pht){

		}

		T& operator*(){
			return _node->_data;
		}

		T* operator->(){
			return &_node->_data;
		}

		bool operator!=(const self& s){
			return _node != s._node;
		}

		bool operator==(const self& s){
			return _node == s._node;
		}

		self& operator++(){
			//如果当前桶里还有数据，就去找下一个数据
			if (_node->_next){
				_node = _node->_next;
				return *this;
			}
			//如果当前桶里没有数据了，计算散列地址，去找下一个有数据的桶
			else{
				KeyOfT kot;
				size_t index = kot(_node->_data) % _pht->_table.size();
				++index;
				while (index < _pht->_table.size()){
					if (_pht->_table[index]){
						_node = _pht->_table[index];
						return *this;
					}
					else{
						++index;
					}
				}
				_node = nullptr;
			}
			return *this;

		}

			


		};


		template <class  K, class T, class KeyOfT, class HashFunc>
		class HashTable{
		public:
			template <class  K, class T, class KeyOfT, class HashFunc>
			friend struct HTIterator;  
			//把迭代器定义为HT的友元，使其能访问它的私有成员(加一下模板参数)
			typedef HashNode<T> node;
			typedef HTIterator<K, T, KeyOfT, HashFunc> iterator;

			bool insert(const T& data){
				KeyOfT kot;
				//先判断是否表中已有该元素，若已存在，就不用插入
				node* ret = find(kot(data));
				if (ret != nullptr){
					return false;
				}
				HashFunc hf;
				//当负载因子等于1时，进行增容处理
				if (_n == _table.size()){
					//新建一个table表，里面存放结点的指针
					vector<node*> newtable;
					//newtable.resize(_table.size() == 0 ? 8 : _table.size() * 2,nullptr);
					newtable.resize(_table.size() == 0 ? 8 : GetNextPrime(_table.size()));
					//依次遍历哈希表，把各个桶中的元素重新计算映射位置
					for (size_t i = 0; i < _table.size(); i++){
						if (_table[i] != nullptr){
							node* cur = _table[i];
							while (cur){
								node* curnext = cur->_next;

								int index = hf(kot(cur->_data)) % newtable.size();
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
				size_t index = hf(kot(data)) % _table.size();
				//把结点头插进相应的桶中，更新_n
				node* newnode = new node(data);
				newnode->_next = _table[index];
				_table[index] = newnode;
				_n++;
				return true;
			}

			node* find(const K& key){
				if (_table.size() == 0)
					return nullptr;
				HashFunc hf;
				KeyOfT kot;
				size_t index = hf(key) % _table.size();
				node* cur = _table[index];  //去相应的桶里遍历

				while (cur != nullptr){
					if (kot(cur->_data) == key)
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
				KeyOfT kot;
				size_t index = hf(key) % _table.size();
				node* prev = nullptr;
				node* cur = _table[index];
				while (cur != nullptr){
					if (kot(cur->_data) == key){
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

			iterator begin(){
				for (size_t i = 0; i < _table.size(); i++){
					if (_table[i] != nullptr){
						return iterator(_table[i], this);  //本对象哈希表的地址
					}
				}
				return end();
			}

			iterator end(){
				return iterator(nullptr, this);
			}

		private:
			vector<HashNode<T>*> _table;
			size_t _n; //哈希表中的有效数据个数
		};


		const int PRIMECOUNT = 28;
		const size_t primeList[PRIMECOUNT] = {
			53ul, 97ul, 193ul, 389ul, 769ul,
			1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
			49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
			1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
			50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
			1610612741ul, 3221225473ul, 4294967291ul
		};

		size_t GetNextPrime(size_t prime) {
			size_t i = 0;
			for (; i < PRIMECOUNT; ++i)
			{
				if (primeList[i] > primeList[i])
					return primeList[i];
			}

			return primeList[i];
		}

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

	
}