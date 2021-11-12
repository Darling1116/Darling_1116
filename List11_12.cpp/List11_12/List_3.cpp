#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stack>
#include <math.h>
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


void InitList(LinkedList *list){
	list->head->next = NULL;
	//初始时，把头结点的next置为空(也可以根据情况，把list->head置为空)
}

//头插法
void addFirst(LinkedList *list, int data){
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



//查找关键字key是否在单链表中
bool contains(LinkedList *list, int key){
	Node *cur = list->head->next;
	while (cur != NULL){
		if (cur->val == key){
			return true;
		}
		cur = cur->next;
	}
	return false;
}


//任意位置插入
void addIndex(LinkedList *list, int index, int data){
	Node *newnode = new Node(data);
	if (index == 1){
		newnode->next = list->head->next;
		list->head->next = newnode;
	}
	else
	{
		Node *cur = list->head->next; //从第一个结点开始找位置
		Node *prev = list->head;
		while (index > 1){
			index--;
			prev = cur;
			cur = cur->next;
		}
		newnode->next = cur;
		prev->next = newnode;
	}

}


//删除有序链表中的重复元素:重复结点只保留一个
Node *deleteDuplicates(LinkedList* list) {
	if (list->head->next == NULL) //链表为空
		return list->head;
	if (list->head->next->next == NULL) //只有一个结点
		return list->head;

	Node *cur = list->head->next;
	while (cur != NULL && cur->next != NULL){
		Node *p = cur->next;
		if (cur->val == p->val){
			cur->next = p->next;
		}
		else{
			cur = cur->next;
		}
	}
	return list->head;
}


//删除链表中的重复结点：重复结点不保留
Node *deleteDuplication(LinkedList* list) {
	if (list->head->next == NULL)
		return list->head;
	if (list->head->next->next == NULL)
		return list->head;

	Node *newhead = new Node(); //新设置一个头结点
	Node *p = newhead; //用p来进行新链表的尾插
	Node *cur = list->head->next;
	while (cur != NULL){
		if (cur->next != NULL && cur->val == cur->next->val){
			while (cur != NULL &&cur->next != NULL && cur->val == cur->next->val){
				cur = cur->next;
			}
			cur = cur->next; //不保留重复元素
		}
		else{
			Node *q = cur->next;
			p->next = cur;
			p = cur;
			cur = q;
		}
	}
	p->next = NULL;
	return newhead;

}


//判断是否有环：如果有环，快慢指针一定会相遇
bool hasCycle(LinkedList *list) {
	if (list->head->next == NULL)
		return false;
	Node *fast = list->head->next;
	Node *slow = list->head->next;
	//用fast来控制链表的遍历：如果没有环，fast势必会有为空的时候
	while (fast != NULL && slow != NULL){
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			return true;
	}
	return false;
}



//判断链表是否有环，并返回入环的第一个结点
Node *detectCycle(LinkedList *list) {
	if (list->head->next == NULL)
		return NULL;

	Node *fast = list->head->next;
	Node *slow = list->head->next;

	while (fast != NULL && slow != NULL){
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow){ //快慢指针相遇了，有环
			//然后让一个指针从头开始走，另一个指针从相遇点开始走
			//两指针相遇的地方，就是环的入口
			Node *p = list->head->next;
			while (p != slow){
				p = p->next;
				slow = slow->next;
			}
			return p;
		}		
	}
	return NULL;
}


//给定两个单链表的头节点 headA 和 headB,找出并返回两个单链表相交的起始节点
//如果两个链表没有交点，返回 null 
Node *getIntersectionNode(Node *headA, Node *headB) {
	if (headA == NULL || headB == NULL)
		return NULL;

	Node *pA = headA;
	Node *pB = headB;
	int lenA = 0;
	int lenB = 0;
	while (pA != NULL){
		lenA++;
		pA = pA->next;
	}
	while (pB != NULL){
		lenB++;
		pB = pB->next;
	}

	int k = abs(lenA - lenB);
	//让curA指向较长的链表
	Node *curA = headA;
	Node *curB = headB;
	if (lenB > lenA){
		curA = headB;
		curB = headA;
	}
	
	//让较长的链表先走k步
	while (k != 0){
		k--;
		curA = curA->next;
	}
	while (curA != curB && curA != NULL && curB != NULL){
		curA = curA->next;
		curB = curB->next;
	}
	if (curA == curB){
		return curA;
	}
	else{
		return NULL;
	}
}



int main(){
	LinkedList list;
	InitList(&list);

	addFirst(&list, 1);
	addFirst(&list, 2);
	addFirst(&list, 2);
	addFirst(&list, 4);
	addFirst(&list, 4);
	addFirst(&list, 6);
	display(&list);

	//printf("%d\n", contains(&list, 9));

	addIndex(&list, 7, 10);
	display(&list);

	//deleteDuplicates(&list);
	deleteDuplication(&list);
	display(&list);

	system("pause");
	return 0;
}