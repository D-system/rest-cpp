
NAME    = MyRestSql

SRC     =	main.cpp			\
		socket_listener.cpp		\
		client_handler.cpp		\
		router.cpp			\
		get_action.cpp			\
		post_action.cpp			\
		delete_action.cpp		\
		responses.cpp

OBJ	= $(SRC:.cpp=.o)

CC      = g++

CFLAGS  = -W -Wall -O -O2

LFLAGS	= -lboost_system -pthread -lboost_regex -lboost_filesystem

RM      = rm -f


all	 : $(OBJ)
	   $(CC) -o $(NAME) $(LFLAGS) $(OBJ)

clean	:
	  $(RM) *.o *~

fclean	: clean
	  $(RM) $(NAME)

re	: clean all

.PHONY	: clean fclean ld re 
