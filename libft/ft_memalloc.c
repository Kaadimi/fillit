/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikadimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:44:59 by ikadimi           #+#    #+#             */
/*   Updated: 2018/10/25 16:45:04 by ikadimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*zone;
	size_t			i;

	i = 0;
	if (!(zone = (unsigned char *)malloc(sizeof(unsigned char) * size)))
		return (NULL);
	while (i <= size)
		zone[i++] = 0;
	return (zone);
}
