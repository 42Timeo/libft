/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:23:48 by tdaclin           #+#    #+#             */
/*   Updated: 2024/11/06 10:23:49 by tdaclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*result;

	i = 0;
	while (s[i])
		i++;
	result = malloc((i + 1) * sizeof(char));
	if (result)
	{
		result[i] = 0;
		while (--i != 0)
			result[i] = f(i, s[i]);
	}
	return (result);
}
