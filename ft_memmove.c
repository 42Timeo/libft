/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:23:06 by tdaclin           #+#    #+#             */
/*   Updated: 2024/11/06 10:23:07 by tdaclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = -1;
	if (dst < src)
		while (++i < len)
			((unsigned char *) dst)[i] = ((unsigned char *) src)[i];
	else
		while (++i < len)
			((unsigned char *) dst)[len - i] = ((unsigned char *) src)[len - i];
	return (dst);
}