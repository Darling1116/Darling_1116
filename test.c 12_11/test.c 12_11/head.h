#define _CRT_SECURE_NO_WARNING
#pragma once

#include <stdio.h>
#include <stdlib.h>
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

void HeapInit(Heap *hp, HPDataType *a, size_t n);

void Adjustdown(HPDataType *a, size_t n, int root);
void Adjustup(HPDataType *a, size_t n, int child);

void Heappush(Heap *hp, HPDataType *a, HPDataType x);

void HeapPrint(Heap *hp);
void HeapDestory(Heap *hp);