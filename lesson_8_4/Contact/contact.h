#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 20
#define SEX_NAME 5
#define TELE_NAME 12
#define ADDR_NAME 30
#define MAX 1000

typedef struct PeoInfo{
	char name[MAX_NAME];
	char sex[SEX_NAME];
	int age;
	char tele[TELE_NAME];
	char addr[ADDR_NAME];
}PeoInfo;


typedef struct Contact{
	PeoInfo data[MAX];
	int sz;
}Contact;

void init_contact(Contact* con);

void add_contact(Contact* con);

//打印通讯录信息，不能修改
void print_contact(const Contact* con);


//按名字进行查找:找到返回其下标，找不到返回-1
int find_by_name(const Contact* con, char name[]);

//以名字为关键字进行删除
void del_contact(Contact* con);

//查找成功，打印该信息
void search_contact(const Contact* con);

//以名字为关键字修改信息
void modify_contact(const Contact* con);