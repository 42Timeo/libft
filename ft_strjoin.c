/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:23:38 by tdaclin           #+#    #+#             */
/*   Updated: 2024/11/06 10:23:39 by tdaclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	char	*str;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	str = malloc(s1len + s2len + 1);
	if (str)
	{
		ft_memcpy(str, s1, s1len);
		ft_memcpy(str + s1len, s2, s2len);
		str[s1len + s2len] = 0;
	}
	return (str);
}