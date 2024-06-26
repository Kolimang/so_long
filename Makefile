# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrichir <jrichir@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/26 10:28:29 by jrichir           #+#    #+#              #
#    Updated: 2024/06/26 16:52:34 by jrichir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------------- VARIABLES ------------------------------------

ROOT_DIR := $(realpath .)
INC_DIR  := $(ROOT_DIR)/include # test : added final /
SRC_DIR  := src/
OBJ_DIR  := build/

NAME     := so_long
CC       := cc
CFLAGS   := -I$(INC_DIR) -I$(INC_DIR)/libftx -I$(INC_DIR)/mlx # before : -I$(INC_DIR)
#CFLAGS   := -Wall -Wextra -Werror -I$(INC_DIR) -lm

AR       := ar -cr
RM       := rm -f

# 			use space or backslash as separator to add more
FILES    := main

SRCS     := $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJS     := $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

# --------------------------------- RULES --------------------------------------

.PHONY: bonus all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
#	@(cd include/libftx ; make all)
#	@(cd include/mlx ; make all)
	@$(CC) $(CFLAGS) -framework OpenGL -framework AppKit -L$(INC_DIR)libftx -lft -L$(INC_DIR)mlx -lmlx $(OBJS) -o $@
	@echo "Build $(NAME) program."

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@(cd include/libftx ; make all)
	@(cd include/mlx ; make all)
	@if [ ! -d $(OBJ_DIR) ]; then \
		mkdir -p $(OBJ_DIR); \
	fi
	@$(CC) $(CFLAGS) -Lmlx -lmlx -c $< -o $@

clean:
	@(cd include/libftx ; make clean)
	@$(RM) $(OBJS)
	@rm -rf $(OBJ_DIR)
	@echo "Delete $(NAME) object files and dependencies."

fclean: clean
	@(cd include/libftx ; make fclean)
	@$(RM) $(NAME)
	@echo "Delete $(NAME) program."

re: fclean all
