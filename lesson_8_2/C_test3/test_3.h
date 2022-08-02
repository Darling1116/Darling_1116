#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//1.����ˮ��һƿ��ˮ1ԪǮ��������ƿ���Ի�һƿ��ˮ
//��20Ԫ�����Ժȶ���ƿ��ˮ
void test3_1(){
	int money = 40;
	int sum = money;
	int empty = money;
	while (empty/2 >= 1){
		sum += empty / 2;
		empty = empty / 2 + empty % 2;
	}
	printf("%d\n", sum);
}


//2.��������ʹ����ȫ��λ��ż��֮ǰ
void test3_2(){
	int arr[11] = { 3, 45, 31, 556, 7884, 2, 4424, 4, 35, 3, 42};
	int len = sizeof(arr) / sizeof(arr[0]);
	int left = 0;
	int right = len - 1;
	while (left < right){
		while (left<right && arr[left] % 2 == 1){
			left++;
		}
		while (left<right && arr[right] % 2 == 0){
			right--;
		}
		if (left != right){
			int tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
			left++;
			right--;
		}
		
	}

	for (int i = 0; i < len; i++){
		printf("%d ", arr[i]);
	}
}



//3.��ӡ���������
void test3_3(){
	int n = 6;
	int arr[6][6] = { 0 };
	for (int i = 0; i < 6; i++){
		for (int j = 0; j <= i; j++){
			if (j == 0 || j == i){
				arr[i][j] = 1;
			}
			else{
				arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
			}
			
		}
	}
	for (int i = 0; i < 6; i++){
		for (int j = 0; j <= i; j++){
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}