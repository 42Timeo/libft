#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		if (((unsigned char *) s)[i] == (char) c)
			return ((void *) &s[i]);
	return (NULL);
}
