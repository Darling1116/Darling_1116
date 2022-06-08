#pragma once
#include "BitSet.h"
#include "string"
using namespace GXR_1;

namespace GXR_2{
	template <size_t N, class K = string, 
	class Hash_1 = BKDRHash, 
	class Hash_2 = SDBMHash,
	class Hash_3 = RSHash>
	class BloomFilter{
	public:
		void Set(const K& x){
		/*	Hash_1 h1;
			h1(x);*/
			size_t i1 = Hash_1()(x) % N;
			size_t i2 = Hash_2()(x) % N;
			size_t i3 = Hash_3()(x) % N;
			cout << i1 << " " << i2 << " " << i3 << endl;
			_bs.set(i1);
			_bs.set(i2);
			_bs.set(i3);
		}

		bool Test(const K& key){
			size_t i1 = Hash_1()(key) % N;
			size_t i2 = Hash_2()(key) % N;
			size_t i3 = Hash_3()(key) % N;
			//如果有一个位上的值不为1，则不存在；全部为1，可能存在(误判)
			if (!_bs.test(i1))
				return false;
			if (!_bs.test(i2))
				return false;
			if (!_bs.test(i3))
				return false;
			return true;
		}

	private:
		BitSet<N> _bs;
	};


	struct BKDRHash{
		size_t operator()(const string str){
			size_t hash = 0;
			for (auto&ch : str){
				hash = hash * 131 + ch;
			}
			return hash;
		}
	};

	struct SDBMHash{
		size_t operator()(const string str){
			size_t hash = 0;
			for (auto&ch : str){
				hash = 65599 * hash + ch;  
			}
			return hash; 
		}
	};

	struct RSHash{
		size_t operator()(const string str){
			size_t hash = 0;
			size_t magic = 63689;
			for (auto&ch : str){
				hash = hash * magic + ch;
				magic *= 378551;
			}
			return hash;
		}
	};



	void test_BloomFilter(){
		BloomFilter<1000> bf;
		//bf.Set("hahhs");
		//bf.Set("ahahs");
		//bf.Set("nuuas");
		//cout << bf.Test("ahahs") << endl;
		//cout << bf.Test("nuuas") << endl;

		int count = 100;
		string url = "https://www.cnblogs.com/-clq/archive/2012/05/31/2528153.html";
		for (int i = 0; i < 100; i++){
			bf.Set(url + to_string(1234 + i));
		}
		for (int j = 10000; j < 10100; j++){
			cout << bf.Test(url + to_string(9876 + j)) << endl;
		}

	}
}