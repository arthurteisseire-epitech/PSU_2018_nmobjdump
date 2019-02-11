##
## EPITECH PROJECT, 2018
## lib
## File description:
## Makefile
##

CC		=	gcc
INC		=	include/
DSRC	=	src/

SRC	=		$(DSRC)print.c			\
			$(DSRC)map_file.c		\
			$(DSRC)utils.c			\

CFLAGS	+=	-Wall -W -Wextra -I$(INC)
LDFLAGS	=	-lcriterion
OBJ		=	$(SRC:.c=.o)
NAME	=	libelf.a

all: $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_UT)

re: fclean all

debug: CFLAGS += -g
debug: re

.PHONY: all clean fclean re debug
