#include "contact.h"

void init_contact(Contact* con){
	//ʹ��memset��ʼ��ͨѶ¼
	memset(con->data, 0, sizeof(con->data));
	con->sz = 0;
}

void add_contact(Contact* con){
	if (con->sz == MAX){
		printf("ͨѶ¼������\n");
		return;
	}
	
	printf("����������:> ");
	scanf("%s", &con->data[con->sz].name);
	printf("�������Ա�:> ");
	scanf("%s", &con->data[con->sz].sex);
	printf("����������:> ");
	scanf("%d", &con->data[con->sz].age);
	printf("������绰:> ");
	scanf("%s", &con->data[con->sz].tele);
	printf("�������ַ:> ");
	scanf("%s", &con->data[con->sz].addr);

	con->sz++;
	printf("��ӳɹ�...\n");
}

void print_contact(const Contact* con){
	printf("%-20s%-8s%-8s%-15s%-30s\n", "����", "�Ա�", "����", "�绰", "��ַ");
	for (int i = 0; i < con->sz; i++){
		printf("%-20s%-8s%-8d%-15s%-30s\n",
			con->data[i].name,
			con->data[i].sex,
			con->data[i].age,
			con->data[i].tele,
			con->data[i].addr);
	}
}


int find_by_name(const Contact* con, char name[]){
	if (con->sz == 0)
		return -1;
	for (int i = 0; i < con->sz; i++){
		if (strcmp(con->data[i].name, name) == 0){
			return i;
		}
	}
	return -1;
}

void del_contact(Contact* con){
	if (con->sz == 0){
		printf("ͨѶ¼Ϊ�գ�\n");
		return;
	}
	printf("������Ҫɾ����Ϣ������:>");
	char name[20] = { 0 };
	scanf("%s", &name);
	int pos = find_by_name(con, name);
	if (pos == -1){
		printf("ͨѶ¼��û�д�����Ϣ���޷�ɾ����\n");
	}
	else{
		for (int i = pos + 1; i < con->sz; i++){
			con->data[i - 1] = con->data[i];
		}
		con->sz--;
	}
}


void search_contact(const Contact* con){
	printf("������Ҫɾ����Ϣ������:>");
	char name[20] = { 0 };
	scanf("%s", &name);

	int pos = find_by_name(con, name);
	if (pos == -1){
		printf("ͨѶ¼��û�д�����Ϣ��\n");
	}
	else{
		printf("%-20s%-8s%-8s%-15s%-30s\n", "����", "�Ա�", "����", "�绰", "��ַ");
		printf("%-20s%-8s%-8d%-15s%-30s\n",
			con->data[pos].name,
			con->data[pos].sex,
			con->data[pos].age,
			con->data[pos].tele,
			con->data[pos].addr);
	}
}


void modify_contact(const Contact* con){
	printf("������Ҫ�޸���Ϣ������:>");
	char name[20] = { 0 };
	scanf("%s", &name);

	int pos = find_by_name(con, name);
	if (pos == -1){
		printf("ͨѶ¼��û�д�����Ϣ��\n");
	}
	else{
		printf("�޸ĵ绰����Ϊ:>");
		scanf("%s", &con->data[pos].tele);
		printf("�޸ļ�ͥסַΪ:>");
		scanf("%s", &con->data[pos].addr);
		printf("�޸ĳɹ���\n");
	}
}
