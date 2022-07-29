#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//猜数字游戏
void test(){
	printf("---猜数字游戏开始---\n");
	//随机生成1-100之间的数
	int num = rand( )%100+1;  //rand( )随机生成0-32767之间的数
	//printf("%d", num);
	int input = 0;
	while (1){
		printf("请输入数字:\n");
		scanf("%d", &input);
		if (input < num)
			printf("猜小了...\n");
		else if (input > num)
			printf("猜大了...\n");
		else{
			printf("猜对了...\n");
			break;
		}
	}
}