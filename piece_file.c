/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikadimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:56:25 by ikadimi           #+#    #+#             */
/*   Updated: 2019/11/04 18:56:29 by ikadimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		piece_create(t_piece *p, char *line)
{
	char	**tab;
	int		i;

	i = 0;
	if (!(tab = ft_strsplit(line, ' ')))
		return (0);
	p->y = ft_atoi(tab[1]);
	p->x = ft_atoi(tab[2]);
	if (!(p->piece = (char **)malloc(sizeof(char *) * p->y)))
		return (0);
	while (i < p->y)
		if (!(p->piece[i++] = (char *)malloc(sizeof(char) * p->x + 1)))
			return (0);
	tab_free(tab);
	return (1);
}

int		piece_fits2(t_fill stats, t_cord c, t_cord *pc, int *layer)
{
	if (c.y + pc->y >= stats.y)
		return (0);
	if (c.x + pc->x >= stats.x)
		return (0);
	if (stats.map[c.y + pc->y][c.x + pc->x] == stats.vs)
		return (0);
	if (stats.map[c.y + pc->y][c.x + pc->x] == stats.player)
		*layer += 1;
	else
		pc->score += stats.map[c.y + pc->y][c.x + pc->x];
	return (1);
}

int		piece_fits(t_fill stats, t_piece p, t_cord c)
{
	int		layer;
	t_cord	pc;

	pc.y = 0;
	pc.score = 1;
	layer = 0;
	while (pc.y < p.y)
	{
		pc.x = 0;
		while (pc.x < p.x)
		{
			if (p.piece[pc.y][pc.x] == '*')
				if (!(piece_fits2(stats, c, &pc, &layer)))
					return (0);
			pc.x++;
		}
		pc.y++;
	}
	if (layer == 1)
		return (pc.score);
	return (0);
}

t_cord	next_placement(t_fill stats, t_piece p)
{
	t_cord	c;
	t_cord	place;
	int		a;

	place.score = -1;
	place.x = 0;
	place.y = 0;
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
			c.x++;
		}
		c.y++;
	}
	return (place);
}

void	piece_handler(t_fill *stats, t_piece p)
{
	t_cord	c;
	char	*line_2;

	line_2 = NULL;
	stats->counter = 0;
	while (stats->counter < p.y && get_next_line(0, &line_2))
	{
		ft_strcpy(p.piece[stats->counter++], line_2);
		free(line_2);
		line_2 = NULL;
	}
	c = next_placement(*stats, p);
	piece_free(p);
	ft_putnbr(c.y);
	ft_putstr(" ");
	ft_putnbr(c.x);
	ft_putstr("\n");
}
