#include <unistd.h>

// three way to do it: recusif, iteratif, reverse

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

/* #include <limits.h>
#include <stdio.h>
int main(void)
{
	_ft_putnbr_fd(INT_MIN, 1);
	printf("\n");
	_ft_putnbr_fd(INT_MAX, 1);
	printf("\n");
	_ft_putnbr_fd(0, 1);
	printf("\n");
	_ft_putnbr_fd(-42, 1);
	printf("\n");
	_ft_putnbr_fd(42, 1);
	printf("\n");
	return (0);
} */
