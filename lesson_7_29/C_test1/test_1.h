#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 1.�������������Ӵ�С���
void test1_1(){
	int a = 0;
	int b = 0;
	int c = 0;
	scanf("%d %d %d", &a, &b, &c);
	if (a < b){
		int tmp = a;
		a = b;
		b = tmp;
	}
	if (a < c){
		int tmp = a;
		a = c;
		c = tmp;
	}
	if (b < c){
		int tmp = b;
		b = c;
		c = tmp;
	}
	printf("%d %d %d", a, b, c);
}


// 2.��ӡ1-100��3�ı�������
void test1_2(){
	for (int i = 3; i <= 100; i += 3){
		printf("%d ", i);
	}
}

//3.���������������Լ��
void test1_3(){
	int x = 0;
	int y = 0;
	scanf("%d %d", &x, &y);

	//1.�����С���������Լ��
	//int num = x > y ? y : x;
	//for (int i = num; i > 0; i--){
	//	if (x%num == 0 && y%num == 0)
	//		break;
	//	num--;
	//}
	//printf("%d\n", num);

	//2.����a%b
	int num = 0;
	while (num = x%y){
		y = x;
		num = y;
	}
	printf("%d\n", y);
}

//4.��ӡ1000-2000��֮�������
void test1_4(){
	for (int i = 1000; i <= 2000; i++){
		if ((i % 4 == 0 && 1 % 100 != 0) || (i % 400 == 0))
			printf("%d ", i);
	}
}

//5.��ӡ100-200֮�����������ͳ�Ƹ���
void test1_5(){
	int i = 0;
	int j = 0;
	int count = 0;
	int flag = 1;
	for (i = 100; i <= 200; i++){
		flag = 1;
		//for (j = 2; j < i; j++){
		//�Ż���
		for (j = 2; j <= sqrt((double)i); j++){
			if (i%j == 0){
				flag = 0;
				break;
			}
		}
		if (flag){
			count++;
			printf("%d ", i);
		}
	}
	printf("\n");
	printf("count: %d", count);
}

//6.��һ��1-100�����������г��ֶ��ٸ�����9
void test1_6(){
	int i = 0;
	int count = 0;
	for (i = 1; i <= 100; i++){
		if (i % 10 == 9)
			count++;
		if (i / 10 == 9)
			count++;
	}
	printf("%d\n", count);
}

//7.����1/1-1/2+1/3-1/4......+1/99-1/100��ֵ����ӡ�����
void test1_7(){
	int flag = 1;
	double sum = 0;
	double i = 0;
	for (i = 1; i <= 100; i++){
		sum += (flag * (1.0 / i));
		flag = -flag;
	}
	printf("%lf\n", sum);
}

//8.��10�������е����ֵ
void test1_8(){
	int arr[10] = { 4, 29, 8, 38, 10, 68, 29, 2, 34, 22 };
	int max = arr[0];
	for (int i = 1; i < 10; i++){
		if (max < arr[i])
			max = arr[i];
	}
	printf("%d\n", max);
}

//9.����Ļ�����9*9�˷���
void test1_9(){
	int i = 0;
	int j = 0;
	for (i = 1; i <= 9; i++){  //9��
		for (j = 1; j <= i; j++){
			printf("%d*%d=%2d ", i, j, i*j);
		}
		printf("\n");
	}
}

void Mul_table(int size){
	int i = 0;
	int j = 0;
	for (i = 1; i <= size; i++){
		for (j = 1; j <= i; j++){
			printf("%2d*%2d=%3d ", i, j, i*j);
		}
		printf("\n");
	}
}

//10.���ֲ��ң���һ���������������в��Ҿ����ĳ����
//�ҵ��ʹ�ӡ�±꣬�Ҳ���������Ҳ�����
void test1_10(){
	int arr[] = { 2, 3, 8, 19, 34, 56, 87 };
	int x = 0;
	scanf("%d", &x);

	int left = 0;
	int right = sizeof(arr)/arr[0]-1;
	int mid = 0;
	while (left <= right){
		mid = (left + right) / 2;
		if (x == arr[mid]){
			printf("�ҵ��ˣ��±�Ϊ��%d", mid);
			return;
		}
		else if (x < arr[mid]){
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}
	}
	printf("�Ҳ���\n");
	//for (int i = 0; i < sizeof(arr); i++){
	//	if (x == arr[i]){
	//		printf("�ҵ��ˣ��±�Ϊ��%d", i);
	//		return;
	//	}
	//}
	//printf("�Ҳ���\n");
}
