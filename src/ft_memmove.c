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
