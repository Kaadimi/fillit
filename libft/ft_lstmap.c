/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmostafa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 16:59:10 by mmostafa          #+#    #+#             */
/*   Updated: 2018/10/18 12:25:35 by mmostafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*save;

	if (!lst || !f)
		return (NULL);
	save = f(lst);
	new = save;
	lst = lst->next;
	while (lst != NULL)
	{
		save->next = f(lst);
		save = save->next;
		lst = lst->next;
	}
	save->next = NULL;
	return (new);
}
