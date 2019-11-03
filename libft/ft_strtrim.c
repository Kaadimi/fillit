/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmostafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 17:45:06 by mmostafa          #+#    #+#             */
/*   Updated: 2018/10/24 21:10:55 by mmostafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t			f;
	size_t			d;
	size_t			e;
	char			*fr;

	if (s)
	{
		d = 0;
		while (s[d] == ' ' || s[d] == '\t' || s[d] == '\n')
			d++;
		f = ft_strlen(s) - 1;
		while ((s[f] == ' ' || s[f] == '\n' || s[f] == '\t') && f >= d)
			f--;
		e = f - d + 1;
		fr = ft_strsub(s, d, (e));
		return (fr);
	}
	return (0);
}
