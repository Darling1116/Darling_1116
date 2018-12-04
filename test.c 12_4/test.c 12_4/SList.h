#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <malloc.h>

typedef int SLDataType;

typedef struct SListNode
{
	SLDataType _data;
	struct SListNode* _next;
}SListNode;

typedef struct SList
{
	SListNode*_head;
}SList;

void SListInit(SList *plist);

SListNode* BuyNode(SLDataType x);

void SListPushFront(SList *plist, SLDataType x);
void SListPushBack(SList *plist, SLDataType x);
void SListPopFront(SList *plist);
void SListPopBack(SList *plist);

SListNode *SListFind(SList *plist, SLDataType x);
void SListInsertAfter(SListNode *pos, SLDataType x);
void  SListEraseAfter(SListNode *pos);

SListNode* partition(SList* plist, SLDataType x);
SListNode* deleteDuplication(SListNode* plist);

void SListPrint(SList *plist);
void SListDestory(SList *plist);


