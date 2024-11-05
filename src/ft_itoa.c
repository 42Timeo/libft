#include <stdlib.h>
#include "libft.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static unsigned int	get_size(int n)
{
	unsigned int	size;

	size = 0;
	if (n < 0)
		size++;
	while (1)
	{
		size++;
		n = n / 10;
		if (n == 0)
			break ;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	unsigned int	size;
	char			*str;

	size = get_size(n);
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[size] = 0;
	if (n < 0)
		str[0] = '-';
	while (1)
	{
		str[--size] = ft_abs(n % 10) + '0';
		n /= 10;
		if (n == 0)
			break ;
	}
	return (str);
}

/* #include <limits.h>
#include <stdio.h>
int main(void)
{
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(1));
	printf("%s\n", ft_itoa(-1));
	printf("%s\n", ft_itoa(42));
	printf("%s\n", ft_itoa(-42));
	printf("%s\n", ft_itoa(INT_MAX));
	printf("%s\n", ft_itoa(INT_MIN));
	return (0);
} */
