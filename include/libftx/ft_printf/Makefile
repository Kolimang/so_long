# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrichir <jrichir@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/20 12:26:19 by jrichir           #+#    #+#              #
#    Updated: 2024/04/15 12:16:49 by jrichir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
INC				=	-Iinclude
AR				=	ar
ARFLAGS 		=	rcs
RM				=	rm -rf

SRC				=	ft_printf \
					ft_printf_utils_str \
					ft_printf_utils_nb \
					ft_printf_char \
					ft_printf_hex \
					ft_printf_int \
					ft_printf_ptr \
					ft_printf_str \
					ft_printf_u


SRC_DIR			=	src
OBJ_DIR			=	build

SRCS 			=	$(addsuffix .c, $(SRC))
OBJS			=	$(SRCS:%.c=$(OBJ_DIR)/%.o)


# --------------------------------- RULES --------------------------------------

.PHONY:				all clean fclean re libftprintf

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.c
					@mkdir -p $(OBJ_DIR)
					@$(CC) $(CFLAGS) $(INC) -c -o $@ $<

all:				$(NAME)

$(NAME):			$(OBJS)
					@$(AR) $(ARFLAGS) $(NAME) $(OBJS)

clean:
					@$(RM) $(OBJ_DIR)

fclean:				clean
					@$(RM) $(NAME)

re:					fclean all
