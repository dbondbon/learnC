#ifndef DATA_STUCTURE_C_H
#define DATA_STUCTURE_C_H

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

#endif
