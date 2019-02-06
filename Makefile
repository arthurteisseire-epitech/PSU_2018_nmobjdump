##
## EPITECH PROJECT, 2018
## PSU_2018_nmobjdump
## File description:
## Makefile
##

CC		=	gcc
INC		=	include/
DTESTS	=	tests/
DSRC	=	src/
DSRC_UT	=	tests/src/

SRC		=	$(DSRC)main.c			\

SRC_UT	=	$(DSRC_UT)tests_file.c			\

CFLAGS	+=  -std=gnu11 -Wall -Wextra -I$(INC)
LDFLAGS	=	-lcriterion
OBJ		=	$(SRC:.c=.o)
NAME	=	nm
NAME_UT	=	units

all: $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_UT)

re: fclean all

debug: CFLAGS += -g
debug: re

test_run: CFLAGS += --coverage
test_run: LDFLAGS += -lgcov
test_run:
	$(CC) -o $(NAME_UT) $(SRC) $(SRC_UT) $(CFLAGS) $(LDFLAGS)
	./$(NAME_UT)
	gcov *.gcno &> /dev/null

test_debug: CFLAGS += -g
test_debug: test_run

.PHONY: all clean fclean re debug test_run test_debug
