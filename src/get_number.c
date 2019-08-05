#include "../inc/money_maker.h"

void	get_input(t_base *input)
{
	char get_nb[1024];

	memset(get_nb, '\0', 150);
	input->number = (char*)malloc(sizeof(char) * 15);
	input->number[15] = '\0';
	printf("Enter number: ");
	fgets(get_nb, 1024, stdin);
	if (strlen(get_nb) > 13)
		p_error("\033[32mError! Value must be >= 0 and <= 2147483647.\033[0m", input);
	else
	{
		strcpy(input->number, get_nb);
		number_validation(input);
	}
}

void	number_validation(t_base *input)
{
	if (input->number[14] || (atol(input->number) > 2147483647 || atol(input->number) < 0))
		p_error("\033[32mError! Value must be >= 0 and <= 2147483647.\033[0m", input);
	trim(input->number);
	for (int i = 0; i < strlen(input->number); i++)
	{
		if ((input->number[i] > '9' || input->number[i] < '0')
			&& input->number[i] != ',' && input->number[i] != '.')
			p_error("\033[32mError! Please use only numbers.\033[0m", input);
		else if ((input->number[i] == ',' || input->number[i] == '.')
			&& (strchr(input->number + i + 1, '.') || strchr(input->number + i + 1, ',')))
			p_error("\033[32mError! Please use only one separatot at the line.\033[0m", input);
		else if ((input->number[i] == ',' && input->cur_lang == 0)
			|| (input->number[i] == '.' && input->cur_lang == 1))
			p_error("\033[32mError! Please use only ',' with UKR or '.' with USA.\033[0m", input);
	}
}
