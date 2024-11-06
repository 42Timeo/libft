/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:23:56 by tdaclin           #+#    #+#             */
/*   Updated: 2024/11/06 10:23:57 by tdaclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*last_match;

	last_match = NULL;
	while (1)
	{
		if (*s == (char) c)
			last_match = ((char *) s);
		if (!*s)
			return (last_match);
		s++;
	}
}
