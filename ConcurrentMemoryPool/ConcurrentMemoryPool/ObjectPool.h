#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "common.h"

#ifdef _WIN32
#include <Windows.h>
#else
#endif

using std::cout;
using std::endl;

//��windows��ֱ�����������ҳΪ��λ�Ĵ���ڴ�
//inline static void* SystemAlloc(size_t kpage){
//	void* ptr = VirtualAlloc(0, kpage * 8 * 1024, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
//
//	if (ptr == nullptr)
//		throw std::bad_alloc();
//
//	return ptr;
//}


//��ƶ����ڴ�أ�ʵ�ֶ����ڴ��
//ʹ��ģ����
template<class T>
class ObjectPool{
public:
	T* New(){
		T* obj = nullptr; //����һ������

		//����ʹ�����������л���������Դ
		if (_freelist){
			void* next = *(void**)_freelist;  
			//ȡ��ǰ_freelist��ŵ�ַ���ڴ棬�����ã��õ�����ָ�����һ���ڴ��
			obj = (T*)_freelist;
			_freelist = next;
			return obj;
		}

		//ʣ���ڴ��С��������һ������ʱ�����ռ�
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
		//Ϊ�˻����ͷŵ��ڴ���Դ��obj�Ĵ�С����Ϊһ��ָ��Ĵ�С
		size_t objSize = sizeof(T) < sizeof(void*) ? sizeof(void*) : sizeof(T);
		_memory += objSize;
		_remainByte -= objSize;

		//ʹ�ö�λnew����ʾ����T�Ĺ��캯����ʼ��
		new(obj)T;

		return obj;
	}


	void Delete(T* obj){
		//����ͷ�巨������������
		(*(void**)obj) = _freelist;  //_freelistָ�����������еĵ�һ���ڴ�
		_freelist = obj;
		
		//ʹ�ö�λnew����ʾ����T����������������Դ
		obj->~T();
	}

private:
	char* _memory = nullptr;  //һ�鶨�����ڴ�ռ�
	void* _freelist = nullptr;  //�����ڴ���Դ����������
	size_t _remainByte = 0;  //����ڴ�ʣ��δ������ֽ���
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
	//���ж����ֵĲ���
	const size_t Rounds = 3;
	//ÿ�������ͷŶ��ٴ�
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
		v1.clear();  //ÿ��֮������һ��vector
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
