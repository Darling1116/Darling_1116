#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stack>
using namespace std;

//定义结点Node
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


//定义链表LinkedList
typedef struct LinkedList{
	Node* head;
	//初始时，链表只有一个头结点(不含元素的值)
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


//初始化链表
void InitList(LinkedList *list){
	list->head->next = NULL; 
	//初始时，把头结点的next置为空(也可以根据情况，把list->head置为空)
}


//头插法
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


//判断是否是回文结构：利用栈
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
		st.pop(); //取栈顶元素的值，同时删除栈顶元素
		if (data != q->val){
			return false;
		}
		q = q->next;
	}
	return true;
}


//链表逆置:头插法
Node* Reverse_1(LinkedList *list){
	Node *cur = list->head->next; //记录第一个结点的值
	list->head->next = NULL;
	while (cur != NULL){
		Node *p = cur->next;
		cur->next = list->head->next;
		list->head->next = cur;
		cur = p;
	}
	return list->head;
}


//链表逆置:三指针法
Node* Reverse_2(LinkedList *list){
	Node *cur = list->head->next;
	Node *prev = NULL;
	Node *newhead = list->head;
	while (cur != NULL){
		Node *p = cur->next;
		if (cur->next == NULL){
			newhead->next = cur; //只有一个结点，该结点就是新的头结点
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

	//函数返回true时，这里输出1；函数返回false时，这里输出0
	printf("%d\n", IsChkPalindrome(&list));

	Reverse_1(&list);
	display(&list);

	Reverse_2(&list);
	display(&list);
	system("pause");
	return 0;
}