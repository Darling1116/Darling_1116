#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//��ת�������С����

//����1��ֱ�����α�������
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

//����2�������Ƚ�
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