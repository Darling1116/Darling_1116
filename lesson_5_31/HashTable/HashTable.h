#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace GXR{
	//标识当前存储位置的状态情况
	enum Status{
		EMPTY,
		EXITS,
		DELETE
	};

	template <class K, class V>
	struct HashData{
		pair<K, V> _kv;
		Status _status = EMPTY;
	};

	template <class K, class V, class HashFunc>
	class HashTable{
	public:
		bool insert(const pair<K, V>& kv){
			//考虑是否需要增容的问题
			if (_table.size() == 0){
				_table.resize(8);
			}
			HashFunc hf;
			HashData<K, V>* ret = find(kv.first);
			if (ret != nullptr){  //元素已经在哈希表中存在，不需要再次插入
				return true;
			}

			//负载因子大于0.5就增容
			if ((double)_n / (double)_table.size() > 0.5){
				HashTable<K, V, HashFunc> newhash;
				newhash._table.resize(_table.size() * 2);
				for (auto& e : _table){
					if (e._status == EXITS)
						newhash.insert(e._kv);  //把数据插入到新的哈希表中
				}
				_table.swap(newhash._table);  //交换两个哈希表的table
			}

			//插入数据
			size_t start = hf(kv.first) % _table.size();
			size_t index = start;
			size_t i = 1;
			while (_table[index]._status == EXITS){
				index = start + i;  //线性探测法
				index %= _table.size();
				++i;
			}
			_table[index]._kv = kv;
			_table[index]._status = EXITS;
			_n++;
			return true;
		}

		HashData<K, V>* find(const K& key){
			HashFunc hf;
			size_t start = hf(key) % _table.size();
			size_t index = start;
			size_t i = 1;
			while (_table[index]._status != EMPTY){  
				if (_table[index]._status == EXITS && _table[index]._kv.first == key){
					return &_table[index];
				}
				 //往后探测下一个位置
				index = start + i;
				index %= _table.size();
				++i;
			}
			return nullptr;
		}

		bool erase(const K& key){
			HashData<K, V>* ret = find(key);
			if (ret){
				ret->_status = DELETE;
				_n--;
				return true;
			}
			else
				return false;
		}

	private:
		vector<HashData<K, V>> _table;  //vector中的数据类型为HashData
		size_t _n;  //哈希表中有效数据个数
	};

	//hashFunc仿函数：实现key值转化为int型，能进行取模运算
	struct intHashFunc{
		int operator()(int i){
			return i;
		}
	};

	struct stringHashFunc{
		int operator()(string s){
			int count = 0;
			for (auto &e : s){
				count += e;
			}
			return count;
			//return s[0];
		}
	};



	void test_1(){
		int a[] = { 1, 5, 70, 6, 7, 8, 100};
		HashTable<int, int, intHashFunc> ht;
		for (auto&e : a){
			ht.insert(make_pair(e, e));
		}

		HashData<int, int>*ret = ht.find(12);
		if (ret){
			cout << "找到了" << endl;
		}
		else{
			cout << "没找到" << endl;
		}

		ht.erase(100);

	}

	void test_2(){
		HashTable<string, int, stringHashFunc> ht;
		ht.insert(make_pair("abcd", 1));
		ht.insert(make_pair("humh", 2));
	}


}