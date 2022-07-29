#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 1.将三个整数按从大到小输出
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


// 2.打印1-100中3的倍数的数
void test1_2(){
	for (int i = 3; i <= 100; i += 3){
		printf("%d ", i);
	}
}

//3.求两个整数的最大公约数
void test1_3(){
	int x = 0;
	int y = 0;
	scanf("%d %d", &x, &y);

	//1.假设较小的数是最大公约数
	//int num = x > y ? y : x;
	//for (int i = num; i > 0; i--){
	//	if (x%num == 0 && y%num == 0)
	//		break;
	//	num--;
	//}
	//printf("%d\n", num);

	//2.利用a%b
	int num = 0;
	while (num = x%y){
		y = x;
		num = y;
	}
	printf("%d\n", y);
}

//4.打印1000-2000年之间的闰年
void test1_4(){
	for (int i = 1000; i <= 2000; i++){
		if ((i % 4 == 0 && 1 % 100 != 0) || (i % 400 == 0))
			printf("%d ", i);
	}
}

//5.打印100-200之间的素数，并统计个数
void test1_5(){
	int i = 0;
	int j = 0;
	int count = 0;
	int flag = 1;
	for (i = 100; i <= 200; i++){
		flag = 1;
		//for (j = 2; j < i; j++){
		//优化：
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

//6.数一下1-100的所有整数中出现多少个数字9
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

//7.计算1/1-1/2+1/3-1/4......+1/99-1/100的值，打印出结果
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

//8.求10个整数中的最大值
void test1_8(){
	int arr[10] = { 4, 29, 8, 38, 10, 68, 29, 2, 34, 22 };
	int max = arr[0];
	for (int i = 1; i < 10; i++){
		if (max < arr[i])
			max = arr[i];
	}
	printf("%d\n", max);
}

//9.在屏幕上输出9*9乘法表
void test1_9(){
	int i = 0;
	int j = 0;
	for (i = 1; i <= 9; i++){  //9行
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

//10.二分查找：在一个整型有序数组中查找具体的某个数
//找到就打印下标，找不到输出“找不到”
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
			printf("找到了，下标为：%d", mid);
			return;
		}
		else if (x < arr[mid]){
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}
	}
	printf("找不到\n");
	//for (int i = 0; i < sizeof(arr); i++){
	//	if (x == arr[i]){
	//		printf("找到了，下标为：%d", i);
	//		return;
	//	}
	//}
	//printf("找不到\n");
}
