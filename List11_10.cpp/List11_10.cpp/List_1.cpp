#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stack>
using namespace std;

//������Node
typedef struct Node{
	int val;
	struct Node* next;


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



/*
Node* NewNode(int data){
	Node* newnode = (Node*)malloc(sizeof(Node));
	assert(newnode);
	newnode->val = data;
	newnode->next = NULL;
	return newnode;
}
*/


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


//�ж��Ƿ��ǻ��Ľṹ������ջ
bool IsChkPalindrome(LinkedList *list){
	stack<int> st;
	Node *p = list->head->next;
	while (p != NULL){
		st.push(p->val);
		p = p->next;
	}
	
	Node *q = list->head->next;
	int data;
	while (!st.empty()){
		data = st.top();
		st.pop(); //ȡջ��Ԫ�ص�ֵ��ͬʱɾ��ջ��Ԫ��
		if (data != q->val){
			return false;
		}
		q = q->next;
	}
	return true;
}


//��������:ͷ�巨
Node* Reverse_1(LinkedList *list){
	Node *cur = list->head->next; //��¼��һ������ֵ
	list->head->next = NULL;
	while (cur != NULL){
		Node *p = cur->next;
		cur->next = list->head->next;
		list->head->next = cur;
		cur = p;
	}
	return list->head;
}


//��������:��ָ�뷨
Node* Reverse_2(LinkedList *list){
	Node *cur = list->head->next;
	Node *prev = NULL;
	Node *newhead = list->head;
	while (cur != NULL){
		Node *p = cur->next;
		if (cur->next == NULL){
			newhead->next = cur; //ֻ��һ����㣬�ý������µ�ͷ���
		}
		cur->next = prev;
		prev = cur;
		cur = p;
	}
	return newhead;
}


void display(LinkedList *list){
	Node *cur = list->head->next;
	while (cur != NULL){
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("\n");
}


int main(){
	LinkedList list;
	InitList(&list);

	AddFirst(&list, 1);
	AddFirst(&list, 2);
	AddFirst(&list, 3);
	AddFirst(&list, 4);
	AddFirst(&list, 5);
	AddFirst(&list, 6);
	display(&list);

	//��������trueʱ���������1����������falseʱ���������0
	printf("%d\n", IsChkPalindrome(&list));

	Reverse_1(&list);
	display(&list);

	Reverse_2(&list);
	display(&list);
	system("pause");
	return 0;
}