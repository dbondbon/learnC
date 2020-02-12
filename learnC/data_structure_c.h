#ifndef DATA_STUCTURE_C_H
#define DATA_STUCTURE_C_H

#define MAX_LEN   1000 // ������ݳ���
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
 * ʹ��C����ʵ�ּ�����˳���
 * �� insert_int_sequence_table(int_tab tab, int val) �ڱ�ĩβ�����ֵval
 * ɾ delete_int_sequence_table(int_tab tab, int index) ɾ����λ���±�index��ֵ
 * �� modify_int_sequence_table(int_tab tab, int val, int index); ����λ���±�index��ֵ�޸�Ϊval
 * �� get_int_sequence_table(int_tab tab, int index); ��ȡλ���±�index��ֵ
 */
typedef struct int_sequence_table {
	int t_len = 0; // ˳���ǰ����
	int seq_t[MAX_LEN]; // �洢����
}int_tab;

int insert_int_sequence_table(int_tab *tab, const int val);
int delete_int_sequence_table(int_tab *tab, const int index);
int modify_int_sequence_table(int_tab *tab, const int val, const int index);
int get_int_sequence_table(const int_tab *tab, const int index);
int test_int_sequence_table();

#endif
