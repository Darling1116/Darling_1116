#pragma once
#include "RBTree.h"

namespace GXR{
	template <class K, class V>
	class map{
		struct mapKeyOfT{
			const K& operator()(const pair<K, V>& kv){
				return kv.first;
			}
		};

	public:
		typedef typename BRTree<K, pair<K, V>, mapKeyOfT>::iterator iterator;
		iterator begin(){
			return _t.begin();
		}
	
		iterator end(){
			return _t.end();
		}

		typedef typename BRTree<K, pair<K, V>, mapKeyOfT>::reverse_iterator reverse_iterator;
		reverse_iterator rbegin(){
			return _t.rbegin();
		}

		reverse_iterator rend(){
			return _t.rend();
		}

		pair<iterator, bool> Insert(const pair<K, V>& kv){
			return _t.insert(kv);
		}

		V& operator[](const K& key){
			pair<iterator, bool> ret = Insert(make_pair(key, V()));
			return ret.first->second;
		}


	private:
		BRTree<K, pair<K, V>, mapKeyOfT> _t;
	};
};