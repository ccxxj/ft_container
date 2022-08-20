NAME	=	unit_test
SRCS	=	catch_amalgamated.cpp \
			unit_test.cpp 
OBJS	= $(SRCS:.c=.o)
CC		= clang++
FLAGS	= -Wall -Wextra -Werror -fsanitize=address -g -std=c++14

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

%.o: %.c $(HEADER_FILE)
	$(CC) -c $(FLAGS) -o $@ $<

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re