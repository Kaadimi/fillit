/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_corr_uper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmostafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 22:52:43 by mmostafa          #+#    #+#             */
/*   Updated: 2018/10/18 23:28:35 by mmostafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_list(t_list **alst)
{
	t_list	*next;
	size_t	i;

	i = 0;
	while (*alst != NULL)
	{
		next = (*alst)->next;
		*alst = next;
		i++;
	}
	return (i);
}
