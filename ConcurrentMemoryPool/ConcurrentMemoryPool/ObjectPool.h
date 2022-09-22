#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "common.h"

#ifdef _WIN32
#include <Windows.h>
#else
#endif

using std::cout;
using std::endl;

//在windows下直接向堆申请以页为单位的大块内存
//inline static void* SystemAlloc(size_t kpage){
//	void* ptr = VirtualAlloc(0, kpage * 8 * 1024, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
//
//	if (ptr == nullptr)
//		throw std::bad_alloc();
//
//	return ptr;
//}


//设计定长内存池：实现对象内存池
//使用模板类
template<class T>
class ObjectPool{
public:
	T* New(){
		T* obj = nullptr; //定义一个对象

		//优先使用自由链表中还回来的资源
		if (_freelist){
			void* next = *(void**)_freelist;  
			//取当前_freelist存放地址的内存，解引用，得到其所指向的下一个内存块
			obj = (T*)_freelist;
			_freelist = next;
			return obj;
		}

		//剩余内存大小不够分配一个对象时，开空间
		if (_remainByte < sizeof(T)){
			_remainByte = 128 * 1024;
			//_memory = (char*)malloc(_remainByte);
			_memory = (char*)SystemAlloc(_remainByte >> 13);
			if (_memory == nullptr){
				throw std::bad_alloc();
			}
		}
		obj = (T*)_memory;
		//_memory += sizeof(T);
		//_remainByte -= sizeof(T);
		//为了回收释放的内存资源，obj的大小至少为一个指针的大小
		size_t objSize = sizeof(T) < sizeof(void*) ? sizeof(void*) : sizeof(T);
		_memory += objSize;
		_remainByte -= objSize;

		//使用定位new，显示调用T的构造函数初始化
		new(obj)T;

		return obj;
	}


	void Delete(T* obj){
		//采用头插法连接自由链表
		(*(void**)obj) = _freelist;  //_freelist指向自由链表中的第一块内存
		_freelist = obj;
		
		//使用定位new，显示调用T的析构函数清理资源
		obj->~T();
	}

private:
	char* _memory = nullptr;  //一块定长的内存空间
	void* _freelist = nullptr;  //回收内存资源的自由链表
	size_t _remainByte = 0;  //大块内存剩余未分配的字节数
};


struct TreeNode{
	int _val;
	TreeNode* _left;
	TreeNode* _right;

	TreeNode()
		:_val(0),
		_left(nullptr),
		_right(nullptr){

	}
};

void test_ObjectPool(){
	//进行多少轮的操作
	const size_t Rounds = 3;
	//每轮申请释放多少次
	const size_t N = 1000;

	size_t begin1 = clock();
	std::vector<TreeNode*> v1;
	v1.reserve(N);
	for (size_t j = 0; j < Rounds; j++){
		for (int i = 0; i < N; i++){
			v1.push_back(new TreeNode);
		}
		for (int i = 0; i < N; i++){
			delete v1[i];
		}
		v1.clear();  //每轮之后，清理一下vector
	}
	size_t end1 = clock();


	size_t begin2 = clock();
	ObjectPool<TreeNode> TNPool;
	std::vector<TreeNode*> v2;
	v2.reserve(N);
	for (size_t j = 0; j < Rounds; j++){
		for (int i = 0; i < N; i++){
			v2.push_back(TNPool.New());
		}
		for (int i = 0; i < N; i++){
			TNPool.Delete(v2[i]);
		}
		v2.clear();
	}
	size_t end2 = clock();

	cout << "new cost time: " << end1 - begin1 << endl;
	cout << "ObjectPool cost time: " << end2 - begin2 << endl;
	
}
