#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*last_match;

	last_match = NULL;
	while (1)
	{
		if (*s == (char) c)
			last_match = ((char *) s);
		if (!*s)
			return (last_match);
		s++;
	}
}
