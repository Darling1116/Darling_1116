#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType *_array;
	size_t _size;
	size_t _capacity;
}SeqList;



void SeqListInit(SeqList *ps, size_t capacity);

void SeqListPrint(SeqList *ps);
void SeqListDestory(SeqList *ps);

void  CheckCapacity(SeqList *ps);
void SeqListpushback(SeqList *ps, SLDataType x);
void SeqListpopback(SeqList *ps);
void SeqListpushfront(SeqList *ps, SLDataType x);
void SeqListpopfront(SeqList *ps);

void SeqListInsert(SeqList *ps, size_t pos, SLDataType x);
void SeqListErase(SeqList *ps, size_t pos, SLDataType x);

void SeqListBubbleSort(SeqList *ps);

int SeqListBinaryFind(SeqList *ps, SLDataType x);

