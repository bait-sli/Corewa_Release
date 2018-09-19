/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bait-sli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/14 07:25:23 by bait-sli          #+#    #+#             */
/*   Updated: 2018/04/26 05:37:01 by bait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "ft_printf.h"
# include <fcntl.h>
# include <sys/types.h>
# include <stdio.h>
# include <stdint.h>
# include <limits.h>
# include "op.h"
# include "asm_macro.h"

typedef struct		s_format
{
	int				only_label;
	int				dir_instruct;
	int				labeled_instruct;
	int				line_in_file;
	int				has_ocp;
}					t_format;

typedef struct		s_parse
{
	char			*line;
	char			*op_name;
	uint8_t			opcode;
	char			*label_name;
	char			**params;
	int				*binary;
	size_t			dir_size;
	size_t			content_size;
	uint8_t			ocp;
	t_format		form;
	struct s_parse	*next;
}					t_parse;

typedef struct		s_verif
{
	int				name;
	int				comment;
	int				ref_pos;
	int				line_pos;
	int				lab_pos;
	int				check_sum;
}					t_verif;

typedef struct		s_env
{
	t_parse			*buff;
	t_verif			verif;
	char			*output_name;
	int				magic_nbr;
	char			*prog_name;
	int				prog_length;
	char			*prog_comment;
	char			*error_code;
	int				line_nbr;
}					t_env;

void				ft_parsing(char *file, t_env *env);
long long			ft_atoi_long_long(const char *str);
void				ft_error(char *format, t_env *env);
void				ft_line_error(char *format, t_env *env, int index);
void				ft_label_error(char *format, char *label, t_env *env);
void				add_lab_instruct(char *line, t_parse **buff, t_env *env);
void				add_instruction(char *line, t_parse **buff, t_env *env);
void				add_label(char *line, t_parse **buff, t_env *env);
int					ft_check_instruction(char *line, t_env *env);
int					ft_live(char *line, t_env *env);
int					ft_ld(char *line, t_env *env);
int					ft_st(char *line, t_env *env);
int					ft_mul(char *line, t_env *env);
int					ft_div(char *line, t_env *env);
int					ft_mod(char *line, t_env *env);
int					ft_add(char *line, t_env *env);
int					ft_sub(char *line, t_env *env);
int					ft_and(char *line, t_env *env);
int					ft_or(char *line, t_env *env);
int					ft_xor(char *line, t_env *env);
int					ft_zjmp(char *line, t_env *env);
int					ft_ldi(char *line, t_env *env);
int					ft_sti(char *line, t_env *env);
int					ft_fork(char *line, t_env *env);
int					ft_lld(char *line, t_env *env);
int					ft_lldi(char *line, t_env *env);
int					ft_lfork(char *line, t_env *env);
int					ft_aff(char *line, t_env *env);
int					isreg(char *line);
int					isdir(char *line);
int					is_name(char *line, char *format);
int					isindir(char *line);
int					ft_label_and_instru(char *line, t_env *env);
int					line_is_empty(char *line);
int					ft_is_label_only(char *line, t_env *env);
int					ft_is_header(char *line, char *macro);
int					ft_is_comment(char *line);
int					ft_atoi_base(char *str, int base);
int					char_len(char **format);
int					ft_count_char(char *str, char c);
int					tab_len(int *tab);
int					ft_charchr(char *line, char c);
char				*rm_comment_in_hd(char *line);
void				ft_output(t_env *env);
char				*ft_epur_str(char *str);
char				*remove_comment(char *line);
int					dump_header(char *line, t_env *env, char *macro);
void				free_parse(t_parse **content);
int					free_split(int ret, char **content);
int					free_and_return(int ret, char *data);
void				free_mem(t_env *env);
void				ft_build_content(t_parse **buff);
void				get_op_and_dir_size(t_parse *elem);
void				check_label(t_parse **buff, t_env *env);
int					label_ref(char *data);
int					params_size(char *param, int dir);
void				ft_label_to_int(t_env *env);
void				replace_ref(t_env *env, t_parse **buff);
void				ft_convert(t_parse **buff);

#endif
