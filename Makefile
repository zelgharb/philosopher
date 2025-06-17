NAME	= philo

SRCS	= 	ft_split.c \
			parser.c \
			print_error.c \
			test_thread.c \
			main.c \
			routine.c

OBJS	= $(SRCS:.c=.o)

FLAGS	= -Wall -Wextra -Werror #-g3 -fsanitize=address
CC		= cc

$(NAME): $(OBJS) 
	$(CC) $(FLAGS) $(OBJS)  -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re