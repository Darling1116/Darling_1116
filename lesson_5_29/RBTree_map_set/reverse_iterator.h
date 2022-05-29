#pragma once

//��������������з�װ��ʵ�ַ��������
//���������������һ��������
template <class BRIterator>
struct BR_ReverseIterator{
	typedef typename BRIterator::reference Ref;
	typedef typename BRIterator::pointer Ptr;
	typedef BR_ReverseIterator<BRIterator> self;

	BRIterator _it;   //����������ĳ�Ա������һ�����������

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
