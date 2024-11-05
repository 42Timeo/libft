#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	dstlen = 0;
	while (dstlen < dstsize && dst[dstlen])
		dstlen++;
	srclen = 0;
	while (src[srclen])
		srclen++;
	i = -1;
	while (src[++i] && dstlen + i + 1 < dstsize)
		dst[dstlen + i] = src[i];
	if (dstlen + i < dstsize)
		dst[dstlen + i] = 0;
	return (dstlen + srclen);
}
