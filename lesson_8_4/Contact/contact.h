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

//��ӡͨѶ¼��Ϣ�������޸�
void print_contact(const Contact* con);


//�����ֽ��в���:�ҵ��������±꣬�Ҳ�������-1
int find_by_name(const Contact* con, char name[]);

//������Ϊ�ؼ��ֽ���ɾ��
void del_contact(Contact* con);

//���ҳɹ�����ӡ����Ϣ
void search_contact(const Contact* con);

//������Ϊ�ؼ����޸���Ϣ
void modify_contact(const Contact* con);