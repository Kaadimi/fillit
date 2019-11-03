/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmostafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 13:54:30 by mmostafa          #+#    #+#             */
/*   Updated: 2018/10/12 00:13:13 by mmostafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	ld;
	size_t	ls;
	size_t	s;
	size_t	k;

	ld = ft_strlen(dest);
	ls = ft_strlen((char *)src);
	s = ld + ls;
	if (ld > size)
		return (ls + size);
	k = 0;
	while (src[k] != '\0' && ld < size - 1)
		dest[ld++] = src[k++];
	dest[ld++] = '\0';
	return (s);
}
