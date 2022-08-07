#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//旋转数组的最小数字

//方法1：直接依次遍历查找
void test1_1(){
	int arr[] = { 3, 4, 5, 1, 2 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int min = arr[0];
	for (int i = 1; i < len; i++){
		if (min > arr[i]){
			min = arr[i];
		}
	}
	printf("min: %d\n", min);

}

//方法2：两两比较
void test1_2(){
	int arr[] = { 3, 4, 5, 1, 2 };
	int len = sizeof(arr) / sizeof(arr[0]);
	for (int i = 1; i < len; i++){
		if (arr[i - 1] > arr[i]){
			printf("min: %d\n", arr[i]);
			break;
		}
	}
}