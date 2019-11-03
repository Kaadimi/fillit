/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_size_text.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmostafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 16:37:18 by mmostafa          #+#    #+#             */
/*   Updated: 2018/10/18 16:48:14 by mmostafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_count_size_text(char *str)
{
	size_t		l;

	l = (ft_strlen(str) + 1) * sizeof(char);
	if (l < 1000)
	{
		ft_putstr(ft_itoa(l));
		ft_putstr("BYTES");
	}
	if (l >= 1000 && l < 1000000)
	{
		ft_putstr(ft_itoa(l));
		ft_putstr("Kb");
	}
	if (l >= 1000000 && l < 1000000000)
	{
		ft_putstr(ft_itoa(l));
		ft_putstr("Mb");
	}
	if (l >= 1000000000)
	{
		ft_putstr(ft_itoa(l));
		ft_putstr("Gb");
	}
}
