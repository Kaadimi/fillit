/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmostafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 11:36:17 by mmostafa          #+#    #+#             */
/*   Updated: 2018/10/24 18:53:43 by mmostafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t		i;

	i = -1;
	while (++i < n)
		if (src[i] != '\0')
			dest[i] = src[i];
		else
			while (i < n)
				dest[i++] = '\0';
	return (dest);
}
