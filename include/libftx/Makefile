# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrichir <jrichir@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 15:59:07 by jrichir           #+#    #+#              #
#    Updated: 2024/06/04 15:11:03 by jrichir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

all:
	@if [ ! -f ./libft.a ]; then \
		echo "Build libft."; \
	fi
	@(cd libft; make all)
	@(cd ft_printf; make all)
	@mkdir -p temp ; \
	cd temp ; \
	ar -x ../libft/libft.a ; \
	ar -x ../ft_printf/libftprintf.a ; \
	ar -rcs ../libft.a *.o ; \
	cd .. ; \
	rm -rf temp

clean:
	@(cd libft ; make clean)
	@(cd ft_printf ; make clean)

fclean:
	@(cd libft ; make fclean)
	@(cd ft_printf ; make fclean)
	@rm -f libft.a
	@echo "Delete libft."

re: fclean all
