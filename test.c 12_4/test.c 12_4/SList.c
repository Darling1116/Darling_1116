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
	while (cur != NULL)
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
SListNode *SListFind(SList *plist, SLDataType x)
{
	assert(plist);
	SListNode *cur = plist->_head;
	while (cur)
	{
		if (cur->_data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->_next;
		}
	}

}

void SListInsertAfter(SListNode *pos, SLDataType x)
{
	assert(pos);
	SListNode *newnode = BuyNode(x);
	newnode->_next = pos->_next;
	pos->_next = newnode;

}

void  SListEraseAfter(SListNode *pos)
{
	assert(pos && pos->_next);
	SListNode *tail = pos->_next->_next;
	free(pos->_next);
	pos->_next = tail;
}

//SListNode* partition(SList* plist,SLDataType x)
////以给定值x为基准将链表分割成两部分，所有小于x的结点排在大于或等于x的结点之前
//{
//	assert(plist);
//	SListNode *lesshead = (SListNode *)malloc(sizeof (SListNode));
//	SListNode *morehead = (SListNode *)malloc(sizeof (SListNode));
//	//给每一个链表设置一个哑结点，不用来存放数据，没有有效值。
//	SListNode *pless = lesshead;
//	SListNode *pmore = morehead;
//	SListNode *cur = plist->_head;
//	while (cur)
//	{
//		if (cur->_data < x)
//		{
//			pless->_next = cur;
//			pless = pless->_next;
//		}
//		else
//		{
//			pmore->_next = cur;
//			pmore = pmore->_next;
//		}
//		cur = cur->_next;
//	}
//	pless->_next = morehead->_next;
//	pmore->_next = NULL;
//	plist->_head = lesshead->_next;
//	free(lesshead);
//	free(morehead);
//	return plist->_head;
//}

SListNode* deleteDuplication(SList* plist)
//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点.
//重复的结点不保留，返回链表头指针。
{
	assert(plist);
	SListNode *prev = NULL;
	SListNode *cur = plist->_head;
	SListNode *tail = plist->_head->_next;
	while (tail)
	{
		if (cur == NULL || tail == NULL)
		{
			return plist->_head;
		}
		if (cur->_data == tail->_data)
		{
			while (tail)
			{
				if (cur->_data != tail->_data)
				{
					break;
				}
				tail = tail->_next;
			}
			while (cur != tail)
			{
				SListNode *tmp = cur->_next;
				free(cur);
				cur = tmp;
			}
			if (prev == NULL)
			{
				plist->_head == tail;
			}
			else
			{
				prev->_next = tail;
			}
			if (tail)
			{
				tail = tail->_next;//
			}

		}
		prev = cur;
		cur = tail;
		tail = tail->_next;
	}
	return plist->_head;
}

SListNode* chkPalindrome(SList *plist)
//对于一个链表，请设计一个时间复杂度为O(n), 额外空间复杂度为O(1)的算法，判断其是否为回文结构。
//给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。
//测试样例：
//1->2->2->1
//返回：true
{
	assert(plist);

}

void test()
{
	SList plist;
	SListInit(&plist);

	SListPushFront(&plist, 3);
	SListPushFront(&plist, 6);
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 1);

	//SListInsertAfter(SListFind(&plist, 1), 8);
	//SListInsertAfter(SListFind(&plist, 2), 8);
	SListPrint(&plist);

	
	/*partition(&plist, 9);*/
	deleteDuplication(&plist);

	SListPrint(&plist);

	SListDestory(&plist);
}
