/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlamhidr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 17:14:27 by hlamhidr          #+#    #+#             */
/*   Updated: 2018/10/14 11:31:49 by hlamhidr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *ma;

	if (!(ma = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	ma->next = NULL;
	if (content == NULL)
	{
		ma->content = NULL;
		ma->content_size = 0;
	}
	else
	{
		ma->content = malloc(content_size);
		if (ma->content == NULL)
		{
			free(ma);
			return (NULL);
		}
		ft_memmove(ma->content, content, content_size);
		ma->content_size = content_size;
	}
	return (ma);
}
