NAME = push_swap

SRC = errors.c ft_split.c initialization.c main.c\
		push.c rotate.c rrotate.c sorts.c stacks.c\
		comove.c stack_util.c swap.c strs_utils.c\
		preinits.c

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra

DEL = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	 $(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(DEL) $(OBJ)

fclean: clean
	$(DEL) $(NAME)

re: fclean all

.PHONY: all clean fclean re