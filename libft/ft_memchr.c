/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikadimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:46:54 by ikadimi           #+#    #+#             */
/*   Updated: 2018/10/25 16:47:01 by ikadimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*s1;
	int					i;

	s1 = s;
	i = 0;
	while (0 < n)
	{
		if (s1[i] == (unsigned char)c)
			return ((char *)s1 + i);
		n--;
		i++;
	}
	return (NULL);
}
