#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stack>
using namespace std;

//定义结点Node
typedef struct Node{
	int val;
	struct Node* next;
	//构造函数
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
		if (cur->val != min){ //swap函数
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
