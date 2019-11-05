/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikadimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:32:56 by ikadimi           #+#    #+#             */
/*   Updated: 2018/10/25 16:32:59 by ikadimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*dst;
	int				i;

	dst = b;
	i = 0;
	while (len > 0)
	{
		dst[i] = (unsigned char)c;
		len--;
		i++;
	}
	return (dst);
}
