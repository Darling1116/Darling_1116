#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//1.写一个宏，把一个整数里面的二进制位的奇数位与偶数位进行交换
#define CHANGE(num) (((num&0x55555555)<<1)+((num&0xaaaaaaaa)>>1))

void test1_1(){
	int num = 15;
	int ret = CHANGE(num);
	printf("%d\n", ret);
}


//2.实现Offsefof宏：计算结构体中某变量相对于首地址的偏移
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