#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;
typedef struct SeqList{
	SLDataType * array;
	size_t size;
	size_t capacity;
}SeqList;

//初始化顺序表
void SeqListInit(SeqList* sl, size_t capacity){
	sl->array = malloc(capacity*sizeof(SLDataType));
	assert(sl->array);
	sl->size = 0;
	sl->capacity = capacity;
}

//销毁顺序表
void SeqListDestory(SeqList* sl){
	assert(sl);
	free(sl->array);
	sl->array = NULL;
	sl->size = 0;
	sl->capacity = 0;
}

//检查容量
void CheckCapacity(SeqList* sl){
	assert(sl);
	if (sl->size >= sl->capacity){
		size_t newcapacity = sl->capacity * 2;
		SLDataType* newarray = malloc(sizeof(SLDataType)* newcapacity);
		assert(newarray);
		for (int i = 0; i < sl->size; i++){
			newarray[i] = sl->array[i];
		}
		free(sl->array);
		sl->array = newarray;
		sl->capacity = newcapacity;
	}
	else{
		return;
	}
}

//尾插
void SeqListPushBack(SeqList* sl,SLDataType x){
	assert(sl);
	CheckCapacity(sl);
	sl->array[sl->size] = x;
	sl->size++;
}
//尾删
void SeqListPopBack(SeqList* sl){
	assert(sl->size);
	sl->size--;
}

//头插
void SeqListPushFront(SeqList* sl, SLDataType x){
	assert(sl);
	CheckCapacity(sl);
	for (int i = sl->size - 1; i >= 0; i--){
		sl->array[i + 1] = sl->array[i];
	}
	sl->array[0] = x;
	sl->size++;
}

//头删
void SeqListPopFront(SeqList* sl){
	assert(sl->size);
	for (int i = 0; i < sl->size-1; i++){
		sl->array[i] = sl->array[i + 1];
	}
	sl->size--;
}


//插入（pos表示的是要插入元素位置的下标）
void SeqListInsert(SeqList* sl, size_t pos, SLDataType x){
	assert(sl->array);
	assert(pos >= 0 && pos <= sl->size);
	for (int i = sl->size - 1; i >= pos; i--){
		sl->array[i + 1] = sl->array[i];
	}
	sl->array[pos] = x;
	sl->size++;
}

void SeqListErase(SeqList* sl, size_t pos){
	assert(sl->array);
	assert(pos >= 0 && pos < sl->size);
	for (int i = pos; i < sl->size-1; i++){
		sl->array[i] = sl->array[i+1];
	}
	sl->size--;
}


size_t SeqListFind(SeqList* sl, SLDataType x){
	assert(sl);
	for (int i = 0; i < sl->size; i++){
		if (sl->array[i] == x){
			return i;
		}
	}
	return -1;
}


//删除所有值为x的元素
void SeqListRemove(SeqList* sl, SLDataType x){
	assert(sl->array);
	int pos = SeqListFind(sl, x);
	if (pos == -1){
		return;
	}
	else{
		SeqListErase(sl, pos);
	}
}

void SeqListModify(SeqList* sl, size_t pos, SLDataType x){
	assert(sl->array);
	assert(pos >= 0 && pos < sl->size);
	sl->array[pos] = x;
}


void SeqListPrint(SeqList* sl){
	assert(sl->array);
	for (int i = 0; i < sl->size; i++){
		printf("%d ", sl->array[i]);
	}
}

void main(){
	SeqList sl;
	SeqListInit(&sl, 10);
	SeqListPushBack(&sl, 5);
	SeqListPushBack(&sl, 5);
	SeqListPushBack(&sl, 5);
	SeqListPushBack(&sl, 5);
	SeqListPushBack(&sl, 5);
	SeqListPopBack(&sl);

	SeqListPushFront(&sl, 6);
	SeqListPopFront(&sl);

	SeqListInsert(&sl, 1, 2);
	SeqListInsert(&sl, 3, 2);
	SeqListInsert(&sl, 2, 2);
	SeqListErase(&sl, 1);
	SeqListErase(&sl, 0);

	SeqListRemove(&sl, 2);

	SeqListModify(&sl, 0, 12);

	SeqListPrint(&sl);
	//SeqListDestory(&sl);
	system("pause");
	return 0;
}
