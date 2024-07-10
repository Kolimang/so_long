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

#-fsanitize=address
CFLAGS   := -I$(INC_DIR) -I$(INC_DIR)/libftx -I$(INC_DIR)/mlx -g -Wall -Wextra -Werror

AR       := ar -cr
RM       := rm -f

# 			use space or backslash as separator to add more
FILES    := main check_lines check_map check_map2 check_path flood_fill graphics init move utils_arrays

SRCS     := $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJS     := $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

# --------------------------------- RULES --------------------------------------

.PHONY: bonus all clean fclean re

all: $(NAME)

$(NAME): libft.a libmlx.a $(OBJS)
	@if [ ! -f ./so_long ]; then \
		echo "Build $(NAME) program."; \
	fi
	@$(CC) $(CFLAGS) -g -framework OpenGL -framework AppKit -L$(INC_DIR)/libftx -lft -L$(INC_DIR)/mlx -lmlx $(OBJS) -o $@

libft.a:
	@(cd include/libftx ; make all)

libmlx.a:
	@(cd include/mlx ; make all)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@if [ ! -d $(OBJ_DIR) ]; then \
		mkdir -p $(OBJ_DIR); \
	fi
	@$(CC) $(CFLAGS) -c $< -o $@

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
