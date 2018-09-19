/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macro.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 07:25:11 by bait-sli          #+#    #+#             */
/*   Updated: 2018/04/15 07:20:09 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_MACRO_H
# define ASM_MACRO_H

# define ARGS_ERR "\e[1;31mNo arg \nUSAGE: ./asm <champ.s> ....\e[0m"
# define BAD_EXT "\e[1;31minvalid format \nUSAGE: ./asm <champ.s> ....\e[0m"
# define ERR_FILE "\e[1;31mFile is not valid\e[0m"
# define HEADER_ERR "\e[1;31mSYNTAX ERROR:\e[0m Name or comment error line: "
# define NAME_ERR "Name or comment too long"
# define ERR_SIZE "Program size too big"
# define SUCCES "\e[0;32mWriting output program to: \e[0m"
# define OUTPUT_EXT ".cor"
# define INNER_EXT ".s"
# define INV_INSTRU "\e[1;31mINVALID INSTRUCT:\e[0m unknown instruction line: "
# define BAD_PARAM_NBR "\e[1;31mBAD NUMBERS OF PARAMS\e[0m error line: "
# define LABEL_ERR "\e[1;31mUNKNOW LABEL:\e[0m Reference to unknow label line "
# define PARAM_ERR "\e[1;31mSYNTAX ERROR:\e[0m Invalid param at line: "
# define LABEL_INVALID_FORMAT "\e[1;31mERROR:\e[0m invalid label char line "
# define EMPTY_FILE "\e[1;31mEmpty file!\e[0m"
# define BIG_SIZE "\e[1;31mProgram size too big\e[0m"
# define CREAT_FILE_ERR "\e[1;31mError when try creating file\e[0m"

# define LIVE_OP 0x1
# define LD_OP 0x2
# define ST_OP 0x3
# define AND_OP 0x6
# define OR_OP 0x7
# define ADD_OP 0x4
# define SUB_OP 0x5
# define XOR_OP 0x8
# define ZJMP_OP 0x9
# define LDI_OP 0x0a
# define STI_OP 0x0b
# define FORK_OP 0x0c
# define LLDI_OP 0x0e
# define LLD_OP 0x0d
# define LFORK_OP 0x0f
# define AFF_OP 0x10
# define REG_OP 1
# define DIR_OP 2
# define INDIR_OP 3

# define REG_DIGIT "0123456"

#endif
