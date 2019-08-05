#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ENG(str) (strcmp(str, "USA") == 0 || strcmp(str, "usa") == 0) ? 1 : 0
#define UKR(str) (strcmp(str, "UKR") == 0 || strcmp(str, "ukr") == 0) ? 1 : 0

enum lang		{ usa, ukr };
enum money_type	{ paper, coin };

typedef struct	s_base
{
	char	*currency;
	char	*number;
	char	*centesimal;
	enum	lang cur_lang;
	char	out[500];
	int		last_word;
	char	**singles;
	char	**doubles;
	char	**tens;
	char	**powers;
}				t_base;

int		set_language(t_base *input);
char	*get_currency(char *language_input, t_base *input);
void	p_error(char *string, t_base *input);
char 	**copy_arr(char **arr);
void	trim(char *string);
void	get_input(t_base *input);
void	number_validation(t_base *input);
void	set_names(t_base *input);
void	set_eng_names(t_base *input);
void	set_ukr_names(t_base *input);
void	find_pennies(t_base *input, char c);
void	put_words(t_base *input, char *number);
void	put_eng_words(t_base *input, char *number);
void	put_eng_hundreds(char *number, t_base *input, int length);
void	put_eng_powers(t_base *input, int rank);
void	put_ukr_words(t_base *input, char *number);
void	put_ukr_singles(t_base *input, int number, int len);
void	put_ukr_hundreds(char *number, t_base *input, int length);
void	put_powers(t_base *input, int rank);
void	put_eng_powers(t_base *input, int rank);
void	put_ukr_powers(t_base *input, int rank);
void	put_singles(t_base *input, int number, int len);
void	put_hundreds(char *l, t_base *input, int length);
void	put_currency(t_base *input);
void	eng_currency(t_base *input, int type);
void	ukr_currency(t_base *input, int type);
void	del_input(t_base *input);
void	test(char **argv, t_base *input);
