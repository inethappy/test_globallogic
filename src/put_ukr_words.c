#include "../inc/money_maker.h"

void put_ukr_words(t_base *input, char *number)
{
	int len_nb;
	int rank = 0;

	while (*number)
	{
		input->last_word = 0;
		len_nb = strlen(number);
		if (len_nb > 9 && (rank = 1))
		{
			put_ukr_singles(input, *number - '0', len_nb);
			input->last_word = *number - '0';
			strcat(input->out, " ");
			put_ukr_powers(input, rank);
		}
		else if (len_nb < 4 && (rank = len_nb))
			put_ukr_hundreds(number, input, strlen(number));
		else
		{
			int r = (len_nb > 6) ? 6 : 3;
			char *l = (char*)malloc(sizeof(char) * 4);
			memset(l, 0, 4);
			strncpy(l, number, (strlen(number) - r));
			put_ukr_hundreds(l, input, (len_nb > 6) ? 6 : (strlen(number) - r));
			put_ukr_powers(input, r);
			rank = len_nb - r;
			free(l);
		}
		number += rank;
	}
}

void	put_ukr_singles(t_base *input, int number, int len)
{
	if ((number == 1 || number == 2) && len > 5)
		strcat(input->out, (number == 1) ? "один" : "два");
	else
		strcat(input->out, input->singles[number]);
}

void	put_ukr_hundreds(char *number, t_base *input, int length)
{
	char unit;
	int count;
	int len_nb;

	len_nb = strlen(number);
	for (count = 0; count < length; count++)
	{
		if (!number[count])
			break ;
		unit = number[count] - '0';
        if (unit == 0)
            continue ;
		if (len_nb == 3 && (input->last_word = 10))
			strcat(input->out, input->powers[unit]);
		else
		{
			if (len_nb == 2 && unit == 1 && number[count + 1])
				strcat(input->out, input->doubles[unit + number[count++ + 1] - '0']);
			else if (len_nb == 2 && unit > 1)
				strcat(input->out, input->tens[unit]);
			else
				put_ukr_singles(input, unit, length);
			input->last_word = (number[count + 1]) ? unit + (number[count + 1] - '0') : unit;
			if (number[count - 1] && len_nb == 2 && number[count] == '0')
				input->last_word = 10;
		}
		strcat(input->out, " ");
		len_nb--;
	}
}

void put_ukr_powers(t_base *input, int rank)
{
	if (input->last_word == 0)
		return ;
	if (input->last_word == 1)
	{
		if (rank == 1)
			strcat(input->out, "мільярд ");
		else if (rank == 6)
			strcat(input->out, "мільйон ");
		else if (rank == 3)
			strcat(input->out, "тисяча ");
	}
	else if (input->last_word > 1 && input->last_word < 5)
	{
		if (rank == 1)
			strcat(input->out, "мільярди ");
		else if (rank == 6)
			strcat(input->out, "мільйони ");
		else if (rank == 3)
			strcat(input->out, "тисячi ");
	}
	else
	{
		if (rank == 1)
			strcat(input->out, "мільярдiв ");
		else if (rank == 6)
			strcat(input->out, "мільйонiв ");
		else if (rank == 3)
			strcat(input->out, "тисяч ");
	}
}

void	ukr_currency(t_base *input, int type)
{
	if (input->last_word == 1)
		strcat(input->out, (type == 0) ? "гривня " : "копiйка");
	else if (input->last_word > 1 && input->last_word < 5)
		strcat(input->out, (type == 0) ? "гривнi " : "копiйки");
	else
		strcat(input->out, (type == 0) ? "гривень " : "копiйок");
	if (type == 1)
		strcat(input->out, "\n");
}
