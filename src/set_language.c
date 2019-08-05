#include "../inc/money_maker.h"

int	set_language(t_base *input)
{
	char language_input[10];

	printf("Enter your country please (USA/UKR): ");
	fgets(language_input, 10, stdin);
	if (language_input[0] == '\n')
		return (0);
	input->currency = get_currency(language_input, input);
	if (input->currency)
		printf("Thanks! Your currency is %s.\n", input->currency);
	else
	{
		printf("\e[31mWrong currency. If You want to select another country - You need to add this feature manually.\e[0m\n");
		set_language(input);
	}
	return (1);
}

char *get_currency(char *language_input, t_base *input)
{
	char *result;

	result = NULL;
	if (!language_input || *language_input == '\n')
		return (NULL);
	trim(language_input);
	if (ENG(language_input) == 1)
	{
		input->cur_lang = usa;
		result = "USD";
	}
	if (UKR(language_input) == 1)
	{
		input->cur_lang = ukr;
		result = "UAH";
	}
	return (result);
}
