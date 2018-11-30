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

//void SListPushBack(SList *plist, SLDataType x)//注意分为有无结点两种情况
//{
//	assert(plist);
//	SListNode* newnode = BuyNode(x);
//	SListNode* tail = plist->_head;
//	if (tail == NULL)
//	{
//		plist->_head = newnode;
//	}
//	//SListNode* tail = plist->_head;
//	else
//	{
//		while (tail->_next != NULL)
//		{
//			tail = tail->_next;
//		}
//		tail->_next = newnode;
//		//newnode->_next = NULL;
//	}
//	newnode->_next = NULL;
//}
//
//void SListPopFront(SList *plist)
//{
//	assert(plist);
//	SListNode *next = NULL;
//	SListNode *cur = plist->_head;
//	next = cur->_next;
//	free(cur);
//	cur = next;
//	plist->_head = cur;
//}
//
//void SListPopBack(SList *plist)//考虑只有一个结点和有两个及以上结点的情况。
//{
//	assert(plist);
//	//SListNode* tail = plist->_head;
//	if (plist->_head ->_next== NULL)
//	{
//		free(plist->_head);
//		plist->_head = NULL;
//		
//	}
//	else
//	{
//		SListNode* tail = plist->_head;
//		while (tail->_next->_next != NULL)
//		{
//			tail = tail->_next;
//		}
//		free(tail->_next);
//		tail->_next = NULL;
//	}
//}

//void SListDelateallval(SList *plist, SLDataType x)
//{
//	assert(plist);
//	SListNode *prev = NULL;
//	SListNode *cur = plist->_head;
//	SListNode *next ;//默认设置的三个结点的顺序为prev,cur,next
//	while (cur != NULL)
//	{
//		if (cur->_data == x)
//		{
//			next = cur->_next;
//			free(cur);
//			cur = next;
//			if (prev == NULL)//如果删除的是第一个结点
//			{
//				plist->_head = next;
//			}
//			else
//			{
//				prev->_next = next;//如果删除的不是第一个结点，就要把原来的prev 指向 next
//			}
//		}
//		else
//		{
//
//			prev = cur;
//			cur = cur->_next;
//		}
//	}
//	//return plist;
//}

//void  SListturnlist(SList *plist)
//{
//	assert(plist);
//	SListNode *prev = NULL;
//	SListNode *cur = plist->_head;
//	SListNode *next;
//	while (cur != NULL)
//	{
//		next = cur->_next;
//		cur->_next = prev;
//		prev = cur;
//		cur = next;
//	}
//	plist = prev;
//	return plist;
//}

//SListNode*  Findmiddle (SList *plist)
//{
//	assert(plist);
//	SListNode *cur = plist->_head;
//	int count = 0;
//	int mid = count / 2;
//	while (cur != NULL)
//	{
//		count++;
//		cur = cur->_next;
//	}
//	cur = plist->_head;
//	while (mid--)
//	{
//		cur = cur->_next;
//	}
//	return cur;
//	//SListNode *fast = plist->_head;
//	//SListNode *slow = fast;
//	//while (fast && fast->_next)
//	//{
//	//	fast = fast->_next->_next;
//	//	slow = slow->_next;
//
//	//}
//	//return slow;
//}





void test( )
{
	SList plist;
	SListInit(&plist);

	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 4);
	SListPushFront(&plist, 5);
	//SListPushFront(&plist, 6);
	//SListPushFront(&plist, 6);
	//SListPushBack(&plist, 6);

	//SListPopFront(&plist);
	//SListPopBack(&plist);

	/*SListDelateallval(&plist,2);
	SListturnlist(&plist);*/
	/*Findmiddle(&plist);*/

	SListPrint(&plist);
	SListDestory(&plist);
}