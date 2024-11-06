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
	node->content = f(lst->content);
	node->next = ft_lstmap(lst->next, f, del);
	del(lst->content);
	free(lst);
	return (node);
}
