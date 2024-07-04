# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrichir <jrichir@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/26 10:28:29 by jrichir           #+#    #+#              #
#    Updated: 2024/07/04 10:18:30 by jrichir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------------- VARIABLES ------------------------------------

ROOT_DIR := $(realpath .)
INC_DIR  := $(ROOT_DIR)/include
SRC_DIR  := src/
OBJ_DIR  := build/

NAME     := so_long
CC       := cc
#CFLAGS   := -I$(INC_DIR) -Wall -Wextra -Werror
CFLAGS   := -I$(INC_DIR) -I$(INC_DIR)/libftx -I$(INC_DIR)/mlx -g

AR       := ar -cr
RM       := rm -f

# 			use space or backslash as separator to add more
FILES    := main checks

SRCS     := $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJS     := $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

# --------------------------------- RULES --------------------------------------

.PHONY: bonus all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -g -framework OpenGL -framework AppKit -L$(INC_DIR)/libftx -lft -L$(INC_DIR)/mlx -lmlx $(OBJS) -o $@
#	@$(CC) $(CFLAGS) -g -framework OpenGL -framework AppKit -lft -lmlx $(OBJS) -o $@
#	@$(CC) $(CFLAGS) -g -framework OpenGL -framework AppKit $(OBJS) -o $@
	@echo "Build $(NAME) program."

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@(cd include/libftx ; make all)
	@(cd include/mlx ; make all)
	@if [ ! -d $(OBJ_DIR) ]; then \
		mkdir -p $(OBJ_DIR); \
	fi
	@$(CC) $(CFLAGS) -lft -lmlx -c $< -o $@
#	@$(CC) $(CFLAGS) -L$(INC_DIR)/libftx -lft -L$(INC_DIR)/mlx -lmlx -c $< -o $@
#	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@(cd include/libftx ; make clean)
	@(cd include/mlx ; make clean)
	@$(RM) $(OBJS)
	@rm -rf $(OBJ_DIR)
	@echo "Delete $(NAME) object files and dependencies."

fclean: clean
	@(cd include/libftx ; make fclean)
	@$(RM) $(NAME)
	@echo "Delete $(NAME) program."

re: fclean all
