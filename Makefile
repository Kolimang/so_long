# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile_copy                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrichir <jrichir@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/26 10:28:29 by jrichir           #+#    #+#              #
#    Updated: 2024/06/26 10:28:33 by jrichir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------------- VARIABLES ------------------------------------

ROOT_DIR := $(realpath .)
INC_DIR  := $(ROOT_DIR)/include
SRC_DIR  := src/
OBJ_DIR  := build/

NAME     := so_long
CC       := cc
CFLAGS   := -Wall -Wextra -Werror -I$(INC_DIR) -lm

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
	@(cd include/libftx ; make all)
	@$(CC) $(CFLAGS) ./include/libftx/libft.a $(OBJS) -o $@
	@echo "Build $(NAME) program."

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@if [ ! -d $(OBJ_DIR) ]; then \
		mkdir -p $(OBJ_DIR); \
	fi
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@(cd include/libftx ; make clean)
	@$(RM) $(OBJS)
	@rm -rf $(OBJ_DIR)
	@echo "Delete push_swap object files and dependencies."

fclean: clean
	@(cd include/libftx ; make fclean)
	@$(RM) $(NAME)
	@echo "Delete push_swap program."

re: fclean all
