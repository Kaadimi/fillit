/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmostafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 20:51:04 by mmostafa          #+#    #+#             */
/*   Updated: 2018/10/16 13:07:25 by mmostafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *src, const char *to_find)
{
	int		i;
	int		j;

	i = 0;
	if (src[i] == '\0' && to_find[i] == '\0')
		return ((char *)src);
	while (src[i] != '\0')
	{
		j = 0;
		while (src[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return ((char *)src + i);
			j++;
		}
		if (to_find[0] == '\0')
			return ((char *)src);
		i++;
	}
	return (0);
}
