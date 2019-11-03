/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikadimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:59:26 by ikadimi           #+#    #+#             */
/*   Updated: 2019/11/02 21:08:24 by ikadimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft/libft.h"
#define BUFF_SIZE 1
#define RIGHT ((j + 1) < stats->x && stats->map[i][j + 1] == 0)
#define LEFT ((j - 1) >= 0 && stats->map[i][j - 1] == 0)
#define DOWN ((i + 1) < stats->y && stats->map[i + 1][j] == 0)
#define UP ((i - 1) >= 0 && stats->map[i - 1][j] == 0)
#define ANGLE1 ((j + 1) < stats->x && (i + 1) < stats->y && stats->map[i + 1][j + 1] == 0)
#define ANGLE2 ((j - 1) >= 0 && (i + 1) < stats->y && stats->map[i + 1][j - 1] == 0)
#define ANGLE3 ((j + 1) < stats->x && (i - 1) >= 0 && stats->map[i - 1][j + 1] == 0)
#define ANGLE4 ((j - 1) >= 0 && (i - 1) >= 0 && stats->map[i - 1][j - 1] == 0)

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

void	tab_free(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	tab = NULL;
}

void	structs_free(t_fill stats, t_piece p)
{
	int i;

	i = 0;
	while (i < stats.y)
		free(stats.map[i++]);
	free(stats.map);
	i = 0;
	while (i < p.y)
		free(p.piece[i++]);
	free(p.piece);
}

char	*ft_freejoin(char *s1, char *s2)
{
	char	*fr;
	size_t	v;

	if (!s1 || !s2)
		return (NULL);
	v = ft_strlen(s1) + ft_strlen(s2);
	if (!(fr = ft_strnew(v + 1)))
		return (NULL);
	ft_strcpy(fr, s1);
	ft_strcat(fr, s2);
	ft_strdel(&s1);
	s1 = NULL;
	return (fr);
}

int		get_next_line(const int fd, char **line)
{
	int				ret;
	static char		*temp;
	int				i;
	char			buf[BUFF_SIZE + 1];
	char			*tmp;

	i = 0;
	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	if (temp == NULL)
		temp = ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		temp = ft_freejoin(temp, buf);
		if (ft_strchr(temp, '\n'))
			break ;
	}
	while (temp[i] != '\n' && temp[i])
		i++;
	if (!ft_strlen(temp) && !ret && !i)
		return (0);
	tmp = temp;
	*line = ft_strsub(temp, 0, i);
	temp = ft_strdup(temp + i + 1);
	free(tmp);
	return (1);
}

void	init_struct(t_fill *start)
{
	start->x = 0;
	start->y = 0;
	start->player = 0;
	start->vs = 0;
	start->map = NULL;
	start->counter = 0;
}

void	assign_player(t_fill *stats, char *line)
{
	if (ft_strstr(line, "p1"))
	{
		stats->player = -1;
		stats->vs = -2;
	}
	else
	{
		stats->player = -2;
		stats->vs = -1;
	}
}

void	map_create(t_fill *stats, char *line, int fd)
{
	char **tab;
	int i;

	i = 0;
	tab = ft_strsplit(line, ' ');
	stats->y = ft_atoi(tab[1]);
	stats->x = ft_atoi(tab[2]);
	stats->map = (int **)malloc(sizeof(int *) * stats->y);
	while (i < stats->y)
		stats->map[i++] = (int *)malloc(sizeof(int) * stats->x);
	tab_free(tab);
}

void	piece_create(t_piece *p, char *line)
{
	char **tab;
	int i;

	i = 0;
	tab = ft_strsplit(line, ' ');
	p->y = ft_atoi(tab[1]);
	p->x = ft_atoi(tab[2]);
	p->piece = (char **)malloc(sizeof(char *) * p->y);
	while (i < p->y)
		p->piece[i++] = (char *)malloc(sizeof(char) * p->x);
	tab_free(tab);
}

void	fill_tab(t_fill *stats, char *line, int fd)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_strsplit(line, ' ');
	while (tmp[1][i])
	{
		if (tmp[1][i] == 'X' || tmp[1][i] == 'x')
			stats->map[stats->counter - 1][i] = -2;
		else if (tmp[1][i] == 'O' || tmp[1][i] == 'o')
			stats->map[stats->counter - 1][i] = -1;
		else
			stats->map[stats->counter - 1][i] = 0;
		i++;
	}
	tab_free(tmp);
}

int		map_highlighter(t_fill *stats, int last, int outline)
{
	int i;
	int j;
	int	r;

	i = 0;
	r = 0;
	while (i < stats->y)
	{
		j = 0;
		while (j < stats->x)
		{
			if (stats->map[i][j] == last)
			{
				if (RIGHT || LEFT || DOWN || UP || ANGLE1 || ANGLE2
					|| ANGLE3 || ANGLE4)
					r = 1;
				if (RIGHT)
					stats->map[i][j + 1] = outline;
				if (LEFT)
					stats->map[i][j - 1] = outline;
				if (DOWN)
					stats->map[i + 1][j] = outline;
				if (UP)
					stats->map[i - 1][j] = outline;
				if (ANGLE1)
					stats->map[i + 1][j + 1] = outline;
				if (ANGLE2)
					stats->map[i + 1][j - 1] = outline;
				if (ANGLE3)
					stats->map[i - 1][j + 1] = outline;
				if (ANGLE4)
					stats->map[i - 1][j - 1] = outline;
			}
			j++;
		}
		i++;
	}
	if (r == 1)
		return (1);
	return (0);
}

int		map_filled(t_fill stats)
{
	int i;
	int j;

	i = 0;
	while (i < stats.y)
	{
		j = 0;
		while (j < stats.x)
		{
			if (stats.map[i][j] == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}


void	map_highlight(t_fill *stats, int fd)
{
	int i;
	int	j;

	i = stats->vs;
	j = 1;
	//dprintf(fd, "test1.6 %d\n", stats->vs);
	while (!map_filled(*stats))
	{
		if (j == 2)
			i = 1;
		//dprintf(fd, "test1.7 %d\n", stats->vs);
		if (!(map_highlighter(stats, i, j)))
			break ;
		j++;
		i++;
	}
	//dprintf(fd, "test1.8\n");
}

int		piece_fits(t_fill stats, t_piece p, t_cord c)
{
	int i;
	int j;
	int	layer;
	int	score;

	i = 0;
	score = 1;
	layer = 0;
	while (i < p.y)
	{
		j = 0;
		while (j < p.x)
		{
			if (p.piece[i][j] == '*')
			{
				if (c.y + i >= stats.y)
					return (0);
				if (c.x + j >= stats.x)
					return (0);
				if (stats.map[c.y + i][c.x + j] == stats.vs)
					return (0);
				if (stats.map[c.y + i][c.x + j] == stats.player)
					layer++;
				else
					score += stats.map[c.y + i][c.x + j];
			}
			j++;
		}
		i++;
	}
	if (layer == 1)
		return (score);
	return (0);
}

t_cord		next_placement(t_fill stats, t_piece p)
{
	t_cord	c;
	t_cord	place;
	t_cord	tmp;
	int		a;
	int fd = open("/dev/ttys001", O_RDWR);

	// if (!map_filled(stats))
	// 	return (finish_placement(stats, p));
	place.score = -1;
	c.y = 0;
	while (c.y < stats.y)
	{
		c.x = 0;
		while (c.x < stats.x)
		{
			a = piece_fits(stats, p, c);
			if ((a < place.score || place.score == -1) && a != 0)
			{
				place.score = a;
				place.x = c.x;
				place.y = c.y;
			}
			//dprintf(fd, "a == %d\n", a);
			c.x++;
		}
		c.y++;
	}
	//dprintf(fd, "score == %d, x == %d, y == %d, stats.x == %d\n", place.score, place.x, place.y, stats.x);
	return (place);
}

// t_cord	last_place(t_fill stats)
// {
// 	int		i;
// 	int		j;
// 	t_cord	c;

// 	i = 0;
// 	while (stats.map[i])
// 	{
// 		j = 0;
// 		while (stats.map[i][j])
// 		{
// 			if (stats)
// 		}
// 	}
// }

int main()
{
	char	*line;
	t_fill	stats;
	t_piece	p;
	t_cord	c;
	int		ret = 1;
	int fd = open("/dev/ttys001", O_RDWR);
	
	while (ret)
	{
		init_struct(&stats);
		while ((ret = get_next_line(0, &line)))
		{
			//dprintf(fd, " %s\n", line);
			if (ft_strstr(line, "exec"))
			{
				assign_player(&stats, line);
				get_next_line(0, &line);
			}
			//dprintf(fd, "test0\n");
			if (ft_strstr(line, "Plateau"))
			{
				map_create(&stats, line, fd);
				stats.counter = 0;
				while (stats.counter <= stats.y)
				{
					//dprintf(fd, "test0.5\n");
					get_next_line(0, &line);
					if (stats.counter > 0)
						fill_tab(&stats, line, fd);
					stats.counter++;
				}
				//dprintf(fd, "test1\n");
				map_highlight(&stats, fd);
				//dprintf(fd, "test1.5\n");
				get_next_line(0, &line);
				if (ft_strstr(line, "Piece"))
				{
					piece_create(&p, line);
					//dprintf(fd, "test2\n");
					stats.counter = 0;
					while (stats.counter < p.y)
					{
						get_next_line(0, &line);
						//dprintf(fd, "%s\n", line);
						ft_strcpy(p.piece[stats.counter++], line);
					}
					c = next_placement(stats, p);
					// stats.counter = 0;
					// int j;
					// while (stats.counter < stats.y)
					// {
					// 	j = 0;
					// 	while (j < stats.x)
					// 		dprintf(fd, "%d  ", stats.map[stats.counter][j++]);
					// 	dprintf(fd, "\n");
					// 	stats.counter++;
					// }
					//dprintf(fd, "test3\n");
					ft_putnbr(c.y);
					ft_putstr(" ");
					ft_putnbr(c.x);
					ft_putstr("\n");
					//ft_strdel(&line);
					//structs_free(stats, p);
				}
				//dprintf(fd, "test4\n");
			}
			// get_next_line(0, &line);
			// dprintf(fd, " %s\n", line);
			//structs_free(stats, p);
			// stats.counter = 0;
			// int j;
			// while (stats.counter < stats.y)
			// {
			// 	j = 0;
			// 	while (j < stats.x)
			// 		dprintf(fd, "%d  ", stats.map[stats.counter][j++]);
			// 	dprintf(fd, "\n");
			// 	stats.counter++;
			// }
			//dprintf(fd, " %s\n", line);
			//dprintf(fd, " x == %d y == %d score == %d\n", c.x, c.y, c.score);
		}
	}
	return(0);
}
