
NAME    = MyRestSql

SRC     =	main.cpp			\
		socket_listener.cpp		\
		client_handler.cpp		\
		router.cpp			\
		get_action.cpp			\
		post_action.cpp			\
		delete_action.cpp		\
		put_action.cpp			\
		responses.cpp

OBJ	= $(SRC:.cpp=.o)

CC      = g++

CXXFLAGS  = -W -Wall

# CXXFLAGS  = -W -Wall -I/cygdrive/c/Users/Dev/Downloads/boost_1_54_0/ -D__USE_W32_SOCKETS -D _WIN32_WINNT=0x0501

LFLAGS	= -pthread -lboost_system-mt -lboost_regex-mt -lboost_filesystem-mt

RM      = rm -f


all	 : $(OBJ)
	   $(CC) -o $(NAME) $(LFLAGS) $(OBJ)

clean	:
	  $(RM) *.o *~

fclean	: clean
	  $(RM) $(NAME)

re	: clean all

.PHONY	: clean fclean ld re 
