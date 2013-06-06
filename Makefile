
NAME    = MyRestSql

SRC     =	main.c

OBJ	= $(SRC:.c=.o)

CC      = g++

CFLAGS  = -W -Wall -O -O2

RM      = rm -f


all	 : $(OBJ)
	   $(CC) -o $(NAME) $(OBJ)

clean	:
	  $(RM) *.o *~

fclean	: clean
	  $(RM) $(NAME)

re	: clean all

.PHONY	: clean fclean ld re 
