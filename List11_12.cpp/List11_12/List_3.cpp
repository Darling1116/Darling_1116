#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stack>
#include <math.h>
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


void InitList(LinkedList *list){
	list->head->next = NULL;
	//��ʼʱ����ͷ����next��Ϊ��(Ҳ���Ը����������list->head��Ϊ��)
}

//ͷ�巨
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



//���ҹؼ���key�Ƿ��ڵ�������
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


//����λ�ò���
void addIndex(LinkedList *list, int index, int data){
	Node *newnode = new Node(data);
	if (index == 1){
		newnode->next = list->head->next;
		list->head->next = newnode;
	}
	else
	{
		Node *cur = list->head->next; //�ӵ�һ����㿪ʼ��λ��
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


//ɾ�����������е��ظ�Ԫ��:�ظ����ֻ����һ��
Node *deleteDuplicates(LinkedList* list) {
	if (list->head->next == NULL) //����Ϊ��
		return list->head;
	if (list->head->next->next == NULL) //ֻ��һ�����
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


//ɾ�������е��ظ���㣺�ظ���㲻����
Node *deleteDuplication(LinkedList* list) {
	if (list->head->next == NULL)
		return list->head;
	if (list->head->next->next == NULL)
		return list->head;

	Node *newhead = new Node(); //������һ��ͷ���
	Node *p = newhead; //��p�������������β��
	Node *cur = list->head->next;
	while (cur != NULL){
		if (cur->next != NULL && cur->val == cur->next->val){
			while (cur != NULL &&cur->next != NULL && cur->val == cur->next->val){
				cur = cur->next;
			}
			cur = cur->next; //�������ظ�Ԫ��
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


//�ж��Ƿ��л�������л�������ָ��һ��������
bool hasCycle(LinkedList *list) {
	if (list->head->next == NULL)
		return false;
	Node *fast = list->head->next;
	Node *slow = list->head->next;
	//��fast����������ı��������û�л���fast�Ʊػ���Ϊ�յ�ʱ��
	while (fast != NULL && slow != NULL){
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			return true;
	}
	return false;
}



//�ж������Ƿ��л����������뻷�ĵ�һ�����
Node *detectCycle(LinkedList *list) {
	if (list->head->next == NULL)
		return NULL;

	Node *fast = list->head->next;
	Node *slow = list->head->next;

	while (fast != NULL && slow != NULL){
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow){ //����ָ�������ˣ��л�
			//Ȼ����һ��ָ���ͷ��ʼ�ߣ���һ��ָ��������㿪ʼ��
			//��ָ�������ĵط������ǻ������
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


//���������������ͷ�ڵ� headA �� headB,�ҳ������������������ཻ����ʼ�ڵ�
//�����������û�н��㣬���� null 
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
	//��curAָ��ϳ�������
	Node *curA = headA;
	Node *curB = headB;
	if (lenB > lenA){
		curA = headB;
		curB = headA;
	}
	
	//�ýϳ�����������k��
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