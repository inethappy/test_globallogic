#include "../inc/money_maker.h"

void	put_currency(t_base *input)
{
	if (atoi(input->number) > 0)
		input->cur_lang == 0 ? eng_currency(input, paper) : ukr_currency(input, paper);
	if (input->centesimal && atoi(input->centesimal) > 0)
	{
		strcat(input->out, (input->cur_lang == 0 && atoi(input->number) > 0) ? "and " : "");
		put_words(input, input->centesimal);
		input->cur_lang == 0 ? eng_currency(input, coin) : ukr_currency(input, coin);
	}
	else
		strcat(input->out, "\n");
}
