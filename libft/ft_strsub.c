/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikadimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:36:45 by ikadimi           #+#    #+#             */
/*   Updated: 2018/10/29 13:15:48 by ikadimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fr;
	size_t	i;
	size_t	size;

	size = 0;
	if (!s)
		return (NULL);
	while (len > size && *(s + start + size))
		size++;
	if (size < len)
		return (NULL);
	if (!(fr = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	while (size > i)
		fr[i++] = s[start++];
	fr[i] = '\0';
	return (fr);
}
