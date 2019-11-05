/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikadimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:31:26 by ikadimi           #+#    #+#             */
/*   Updated: 2018/10/25 16:31:28 by ikadimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int i;
	int negatif;
	int k;
	int result;

	i = 0;
	negatif = 0;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == '\r' || str[i] == '\f' || str[i] == '\n')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			negatif = 1;
	k = str[i] - '0';
	while (k >= 0 && k <= 9 && str[i] != '\0')
	{
		result = result * 10 + k;
		i++;
		k = str[i] - '0';
	}
	if (negatif)
		result *= -1;
	return (result);
}
