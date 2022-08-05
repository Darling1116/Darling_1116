#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//һ��������ֻ�����������ǳ�����һ�Σ�
//�����������ֶ����������Σ�
//�ҳ�������ֻ����һ�ε�����

void find_single_number(int arr[], int sz){
	int i = 0;
	int ret = 0;
	for (i = 0; i < sz; i++){
		ret = ret^arr[i];
	}

	//��ret�е�һ��������λ��Ϊ1��λ��
	int pos = 0;
	for (i = 0; i < 32; i++){
		if (((ret >> i) & 1) == 1){
			pos = i;
			break;
		}
	}

	//��arr��posλΪ1�ķֳ�һ�飬Ϊ0�ķֳ���һ��
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