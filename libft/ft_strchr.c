/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikadimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:33:14 by ikadimi           #+#    #+#             */
/*   Updated: 2018/10/25 16:33:17 by ikadimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s1, int c)
{
	int i;
	int j;

	i = 0;
	j = ft_strlen(s1);
	while (i <= j)
	{
		if (s1[i] == (char)c)
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}
