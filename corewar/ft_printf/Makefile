# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/07 20:02:57 by bait-sli          #+#    #+#              #
#    Updated: 2017/06/08 12:13:06 by bait-sli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_NAME		=		ft_printf.c\
							ft_convert_characters.c\
							ft_convert_signed.c\
							ft_convert_unsigned.c\
							ft_get_format_specifications.c\
							ft_itoa_base_lld.c\
							ft_itoa_base_llu.c\
							ft_unicode_encoder.c\
							ft_unicode_encoder_string.c\
							ft_get_raw_data.c\
							ft_get_specifiers.c\
							ft_process_characters.c\
							ft_process_data.c\
							ft_process_signed.c\
							ft_process_unsigned.c\
							ft_tools.c\
							ft_is_functions.c\
							ft_strndup.c\
							ft_strcnew.c\
							ft_strupcase.c
SRCS_PATH		=		srcs/
SRCS			=		$(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ_NAME		=		$(SRCS_NAME:.c=.o)
OBJ_PATH		=		obj/
OBJ				=		$(addprefix $(OBJ_PATH), $(OBJ_NAME))
NAME			=		libftprintf.a
FLAG			=		-Wall -Werror -Wextra
INC				=		./includes/

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	cp libft/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p obj
	gcc -c $(FLAGS) -I $(INC) $< -o $@

clean:
	make -C libft/ fclean
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
