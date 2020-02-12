#include "data_structure_c.h"

bool insert_int_sequence_table(int_tab tab, int val, int index)
{
	if (index >= tab.t_len || index < 0 || tab.t_len >= MAX_LEN) {
		return false;
	}
	for (int i = tab.t_len; i > index; i--) {
		tab.seq_t[i] = tab.seq_t[i - 1];
	}
	tab.seq_t[index] = val;
	tab.t_len++;
	return true;
}
