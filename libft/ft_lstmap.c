/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikadimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:37:45 by ikadimi           #+#    #+#             */
/*   Updated: 2018/10/25 16:37:48 by ikadimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin;
	t_list	*fr;

	if (!lst || !f)
		return (NULL);
	fr = f(lst);
	begin = fr;
	lst = lst->next;
	while (lst != NULL)
	{
		fr->next = f(lst);
		fr = fr->next;
		lst = lst->next;
	}
	fr->next = NULL;
	return (begin);
}
