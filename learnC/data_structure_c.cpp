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