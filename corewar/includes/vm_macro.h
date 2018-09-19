/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_macro.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 03:53:51 by yarypert          #+#    #+#             */
/*   Updated: 2018/04/26 03:54:21 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_MACRO_H
# define VM_MACRO_H

# define NBR "-n"
# define RENDER "-render"
# define DMP "-dump"
# define VRBS "-verbose"
# define EXT ".cor"
# define ARGS_ERR "\e[1;31mNo arg! Please specify options and champions\e[0m"
# define BAD_EXT "\e[1;31minvalid format \nUSAGE: ./asm <champ.s> ....\e[0m"
# define PARSE_ERR "\e[1;31mCheck ur args format there is an invalid arg\e[0m"
# define ERR_FILE "\e[1;31mFile is not valid\e[0m"
# define TOO_MANY_ARG "\e[1;31mToo many champions, max: 4\e[0m"
# define BAD_PLR_NB "\e[1;31mWrong format for player number\e[0m"
# define DOUBLE_ARG "\e[1;31mSame option declared 2 times\e[0m"
# define BAD_DMP_FORMAT "\e[1;31mOnly digit after -dump cmd\e[0m"
# define MALLOC_ERR "\e[1;31mUnable to init args array\e[0m"
# define PATH_ERR "\e[1;31mUnable to find asset\e[0m"
# define BAD_MAGIC "\e[1;31mMagic number is not valid\e[0m"
# define BIG_SIZE_NBR "\e[1;31mNumber size is too big\e[0m"
# define SIZE_ERR "\e[1;31mBuffer or file too big than max size\e[0m"
# define SIZE_DIFF "\e[1;31mSize number and real size are differents\e[0m"
# define HEADER_ERR "\e[1;31mHeader content error\e[0m"

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
# define MUL_OP 0x11
# define DIV_OP 0x12
# define MOD_OP 0x13

# define REG_OP 1
# define DIR_OP 2
# define INDIR_OP 3

#endif
