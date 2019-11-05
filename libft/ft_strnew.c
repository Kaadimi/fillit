/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikadimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:49:10 by ikadimi           #+#    #+#             */
/*   Updated: 2018/10/25 16:49:15 by ikadimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*s;
	size_t	i;

	s = NULL;
	i = 0;
	if (!(s = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ft_bzero(s, size + 1);
	return (s);
}
