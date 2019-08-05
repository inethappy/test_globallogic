#include "../inc/money_maker.h"

void	p_error(char *string, t_base *input)
{
	printf("%s\n", string);
	free(input->number);
	input->number = NULL;
	get_input(input);
}

void del_input(t_base *input)
{
	free(input->number);
	input->number = NULL;
	memset(input->out, 0, 500);
	input->centesimal = NULL;
	free(input->singles);
	free(input->doubles);
	free(input->tens);
	free(input->powers);
}

void trim(char *string)
{
	char *eol;

	if ((eol = strchr(string, '\n')) != NULL)
	{
		*eol = '\0';
	}
}

char **copy_arr(char **arr)
{
	char **new_arr;
	int loop;

	new_arr = malloc(sizeof(char*) * 15);
	for(loop = 0; loop < 15; loop++)
	{
		new_arr[loop] = arr[loop];
	}
	return (new_arr);
}
