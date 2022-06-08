#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

namespace GXR_1{
	template <size_t N>  //N¸öbitÎ»
	struct BitSet{
	public:
		BitSet(){
			_bit.resize(N / 32 + 1, 0);
		}

		void set(size_t x){
			size_t i = x / 32;
			size_t j = x % 32;
			_bit[i] |= 1 << j;
		}

		void reset(size_t x){
			size_t i = x / 32;
			size_t j = x % 32;
			_bit[i] &= (~(1 << j));
		}

		bool test(size_t x){
			size_t i = x / 32;
			size_t j = x % 32;
			return _bit[i] & 1 << j;

		}

	private:
		vector<int> _bit;
	};

	void test_bitset(){
		BitSet<-1> bs;
		bs.set(10);
		bs.set(12);
		bs.set(25);
		bs.set(100);
		bool ret = bs.test(1);
		cout << ret << endl;
	}
}