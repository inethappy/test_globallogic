#include "../inc/money_maker.h"

void put_words(t_base *input, char *number)
{

	if (input->cur_lang == 0)
		put_eng_words(input, number);
	else
		put_ukr_words(input, number);
}
