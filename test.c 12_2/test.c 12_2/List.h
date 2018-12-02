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

//ListNode *BuyNode(LTDataType x);
void ListInit(List *plist);
void ListPrint(List *plist);
void Listpushback(List *plist, LTDataType x);
void Listpushfront(List *plist, LTDataType x);
void Listpopback(List *plist, LTDataType x);
void ListDestory(List *plist);
