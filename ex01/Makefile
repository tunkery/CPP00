SRCS = phonebook.cpp utils.cpp

OBJS = $(SRCS:.cpp=.o)
NAME = phonebook
CC = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c lib.hpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re