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


SListNode* slistReverse(SList* plist){
	assert(plist);
	SListNode* prev = NULL;
	SListNode* cur = plist->_head;
	SListNode* tail = NULL;
	while (cur){
		tail = cur->_next;
		cur->_next = prev;
		prev = cur;
		cur = tail;
	}
	return prev;
}
//判断链表是否为回文结构
int isPalindrome(SList* plist){
	assert(plist);
	if (plist->_head == NULL || plist->_head->_next == NULL){
		return 1;
	}
	SListNode* fast = plist->_head;
	SListNode* slow = plist->_head;
	while (fast && fast->_next){
		fast = fast->_next->_next;
		if (fast){
			slow = slow->_next;
		}
	}
	//要给第一段的链表的结束点附上空指针
	//所以我们找的中间结点是前一个，如：2->3->4->5,找的为3。
	SListNode* begin = plist->_head;
	SListNode* newbegin = slow->_next;
	slow->_next = NULL;
	newbegin = slistReverse(newbegin);
	while (begin && newbegin){
		if (begin->_data != newbegin->_data){
			return -1;
		}
		else{
			begin = begin->_next;
			newbegin = newbegin->_next;
		}
	}
	return 1;
}

void main(){
	SList psl;
	//	SList psl2;
	SListInit(&psl);
	//	SListInit(&psl2);
	//SListDestory(&psl);

	SListPushFront(&psl, 5);
	SListPushFront(&psl, 3);
	SListPushFront(&psl, 4);
	SListPushFront(&psl, 1);
	SListPushFront(&psl, 1);
	SListPushFront(&psl, 1);
	SListPrint(&psl);
	//SListPrint(&psl2);

	/*int i = slistSize(&psl) / 2;
	printf("%d\n", i);
	*/
	
	/*SListNode* cur = slistReverse(&psl);
	while (cur){
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	*/

	int is = isPalindrome(&psl);
	printf("%d\n", is);


	system("pause");
	return 0;
}