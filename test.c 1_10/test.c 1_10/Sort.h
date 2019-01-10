#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
void Swap(int *x, int *y);

int PastSort1(int* a, int left, int right);

int PartSort2(int* a, int left, int right);

int PartSort3(int* a, int left, int right);
int GetMiddle(int*a, int left, int right);
void QuickSort1(int* a, int left, int right);

void InsertSort(int* a, int left, int right);

void test();