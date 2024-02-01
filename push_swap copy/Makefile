NAME = push_swap

LIBFT_NAME = libft.a

SRCS = main.c \
		push_swap.c \
		push_command.c \
		swap_command.c \
		rotate_command.c \
		reverse_rotate_command.c \
		error_handler.c \
		stack_utils.c \
		quick_sort.c

CFLAGS = -Wall -Wextra -Werror

BONUS_OBJS = ${BONUS_SRCS:.c=.o}

OBJS = ${SRCS:.c=.o}

all: ${NAME}

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

${NAME}: ${OBJS}
	make -C libft/ bonus
	cc $(CFLAGS) $^ -o $@ -L./libft -lft

clean:
	rm -f ${OBJS}
	make clean -C libft

fclean: clean
	rm -f ${NAME}
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
