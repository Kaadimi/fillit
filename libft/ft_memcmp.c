/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmostafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 23:21:19 by mmostafa          #+#    #+#             */
/*   Updated: 2018/10/24 14:56:29 by mmostafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*src;
	unsigned char	*dest;
	size_t			i;

	i = -1;
	src = (unsigned char *)s1;
	dest = (unsigned char *)s2;
	while (++i < n && src[i] == dest[i])
		;
	if (i == n)
		return (0);
	return (src[i] - dest[i]);
}
