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


//分割链表(此时用buynode后，s11、s22后面就不用把next置空，
//因为buynode函数里已经包含了)
SListNode* partition(SList* plist, int x){
	assert(plist);
	if (plist->_head == NULL || plist->_head->_next == NULL){
		return plist->_head;
	}
	SListNode* cur = plist->_head;
	SListNode* s1 = BuySListNode(0);
	SListNode* s2 = BuySListNode(0);
	SListNode* s11 = s1;
	SListNode* s22 = s2;
	while (cur != NULL){
		if (cur->_data < x){
			s1->_next = cur;
			s1 = s1->_next;
		}
		else{
			s2->_next = cur;
			s2 = s2->_next;
		}
		cur = cur->_next;
	}
	s1->_next = s22->_next;
	return s11->_next;
}

//给定一个排序列表，删除链表里重复的结点,只保留一个
SListNode* deleteDuplicate(SList* plist){
	assert(plist);
	SListNode* cur = plist->_head;
	SListNode* tail = plist->_head->_next;
	SListNode* s = BuySListNode(0);
	SListNode* s1 = s;
	while (tail != NULL){
		if (cur->_data != tail->_data){
			s1->_next = cur;
			s1 = s1->_next;	
		}
		cur = tail;
		tail = tail->_next;
	}
	return s->_next;
}


//给定一个排序列表，删除链表里重复的结点
SListNode* deleteDuplicates(SList* plist){
	assert(plist);
	SListNode* prev = NULL;
	SListNode* cur = plist->_head;
	SListNode* tail = plist->_head->_next;
	if (plist->_head == NULL || plist->_head->_next == NULL)
	{
		return plist->_head;
	}
	while (tail){
		if (cur->_data == tail->_data){
			tail = tail->_next;
			while (tail){
				if (cur->_data != tail->_data){
					break;
				}
				else{
					tail = tail->_next;
				}
			}
			while (cur != tail){
				SListNode* tnode = cur;
				cur = cur->_next;
				free(tnode);

			}
			if (prev == NULL){
				plist->_head = tail;
			}
			else{
				prev->_next = tail;
			}
			if (tail){
				tail = tail->_next;
			}
		}
		else{
			prev = cur;
			cur = tail;
			tail = tail->_next;
		}
	}
	return plist->_head;
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
//	SList psl2;
	SListInit(&psl);
//	SListInit(&psl2);
	//SListDestory(&psl);

	SListPushFront(&psl, 5);
	SListPushFront(&psl, 4);
	SListPushFront(&psl, 4);
	SListPushFront(&psl, 3);
	SListPushFront(&psl, 3);
	SListPushFront(&psl, 2);
	/*
	SListPushFront(&psl2, 4);
	SListPushFront(&psl2, 2);
	SListPushFront(&psl2, 1);
	*/


	SListPrint(&psl);
	//SListPrint(&psl2);

/*	SListNode* cur = partition(&psl, 3);
	while (cur != NULL){
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
*/

	SListNode* cur = deleteDuplicates(&psl);
	while (cur != NULL){
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	system("pause");
	return 0;
}