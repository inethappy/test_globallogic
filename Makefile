NAME	=	money_maker
CC		=	gcc
SOURCES	=	main.c \
			set_language.c \
			additional_functions.c \
			get_number.c \
			set_current_names.c \
			print_words.c \
			print_currency.c \
			put_eng_words.c \
			put_ukr_words.c
OBJECTS_DIR	:= ./obj/
SOURCES_DIR	:= ./src/
OBJECTS		:= $(addprefix $(OBJECTS_DIR), $(SOURCES:.c=.o))

all:	$(NAME)

$(NAME): $(OBJECTS)
	 @$(CC) $(OBJECTS) -I inc/money_maker.h -o $(NAME)
	 @echo 'Done! Please execute money_maker.'

$(OBJECTS): | $(OBJECTS_DIR)

$(OBJECTS_DIR):
		@mkdir $(OBJECTS_DIR)

$(OBJECTS_DIR)%.o: %.c
		@$(CC) -c $< -o $@ -I inc/money_maker.h

%.o: ./%.c
	@gcc -o $@ -c $<
clean:
	@rm -rf $(OBJECTS)
	 @echo 'Done!'
fclean: clean
	@rm -rf $(OBJECTS_DIR)
	@rm -rf $(NAME)
	@rm -rf leaks.txt
re: fclean all
vpath %.c $(SOURCES_DIR)

