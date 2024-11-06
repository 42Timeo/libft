/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:29:02 by tdaclin           #+#    #+#             */
/*   Updated: 2024/11/06 10:28:04 by tdaclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;

	if (!lst)
		return (NULL);
	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = f(lst->content);
	if (lst->next)
	{
		node->next = ft_lstmap(lst->next, f, del);
		if (node->next == NULL)
		{
			del(node->content);
			free(node);
			return (NULL);
		}
	}
	else
		node->next = NULL;
	return (node);
}
