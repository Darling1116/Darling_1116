#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stack>
using namespace std;

//������Node
typedef struct Node{
	int val;
	struct Node* next;
	//���캯��
	Node(){
		val = NULL;
		next = NULL;
	}
	Node(int data){
		val = data;
		next = NULL;
	}
}Node;

//��������LinkedList
typedef struct LinkedList{
	Node* head;
	//��ʼʱ������ֻ��һ��ͷ���(����Ԫ�ص�ֵ)
	LinkedList(){
		head = new Node();
	}
}LinkedList;

//��ʼ������
void InitList(LinkedList *list){
	list->head->next = NULL;
	//��ʼʱ����ͷ����next��Ϊ��(Ҳ���Ը����������list->head��Ϊ��)
}

//ͷ�巨
void AddFirst(LinkedList *list, int data){
	//Node *newnode = NewNode(data);
	Node *newnode = new Node(data);
	if (list->head->next == NULL){
		list->head->next = newnode;
	}
	else{
		newnode->next = list->head->next;
		list->head->next = newnode;
	}
}

void display(LinkedList *list){
	Node *cur = list->head->next;
	while (cur != NULL){
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("\n");
}


void SelectSort(LinkedList *list){
	Node *cur = list->head->next;
	Node *p = NULL;
	Node *q = NULL;
	if (cur == NULL){
		return;
	}
	int min;
	while (cur != NULL){
		p = cur->next;
		q = cur->next;
		min = cur->val;
		while(p != NULL){
			if (p->val < min){
				min = p->val;
				q = p;
			}
			p = p->next;
		}
		if (cur->val != min){ //swap����
			int tmp = q->val;
			q->val = cur->val;
			cur->val = tmp;
		}
		cur = cur->next;
	}
}

int main(){
	LinkedList list1;
	InitList(&list1);
	AddFirst(&list1, 8);
	AddFirst(&list1, 2);
	AddFirst(&list1, 6);
	AddFirst(&list1, 4);
	AddFirst(&list1, 9);
	AddFirst(&list1, 1);
	display(&list1);

	SelectSort(&list1);
	display(&list1);

	system("pause");
	return 0;
}
