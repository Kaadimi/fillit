/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikadimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:45:37 by ikadimi           #+#    #+#             */
/*   Updated: 2018/10/25 16:45:43 by ikadimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && 0 < n)
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		n--;
		i++;
	}
	if (s1[i] != s2[i] && 0 < n)
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}
