NAME = libftprintf.a

SRCS = ft_printf.c \
		ft_put_function.c \
		ft_specifier.c \

CFLAGS = -Wall -Wextra -Werror

BONUS_OBJS = ${BONUS_SRCS:.c=.o}

OBJS = ${SRCS:.c=.o}

all: ${NAME}

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

${NAME}: ${OBJS}
	$(MAKE) -C libft/ bonus
	cp libft/libft.a libftprintf.a
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
