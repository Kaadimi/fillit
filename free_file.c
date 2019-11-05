/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikadimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:28:38 by ikadimi           #+#    #+#             */
/*   Updated: 2019/11/05 14:28:53 by ikadimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	tab_free(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	tab = NULL;
}

void	piece_free(t_piece p)
{
	int i;

	i = 0;
	while (i < p.y)
		free(p.piece[i++]);
	free(p.piece);
	p.piece = NULL;
}

void	map_free(t_fill stats)
{
	int i;

	i = 0;
	while (i < stats.y)
		free(stats.map[i++]);
	free(stats.map);
	stats.map = NULL;
}

void	init_struct(t_fill *start, t_piece *p)
{
	start->x = 0;
	start->y = 0;
	start->player = 0;
	start->vs = 0;
	start->map = NULL;
	start->counter = 0;
	p->piece = NULL;
	p->x = 0;
	p->y = 0;
}
