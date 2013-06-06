
NAME    = MyRestSql

SRC     =	main.c			\
		socket_listener.cpp

OBJ	= $(SRC:.c=.o)

CC      = g++

CFLAGS  = -W -Wall -O -O2

LFLAGS	= -lboost_system -pthread

RM      = rm -f


all	 : $(OBJ)
	   $(CC) -o $(NAME) $(LFLAGS) $(OBJ)

clean	:
	  $(RM) *.o *~

fclean	: clean
	  $(RM) $(NAME)

re	: clean all

.PHONY	: clean fclean ld re 
