#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;
//结点（数据和指向下一个结点的指针，其类型为结点指针）
typedef struct SListNode{
	SLDataType _data;
	struct  SListNode* _next;
}SListNode;
//单链表（链表的起点:不是头结点）
typedef struct SList{
	SListNode* _head;
}SList;


void SListInit(SList* plist){
	assert(plist);
	plist->_head = NULL;
}


//当链表的起点存在时就要开始删除(要记录每次删除结点的下一个结点）
void SListDestory(SList* plist){
	assert(plist);
	while (plist->_head){
		SListNode* tNode = plist->_head->_next;
		free(plist->_head);
		plist->_head = tNode;
	}
}


SListNode* BuySListNode(SLDataType x){
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	assert(newNode);
	newNode->_data = x;
	newNode->_next = NULL;
	return newNode;
}

//链表头插（如果当前链表不为空，就把新结点当做链表的起点，
//原链表的起点就变成了链表的第二个结点）
void SListPushFront(SList* plist, SLDataType x){
	assert(plist);
	SListNode* newNode = BuySListNode(x);
	assert(newNode);
	if (plist->_head == NULL){
		plist->_head = newNode;
		return;
	}
	else{
		newNode->_next = plist->_head;
		plist->_head = newNode;
	}

}

void SListPopFront(SList* plist){
	assert(plist);
	SListNode* tNode = plist->_head->_next;
	free(plist->_head);
	plist->_head = tNode;
}

//尾插：无结点
//已经有结点（找到最后一个结点再插入新结点）
void SListPushBack(SList* plist, SLDataType x){
	assert(plist);
	SListNode* newNode = BuySListNode(x);
	assert(newNode);
	if (plist->_head == NULL){
		plist->_head = newNode;
	}
	else{
		SListNode* tail = plist->_head;
		while (tail->_next){
			tail = tail->_next;
		}
		tail->_next = newNode;
	}
}


//尾删：有一个结点；
//有多个结点：要记录倒数第二个结点的位置
void SListPopBack(SList* plist){
	assert(plist->_head);
	SListNode* tail = plist->_head;
	if (tail->_next == NULL){
		free(tail);
		plist->_head = NULL;
	}
	while (tail->_next->_next != NULL){
		tail = tail->_next;
	}
	free(tail->_next);
	tail->_next = NULL;

}


size_t slistSize(SList* plist){
	assert(plist);
	SListNode* cur = plist->_head;
	size_t count = 0;
	while (cur != NULL){
		count++;
		cur = cur->_next;
	}
	return count;
}

//合并两个有序的单链表（要考虑链表为空的情况）
SListNode* mergeTwoSLists(SList* plist1, SList* plist2){
	assert(plist1&& plist2);
   if (plist1->_head == NULL){
		return plist2;
	}
	if (plist2->_head == NULL){
		return plist1;
	}
	SListNode* cur1 = plist1->_head;
	SListNode* cur2 = plist2->_head;
	SListNode* prev = BuySListNode(0);
	SListNode* tail = prev;
	while (cur1!=NULL && cur2!=NULL){
		if (cur1->_data <= cur2->_data){
			tail->_next = cur1;
			tail = tail->_next;
			cur1 = cur1->_next;
		}
		else{
			tail->_next = cur2;
			tail = tail->_next;
			cur2 = cur2->_next;
		}

	}
	if (cur1 == NULL){
		tail->_next = cur2;
	}
	else{
		tail->_next = cur1;
	}
	return prev->_next;
}


//打印的时候，不能直接用plist->_head直接遍历，会改变头指针的位置。
void SListPrint(SList* plist){
	assert(plist);
	SListNode* head = plist->_head;
	while (head->_next != NULL){
		printf("%d->", head->_data);
		head = head->_next;
	}
	printf("%d\n", head->_data);
}

void main(){
	SList psl;
	SList psl2;
	SListInit(&psl);
	SListInit(&psl2);
	//SListDestory(&psl);

	SListPushFront(&psl, 3);
	SListPushFront(&psl, 2);
	SListPushFront(&psl, 1);

	SListPushFront(&psl2, 4);
	SListPushFront(&psl2, 2);
	SListPushFront(&psl2, 1);



	SListPrint(&psl);
	SListPrint(&psl2);

	SListNode* cur = mergeTwoSLists(&psl, &psl2);
	while (cur != NULL){
		printf("%d->", cur->_data);
		cur = cur->_next;
	}


	

	system("pause");
	return 0;
}