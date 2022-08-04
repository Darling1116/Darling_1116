#include "contact.h"

void init_contact(Contact* con){
	//使用memset初始化通讯录
	memset(con->data, 0, sizeof(con->data));
	con->sz = 0;
}

void add_contact(Contact* con){
	if (con->sz == MAX){
		printf("通讯录已满！\n");
		return;
	}
	
	printf("请输入姓名:> ");
	scanf("%s", &con->data[con->sz].name);
	printf("请输入性别:> ");
	scanf("%s", &con->data[con->sz].sex);
	printf("请输入年龄:> ");
	scanf("%d", &con->data[con->sz].age);
	printf("请输入电话:> ");
	scanf("%s", &con->data[con->sz].tele);
	printf("请输入地址:> ");
	scanf("%s", &con->data[con->sz].addr);

	con->sz++;
	printf("添加成功...\n");
}

void print_contact(const Contact* con){
	printf("%-20s%-8s%-8s%-15s%-30s\n", "姓名", "性别", "年龄", "电话", "地址");
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
		printf("通讯录为空！\n");
		return;
	}
	printf("请输入要删除信息的姓名:>");
	char name[20] = { 0 };
	scanf("%s", &name);
	int pos = find_by_name(con, name);
	if (pos == -1){
		printf("通讯录中没有此人信息，无法删除！\n");
	}
	else{
		for (int i = pos + 1; i < con->sz; i++){
			con->data[i - 1] = con->data[i];
		}
		con->sz--;
	}
}


void search_contact(const Contact* con){
	printf("请输入要删除信息的姓名:>");
	char name[20] = { 0 };
	scanf("%s", &name);

	int pos = find_by_name(con, name);
	if (pos == -1){
		printf("通讯录中没有此人信息！\n");
	}
	else{
		printf("%-20s%-8s%-8s%-15s%-30s\n", "姓名", "性别", "年龄", "电话", "地址");
		printf("%-20s%-8s%-8d%-15s%-30s\n",
			con->data[pos].name,
			con->data[pos].sex,
			con->data[pos].age,
			con->data[pos].tele,
			con->data[pos].addr);
	}
}


void modify_contact(const Contact* con){
	printf("请输入要修改信息的姓名:>");
	char name[20] = { 0 };
	scanf("%s", &name);

	int pos = find_by_name(con, name);
	if (pos == -1){
		printf("通讯录中没有此人信息！\n");
	}
	else{
		printf("修改电话号码为:>");
		scanf("%s", &con->data[pos].tele);
		printf("修改家庭住址为:>");
		scanf("%s", &con->data[pos].addr);
		printf("修改成功！\n");
	}
}
