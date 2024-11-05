#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*result;

	i = 0;
	while (s[i])
		i++;
	result = malloc((i + 1) * sizeof(char));
	if (result)
	{
		result[i] = 0;
		while (--i != 0)
			result[i] = f(i, s[i]);
	}
	return (result);
}
