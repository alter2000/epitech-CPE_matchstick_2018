##
## EPITECH PROJECT, 2018
## CPool_Day07_2018
## File description:
## standard makefile
##

NAME=matchstick
CFLAGS+= -Werror -Wall -I./include -L./lib/my -lmy
DFLAGS+= -Wall -I./include -L./lib/my -lmy
SRC=$(wildcard *.c) $(wildcard ./framebuffer/*.c)
OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC) $(wildcard include/*.h)
	@$(MAKE) -C ./lib/my
	@gcc -o $(NAME) $(SRC) $(CFLAGS)

debug:
	@$(MAKE) -C ./lib/my debug
	clang -o $(NAME) $(SRC) $(DFLAGS) -g

clean:
	@rm -f $(OBJ) $(shell find . -name '*.gc*' -o -name 'vgcore.*')
	@$(MAKE) -C ./lib/my clean

fclean: clean
	@rm -f $(NAME) unit_tests
	@$(MAKE) -C ./lib/my fclean

re: fclean $(NAME)

tests_run:
	@$(MAKE) -C ./lib/my
	@gcc -o unit_tests $(shell find ./tests/ -name '*.c') \
		$(filter-out main.c, $(SRC)) \
		-lcriterion --coverage $(CFLAGS) \
		&& ./unit_tests

.PHONY: all debug clean fclean re tests_run
