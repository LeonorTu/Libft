NAME = libftprintf.a

SRCS = ft_printf.c \

CFLAGS = -Wall -Wextra -Werror

BONUS_OBJS = ${BONUS_SRCS:.c=.o}

OBJS = ${SRCS:.c=.o}

all: ${NAME}

%.o: %.c
	cc $(CFLAGS) -c $< -o $@
	ar rcs ${NAME} $@

${NAME}: ${OBJS}

bonus: ${OBJS} ${BONUS_OBJS}

clean:
	rm -f ${OBJS} ${BONUS_OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
