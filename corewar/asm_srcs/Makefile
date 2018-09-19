# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/28 06:45:12 by bait-sli          #+#    #+#              #
#    Updated: 2018/04/26 05:36:45 by bait-sli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../asm

SRCS_NAME =		free_mem.c\
				ft_lfork.c\
				ft_xor.c\
				add_composed_instruction.c\
				ft_add.c\
				ft_live.c\
				ft_zjmp.c\
				add_instruction.c\
				ft_aff.c\
				ft_lld.c\
				main.c\
				add_label.c\
				ft_and.c\
				ft_lldi.c\
				op.c\
				check_instruction.c\
				ft_atoi_base.c\
				ft_or.c\
				output.c\
				check_line.c\
				ft_dump_header.c\
				ft_parsing.c\
				tools.c\
				check_params.c\
				ft_fork.c\
				ft_st.c\
				epur_str.c\
				ft_ld.c\
				ft_sti.c\
				errors.c\
				ft_ldi.c\
				ft_mul.c\
				ft_div.c\
				ft_mod.c\
				ft_sub.c\
				check_label.c\
				build_content.c\
				get_op_and_dir_size.c\
				label_to_int.c\
				replace_label.c\
				ft_atoi_long_long.c\
				get_ocp.c

SRCS_PATH       = ../asm_srcs/
SRCS            = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ_NAME        = $(SRCS_NAME:.c=.o)
OBJ_PATH        = obj/
OBJ             = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
FLAGS           = -Wall -Wextra -Werror
INC             = -I../includes/ -I../ft_printf/includes/
LIB             = ../ft_printf/libftprintf.a\

.PHONY: all, clean, fclean, re

$(NAME): $(OBJ) ../includes/asm.h ../includes/asm_macro.h ../includes/op.h
				make -C ../ft_printf/
				gcc $(FLAGS) -o $(NAME) $(OBJ) $(INC) $(LIB)

all: $(NAME) 

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
				@mkdir -p obj
				gcc -c $(FLAGS) $< -o $@ $(INC)

clean:
				make -C ../ft_printf/ fclean
				/bin/rm -rf $(OBJ)

fclean: clean
				/bin/rm -rf $(NAME)
				/bin/rm -rf $(OBJ_PATH)
re: fclean all
