/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikadimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:34:57 by ikadimi           #+#    #+#             */
/*   Updated: 2018/10/25 16:35:00 by ikadimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define INT 1
#define CHAR 2
#define STRING 3

void	ft_printlist(t_list *list, int type)
{
	while (list != NULL)
	{
		if (type == INT)
			ft_putnbr((int)list->content);
		else if (type == CHAR)
			ft_putchar((char)list->content);
		else if (type == STRING)
			ft_putstr((char *)list->content);
		ft_putstr("\n");
		list = list->next;
	}
}
