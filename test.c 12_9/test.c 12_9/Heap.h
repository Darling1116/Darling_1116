#define _CRT_SECURE_NO_WARNINGS
#pragma once 

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType *_array;
	size_t _size;
	size_t _capacity;
}Heap;

Heap hp;
void HaepInit(Heap *hp, HPDataType *a, size_t n);

void Adjustdown(HPDataType *a, size_t n, int root);
void Adjustup(HPDataType *a, size_t n, int child);

void  HeapSort(Heap *hp, HPDataType *a);

void Heappush(Heap *hp, HPDataType x);
void Heappop(Heap *hp);

int  HeapSize(Heap *hp);
int HeapEmpty(Heap *hp);

void HeapPrint(Heap *hp);
void HeapDestory(Heap *hp);

