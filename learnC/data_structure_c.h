#ifndef DATA_STUCTURE_C_H
#define DATA_STUCTURE_C_H

#define MAX_LEN 1000 // ������ݳ���

/**
 * ʹ��C����ʵ�ּ�����˳���
 */
typedef struct int_sequence_table {
	int t_len = 0; // ˳���ǰ����
	int seq_t[MAX_LEN]; // �洢����
}int_tab;

bool insert_int_sequence_table(int_tab tab, int val, int index);
bool delete_int_sequence_table(int_tab tab, int index);
bool modify_int_sequence_table(int_tab tab, int val, int index);
int get_int_sequence_table(int_tab tab, int index);

#endif
