/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yarypert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 03:52:53 by yarypert          #+#    #+#             */
/*   Updated: 2018/04/26 03:53:47 by yarypert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# define EXIT "Press ESC to exit game"
# define PAUSE "Game paused, press SPACE to resume"
# define WINNER "The winner is: "
# define UNDEF "Undefined !"
# define NAME "Corewar Arena"
# define PARSE_PATH "asset/neutral.xpm"
# define AR_1 "asset/player1.xpm"
# define AR_2 "asset/player2.xpm"
# define AR_3 "asset/player3.xpm"
# define AR_4 "asset/player4.xpm"

# define FEN_X 1900
# define FEN_Y 1200

# define LONGITUDE 25
# define LATITUDE 20
# define LONG_DIFF 20
# define LAT_DIFF 18

# define SLEEP_TIME 2

# define CLR_P1 0x86F05B
# define CLR_P2 0xD58AE7
# define CLR_P3 0xD69D63
# define CLR_P4 0x21D7FF
# define NEUTRAL_CLR 0xCACACA

# define PROCESS_CLR 0x080808
# define LIVE_CLR 0xFF0000

# define ASCII_P1 32
# define ASCII_P2 33
# define ASCII_P3 31
# define ASCII_P4 34
# define ASCII_NTR 37

# define PLR_CORD_X 1445
# define PLR_CORD_Y 510
# define PLR_SCALE 30
# define PLR_DIS 128

# define VISU_POS_X 1640
# define VISU_POS_Y 190

# define SUSPEND 35
# define RUN 49
# define ECS 53

typedef struct	s_dsp
{
	int lat;
	int lon;
	int ter;
	int ter2;
	int c;
}				t_dsp;

#endif
