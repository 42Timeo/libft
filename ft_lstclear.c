/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:27:27 by tdaclin           #+#    #+#             */
/*   Updated: 2024/11/06 10:26:49 by tdaclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	recursive_free(t_list *lst, void (*del)(void *))
{
	if (lst)
	{
		del(lst->content);
		recursive_free(lst->next, del);
		free(lst);
	}
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	recursive_free(*lst, del);
	*lst = NULL;
}
