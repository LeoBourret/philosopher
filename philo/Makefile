NAME = philo
CC = clang
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c tools.c
OBJS = $(SRCS:.c=.o)
RM = rm -f

all: $(NAME)

compil_no_flag:
	$(CC) -c $(SRCS)

no_flag: compil_no_flag
	$(CC) $(OBJS) -o $(NAME)
$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
