/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmostafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 13:48:09 by mmostafa          #+#    #+#             */
/*   Updated: 2018/10/24 15:21:54 by mmostafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		i;

	i = 0;
	while (s1[i] == s2[i] && n > 0)
	{
		if (s1[i] == '\0')
			return (0);
		i++;
		n--;
	}
	while (s1[i] != s2[i] && n-- > 0)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
