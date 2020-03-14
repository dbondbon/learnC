#ifndef DATA_STUCTURE_C_H
#define DATA_STUCTURE_C_H

#include "algorithm.h"

#define MAX_LEN   1000 // 最大数据长度
#define RES_TRUE    1
#define RES_FALSE   0
#define RES_SUCCESS 0	
#define RES_FAIL    -1
#define CHECK_RES(res)              \
	do {		                        \
		if ((res) == RES_FAIL) {	    \
			return RES_FAIL;        \
		}                           \
	} while (0);

/**
 * 使用C语言实现简单整型顺序表
 * 增 insert_int_sequence_table(int_tab tab, int val) 在表末尾添加数值val
 * 删 delete_int_sequence_table(int_tab tab, int index) 删除表位于下标index的值
 * 改 modify_int_sequence_table(int_tab tab, int val, int index); 将表位于下标index的值修改为val
 * 查 get_int_sequence_table(int_tab tab, int index); 获取位于下标index的值
 */
typedef struct int_sequence_table {
	int t_len = 0; // 顺序表当前长度
	int seq_t[MAX_LEN]; // 存储数组
}int_tab;

int insert_int_sequence_table(int_tab *tab, const int val);
int delete_int_sequence_table(int_tab *tab, const int index);
int modify_int_sequence_table(int_tab *tab, const int val, const int index);
int get_int_sequence_table(const int_tab *tab, const int index);
int test_int_sequence_table();


/**
 * 实现链表实现栈的基本操作：
 * push(x) -- 元素 x 入栈
 * pop() -- 移除栈顶元素
 * top() -- 获取栈顶元素
 * empty() -- 返回栈是否为空
 */
typedef struct {
	ListNode *first;
	int size;
} MyStack;

/** Initialize your data structure here. */
MyStack* myStackCreate();
/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x);
/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj);
/** Get the top element. */
int myStackTop(MyStack* obj);
/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj);
/** Free the stack. */
void myStackFree(MyStack* obj);
/** Test the stack. */
int test_myStack();

#endif
