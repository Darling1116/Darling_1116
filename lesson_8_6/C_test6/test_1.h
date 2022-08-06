#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//1.дһ���꣬��һ����������Ķ�����λ������λ��ż��λ���н���
#define CHANGE(num) (((num&0x55555555)<<1)+((num&0xaaaaaaaa)>>1))

void test1_1(){
	int num = 15;
	int ret = CHANGE(num);
	printf("%d\n", ret);
}


//2.ʵ��Offsefof�꣺����ṹ����ĳ����������׵�ַ��ƫ��
struct S{
	char a;
	int i;
	double d;
	short s;
};

#define OFFSETOF(s_type, s_member) ((size_t)&(((s_type*)0)->s_member))
void test1_2(){
	printf("%d\n", OFFSETOF(struct S, a));
	printf("%d\n", OFFSETOF(struct S, i));
	printf("%d\n", OFFSETOF(struct S, d));
	printf("%d\n", OFFSETOF(struct S, s));
}