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

#include "fillit.h"

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

int		map_create(t_fill *stats, char *line)
{
	char	**tab;
	int		i;

	i = 0;
	tab = ft_strsplit(line, ' ');
	stats->y = ft_atoi(tab[1]);
	stats->x = ft_atoi(tab[2]);
	stats->map = (int **)malloc(sizeof(int *) * stats->y);
	while (i < stats->y)
		stats->map[i++] = (int *)malloc(sizeof(int) * stats->x);
	tab_free(tab);
	return (1);
}

void	main_2(t_fill *stats)
{
	char	*line_2;

	line_2 = NULL;
	stats->counter = 0;
	while (stats->counter <= stats->y && get_next_line(0, &line_2))
	{
		if (stats->counter > 0)
			fill_tab(stats, line_2);
		free(line_2);
		line_2 = NULL;
		stats->counter++;
	}
	map_highlight(stats);
}

void	main_1_5(char *line, t_fill *stats, t_piece *p)
{
	if (ft_strstr(line, "exec") && stats->player == 0)
		assign_player(stats, line);
	else if (ft_strstr(line, "Plateau"))
	{
		if (!stats->map)
			map_create(stats, line);
		main_2(stats);
	}
	else if (ft_strstr(line, "Piece"))
	{
		if (piece_create(p, line))
			piece_handler(stats, *p);
	}
}

int		main(void)
{
	char	*line;
	t_fill	stats;
	t_piece	p;
	int		ret;

	ret = 1;
	line = NULL;
	while (ret)
	{
		init_struct(&stats, &p);
		while ((ret = get_next_line(0, &line)))
		{
			main_1_5(line, &stats, &p);
			free(line);
			line = NULL;
		}
	}
	map_free(stats);
	return (0);
}
