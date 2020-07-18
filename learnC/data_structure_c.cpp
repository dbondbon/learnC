#include <stdlib.h>
#include "data_structure_c.h"

int insert_int_sequence_table(int_tab *tab, int val)
{
	if (tab->t_len == MAX_LEN) {
		return RES_FAIL;
	}
	tab->seq_t[tab->t_len] = val;
	tab->t_len++;
	return RES_SUCCESS;
}

int delete_int_sequence_table(int_tab *tab, int index)
{
	if (index >= tab->t_len) {
		return RES_FAIL;
	}
	for (int i = index; i < tab->t_len - 1; i++) {
		tab->seq_t[i] = tab->seq_t[i + 1];
	}
	tab->t_len--;
	return RES_SUCCESS;
}

int modify_int_sequence_table(int_tab *tab, int val, int index)
{
	if (index >= tab->t_len) {
		return RES_FAIL;
	}
	tab->seq_t[index] = val;
	return RES_SUCCESS;
}

int get_int_sequence_table(int_tab *tab, int index)
{
	if (index >= tab->t_len) {
		return RES_FAIL;
	}
	return tab->seq_t[index];
}

int test_int_sequence_table()
{
	int_tab tab;
	int res;

	for (int i = 2; i < 10; i++) {
		res = insert_int_sequence_table(&tab, 2 * i + 1);
		CHECK_RES(res);
	}

	res = delete_int_sequence_table(&tab, 1);
	CHECK_RES(res);
	res = delete_int_sequence_table(&tab, 5);
	CHECK_RES(res);
	res = modify_int_sequence_table(&tab, 2, 1);
	CHECK_RES(res);
	res = modify_int_sequence_table(&tab, 3, 1);
	CHECK_RES(res);
	res = get_int_sequence_table(&tab, 1);
	CHECK_RES(res);
	res = get_int_sequence_table(&tab, 5);
	CHECK_RES(res);

	return RES_SUCCESS;
}

/** Initialize your data structure here. */
MyStack* myStackCreate() 
{
	MyStack *newStack = (MyStack *)malloc(sizeof(MyStack));
	newStack->size = 0;
	return newStack;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) 
{
	ListNode *new_element = (ListNode *)malloc(sizeof(ListNode));
	new_element->val = x;
	if (obj->size == 0) {
		new_element->next = NULL;
		obj->first = new_element;
		obj->size++;
	} else {
		new_element->next = obj->first;
		obj->first = new_element;
		obj->size++;
	}
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) 
{
	int res = obj->first->val;
	ListNode* temp = obj->first;
	obj->first = obj->first->next;
	obj->size--;
	free(temp);
	return res;
}

/** Get the top element. */
int myStackTop(MyStack* obj) 
{
	return obj->first->val;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) 
{
	return obj->size == 0;
}

void myStackFree(MyStack* obj) 
{
	while (obj->size != 0) {
		ListNode* temp = obj->first;
		obj->first = obj->first->next;
		obj->size--;
		free(temp);
	}
	free(obj);
}

int test_myStack()
{
	MyStack* myStack = myStackCreate();
	int is_empty = myStackEmpty(myStack);
	myStackPush(myStack, 2);
	myStackPush(myStack, 5);
	myStackPush(myStack, 8);
	is_empty = myStackEmpty(myStack);
	int top_element = myStackTop(myStack);
	int pop_element = myStackPop(myStack);
	pop_element = myStackPop(myStack);
	pop_element = myStackPop(myStack);
	myStackPush(myStack, 1);
	myStackPush(myStack, 3);
	myStackFree(myStack);
	return RES_SUCCESS;
}

