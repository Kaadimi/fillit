/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmostafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 18:00:03 by mmostafa          #+#    #+#             */
/*   Updated: 2018/10/24 14:41:35 by mmostafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char		*s1;
	size_t					i;

	s1 = s;
	i = -1;
	while (++i < n)
		if (s1[i] == (unsigned char)c)
			return ((char *)s1 + i);
	return (NULL);
}
