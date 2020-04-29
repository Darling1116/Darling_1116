#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int SLDataType;

typedef struct SeqList{
	SLDataType* data;
	int maxSize;
	int length;
}SeqList;

void InitList(SeqList* sl, int maxsize){
	sl->data = (SLDataType*)malloc(sizeof(SLDataType)*maxsize);
	assert(sl->data);
	sl->maxSize = maxsize;
	sl->length = 0;
}

void PrintList(SeqList* sl){
	for (int i = 0; i < sl->length; i++){
		printf("%d ", sl->data[i]);
	}
	printf("\n");
}

bool InsertList(SeqList* sl,int pos, SLDataType x){
	if (pos<1 || pos>sl->length + 1){
		return false;
	}
	if (sl->length >= sl->maxSize){
		return false;
	}
	for (int i = sl->length; i >= pos; i--){
		sl->data[i] = sl->data[i - 1];
	}
	sl->data[pos - 1] = x;
	sl->length++;
	return true;
}


//合并两个有序顺序表
bool MergeTwoList(SeqList* s1, SeqList* s2, SeqList*s){
	if (s1->length + s2->length > s->maxSize){
		return false;
	}
	int i = 0, j = 0, k = 0;
	//用k表示新的序列
	while (i < s1->length && j < s2->length){
		if (s1->data[i] <= s2->data[j]){
			s->data[k++] = s1->data[i++];
		}
		else{
			s->data[k++] = s2->data[j++];
		}
	}
	while (i < s1->length){
		s->data[k++] = s1->data[i++];
	}
	while (j < s2->length){
		s->data[k++] = s2->data[j++];
	}
	s->length = k;
	//这里用k，不用k+1，原因：k++过后k的值已经加过1。
	return true;
}

int main(){
	SeqList sl;
	SeqList s2;
	SeqList s;
	InitList(&sl, 10);
	InitList(&s2, 10);
	InitList(&s, 10);
	InsertList(&sl, 1, 8);
	InsertList(&sl, 1, 7);
	InsertList(&sl, 1, 3);
	InsertList(&sl, 1, 3);
	InsertList(&s2, 1, 4);
	InsertList(&s2, 1, 2);
	InsertList(&s2, 1, 1);

	MergeTwoList(&sl, &s2, &s);
	PrintList(&sl);
	PrintList(&s2);
	PrintList(&s);

	system("pause");
	return 0;
}