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

//删除第一次出现key值的结点：先找前驱结点
Node *Remove(LinkedList *list, int key){
	if (list->head->next == NULL){ //只有头结点
		return list->head;
	}
	if (list->head->next->val == key){ //第一个结点的值为key
		list->head->next = list->head->next->next;
		return list->head;
	}

	Node *cur = list->head->next;
	Node *prev = NULL;
	while (cur->val != key){
		prev = cur;
		cur = cur->next;
	}
	prev->next = cur->next;
	return list->head;
}


//删除所有值为key的结点：先找前驱结点
Node *RemoveAll(LinkedList *list, int key){
	if (list->head->next == NULL){ //只有头结点
		return list->head;
	}

	Node *cur = list->head->next;
	Node *prev = list->head;
	while (cur != NULL){
		if (cur->val == key){
			cur = cur->next;
			prev->next = cur;
		}
		else{
			prev = cur;
			cur = cur->next;
		}
	}
	if (list->head->next->val == key){ //第一个带值结点为key,另头结点的next指向下一个结点
		list->head->next = list->head->next->next;
	}
	return list->head;
}


//找中间结点：快慢指针的方法
Node *MiddleNode(LinkedList *list){
	Node *fast = list->head->next;
	Node *slow = list->head->next;
	while (fast != NULL && fast->next != NULL){
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}


//找倒数第k个结点：让快指针先走k-1步，然后快慢指针一起走
Node *LastKthNode(LinkedList *list, int k){
	Node *fast = list->head;
	Node *slow = list->head;
	while (k>1){
		fast = fast->next;
		k--;
	}
	while (fast->next != NULL){
		fast = fast->next;
		slow = slow->next;
	}
	return slow;

}


void display(LinkedList *list){
	Node *cur = list->head->next;
	while (cur != NULL){
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("\n");
}




//链表分割：给一定值key，将所有小于等于x的结点排在其余结点之前，
//且不能改变原来的数据顺序，然后返回重新排列后的链表。
Node *PartitionList(LinkedList *list, int key){
	//这里的list->head可以理解为我们讲的NULL
	//因为我们定义的list->head是头结点，该结点不带值，无实际意义
	Node *a1 = NULL;
	Node *a2 = NULL;
	Node *b1 = NULL;
	Node *b2 = NULL;

	Node *cur = list->head->next;
	while (cur != NULL){  //从第一个带值结点开始遍历
		if (cur->val <= key){
			if (a1 == NULL){
				a1 = cur;
				a2 = cur;
			}
			else{
				a2->next = cur;
				a2 = cur;
			}
		}
		else{
			if (b1 == NULL){
				b1 = cur;
				b2 = cur;
			}
			else{
				b2->next = cur;
				b2 = cur;
			}
		}
		cur = cur->next;
	}

	//开始连接两个表A和B，有四种情况
	if (a1 == NULL){
		//A空B空
		if (b1 == NULL){
			return NULL;
		}
		//A空B非空
		b2->next = NULL;
		return b1;
	}
	else{
		//A非空B空
		if (b1 == NULL){
			a2->next = NULL;
			return a1;
		}
		//A非空B非空：首尾相接
		b2->next = NULL;
		a2->next = b1;
		return a1;
	}
}

void display2(Node *node){ //只针对链表分割的打印
	Node *cur = node;
	while (cur != NULL){
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("\n");
}






int main(){
	LinkedList list;
	InitList(&list);

	AddFirst(&list, 5);
	AddFirst(&list, 2);
	AddFirst(&list, 3);
	AddFirst(&list, 4);
	AddFirst(&list, 2);
	AddFirst(&list, 6);
	display(&list);

	//函数返回true时，这里输出1；函数返回false时，这里输出0
	//printf("%d\n", IsChkPalindrome(&list));

	//Reverse_1(&list);
	//display(&list);

	//Reverse_2(&list);
	//display(&list);

	//Remove(&list, 4);
	//display(&list);

	//RemoveAll(&list, 6);
	//display(&list);

	//printf("%d\n", MiddleNode(&list)->val);

	//printf("%d\n", LastKthNode(&list, 3)->val);

    display2(PartitionList(&list, 3));

	system("pause");
	return 0;
}