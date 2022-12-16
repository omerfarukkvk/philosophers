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

norm: 
	@norminette *.[ch]

.PHONY : all clean fclean re norm