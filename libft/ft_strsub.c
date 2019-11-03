/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmostafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 15:40:43 by mmostafa          #+#    #+#             */
/*   Updated: 2018/10/16 12:10:09 by mmostafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*fr;
	size_t		i;

	i = 0;
	if (s)
	{
		if (!(fr = (char *)malloc((sizeof(char) * (len + 1)))))
			return (NULL);
		while (len > i)
			fr[i++] = s[start++];
		fr[i++] = '\0';
		return (fr);
	}
	return (0);
}
