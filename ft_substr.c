/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:24:00 by tdaclin           #+#    #+#             */
/*   Updated: 2024/11/06 10:24:01 by tdaclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	s += start;
	i = 0;
	while (i < len && s[i])
		i++;
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	str[i] = 0;
	while (i-- != 0)
		str[i] = s[i];
	return (str);
}