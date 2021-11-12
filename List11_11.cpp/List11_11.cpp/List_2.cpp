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

//ɾ����һ�γ���keyֵ�Ľ�㣺����ǰ�����
Node *Remove(LinkedList *list, int key){
	if (list->head->next == NULL){ //ֻ��ͷ���
		return list->head;
	}
	if (list->head->next->val == key){ //��һ������ֵΪkey
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


//ɾ������ֵΪkey�Ľ�㣺����ǰ�����
Node *RemoveAll(LinkedList *list, int key){
	if (list->head->next == NULL){ //ֻ��ͷ���
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
	if (list->head->next->val == key){ //��һ����ֵ���Ϊkey,��ͷ����nextָ����һ�����
		list->head->next = list->head->next->next;
	}
	return list->head;
}


//���м��㣺����ָ��ķ���
Node *MiddleNode(LinkedList *list){
	Node *fast = list->head->next;
	Node *slow = list->head->next;
	while (fast != NULL && fast->next != NULL){
		fast = fast->next->next;
		slow = slow->next;
	}
	return slow;
}


//�ҵ�����k����㣺�ÿ�ָ������k-1����Ȼ�����ָ��һ����
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




//����ָ��һ��ֵkey��������С�ڵ���x�Ľ������������֮ǰ��
//�Ҳ��ܸı�ԭ��������˳��Ȼ�󷵻��������к������
Node *PartitionList(LinkedList *list, int key){
	//�����list->head�������Ϊ���ǽ���NULL
	//��Ϊ���Ƕ����list->head��ͷ��㣬�ý�㲻��ֵ����ʵ������
	Node *a1 = NULL;
	Node *a2 = NULL;
	Node *b1 = NULL;
	Node *b2 = NULL;

	Node *cur = list->head->next;
	while (cur != NULL){  //�ӵ�һ����ֵ��㿪ʼ����
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

	//��ʼ����������A��B�����������
	if (a1 == NULL){
		//A��B��
		if (b1 == NULL){
			return NULL;
		}
		//A��B�ǿ�
		b2->next = NULL;
		return b1;
	}
	else{
		//A�ǿ�B��
		if (b1 == NULL){
			a2->next = NULL;
			return a1;
		}
		//A�ǿ�B�ǿգ���β���
		b2->next = NULL;
		a2->next = b1;
		return a1;
	}
}

void display2(Node *node){ //ֻ�������ָ�Ĵ�ӡ
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

	//��������trueʱ���������1����������falseʱ���������0
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