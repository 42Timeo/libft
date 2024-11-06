/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:23:31 by tdaclin           #+#    #+#             */
/*   Updated: 2024/11/06 10:23:33 by tdaclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	s1len;
	char	*s2;
	size_t	i;

	s1len = 0;
	while (s1[s1len])
		s1len++;
	s1len++;
	s2 = malloc(s1len);
	i = -1;
	while (s2 && ++i < s1len)
		s2[i] = s1[i];
	return (s2);
}
