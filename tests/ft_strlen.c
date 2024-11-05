#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/parameterized.h>
#include <criterion/theories.h>
#include <string.h>
#include <signal.h>
#include "libft.h"


Test(strlen, null, .signal = SIGSEGV) {
	ft_strlen(NULL);
}


/// DYNAMIC ALLOCATION

void free_params(struct criterion_test_params *crp)
{
	for (size_t i = 0; i < crp->length; i++)
		cr_free(((void **) crp->params)[i]);
	cr_free(crp->params);
}

struct criterion_test_params alloc_params(char buffers[][1024], size_t size, size_t buffer_size)
{
	char **params = cr_malloc(size * sizeof(char *));
	for (size_t i = 0; i < size; i++)
	{
		params[i] = cr_malloc(buffer_size * sizeof(char));
		memcpy(params[i], buffers[i], buffer_size);
	}
	return cr_make_param_array(char *, params, size, free_params);
}

ParameterizedTestParameters(strlen, reference_dynamic) {
	char buffers[][1024] = {
		"abcdef",
		"abcdefg\0saosjoa",
		"",
	};
	return (alloc_params(buffers, sizeof(buffers) / sizeof(buffers[0]), sizeof(buffers[0])));
}

ParameterizedTest(char **param, strlen, reference_dynamic) {
	cr_skip();
	__builtin_printf("dynamic: %s\n", *param);
	cr_expect(eq(sz, strlen(*param), ft_strlen(*param)));
	*param[0] = 'A';
}


/// STRUCTURE

struct my_param
{
	char str[1024];
};

ParameterizedTestParameters(strlen, reference_structure) {
	static struct my_param params[] = {
		{ "abcdef" },
		{ "abcdefg\0saosjoa" },
		{ "" },
	};
	return cr_make_param_array(struct my_param, params, 3);
}

ParameterizedTest(struct my_param *param, strlen, reference_structure) {
	cr_skip();
	__builtin_printf("struct: %s\n", param->str);
	cr_expect(eq(sz, strlen(param->str), ft_strlen(param->str)));
	param->str[0] = 'A';
}


/// BUFFER

ParameterizedTestParameters(strlen, reference_buffer) {
	static char params[][1024] = {
		"abcdef",
		"abcdefg\0saosjoa",
		"",
	};
	return cr_make_param_array(char[1024], params, 3);
}

ParameterizedTest(char (*param)[1024], strlen, reference_buffer) {
	cr_skip();
	__builtin_printf("buffer: %s\n", *param);
	cr_expect(eq(sz, strlen(*param), ft_strlen(*param)));
	*param[0] = 'A';
}



/// PLAIN LOOP

Test(strlen, loop) {
	cr_skip();
	char *strs[] = {
		"abcdef",
		"abcdefg\0saosjoa",
		"",
	};
	for (size_t i = 0; i < (sizeof(strs)/sizeof(char*)); i++)
	{
		__builtin_printf("loop: %s\n", strs[i]);
		cr_expect(eq(sz, strlen(strs[i]), ft_strlen(strs[i])));
		strs[i][0] = 'A';
	}
}


/// THEORY

TheoryDataPoints(strlen, theory) = {
	DataPoints(char *, "abcdef", "abcdefg\0asiahs", ""),
};

Theory((char *str), strlen, theory) {
	cr_skip();
	__builtin_printf("theory: %s\n", str);
	cr_expect(eq(sz, strlen(str), ft_strlen(str)));
	str[0] = 'A';
}


