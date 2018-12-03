#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode *_next;
	struct ListNode *_prev;
}ListNode;

typedef struct List
{
	struct ListNode *_head;
}List;

ListNode *BuyNode(LTDataType x);
void ListInit(List *plist);
void ListPrint(List *plist);
void Listpushback(List *plist, LTDataType x);
void Listpushfront(List *plist, LTDataType x);

void Listpopback(List *plist, LTDataType x);
void Listpopfront(List *plist);

ListNode *ListFind(List *plist, LTDataType x);
void ListInsert(ListNode *pos, LTDataType x);
void ListErase(ListNode *pos);

//int ListSize(List *plist);
//int ListEmpty(List *plist);
void ListReserve(List *plist);

void ListDestory(List *plist);
