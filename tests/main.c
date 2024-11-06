#include "../libft.h"
#include <assert.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

// $(CC) -Wall -Wextra -Werror libft.a tests/*

/*
	strlcpy
	strlcat
	strnstr
	calloc
	strdup
*/


/*
check everyy NULL
strlen called with NULL should probably crash
memset called with size=0 should not access memory (should be working with not unreadable memory)
memset called with c=999 ???
*/


void check_functions_with_chars(void)
{
	for (int i = 0; i <= UCHAR_MAX; i++)
	{
		assert(!ft_isalpha(i) == !isalpha(i));
		assert(!ft_isdigit(i) == !isdigit(i));
		assert(!ft_isalnum(i) == !isalnum(i));
		assert(!ft_isascii(i) == !isascii(i));
		assert(!ft_isprint(i) == !isprint(i));
		assert(!ft_toupper(i) == !toupper(i));
		assert(!ft_tolower(i) == !tolower(i));
	}
}

void check_strlen(void)
{
	char *strs[] = {
		"",
		"abc\0def",
		"\0",
		"XXX",
		"babab",
		"j",
		"jfiwa\xffjlhg",
		"XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
	};
	for (size_t i = 0; i < (sizeof(strs) / sizeof(strs[0])); i++)
		assert(ft_strlen(strs[i]) == strlen(strs[i]));
}

void check_memset(void)
{
	char buf1[1024];
	char buf2[1024];

	ft_memset(buf1, 99, 1024);
	memset(buf2, 99, 1024);
	assert(memcmp(buf1, buf2, 1024) == 0);

	ft_memset(buf1, 1, 1024);
	memset(buf2, 1, 1024);
	assert(memcmp(buf1, buf2, 1024) == 0);

	ft_memset(buf1, 42, (0));
	memset(buf2, 42, (0));
	assert(memcmp(buf1, buf2, 1024) == 0);

	ft_bzero(buf1, 1024);
	bzero(buf2, 1024);
	assert(memcmp(buf1, buf2, 1024) == 0);
}

void check_memcpy(void)
{
	char buf1[1024] = { 0 };
	char buf2[1024] = { 0 };

	ft_memcpy(buf1, "abcdef", 5);
	memcpy(buf2, "abcdef", 5);
	assert(memcmp(buf1, buf2, 1024) == 0);

	ft_memcpy(buf1, "\xff\x00\xaa\0\xee", 5);
	memcpy(buf2, "\xff\x00\xaa\0\xee", 5);
	assert(memcmp(buf1, buf2, 1024) == 0);
}

void check_memmove(void)
{
	char buf1[1024] = { 0 };
	char buf2[1024] = { 0 };
	strcpy(buf1, "abcdef");
	strcpy(buf2, "abcdef");

	ft_memmove(buf1+1, buf1, 10);
	memmove(buf2+1, buf2, 10);
	assert(memcmp(buf1, buf2, 1024) == 0);
	
	ft_memmove(buf1, buf1+1, 10);
	memmove(buf2, buf2+1, 10);
	assert(memcmp(buf1, buf2, 1024) == 0);
	
	ft_memmove(buf1, buf1, 10);
	memmove(buf2, buf2, 10);
	assert(memcmp(buf1, buf2, 1024) == 0);
	
	ft_memmove(buf1+512, buf1, 10);
	memmove(buf2+512, buf2, 10);
	assert(memcmp(buf1, buf2, 1024) == 0);
}

void check_strchr(void)
{
	char *strs[] = {
		"",
		"abc\0def",
		"\0",
		"XXX",
		"babab",
		"j",
		"jfiwa\xffjlhg",
	};
	char chars[] = "ab\0d\xff";

	for (size_t i = 0; i < (sizeof(strs) / sizeof(strs[0])); i++)
		for (size_t j = 0; j < (sizeof(chars) - 1); j++)
		{
			assert(ft_strchr(strs[i], chars[j]) == strchr(strs[i], chars[j]));
			assert(ft_strrchr(strs[i], chars[j]) == strrchr(strs[i], chars[j]));
		}
}

void check_strncmp(void)
{
	assert(ft_strncmp("abcdef", "abcdef", 60) == strncmp("abcdef", "abcdef", 60));
	assert(ft_strncmp("abcdef", "abcdef", 6) == strncmp("abcdef", "abcdef", 6));
	assert(ft_strncmp("abcdef", "abcdeg", 6) == strncmp("abcdef", "abcdeg", 6));
	assert(ft_strncmp("abcdef", "abcdeg", 5) == strncmp("abcdef", "abcdeg", 5));
	assert(ft_strncmp("X", "X", 1) == strncmp("X", "X", 1));
	assert(ft_strncmp("X", "Z", 0) == strncmp("X", "Z", 0));
}

void check_memchr(void)
{
	char strs[][1024] = {
		"",
		"abc\0def",
		"\0",
		"XXX",
		"babab",
		"j",
		"jfiwa\xffjlhg",
	};
	char chars[] = "ab\0d\xff";

	for (size_t i = 0; i < (sizeof(strs) / sizeof(strs[0])); i++)
		for (size_t j = 0; j < (sizeof(chars) - 1); j++)
		{
			assert(ft_memchr(strs[i], chars[j], 1024) == memchr(strs[i], chars[j], 1024));
		}
}

void check_atoi(void)
{
	assert(ft_atoi("") == atoi(""));
	assert(ft_atoi("abc") == atoi("abc"));
	assert(ft_atoi("1abc") == atoi("1abc"));
	assert(ft_atoi(" 1a") == atoi(" 1a"));
	assert(ft_atoi("-1a") == atoi("-1a"));
	assert(ft_atoi("1") == atoi("1"));
	assert(ft_atoi("0") == atoi("0"));
	assert(ft_atoi("-0") == atoi("-0"));
	assert(ft_atoi("10") == atoi("10"));
	assert(ft_atoi("-10") == atoi("-10"));
	assert(ft_atoi("1234567890") == atoi("1234567890"));
	assert(ft_atoi("2147483647") == atoi("2147483647"));
	assert(ft_atoi("-2147483648") == atoi("-2147483648"));
}

void check_memcmp(void)
{
	assert(ft_memcmp("abcdef", "abcdef", 6) == memcmp("abcdef", "abcdef", 6));
	assert(ft_memcmp("abcdef", "abcdeg", 6) == memcmp("abcdef", "abcdeg", 6));
	assert(ft_memcmp("abcdef", "abcdeg", 5) == memcmp("abcdef", "abcdeg", 5));
	assert(ft_memcmp("X", "X", 1) == memcmp("X", "X", 1));
	assert(ft_memcmp("X", "Z", 0) == memcmp("X", "Z", 0));
}

void check_strnstr(void)
{
	// assert(strnstr("abc", "", 3) == strnstr("abc", "", 3));
}


int main(void)
{
	check_functions_with_chars();
	check_strlen();
	check_memset();
	check_memcpy();
	check_memmove();
	check_strchr();
	check_strncmp();
	check_memchr();
	check_memcmp();
	check_strnstr();
	check_atoi();

	return (0);
}
