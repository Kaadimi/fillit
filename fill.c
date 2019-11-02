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

typedef struct	s_fill
{
	int x;
	int y;
	int player;
}				t_fill;

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
	static char	*temp[256];
	int			i;
	char		buf[BUFF_SIZE + 1];

	i = 0;
	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	if (temp[fd] == NULL)
		temp[fd] = ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		temp[fd] = ft_freejoin(temp[fd], buf);
		if (ft_strchr(temp[fd], '\n'))
			break ;
	}
	while (temp[fd][i] != '\n' && temp[fd][i])
		i++;
	if (!ft_strlen(temp[fd]) && !ret && !i)
		return (0);
	*line = ft_strsub(temp[fd], 0, i);
	temp[fd] = ft_strdup(temp[fd] + i + 1);
	return (1);
}

/*
 *    int		return_cord()
 *       {
 *
 *          }*/

int main()
{
	char buf[BUFF_SIZE + 1];
	int ret = 0;
	static int backspace = 0;
	char	*line;
	char	*tab;
	int fd = open("/dev/ttys003", O_RDWR);

	while (ret < 5)
	{
		get_next_line(0, &line);
		dprintf(fd, "%s\n", line);
		ret++;
	}
	get_next_line(0, &line);
	dprintf(fd, "%s\n", line);

	/*	while ((ret = read(0, buf, BUFF_SIZE)))
	 *		{
	 *				buf[ret] = '\0';
	 *						//dprintf(fd, "%s", buf);
	 *								line = ft_freejoin(line, buf);
	 *										if (ft_strstr(line, "\n\0"))
	 *													dprintf(fd, "this is backspace == %d\n", backspace);
	 *															//	write(1, buf, 1);
	 *																}*/
	return(0);
}
