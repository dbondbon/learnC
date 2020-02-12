#ifndef DATA_STUCTURE_C_H
#define DATA_STUCTURE_C_H

#define MAX_LEN 1000 // 最大数据长度

/**
 * 使用C语言实现简单整型顺序表
 */
typedef struct int_sequence_table {
	int t_len = 0; // 顺序表当前长度
	int seq_t[MAX_LEN]; // 存储数组
}int_tab;

bool insert_int_sequence_table(int_tab tab, int val, int index);
bool delete_int_sequence_table(int_tab tab, int index);
bool modify_int_sequence_table(int_tab tab, int val, int index);
int get_int_sequence_table(int_tab tab, int index);

#endif
