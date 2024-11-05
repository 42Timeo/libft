#include <stdlib.h>
#include "libft.h"

static int	is_in(char c, const char *s)
{
	while (*s)
		if (*s++ == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	start = 0;
	while (is_in(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (is_in(s1[end], set))
		end--;
	str = malloc(end - start + 1);
	if (str)
	{
		ft_memcpy(str, s1 + start, end - start);
		str[end - start] = 0;
	}
	return (str);
}
