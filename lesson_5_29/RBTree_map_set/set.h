#pragma once
#include "RBTree.h"

namespace GXR{
	template <class K, class V>
	class set{
		struct setKeyOfT{
			const K& operator()(const K& k){
				return k;
			}
		};

	public:
		typedef typename BRTree<K, K, setKeyOfT>::iterator iterator;
		typedef typename BRTree<K, K, setKeyOfT>::reverse_iterator reverse_iterator;

		bool Insert(const K& k){
			_t.insert(k);
			return true;
		}

		iterator begin(){
			return _t.begin();
		}

		iterator end(){
			return _t.end();
		}
		
		reverse_iterator rbegin(){
			return _t.rbegin();
		}

		reverse_iterator rend(){
			return _t.rend();
		}

	private:
		BRTree<K, K, setKeyOfT> _t;
	};
};