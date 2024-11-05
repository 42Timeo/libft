#include <stdlib.h>
#include "libft.h"

// be carefull when c is \0
// won't have empty strings or strings with c in them
// what to do when c is \0

static size_t	count_number_of_strings(char const *s, char c)
{
	size_t	counter;

	counter = 0;
	while (*s)
	{
		counter++;
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	return (counter);
}

static size_t	strlen_up_to(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void	*free_array(void **array, size_t length)
{
	while (length-- != 0)
		free(array[length]);
	free(array);
	return (NULL);
}

static char	*make_string(const char *src, size_t length)
{
	char	*str;

	str = malloc((length + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[length] = 0;
	while (length-- != 0)
		str[length] = src[length];
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	number_of_strs;
	size_t	length;
	size_t	i;

	while (*s && *s == c)
		s++;
	number_of_strs = count_number_of_strings(s, c);
	strs = malloc((number_of_strs + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	i = -1;
	while (++i < number_of_strs)
	{
		length = strlen_up_to(s, c);
		strs[i] = make_string(s, length);
		s += length;
		if (!strs[i])
			return (free_array((void **) strs, i));
		while (*s && *s == c)
			s++;
	}
	strs[number_of_strs] = NULL;
	return (strs);
}

/* #include <stdio.h>
int main(void)
{
	// printf("%zu\n", count_number_of_strings("--abc----def--sasad-è--", '-'));
	char **strs = ft_split("----abc----def--sasad-è--", '-');
	printf("strs = %p\n", strs);
	for (int i = 0; strs[i]; i++)
		printf("strs[%d] = \"%s\"\n", i, strs[i]);
	return (0);
} */
