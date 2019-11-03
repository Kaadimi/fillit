/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmostafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 15:22:31 by mmostafa          #+#    #+#             */
/*   Updated: 2018/10/16 13:13:37 by mmostafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	int		i;
	char	*fr;

	i = 0;
	if (s)
	{
		if (!(fr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
			return (NULL);
		while (s[i] != '\0')
		{
			fr[i] = f(i, s[i]);
			i++;
		}
		fr[i] = '\0';
		return (fr);
	}
	return (0);
}
