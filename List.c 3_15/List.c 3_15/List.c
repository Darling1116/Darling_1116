#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LTDataType;

typedef struct ListNode{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;

typedef struct List{
	ListNode* _head;
}List;

//带头的链表的头结点占用空间
void ListInit(List* plist){
	assert(plist);
	plist->_head = malloc(sizeof(ListNode));
	plist->_head->_data = 0;
	plist->_head->_prev = plist->_head;
	plist->_head->_next = plist->_head;
}

//销毁链表（连头结点一起销毁）
void ListDestory(List* plist){
	assert(plist->_head);
	ListNode* cur = plist->_head;
	ListNode* eNode = plist->_head->_prev;
	ListNode* tNode = NULL;
	while (cur != eNode){
		tNode = cur->_next;
		free(cur);
		cur = tNode;
	}
	free(eNode);
	eNode = NULL;
	plist->_head = NULL;
}

//新建一个结点，一定会有返回类型
ListNode* BuyNode(LTDataType x){
	ListNode* newNode = malloc(sizeof(ListNode));
	assert(newNode);
	newNode->_data = x;
	newNode->_next = NULL;
	newNode->_prev = NULL;
	return newNode;
}


void ListPushBack(List* plist, LTDataType x){
	assert(plist->_head);
	ListNode* eNode = plist->_head->_prev;
	ListNode* newNode = BuyNode(x);
	assert(newNode);
	eNode->_next = newNode;
	newNode->_prev = eNode;
	newNode->_next = plist->_head;
	plist->_head->_prev = newNode;
}


void ListPopBack(List* plist){
	assert(plist->_head);
	if (plist->_head->_next == plist->_head){
		return;
	}
	else{
		ListNode* eNode = plist->_head->_prev->_prev;
		free(plist->_head->_prev);
		eNode->_next = plist->_head;
		plist->_head->_prev = eNode;
	}
}

void ListPushFront(List* plist, LTDataType x){
	assert(plist->_head);
	ListNode* newNode = BuyNode(x);
	assert(newNode);
	ListNode* tNode = plist->_head->_next;
	plist->_head->_next = newNode;
	newNode->_prev = plist->_head;
	newNode->_next = tNode;
	tNode->_prev = newNode;
}

void ListPopFront(List* plist){
	assert(plist->_head);
	if (plist->_head->_next == plist->_head){
		return;
	}
	else{
		ListNode* tNode = plist->_head->_next->_next;
		free(plist->_head->_next);
		plist->_head->_next = tNode;
		tNode->_prev = plist->_head;
	}
}

ListNode* ListFind(List* plist, LTDataType x){
	assert(plist->_head);
	ListNode* tNode = plist->_head;
	if (tNode->_next == plist->_head){
		return -1;
	}
	while (tNode->_next != plist->_head){
		if (tNode->_data == x){
			return tNode;
		}
		else{
			tNode = tNode->_next;
		}
	}
	return -1;
}

//在pos的前面插入结点
void ListInsert(List* plist,ListNode* pos, LTDataType x){
	assert(plist->_head);
	if (pos == -1){
		return -1;
	}
	ListNode* bNode = pos->_prev;
	ListNode* newNode = BuyNode(x);
	assert(newNode);
	bNode->_next = newNode;
	newNode->_prev = bNode;
	newNode->_next = pos;
	pos->_prev = newNode;
}

//删除pos位置的结点(pos位置不存在)
void ListErase(List* plist, ListNode* pos){
	assert(plist->_head);
	if (pos == -1){
		return -1;
	}
	ListNode* bNode = pos->_prev;
	ListNode* eNode = pos->_next;
	free(pos);
	bNode->_next = eNode;
	eNode->_prev = bNode;
}

void ListRemove(List* plist, LTDataType x){
		assert(plist->_head);
		ListNode* tNode = plist->_head->_next;
		while (tNode != plist->_head){
			if (tNode->_data == x){
				ListNode* bNode = tNode->_prev;
				ListNode* eNode = tNode->_next;
				free(tNode);
				bNode->_next = eNode;
				eNode->_prev = bNode;
				return;
			}
			else{
				tNode = tNode->_next;
			}
	}
}

void ListPrint(List* plist){
	assert(plist->_head);
	ListNode* tNode = plist->_head;
	while (tNode->_next != plist->_head){
		printf("%d<=>", tNode->_data);
		tNode = tNode->_next;
	}
	printf("%d<=>", tNode->_data);
	printf("\n");
}

int main(){

	List psl;
	ListInit(&psl);
	ListDestory(&psl);
	/*
	ListPushBack(&psl, 1);
	ListPushBack(&psl, 2);
	ListPushBack(&psl, 3);
	ListPushBack(&psl, 4);
	ListPushBack(&psl, 5);
	ListPopBack(&psl);

	ListPushFront(&psl, 11);
	ListPushFront(&psl, 22);
	ListPushFront(&psl, 33);
	ListPopFront(&psl);

	ListNode* pos = ListFind(&psl, 11);
	ListInsert(&psl, pos, 666);
	ListErase(&psl, pos);

	//ListRemove(&psl, 666);

	ListPrint(&psl);
	*/
	system("pause");
	return 0;
}