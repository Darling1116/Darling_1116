#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace GXR{
	//��ʶ��ǰ�洢λ�õ�״̬���
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
			//�����Ƿ���Ҫ���ݵ�����
			if (_table.size() == 0){
				_table.resize(8);
			}
			HashFunc hf;
			HashData<K, V>* ret = find(kv.first);
			if (ret != nullptr){  //Ԫ���Ѿ��ڹ�ϣ���д��ڣ�����Ҫ�ٴβ���
				return true;
			}

			//�������Ӵ���0.5������
			if ((double)_n / (double)_table.size() > 0.5){
				HashTable<K, V, HashFunc> newhash;
				newhash._table.resize(_table.size() * 2);
				for (auto& e : _table){
					if (e._status == EXITS)
						newhash.insert(e._kv);  //�����ݲ��뵽�µĹ�ϣ����
				}
				_table.swap(newhash._table);  //����������ϣ���table
			}

			//��������
			size_t start = hf(kv.first) % _table.size();
			size_t index = start;
			size_t i = 1;
			while (_table[index]._status == EXITS){
				index = start + i;  //����̽�ⷨ
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
				 //����̽����һ��λ��
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
		vector<HashData<K, V>> _table;  //vector�е���������ΪHashData
		size_t _n;  //��ϣ������Ч���ݸ���
	};

	//hashFunc�º�����ʵ��keyֵת��Ϊint�ͣ��ܽ���ȡģ����
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
			cout << "�ҵ���" << endl;
		}
		else{
			cout << "û�ҵ�" << endl;
		}

		ht.erase(100);

	}

	void test_2(){
		HashTable<string, int, stringHashFunc> ht;
		ht.insert(make_pair("abcd", 1));
		ht.insert(make_pair("humh", 2));
	}


}