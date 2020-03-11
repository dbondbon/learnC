#include<stdio.h>
#include<stdlib.h>
#include "algorithm.h"

int main()
{
	ListNode node3 = { 6, NULL };
	ListNode node7 = { 5, &node3 };
	ListNode node2 = { 2, &node7 };
	ListNode node1 = { 1, &node2 };
	
	ListNode node6 = { 4, NULL };
	ListNode node5 = { 3, &node6 };
	ListNode node4 = { 1, &node5 };
	
	ListNode* res = mergeTwoLists(&node1, &node4);

	return 0;
}