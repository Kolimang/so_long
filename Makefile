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

ROOT_DIR  := $(realpath .)
INC_DIR   := $(ROOT_DIR)/include
SRC_DIR   := src/
OBJ_DIR   := build/
LIBFT_DIR := $(INC_DIR)/libftx
MLX_DIR   := $(INC_DIR)/mlx

NAME     := so_long
CC       := cc

CFLAGS   := -I$(INC_DIR) -I$(LIBFT_DIR) -I$(MLX_DIR) -Wall -Wextra -Werror -g
MLXFLAGS := -framework OpenGL -framework AppKit -L$(INC_DIR)/mlx -lmlx

RM       := rm -f

FILES    := main check_lines check_map check_map2 check_path flood_fill \
			graphics init move utils_arrays

SRCS     := $(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJS     := $(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

# --------------------------------- RULES --------------------------------------

.PHONY: bonus all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT_DIR)/libft.a $(MLX_DIR)/libmlx.a $(OBJ_DIR) $(OBJS)
	@echo "Build $(NAME) program."
	@$(CC) $(CFLAGS) $(MLXFLAGS) -L$(INC_DIR)/libftx -lft $(OBJS) -o $@

$(OBJ_DIR):
	@if [ ! -d $(OBJ_DIR) ]; then \
		mkdir -p $(OBJ_DIR); \
	fi

$(LIBFT_DIR)/libft.a:
	@(cd include/libftx ; make all)

$(MLX_DIR)/libmlx.a:
	@(cd include/mlx ; make all)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
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
