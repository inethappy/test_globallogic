#include "../inc/money_maker.h"

void set_names(t_base *input)
{
	if (input->cur_lang == 0)
		set_eng_names(input);
	else
		set_ukr_names(input);
}

void set_eng_names(t_base *input)
{
	char *single_digits[] = { "zero", "one", "two",
							"three", "four","five",
							"six", "seven", "eight", "nine"};
	input->singles = copy_arr(single_digits);
	char *two_digits[] = {"", "ten", "eleven", "twelve",
							"thirteen", "fourteen",
							"fifteen", "sixteen",
							"seventeen", "eighteen", "nineteen"};
	input->doubles = copy_arr(two_digits);
	char *tens_multiple[] = {"", "", "twenty", "thirty", "forty", "fifty",
							"sixty", "seventy", "eighty", "ninety"};
	input->tens = copy_arr(tens_multiple);
	char *tens_power[] = {"", "one hundred", "two hundred", "three hundred",
						"four hundred", "five hundred", "six hundred",
						"seven hundred", "eight hundred", "nine hundred",
						"thousand", "million", "billion"};
	input->powers = copy_arr(tens_power);
	find_pennies(input, '.');
}

void set_ukr_names(t_base *input)
{
	char *single_digits[] = { "ноль", "одна", "двi",
							"три", "чотири", "п'ять",
							"шість", "сім", "вісім", "дев'ять"};
	input->singles = copy_arr(single_digits);
	char *two_digits[] = {"", "десять", "одинадцять", "дванадцять",
							"тринадцять", "чотирнадцять",
							"п'ятнадцять", "шістнадцять",
							"сімнадцять", "вісімнадцять", "дев'ятнадцять"};
	input->doubles = copy_arr(two_digits);
	char *tens_multiple[] = {"", "", "двадцять", "тридцять", "сорок",
							"п'ятдесят", "шістдесят", "сімдесят",
							"вісімдесят", "дев'яносто"};
	input->tens = copy_arr(tens_multiple);
	char *tens_power[] = {"", "сто", "двісті", "триста", "чотириста",
							"п'ятсот", "шістсот", "сімсот", "вісімсот",
							"дев'ятсот", "тисяча", "мільйон", "мільярд"};
	input->powers = copy_arr(tens_power);
	find_pennies(input, ',');
}

void find_pennies(t_base *input, char c)
{
	if (strchr(input->number, c))
	{
		input->centesimal = strchr(input->number, c) + 1;
		if (strlen(input->centesimal) != 2)
			p_error("\e[31mError! Divisional part from 00 to 99, please.", input);
		input->number[strlen(input->number) - 3] = '\0';
	}
}
