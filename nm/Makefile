##
## EPITECH PROJECT, 2018
## PSU_2018_nmobjdump
## File description:
## Makefile
##

CC		=	gcc
INC		=	include/
DSRC	=	src/
DLIB	=	../lib/
LIBS	=	-L$(DLIB) -lelf

SRC		=	$(DSRC)main.c			\
			$(DSRC)symbol.c			\
			$(DSRC)find_symbols.c	\
			$(DSRC)print_symbol.c	\

CFLAGS	+=  -std=gnu11 -Wall -Wextra -I$(INC) -I$(DLIB)include
LDFLAGS	=	-lcriterion
OBJ		=	$(SRC:.c=.o)
NAME	=	my_nm

all: $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS) $(LIBS)
	cp $(NAME) ..

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)
	rm -f $(NAME_UT)

re: fclean all

debug: CFLAGS += -g
debug: re

.PHONY: all clean fclean re debug
