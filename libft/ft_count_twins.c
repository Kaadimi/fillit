/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_twins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmostafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 14:26:29 by mmostafa          #+#    #+#             */
/*   Updated: 2018/10/18 16:50:41 by mmostafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_count_twins(const char *src, const char *to_find)
{
	size_t		i;
	size_t		j;
	size_t		k;
	size_t		l;

	i = 0;
	k = 0;
	l = ft_strlen(to_find) + 1;
	if (src[i] == '\0' || to_find[i] == '\0')
		return ;
	while (src[i] != '\0')
	{
		j = 0;
		while (src[i + j] == to_find[j])
			j++;
		if (j == l || j == l - 1 || j == l + 1)
			k++;
		i++;
	}
	ft_putstr("the word exist ");
	ft_putstr(ft_itoa(k));
	if (k == 1)
		ft_putstr(" time");
	else
		ft_putstr(" times\n");
}
