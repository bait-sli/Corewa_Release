/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 03:54:46 by yarypert          #+#    #+#             */
/*   Updated: 2018/04/26 05:06:12 by acombe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include "render.h"
# include "op.h"
# include "mlx.h"
# include "vm_macro.h"
# include "ft_printf.h"
# include <stdlib.h>
# include <stdint.h>
# include <fcntl.h>
# include <sys/types.h>
# include <unistd.h>

typedef struct	s_param
{
	int				ok_ocp;
	int				dir;
	int				fsize;
	int				p[3];
	uint8_t			ocp[3];
	void			(*f)();
}				t_param;

typedef struct	s_process
{
	int					reg[REG_NUMBER + 1];
	uint16_t			pc;
	int					carry;
	int					couldown;
	int					color;
	int					play;
	int					rip;
	t_param				par;
	struct s_process	*next;
}				t_process;

typedef struct	s_player
{
	int			booked;
	char		*path;
	int			magic;
	char		name[PROG_NAME_LENGTH + 1];
	char		*uname;
	char		comment[COMMENT_LENGTH + 1];
	int			nbr;
	int			size;
	int			total_lives;
	int			color;
	uint8_t		content[CHAMP_MAX_SIZE + 1];
	int			main_pc;
}				t_player;

typedef struct	s_memory
{
	uint8_t	octet;
	char	*itoa_value;
	int		pc_here;
	int		live_here;
	int		color;
}				t_memory;

typedef struct	s_verbose
{
	char	*content;
	int		color;
	int		booked;
}				t_verbose;

typedef struct	s_verif
{
	int died_cld;
	int lives_prd;
	int nbr_check;
	int render;
	int dump;
	int dump_cycle;
	int pause;
	int last_live_id;
	int game_over;
	int verbose;
	int win_clr;
}				t_verif;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*frame;
	void		*stuff[4];
	int			processes;
	int			cycle_to_die;
	int			cycle_delta;
	int			cycle;
	int			nbr_live;
	char		*winner;
	t_memory	mem[MEM_SIZE];
	t_player	p[MAX_ARGS_NUMBER];
	t_verif		vr;
	t_process	*data;
	t_verbose	v[12];
	int			no_more_vrb;
}				t_env;

void			ft_init(t_env *env);

void			ft_init_env(t_env *env);

char			*ft_itoa_base(intmax_t value, int base);
void			ft_render(t_env *env);
int				ft_redraw(t_env *env);
int				ft_keyhook(int key, t_env *env);
void			ft_display(t_env *env);

void			ft_error(char *format, t_env *env);
void			free_mem(t_env *env);
void			free_split(char **content);

void			check_args(char **arg, int len, t_env *env);
void			ft_arg_error(char *format, char **arg, t_env *env);

void			ft_parsing(t_env *env);

int				st_isdigit(char *line);
void			ft_convert_mem(t_memory mem[MEM_SIZE]);

void			init_mem(t_env *env);

void			ft_destroy(t_process **all, int pos);
void			end_game(t_env *env);
void			ft_gameplay(t_env *env);

void			free_arena(t_memory mem[MEM_SIZE]);
void			check_dump(t_env *env);

void			ft_try_op(t_process *current, t_env *env);
int				ft_add(t_process *current, t_env *env);
int				ft_mul(t_process *current, t_env *env);
int				ft_div(t_process *current, t_env *env);
int				ft_mod(t_process *current, t_env *env);
int				ft_aff(t_process *current, t_env *env);
int				ft_and(t_process *current, t_env *env);
int				ft_fork(t_process *current, t_env *env);
int				ft_ld(t_process *current, t_env *env);
int				ft_ldi(t_process *current, t_env *env);
int				ft_lfork(t_process *current, t_env *env);
int				ft_live(t_process *current, t_env *env);
int				ft_lld(t_process *current, t_env *env);
int				ft_lldi(t_process *current, t_env *env);
int				ft_or(t_process *current, t_env *env);
int				ft_st(t_process *current, t_env *env);
int				ft_sti(t_process *current, t_env *env);
int				ft_sub(t_process *current, t_env *env);
int				ft_xor(t_process *current, t_env *env);
int				ft_zjmp(t_process *current, t_env *env);

void			ft_add_process(t_process **all, t_process *dad, int pc);

void			get_buff(uint8_t *ret, t_memory mem[MEM_SIZE],
		uint16_t start, int size);
void			ocp_to_params(uint8_t *ret, uint8_t nb);
int				get_uint16(uint8_t t[2]);
int				get_integer(uint8_t t[4]);
int				check_reg(t_param *pls);

void			ft_get_params(t_process *ec, t_env *env);

int				ft_endian(int x);

uint16_t		ft_get_addr(uint16_t pc, int addr, int modulo);

void			parse_stuff(t_env *env);
void			get_theme(t_env *env);
void			get_verbose(t_env *env, t_process *ec, char *format, int value);

void			check_chp(char **arg, int len, t_env *env);
int				ischp(char *arg);
void			display_free(int format, int x, int y, t_env *env);
void			render_players(void *mlx, void *win, t_player p[4], t_env *env);
void			render_arena(void *mlx, void *win, t_memory mem[MEM_SIZE]);
void			display_manual(void);
void			ft_intro(t_env *env);
#endif
