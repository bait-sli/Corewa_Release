# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/18 02:27:27 by bait-sli          #+#    #+#              #
#    Updated: 2018/04/25 18:54:59 by bait-sli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME            = ../corewar
SRCS_NAME       = main.c\
				  check_args.c\
				  check_chp.c\
				  manual.c\
				  free_mem.c\
				  ft_dump..c\
				  ft_errors.c\
				  ft_parsing.c\
				  ft_play.c\
				  init_mem.c\
				  init_env.c\
				  kill_process.c\
				  new_process.c\
				  util.c\
				  ft_itoa_base.c\
				  render/ft_hook.c\
				  render/ft_render.c\
				  render/get_theme.c\
				  render/get_render_verbose.c\
				  render/render_player.c\
				  render/render_arena.c\
				  instruction/decode_ocp.c\
				  instruction/find_op.c\
				  instruction/ft_add.c\
				  instruction/ft_mul.c\
				  instruction/ft_div.c\
				  instruction/ft_mod.c\
				  instruction/ft_aff.c\
				  instruction/ft_and.c\
				  instruction/ft_fork.c\
				  instruction/ft_ld.c\
				  instruction/ft_ldi.c\
				  instruction/ft_lfork.c\
				  instruction/ft_live.c\
				  instruction/ft_lld.c\
				  instruction/ft_lldi.c\
				  instruction/ft_or.c\
				  instruction/ft_st.c\
				  instruction/ft_sti.c\
				  instruction/ft_sub.c\
				  instruction/ft_xor.c\
				  instruction/ft_zjmp.c\
				  instruction/get_params.c\
				  instruction/get_addr.c

SRCS_PATH       = ../corewar_srcs/
SRCS            = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ_NAME        = $(SRCS_NAME:.c=.o)
OBJ_PATH        = obj/
OBJ             = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
FLAGS           = -Wall -Wextra -Werror -Ofast -march=native
INC             = -I ../includes/ -I ../ft_printf/includes -I ../minilibx
LIB             = -L ../minilibx -lmlx -framework OpenGL -framework AppKit \
                  ../ft_printf/libftprintf.a\

.PHONY: all, clean, fclean, re

$(NAME): $(OBJ) ../includes/corewar.h ../includes/op.h ../includes/render.h ../includes/vm_macro.h
	make -C ../ft_printf/
	make -C ../minilibx/
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(INC) $(LIB)

all: $(NAME)

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p obj
	@mkdir -p obj/instruction
	@mkdir -p obj/render
	gcc -c $(FLAGS) $< -o $@ $(INC)

clean:
	make -C ../minilibx/ clean
	make -C ../ft_printf/ fclean
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -rf $(NAME)
	/bin/rm -rf $(OBJ_PATH)
re: fclean all
