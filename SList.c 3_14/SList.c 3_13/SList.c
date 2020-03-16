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
void SListPushBack(SList* plist,SLDataType x){
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
	while (tail->_next->_next!=NULL){
		tail = tail->_next;
	}
	free(tail->_next);
	tail->_next = NULL;

}

SListNode* SListFind(SList* plist, SLDataType x){
	    assert(plist);
		SListNode* tNode = plist->_head;
		while (tNode != NULL){
			if (tNode->_data != x){
				tNode = tNode->_next;
			}
			else{
				return tNode;
			}
		}
		return -1;
		
}

//在pos的后面插入结点(pos位置不存在；pos在头上；pos在后边)
void SListInsertAfter(SList*plist,SListNode* pos, SLDataType x){
	assert(plist);
	SListNode* newNode = BuySListNode(x);
	assert(newNode);
	if (pos == -1){
		return - 1;
	}
	else if (pos == plist->_head){
		SListPushFront(plist,x);
	}
	else{
		SListNode* tNode = plist->_head->_next;
		while (tNode != pos){
			tNode = tNode->_next;
		}
		tNode = pos->_next;
		pos->_next = newNode;
		newNode->_next = tNode;
	}
}

//在pos的后面删除结点
void SListEraseAfter(SList*plist, SListNode* pos){
	assert(plist);
	if (pos == -1){
		return -1;
	}
	else if (pos == plist->_head){
		SListPopFront(plist);
	}
	else{
		SListNode* tNode = plist->_head->_next;
		while (tNode != pos){
			tNode = tNode->_next;
		}
		SListNode* cur = tNode->_next;
		SListNode* tail = tNode->_next->_next;
		free(cur);
		tNode->_next = tail;
	}
}

//删除链表中的值为X的元素
void SListRemove(SList* plist, SLDataType x){
	assert(plist);
	SListNode* bNode = plist->_head;
	if (bNode->_data == x){
		SListNode* cur = bNode;
		free(bNode);
		cur->_next = plist->_head;
		return;
	}
	else{
		SListNode* tNode = plist->_head->_next;
		while (tNode->_data != x){
			bNode = bNode->_next;
			tNode = tNode->_next;
		}
		SListNode* eNode = tNode->_next;
		free(tNode);
		bNode->_next = eNode;
	}
}

//删除链表中值为val的所有元素
SListNode*  removeElements(SList* plist, int val) {
//利用三个指针结点，遍历链表（对于满足条件的值<是否为头？>；对于不满足条件的值）
	/*SListNode* prev = NULL;
	SListNode* cur = plist->_head;
	SListNode* tail = NULL;
	while (cur != NULL){
		if (cur->_data == val){
			tail = cur->_next;
			free(cur);
			cur = tail;
			if (prev == NULL){
				plist->_head = tail;
			}
			else{
				prev->_next = tail;
			}
		}
		else{
			prev = cur;
			cur = cur->_next;
		}
	}
	return plist->_head;
	*/

	SListNode* head = plist->_head;
	if (head == NULL){
		return NULL;
	}
	while (head->_data==val && head!=NULL)
	{
		SListNode* tnode = head;
		head = head->_next;
		free(tnode);
	}
	SListNode* cur = head->_next;
	SListNode* prev = head;
	while (cur != NULL){
		if (cur->_data == val){
			SListNode* tail = cur->_next;
			free(cur);
			prev->_next = tail;
			cur = tail;
		}
		else{
			prev = cur;
			cur = cur->_next;
		}
	}
	return plist->_head;
}


void SListPrint(SList* plist){
	assert(plist);
	while (plist->_head){
		printf("%d->", plist->_head->_data);
		plist->_head = plist->_head->_next;
	}
}

void main(){
	SList psl;
	SListInit(&psl);
	//SListDestory(&psl);

	SListPushFront(&psl, 1);
	SListPushFront(&psl, 2);
	SListPushFront(&psl, 3);
	SListPushFront(&psl, 2);
	SListPushFront(&psl, 5);
	SListPushFront(&psl, 6);
	SListPopFront(&psl);

	SList* s = removeElements(&psl, 2);
	SListPrint(&s);

	//BuySListNode(&psl, 1);
	/*
	SListPushBack(&psl, 6);
	SListPopBack(&psl);

	SListNode* pos = SListFind(&psl, 32);
	SListInsertAfter(&psl,pos,12);
	SListEraseAfter(&psl, pos);
    
	SListRemove(&psl, 1);
	*/

	SListPrint(&psl);
	system("pause");
	return 0;
}