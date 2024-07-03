# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrichir <jrichir@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 15:59:07 by jrichir           #+#    #+#              #
#    Updated: 2024/07/03 16:43:04 by jrichir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------------- VARIABLES ------------------------------------

NAME := libft.a
CC := cc
CFLAGS := -Wall -Wextra -Werror
INC = -Iinclude
AR := ar -cr
RM := rm -f

SRC_DIR := src/
OBJ_DIR := build/

FILES := gnl \
		gnl_utils \
		ft_memset \
		ft_bzero \
		ft_calloc \
		ft_memcpy \
		ft_memmove \
		ft_memchr \
		ft_memcmp \
		ft_strlen \
		ft_strlcpy \
		ft_strlcat \
		ft_strchr \
		ft_strrchr \
		ft_strnstr \
		ft_strncmp \
		ft_atoi \
		ft_isalpha \
		ft_isdigit \
		ft_isalnum \
		ft_isascii \
		ft_isprint \
		ft_toupper \
		ft_tolower \
		ft_strdup \
		ft_strjoin \
		ft_substr \
		ft_strtrim \
		ft_split \
		ft_itoa \
		ft_strmapi \
		ft_striteri \
		ft_putchar_fd \
		ft_putstr_fd \
		ft_putendl_fd \
		ft_putnbr_fd \
		ft_lstnew \
		ft_lstadd_front \
		ft_lstsize \
		ft_lstlast \
		ft_lstadd_back \
		ft_lstdelone \
		ft_lstclear \
		ft_lstiter \
		ft_lstmap

SRCS := $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJS := $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))


# --------------------------------- RULES --------------------------------------

.PHONY: bonus all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $@ $^

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@if [ ! -d $(OBJ_DIR) ]; then \
		mkdir -p $(OBJ_DIR); \
	fi
	@$(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@$(RM) $(OBJS)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
