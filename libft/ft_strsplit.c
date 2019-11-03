/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmostafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 13:54:07 by mmostafa          #+#    #+#             */
/*   Updated: 2018/10/16 20:39:20 by mmostafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_count_words(char *s, char c)
{
	int j;

	j = 0;
	while (*s)
	{
		if (*s != c)
		{
			j++;
			while (*s != c && *s)
				s++;
		}
		else
			s++;
	}
	return (j);
}

static	char	**ft_allocate_tab(char *s, char c, int j)
{
	int		i;
	char	**strs;

	i = ft_count_words(s, c);
	if (!(strs = (char **)malloc((i + 1) * sizeof(char *))))
		return (NULL);
	while (i--)
		if (!(strs[i] = (char *)malloc(sizeof(char) * (j + 1))))
			return (NULL);
	return (strs);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**strs;
	int		j;
	int		l;

	if (!s || !c)
		return (NULL);
	if (!(strs = ft_allocate_tab((char *)s, c, ft_strlen(s))))
		return (NULL);
	j = 0;
	l = 0;
	while (*s)
	{
		if (*s != c)
		{
			strs[j][l++] = *s;
			if (*(s + 1) == c || *(s + 1) == '\0')
			{
				strs[j++][l] = '\0';
				l = 0;
			}
		}
		s++;
	}
	strs[j] = 0;
	return (strs);
}
