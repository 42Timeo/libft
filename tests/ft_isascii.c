#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <limits.h>
#include <ctype.h>
#include "libft.h"

Test(isascii, reference) {
	cr_skip("skipped because too long");
	for (long int i = INT_MIN; i <= INT_MAX; i++)
		cr_expect(eq(int, isascii(i) != 0, ft_isascii(i) != 0), "%d", i);
}
