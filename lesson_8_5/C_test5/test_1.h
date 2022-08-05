#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//一个数组中只有两个数字是出现了一次，
//其他所有数字都出现了两次，
//找出这两个只出现一次的数字

void find_single_number(int arr[], int sz){
	int i = 0;
	int ret = 0;
	for (i = 0; i < sz; i++){
		ret = ret^arr[i];
	}

	//找ret中第一个二进制位数为1的位置
	int pos = 0;
	for (i = 0; i < 32; i++){
		if (((ret >> i) & 1) == 1){
			pos = i;
			break;
		}
	}

	//把arr中pos位为1的分成一组，为0的分成另一组
	int single1 = 0;
	int single2 = 0;
	for (i = 0; i < sz; i++){
		if (((arr[i] >> pos) & 1) == 1){
			single1 = single1^arr[i];
		}
	}

	single2 = ret ^ single1;
	printf("single1:%d  single2:%d\n", single1, single2);
	
}

void test1_1(){
	int arr[] = { 2, 6, 4, 3, 5, 9, 2, 5, 9, 4 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	for (int i = 0; i < sz; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	find_single_number(arr, sz);
}