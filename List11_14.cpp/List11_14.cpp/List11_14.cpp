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

void display2(Node *node){
	Node *cur = node->next;
	while (cur != NULL){
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("\n");
}


//����ĺϲ�����������������ϲ���Ϊһ����������
Node *merge_1(LinkedList *list1, LinkedList *list2){
	Node *newhead = new Node();
	Node *p = newhead;

	Node *cur1 = list1->head->next;
	Node *cur2 = list2->head->next;
	while (cur1 != NULL && cur2 != NULL){
		if (cur1->val <= cur2->val){
			p->next = cur1;
			p = cur1;
			cur1 = cur1->next;
		}
		else
		{
			p->next = cur2;
			p = cur2;
			cur2 = cur2->next;
		}
	}
	if (cur1 == NULL){
		cur1 = cur2;
	}
	while (cur1 != NULL){
		p->next = cur1;
		p = cur1;
		cur1 = cur1->next;
	}
	p->next = NULL;
	return newhead;
}


//�������������ϲ���Ϊһ���ݼ�������:ͷ�巨
Node *merge_2(LinkedList *list1, LinkedList *list2){
	Node *newhead = new Node();

	Node *cur1 = list1->head->next;
	Node *cur2 = list2->head->next;

	Node *p = NULL;
	
	while (cur1 != NULL && cur2 != NULL){
		if (cur1->val <= cur2->val){
			p = cur1->next;
			cur1->next = newhead->next;
			newhead->next = cur1;
			cur1 = p;
		}
		else{
			p = cur2->next;
			cur2->next = newhead->next;
			newhead->next = cur2;
			cur2 = p;
		}
	}
	if (cur1 == NULL){
		cur1 = cur2;
	}
	while (cur1 != NULL){
		p = cur1->next;
		cur1->next = newhead->next;
		newhead->next = cur1;
		cur1 = p;
	}
	return newhead;
}


//������������A��B��������������Ľ��������ѽ����������A������
LinkedList *Union(LinkedList *list1, LinkedList *list2){
	Node *cur1 = list1->head->next;
	Node *cur2 = list2->head->next;

	Node *p = list1->head;
	Node *u = NULL;

	while (cur1 != NULL && cur2 != NULL){
		if (cur1->val == cur2->val){
			p->next = cur1;
			p = cur1;
			cur1 = cur1->next;

			//u = cur2;
			cur2 = cur2->next;
			//free(u);
		}
		else if (cur1->val < cur2->val){
			//u = cur1;
			cur1 = cur1->next;
			//free(u);
		}
		else{
			//u = cur2;
			cur2 = cur2->next;
			//free(u);
		}
	}
	/*
	while (cur1 != NULL){
		u = cur1;
		cur1 = cur1->next;
		free(u);
	}
	while (cur2 != NULL){
		u = cur2;
		cur2 = cur2->next;
		free(u);
	}
	*/
	p->next = NULL;
	//free(list2->head);
	return list1;
	
}

int main(){
	LinkedList list1;
	InitList(&list1);
	AddFirst(&list1, 8);
	AddFirst(&list1, 7);
	AddFirst(&list1, 6);
	AddFirst(&list1, 4);
	AddFirst(&list1, 2);
	AddFirst(&list1, 1);
	display(&list1);

	LinkedList list2;
	InitList(&list2);
	AddFirst(&list2, 9);
	AddFirst(&list2, 6);
	AddFirst(&list2, 5);
	AddFirst(&list2, 4);
	AddFirst(&list2, 2);
	AddFirst(&list2, 0);
	display(&list2);
	
	//Node *head = merge_1(&list1, &list2);
	//display2(head);

	//Node *head = merge_2(&list1, &list2);
	//display2(head);

	LinkedList *list = Union(&list1, &list2);
	display(list);
	
	system("pause");
	return 0;
}