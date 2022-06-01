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
			//���ж��Ƿ�������и�Ԫ�أ����Ѵ��ڣ��Ͳ��ò���
			node* ret = find(kv.first);
			if (ret != nullptr){
				return false;
			}
			HashFunc hf;
			//���������ӵ���1ʱ���������ݴ���
			if (_n == _table.size()){
				//�½�һ��table�������Ž���ָ��
				vector<node*> newtable;
				newtable.resize(_table.size() == 0 ? 8 : _table.size() * 2,nullptr);
				//���α�����ϣ���Ѹ���Ͱ�е�Ԫ�����¼���ӳ��λ��
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
						_table[i] = nullptr;  //�ɱ��е�Ԫ���ÿ�
					}
				}
				swap(_table, newtable);
			}

			//����ɢ�е�ַ
			size_t index = hf(kv.first) % _table.size();
			//�ѽ��ͷ�����Ӧ��Ͱ�У�����_n
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
			node* cur = _table[index];  //ȥ��Ӧ��Ͱ�����

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

			//ȥͰ���Ҵ�ɾ��Ԫ��
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
		size_t _n; //��ϣ���е���Ч���ݸ���
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
			cout << "�ҵ���" << endl;
		else
			cout << "û�ҵ�" << endl;

		if (ht.erase(3)){
			cout << "Ԫ����ɾ��" << endl;
		}
		else{
			cout << "ɾ��ʧ��" << endl;
		}
		
	}

	void test_2(){
		HashTable<string, int, stringHashFunc> ht;
		ht.insert(make_pair("����", 1));
		ht.insert(make_pair("ɾ��", 2));
		ht.insert(make_pair("����", 3));
		ht.insert(make_pair("����", 4));
		ht.insert(make_pair("����", 5));
	}
}