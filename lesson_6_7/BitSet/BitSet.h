#pragma once
#include <iostream>
#include <vector>
using namespace std;

namespace GXR{
	template <size_t N>
	class BitSet{
	public:
		BitSet(){
			_bit.resize(N / 32 + 1, 0);
		}

		void Set(size_t x){  //置1
			size_t i = x / 32;
			size_t j = x % 32;
			_bit[i] |= (1 << j);
		}

		void ReSet(size_t x){  //置0
			size_t i = x / 32;
			size_t j = x % 32;
			_bit[i] &= (~(1 << j));
		}

		bool Test(size_t x){  //判断x在位图中的状态是否为1
			size_t i = x / 32;
			size_t j = x % 32;
			return _bit[i] & (1 << j);
		}

	private:
		vector<int> _bit;
	};

	void test(){
		BitSet<-1> bs;
		bs.Set(18);
		bs.Set(154);
		bs.Set(25);
		cout << bs.Test(154) << endl;
		cout << bs.Test(200) << endl;
	}
}

