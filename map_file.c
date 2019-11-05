/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikadimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:53:48 by ikadimi           #+#    #+#             */
/*   Updated: 2019/11/04 18:53:49 by ikadimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fill_tab(t_fill *stats, char *line)
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

void	map_hilight2(t_fill *stats, int outline, t_cord *c)
{
	if (RIGHT || LEFT || DOWN || UP || ANGLE1 || ANGLE2
		|| ANGLE3 || ANGLE4)
		c->score = 1;
	if (RIGHT)
		stats->map[c->y][c->x + 1] = outline;
	if (LEFT)
		stats->map[c->y][c->x - 1] = outline;
	if (DOWN)
		stats->map[c->y + 1][c->x] = outline;
	if (UP)
		stats->map[c->y - 1][c->x] = outline;
	if (ANGLE1)
		stats->map[c->y + 1][c->x + 1] = outline;
	if (ANGLE2)
		stats->map[c->y + 1][c->x - 1] = outline;
	if (ANGLE3)
		stats->map[c->y - 1][c->x + 1] = outline;
	if (ANGLE4)
		stats->map[c->y - 1][c->x - 1] = outline;
}

int		map_highlighter(t_fill *stats, int last, int outline)
{
	t_cord c;

	c.y = 0;
	c.score = 0;
	while (c.y < stats->y)
	{
		c.x = 0;
		while (c.x < stats->x)
		{
			if (stats->map[c.y][c.x] == last)
				map_hilight2(stats, outline, &c);
			c.x++;
		}
		c.y++;
	}
	if (c.score == 1)
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

void	map_highlight(t_fill *stats)
{
	int i;
	int	j;

	i = stats->vs;
	j = 1;
	while (!map_filled(*stats))
	{
		if (j == 2)
			i = 1;
		if (!(map_highlighter(stats, i, j)))
			break ;
		j++;
		i++;
	}
}
