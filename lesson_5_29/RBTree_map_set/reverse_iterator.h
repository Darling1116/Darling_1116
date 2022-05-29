#pragma once

//对正向迭代器进行封装，实现反向迭代器
//反向迭代器本质是一个适配器
template <class BRIterator>
struct BR_ReverseIterator{
	typedef typename BRIterator::reference Ref;
	typedef typename BRIterator::pointer Ptr;
	typedef BR_ReverseIterator<BRIterator> self;

	BRIterator _it;   //反向迭代器的成员变量是一个正向迭代器

	BR_ReverseIterator(BRIterator it)
		:_it(it){
	}

	Ref operator*(){
		return *_it;
	}

	Ptr operator->(){
		return _it.operator->();
	}

	self& operator++(){
		--_it;
		return *this;
	}

	self& operator--(){
		++_it;
		return *this;
	}

	bool operator!=(const self& s){
		return _it != s._it;
	}

	bool operator==(const self& s){
		return _it == s._it;
	}

};
