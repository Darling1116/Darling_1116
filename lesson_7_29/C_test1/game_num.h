#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//��������Ϸ
void test(){
	printf("---��������Ϸ��ʼ---\n");
	//�������1-100֮�����
	int num = rand( )%100+1;  //rand( )�������0-32767֮�����
	//printf("%d", num);
	int input = 0;
	while (1){
		printf("����������:\n");
		scanf("%d", &input);
		if (input < num)
			printf("��С��...\n");
		else if (input > num)
			printf("�´���...\n");
		else{
			printf("�¶���...\n");
			break;
		}
	}
}