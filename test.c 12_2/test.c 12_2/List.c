#include "List.h"
List plist;

ListNode *BuyNode(LTDataType x)
{
	ListNode *pnode = (ListNode*)malloc(sizeof (ListNode));
	pnode->_data = x;
	pnode->_next = pnode;
	pnode->_prev = pnode;
}

void ListInit(List *plist)
{
	assert(plist);
	ListNode *head = BuyNode(-1);
	plist->_head = head;//让头指针指向第一个没有有效值的结点，作为开头
}

void Listpushback(List *plist, LTDataType x)
{
	assert(plist);
	ListNode *tail = plist->_head->_prev;
	ListNode *newnode = BuyNode(x);
	tail->_next = newnode;
	newnode->_prev = tail;
	newnode->_next = plist->_head;
	plist->_head->_prev = newnode;
}

void Listpushfront(List *plist, LTDataType x)
{
	assert(plist);
	ListNode *cur = plist->_head->_next;
	ListNode *newnode = BuyNode(x);
	newnode->_next = cur;
	cur->_prev = newnode;
	plist->_head->_next = newnode;
	newnode->_prev = plist->_head;
}


void ListPrint(List *plist)
{
	assert(plist);
	printf("<-head->");
	ListNode *cur = plist->_head->_next;
	while (cur != plist->_head)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}

}

void ListDestory(List *plist)
{
	assert(plist);
	ListNode *head = plist->_head;
	ListNode *cur = head->_next;
	while (cur != head)
	{
		ListNode *next = cur->_next;
		free(cur);
		cur = next;
	}
	head->_next = head;
	head->_prev = head;
}

void test()
{
	ListInit(&plist);
	Listpushback(&plist, 1);
	Listpushback(&plist, 2);
	Listpushback(&plist, 3);
	Listpushback(&plist, 5);
	Listpushback(&plist, 6);
	Listpushfront(&plist, 8);
	Listpushfront(&plist, 9);
	Listpopback(&plist);

	ListPrint(&plist);
	ListDestory(&plist);
}