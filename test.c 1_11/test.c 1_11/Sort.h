#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <time.h>

void MergeSort(int* a, int n);
void _MergeSort(int* a, int left, int right, int* tmp);

void Sort(int* a, int n);
void test();