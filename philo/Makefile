NAME = philo

SRCS=$(wildcard *.c)

CC = gcc
CFLAGS = -pthread -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRCS)
	@$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

clean:
	@rm -f $(NAME)

fclean:clean

re: clean all

.PHONY : all clean fclean re