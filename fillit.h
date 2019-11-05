/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikadimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:51:09 by ikadimi           #+#    #+#             */
/*   Updated: 2019/11/04 18:51:11 by ikadimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"
# define BUFF_SIZE 1
# define A1N (stats->map[c->y + 1][c->x + 1] == 0)
# define A2N (stats->map[c->y + 1][c->x - 1] == 0)
# define A3N (stats->map[c->y - 1][c->x + 1] == 0)
# define A4N (stats->map[c->y - 1][c->x - 1] == 0)
# define RIGHT ((c->x + 1) < stats->x && stats->map[c->y][c->x + 1] == 0)
# define LEFT ((c->x - 1) >= 0 && stats->map[c->y][c->x - 1] == 0)
# define DOWN ((c->y + 1) < stats->y && stats->map[c->y + 1][c->x] == 0)
# define UP ((c->y - 1) >= 0 && stats->map[c->y - 1][c->x] == 0)
# define ANGLE1 ((c->x + 1) < stats->x && (c->y + 1) < stats->y && A1N)
# define ANGLE2 ((c->x - 1) >= 0 && (c->y + 1) < stats->y && A2N)
# define ANGLE3 ((c->x + 1) < stats->x && (c->y - 1) >= 0 && A3N)
# define ANGLE4 ((c->x - 1) >= 0 && (c->y - 1) >= 0 && A4N)

typedef struct		s_fill
{
	int				x;
	int				y;
	int				player;
	int				vs;
	int				**map;
	int				counter;
}					t_fill;

typedef struct		s_piece
{
	int				x;
	int				y;
	char			**piece;
}					t_piece;

typedef struct		s_cord
{
	int				x;
	int				y;
	int				score;
}					t_cord;

typedef struct		s_gnl
{
	int				ret;
	int				i;
	char			buf[BUFF_SIZE + 1];
	char			*tmp;
}					t_gnl;

int					get_next_line(const int fd, char **line);
void				piece_free(t_piece p);
void				map_free(t_fill stats);
void				tab_free(char **tab);
void				map_highlight(t_fill *stats);
void				fill_tab(t_fill *stats, char *line);
void				piece_handler(t_fill *stats, t_piece p);
int					piece_create(t_piece *p, char *line);
void				init_struct(t_fill *start, t_piece *p);

#endif
