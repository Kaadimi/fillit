/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikadimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 18:51:35 by ikadimi           #+#    #+#             */
/*   Updated: 2019/11/04 18:51:38 by ikadimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

int		gnl_2(char *temp, int ret, int *i)
{
	while (temp[*i] != '\n' && temp[*i])
		*i += 1;
	if (!ft_strlen(temp) && !ret && !*i)
	{
		free(temp);
		temp = NULL;
		return (0);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	t_gnl			g;
	static char		*temp;

	g.i = 0;
	if (!line || read(fd, g.buf, 0) < 0)
		return (0);
	if (temp == NULL)
		temp = ft_strdup("");
	while ((g.ret = read(fd, g.buf, BUFF_SIZE)) > 0)
	{
		g.buf[g.ret] = '\0';
		temp = ft_freejoin(temp, g.buf);
		if (ft_strchr(temp, '\n'))
			break ;
	}
	if (!(gnl_2(temp, g.ret, &g.i)))
		return (0);
	g.tmp = temp;
	*line = ft_strsub(temp, 0, g.i);
	temp = ft_strdup(temp + g.i + 1);
	ft_strdel(&g.tmp);
	return (1);
}
