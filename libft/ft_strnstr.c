/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmostafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 11:15:32 by mmostafa          #+#    #+#             */
/*   Updated: 2018/10/24 21:07:41 by mmostafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *to_find, size_t l)
{
	size_t		i;
	int			j;

	i = 0;
	if ((src[0] == '\0' && to_find[0] == '\0') || to_find[0] == '\0')
		return ((char *)src);
	while (src[i] != '\0')
	{
		j = 0;
		while (src[i + j] == to_find[j] && l > i + j)
		{
			if (to_find[j + 1] == '\0')
				return ((char *)src + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
