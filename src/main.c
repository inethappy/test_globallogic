#include "../inc/money_maker.h"

void	test(char **argv, t_base *input)
{
	input->currency = (char*)malloc(sizeof(char) * 15);
	input->currency = get_currency(argv[2], input);
	if (!input->currency)
	{
		printf("\e[31mWrong currency. If You want to select another country - You need to add this feature manually.");
		exit(0);
	}
	input->number = (char*)malloc(sizeof(char) * 15);
	strcpy(input->number, argv[3]);
	number_validation(input);
	set_names(input);
	put_words(input, input->number);
	put_currency(input);
	printf("%s", input->out);
	del_input(input);
}

int main(int argc, char **argv)
{
	t_base *input;

	input = (t_base*)malloc(sizeof(t_base));
	memset(input, 0, sizeof(t_base));
	if (argv[1] && strcmp(argv[1], "-test") == 0)
	{
		test(argv, input);
		return (0);
	}
	while(1)
	{
		if (!set_language(input))
			break ;
		get_input(input);
		set_names(input);
		put_words(input, input->number);
		put_currency(input);
		printf("%s", input->out);
		del_input(input);
	}
	system("leaks money_maker > leaks.txt");
	return (0);
}
