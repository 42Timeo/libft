#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = malloc(count * size);
	if (ptr)
		while (i < count * size)
			ptr[i++] = 0;
	return (ptr);
}
