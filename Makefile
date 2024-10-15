# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtu <jtu@student.hive.fi>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/15 18:09:04 by jtu               #+#    #+#              #
#    Updated: 2024/10/15 18:22:45 by jtu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS 		=	ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_strlen.c \
				ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strnstr.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_striteri.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_lstnew_bonus.c\
				ft_lstadd_front_bonus.c\
				ft_lstsize_bonus.c\
				ft_lstlast_bonus.c\
				ft_lstadd_back_bonus.c\
				ft_lstdelone_bonus.c\
				ft_lstclear_bonus.c\
				ft_lstiter_bonus.c\
				ft_lstmap_bonus.c\

FT_PF_SRC	=	ft_printf.c \
		ft_put_function.c \
		ft_specifier.c \
		ft_numlen.c

GNL_SRC		=	get_next_line.c\
				get_next_line_utils.c

################################################################################
# GENERAL
################################################################################
OBJ_DIR		=	./obj
INCLUDES	=	./include

################################################################################
# COMPILATION
################################################################################
CC				=	cc
CC_STRICT		=	-Wall -Wextra -Werror
CC_DEBUG		=	-g #-fsanitize=leak
HEADERS			=	-I $(INCLUDES)
CC_FULL			=	$(CC) $(CC_STRICT) $(HEADERS) $(CC_DEBUG)

################################################################################
# LIBFT
################################################################################
NAME 		=	libft.a
LIBFT_DIR	=	./src
OBJECTS		=	$(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

################################################################################
# FT_PRINTF
################################################################################
FT_PF_DIR	=	./ft_printf
FT_PF_OBJ	=	$(addprefix $(OBJ_DIR)/, $(FT_PF_SRC:%.c=%.o))

################################################################################
# GNL
################################################################################
GNL_DIR		=	./get_next_line
GNL_OBJ		=	$(addprefix $(OBJ_DIR)/, $(GNL_SRC:%.c=%.o))

# vpath for finding source files
vpath %.c $(LIBFT_DIR) $(FT_PF_DIR) $(GNL_DIR)

all: $(NAME)

$(NAME): $(OBJECTS) $(FT_PF_OBJ) $(GNL_OBJ)
		@echo "--------------------------------------------"
		@ar -rcs $@ $^
		@echo "[$(NAME)] $(BLUE)Built static library $(NAME)$(RESET)"
		@echo "--------------------------------------------"

$(OBJ_DIR)/%.o: %.c
		@mkdir -p $(@D)
		@$(CC_FULL) -c $< -o $@

clean:
		@rm -rf $(OBJ_DIR)

fclean: clean
		@rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m
BLUE = \033[34m
