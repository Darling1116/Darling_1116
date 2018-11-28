#define _CRT_SECURE_NO_WARNINGS
#include "SList.h"

void SListInit(SList *plist)
{
	assert(plist);
	plist->_head = NULL;
}


void SListPrint(SList *plist)
{
	assert(plist);
	SListNode *cur = plist->_head;
	while (cur != NULL)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("NULL\n");
}


void SListDestory(SList *plist)
{
	assert(plist);
	SListNode *cur = plist->_head;
	SListNode *next = NULL;
	while (cur!= NULL)
	{
		next = cur->_next;
		free(cur);
		cur = next;
	}
	plist->_head = NULL;
}

SListNode* BuyNode(SLDataType x)
{
	SListNode *pnode = (SListNode*)malloc(sizeof (SListNode));
	pnode->_data = x;
	pnode->_next = NULL;
	return pnode;
}


void SListPushFront(SList *plist, SLDataType x)
{
	assert(plist);
	SListNode* newnode = BuyNode(x);
	newnode->_next = plist->_head;
	plist->_head = newnode;
}

void SListPushBack(SList *plist, SLDataType x)//注意分为有无结点两种情况
{
	assert(plist);
	SListNode* newnode = BuyNode(x);
	SListNode* tail = plist->_head;
	if (tail == NULL)
	{
		plist->_head = newnode;
	}
	//SListNode* tail = plist->_head;
	else
	{
		while (tail->_next != NULL)
		{
			tail = tail->_next;
		}
		tail->_next = newnode;
		//newnode->_next = NULL;
	}
	newnode->_next = NULL;
}

void SListPopFront(SList *plist)
{
	assert(plist);
	SListNode *next = NULL;
	SListNode *cur = plist->_head;
	next = cur->_next;
	free(cur);
	cur = next;
	plist->_head = cur;
}

void SListPopBack(SList *plist)//考虑只有一个结点和有两个及以上结点的情况。
{
	assert(plist);
	//SListNode* tail = plist->_head;
	if (plist->_head ->_next== NULL)
	{
		free(plist->_head);
		plist->_head = NULL;
		
	}
	else
	{
		SListNode* tail = plist->_head;
		while (tail->_next->_next != NULL)
		{
			tail = tail->_next;
		}
		free(tail->_next);
		tail->_next = NULL;
	}
}

void test()
{
	SList plist;
	SListInit(&plist);

	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPushFront(&plist, 5);
	SListPushBack(&plist, 6);

	SListPopFront(&plist);
	SListPopBack(&plist);

	SListPrint(&plist);
	SListDestory(&plist);
}