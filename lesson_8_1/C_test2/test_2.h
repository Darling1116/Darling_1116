#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//1.strlen的模拟实现
int my_strlen(char* str){
	char* tmp = str;
	int len = 0;
	while (*tmp != '\0'){
		tmp++;
		len++;
	}
	return tmp - str;
}

void test2_1(){
	char* str = "abcdefg";
	printf("%d\n", my_strlen(str));
	char arr[] = "abcdefg";
	printf("%d\n", my_strlen(arr));
}

//2.冒泡排序：参数为整型数组

void my_swap(int* x, int* y){
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

//不能在冒泡排序内部用sizeof(arr)/sizeof(arr[0])求数组长度
void bubble_sort(int arr[], int len){
	for (int i = 0; i < len; i++){
		for (int j = len - 1; j > i; j--){
			if (arr[j] < arr[j - 1]){
				//my_swap(&arr[j-1], &arr[j]);
				int tmp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = tmp;
			}
		}
		printf("%d ", arr[i]);
	}
	printf("\n");
}



void test2_2(){
	//int a = 10;
	//int b = 20;
	//my_swap(&a, &b);
	//printf("%d %d", a, b);

	int arr[] = { 3, 6, 2, 0, 20, 34 };
	for (int i = 0; i < 6; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	int len = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, len);
	
}

//3.创建一个整型数组，完成对数组的操作
//init---初始化数组全为0；print---打印每个元素；
//reverse---数组元素逆置

void test2_3(){
	int arr[10] = { 0 };
	for (int i = 0; i < 10; i++){
		arr[i] = i;
	}
	int len = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < len; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

	int left = 0;
	int right = len - 1;
	while (left < right){
		int tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
	for (int i = 0; i < len; i++){
		printf("%d ", arr[i]);
	}

}

//4.将数组A和数组B中的内容进行交换（两个数组一样大）
void test2_4(){
	int a[] = { 3, 6, 2, 0, 20, 34 };
	int b[] = { 1, 2, 3, 4, 5, 6 };

	int len = sizeof(a) / sizeof(a[0]);
	for (int i = 0; i < len; i++){
		int tmp = a[i];
		a[i] = b[i];
		b[i] = tmp;
	}

	int i = 0;
	for (i = 0; i < len; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	for (i = 0; i < len; i++){
		printf("%d ", b[i]);
	}
}