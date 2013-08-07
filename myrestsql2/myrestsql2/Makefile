
NAME    = MyRestSql

INSTALL_DIR = /usr/local/bin

FILES_DIR = /etc/MyRestSql

RC_FILE = myrestsql.rc

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

LFLAGS	= -pthread -lboost_system-mt -lboost_regex-mt -lboost_filesystem-mt

RM      = rm -f


all	:  $(OBJ)
	   $(CC) -o $(NAME) $(LFLAGS) $(OBJ)

install	:
	  mkdir -p $(INSTALL_DIR)
	  mkdir -p $(FILES_DIR)
	  cp $(NAME) $(INSTALL_DIR)
	  cp $(RC_FILE) /etc/init.d/
	  insserv $(RC_FILE)

uninstall:
	  insserv --remove $(RC_FILE)

clean	:
	  find . -name "*~" -exec rm {} \;
	  find . -name "*.o" -exec rm {} \;

fclean	: clean
	  $(RM) $(NAME)

re	: clean all

.PHONY	: clean fclean ld re install
