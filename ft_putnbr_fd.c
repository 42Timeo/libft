/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdaclin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:23:20 by tdaclin           #+#    #+#             */
/*   Updated: 2024/11/08 13:29:09 by tdaclin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	char			str[11];
	unsigned int	i;

	i = 11;
	while (1)
	{
		str[--i] = abs(n % 10) + '0';
		if (n / 10 == 0)
		{
			if (n < 0)
				str[--i] = '-';
			break ;
		}
		n /= 10;
	}
	write(fd, str + i, 11 - i);
}
