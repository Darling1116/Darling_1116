#pragma once
#include <stdio.h>
#include <stdlib.h>

//求一个整数存储在内存中的二进制中的1的个数
void test2_1_1(){
	int n = 0;
	scanf("%d", &n);
	int count = 0;
	for (int i = 0; i < 32; i++){
		if ((n >> i) & 1 == 1)
			count++;
	}
	printf("%d ", count);
}

void test2_1_2(){
	int n = 0;
	scanf("%d", &n);
	int count = 0;
	while (n){
		count++;
		n = n&(n - 1);
	}
	printf("%d ", count);
}


struct Stu{
	char name[20];
	int age;
};

void print(struct Stu* ps) {
	//二者效果相同
	printf("name = %s   age = %d\n", (*ps).name, (*ps).age);
	//使用结构体指针访问指向对象的成员
	printf("name = %s   age = %d\n", ps->name, ps->age);
}

void test2_2(){
	struct Stu s = { "zhangsan", 20 };
	print(&s);//结构体地址传参
}

//模拟实现strcpy
char* my_strcpy(char* dst, const char* src){
	char* copy = dst;
	while (*copy++ = *src++);
	return dst;
}

//模拟实现strlen
int my_strlen(char* src){
	int len = 0;
	while (*src++ != '\0'){
		len++;
	}
	return len;
}

void test2_3(){
	char ret[100] = { 0 };
	char* str = "hahahaha";
	my_strcpy(ret, str);
	printf("%s\n", ret);
	printf("%d\n", my_strlen(str));
}