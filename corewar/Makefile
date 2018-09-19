# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acombe <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/25 21:24:42 by acombe            #+#    #+#              #
#    Updated: 2018/04/26 03:58:28 by bait-sli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = asmvm

.PHONY: all, clean, fclan, re

$(NAME):
	make -C ./ft_printf/
	make -C ./corewar_srcs/
	make -C ./asm_srcs/
	make -C ./minilibx/

all: $(NAME)

clean:
	make -C ./ft_printf/ clean
	make -C ./corewar_srcs/ clean
	make -C ./asm_srcs/ clean
	
fclean: clean
	make -C ./ft_printf/ fclean
	make -C ./corewar_srcs/ fclean
	make -C ./asm_srcs/ fclean

re: fclean all
