#include "../inc/money_maker.h"

void put_eng_words(t_base *input, char *number)
{
	int len_nb;
	int rank = 0;

	while (*number)
	{
		input->last_word = 0;
		len_nb = strlen(number);
		if (len_nb > 9 && (rank = 1))
		{
            strcat(input->out, input->singles[*number - '0']);
			input->last_word = *number - '0';
			strcat(input->out, " ");
			put_eng_powers(input, rank);
		}
		else if (len_nb < 4 && (rank = len_nb))
			put_eng_hundreds(number, input, strlen(number));
		else
		{
			int odds = (len_nb > 6) ? 6 : 3;
			char *buf = (char*)malloc(sizeof(char) * 4);
			memset(buf, 0, 4);
			strncpy(buf, number, (strlen(number) - odds));
			put_eng_hundreds(buf, input, (strlen(number) - odds));
			put_eng_powers(input, odds);
			rank = len_nb - odds;
			free(buf);
		}
		number += rank;
	}
}

void	put_eng_hundreds(char *number, t_base *input, int length)
{
	char unit;
	int count;

	for (count = 0; count < length; count++)
	{
		unit = number[count] - '0';
        if (unit == 0)
            continue ;
		if ((length - count) == 3)
			strcat(input->out, input->powers[unit]);
		else if ((length - count) == 2)
		{
			if (unit == 1)
				strcat(input->out, input->doubles[unit + number[count++ + 1] - '0']);
			else
			{
				strcat(input->out, input->tens[unit]);
				strcat(input->out, "-");
			}
		}
		else
            strcat(input->out, input->singles[unit]);
		input->last_word = (number[count + 1]) ? unit + (number[count + 1] - '0') : unit;
		strcat(input->out, (input->out[strlen(input->out) - 1] == '-') ? "" : " ");
	}
}

void put_eng_powers(t_base *input, int rank)
{
	if (input->last_word == 0)
		return ;
    if (rank == 6)
        strcat(input->out, input->powers[11]);
    else if (rank == 3)
        strcat(input->out, input->powers[10]);
    else
        strcat(input->out, input->powers[12]);
    strcat(input->out, " ");
}

void	eng_currency(t_base *input, int type)
{
	if (type == 0)
		strcat(input->out, (input->last_word == 1) ? "dollar " : "dollars ");
	else
		strcat(input->out, (input->last_word == 1) ? "cent\n" : "cents\n");
}
