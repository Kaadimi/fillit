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

typedef struct		s_fill
{
	int		x;
	int		y;
	int		player;
}			t_fill;

typedef struct		s_piece
{
	int		x;
	int		y;
}			t_piece;

void	tab_free(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	tab = NULL;
}

char	*ft_freejoin(char *s1, char *s2)
{
	char	*fr;
	size_t	v;
	int fd = open("/dev/ttys002", O_RDWR);


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
	int			ret;
	static char		*temp;
	int			i;
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

/*
 *    int		return_cord()
 *       {
 *
 *          }*/

void	init_struct(t_fill *start)
{
	start->x = 0;
	start->y = 0;
	start->player = 0;
}

void	assign_player(t_fill *stats, char *line)
{
	if (ft_strstr(line, "p1"))
		stats->player = 1;
	else 
		stats->player = 2;
}

char	**map_create(char *line, t_fill stats)
{
	
}

void	map_size(t_fill *stats, char *line, int fd)
{
	char **tab;

	tab = ft_strsplit(line, ' ');
	dprintf(fd, "%s%s\n", tab[1], tab[2]);
	stats->y = ft_atoi(tab[1]);
	stats->x = ft_atoi(tab[2]);
	tab_free(tab);
}

int main()
{
	char	*line;
	char	**map;
	t_fill stats;
	int fd = open("/dev/ttys000", O_RDWR);
	
	init_struct(&stats);
	get_next_line(0, &line);
	if (ft_strstr(line, "exec"))
		assign_player(&stats, line);
	get_next_line(0, &line);
	if (ft_strstr(line, "Plateau"))
	{
		map_size(&stats, line, fd);
		map = map_create();
	}
	dprintf(fd, " player == %d x == %d y == %d\n", stats.player, stats.x, stats.y);
	dprintf(fd, "%s\n", line);
	return(0);
}
