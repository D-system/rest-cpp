
NAME    = MyRestSql

SRC     =	main.cpp			\
		socket_listener.cpp		\
		client_handler.cpp		\
		router.cpp			\
		get_action.cpp			\
		errors.cpp

OBJ	= $(SRC:.cpp=.o)

CC      = g++

CFLAGS  = -W -Wall -O -O2

LFLAGS	= -lboost_system -pthread -lboost_regex

RM      = rm -f


all	 : $(OBJ)
	   $(CC) -o $(NAME) $(LFLAGS) $(OBJ)

clean	:
	  $(RM) *.o *~

fclean	: clean
	  $(RM) $(NAME)

re	: clean all

.PHONY	: clean fclean ld re 
