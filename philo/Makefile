NAME = philo
CC = clang
CFLAGS = -Wall -Wextra -Werror
PTHREAD = -pthread
SRCS = main.c messages.c tools.c init.c exit.c actions.c
OBJS = $(SRCS:.c=.o)
RM = rm -f


all: $(NAME)

compil_no_flag:
	$(CC) -c $(SRCS)

no_flag: compil_no_flag
	$(CC) -pthread $(OBJS) -o $(NAME)

$(NAME): $(OBJS)
	$(CC) -pthread $(OBJS) -o $(NAME)

sani: $(OBJS)
	$(CC) $(OBJS) -fsanitize=thread -g -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
