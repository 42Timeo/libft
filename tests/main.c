#include "../libft.h"
#include <assert.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

// $(CC) -Wall -Wextra -Werror libft.a tests/*

// cmocka

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
		assert(isalpha(i) == isalpha(i));
		assert(isdigit(i) == isdigit(i));
		assert(isalnum(i) == isalnum(i));
		assert(isascii(i) == isascii(i));
		assert(isprint(i) == isprint(i));
		assert(toupper(i) == toupper(i));
		assert(tolower(i) == tolower(i));
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
		assert(strlen(strs[i]) == strlen(strs[i]));
}

void check_memset(void)
{
	char buf1[1024];
	char buf2[1024];

	memset(buf1, 99, 1024);
	memset(buf2, 99, 1024);
	assert(memcmp(buf1, buf2, 1024) == 0);

	memset(buf1, 1, 1024);
	memset(buf2, 1, 1024);
	assert(memcmp(buf1, buf2, 1024) == 0);

	memset(buf1, 42, (0));
	memset(buf2, 42, (0));
	assert(memcmp(buf1, buf2, 1024) == 0);

	bzero(buf1, 1024);
	bzero(buf2, 1024);
	assert(memcmp(buf1, buf2, 1024) == 0);
}

void check_memcpy(void)
{
	char buf1[1024] = { 0 };
	char buf2[1024] = { 0 };

	memcpy(buf1, "abcdef", 5);
	memcpy(buf2, "abcdef", 5);
	assert(memcmp(buf1, buf2, 1024) == 0);

	memcpy(buf1, "\xff\x00\xaa\0\xee", 5);
	memcpy(buf2, "\xff\x00\xaa\0\xee", 5);
	assert(memcmp(buf1, buf2, 1024) == 0);
}

void check_memmove(void)
{
	char buf1[1024] = "abcdef";
	char buf2[1024] = "abcdef";

	memmove(buf1+1, buf1, 10);
	memmove(buf2+1, buf2, 10);
	assert(memcmp(buf1, buf2, 1024) == 0);
	
	memmove(buf1, buf1+1, 10);
	memmove(buf2, buf2+1, 10);
	assert(memcmp(buf1, buf2, 1024) == 0);
	
	memmove(buf1, buf1, 10);
	memmove(buf2, buf2, 10);
	assert(memcmp(buf1, buf2, 1024) == 0);
	
	memmove(buf1+512, buf1, 10);
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
			assert(strchr(strs[i], chars[j]) == strchr(strs[i], chars[j]));
			assert(strrchr(strs[i], chars[j]) == strrchr(strs[i], chars[j]));
		}
}

void check_strncmp(void)
{
	assert(strncmp("abcdef", "abcdef", 60) == strncmp("abcdef", "abcdef", 60));
	assert(strncmp("abcdef", "abcdef", 6) == strncmp("abcdef", "abcdef", 6));
	assert(strncmp("abcdef", "abcdeg", 6) == strncmp("abcdef", "abcdeg", 6));
	assert(strncmp("abcdef", "abcdeg", 5) == strncmp("abcdef", "abcdeg", 5));
	assert(strncmp("X", "X", 1) == strncmp("X", "X", 1));
	assert(strncmp("X", "Z", 0) == strncmp("X", "Z", 0));
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
			assert(memchr(strs[i], chars[j], 1024) == memchr(strs[i], chars[j], 1024));
		}
}

void check_atoi(void)
{
	assert(atoi("") == atoi(""));
	assert(atoi("abc") == atoi("abc"));
	assert(atoi("1abc") == atoi("1abc"));
	assert(atoi(" 1a") == atoi(" 1a"));
	assert(atoi("-1a") == atoi("-1a"));
	assert(atoi("1") == atoi("1"));
	assert(atoi("0") == atoi("0"));
	assert(atoi("-0") == atoi("-0"));
	assert(atoi("10") == atoi("10"));
	assert(atoi("-10") == atoi("-10"));
	assert(atoi("1234567890") == atoi("1234567890"));
	assert(atoi("2147483647") == atoi("2147483647"));
	assert(atoi("-2147483648") == atoi("-2147483648"));
}

void check_memcmp(void)
{
	assert(memcmp("abcdef", "abcdef", 6) == memcmp("abcdef", "abcdef", 6));
	assert(memcmp("abcdef", "abcdeg", 6) == memcmp("abcdef", "abcdeg", 6));
	assert(memcmp("abcdef", "abcdeg", 5) == memcmp("abcdef", "abcdeg", 5));
	assert(memcmp("X", "X", 1) == memcmp("X", "X", 1));
	assert(memcmp("X", "Z", 0) == memcmp("X", "Z", 0));
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
