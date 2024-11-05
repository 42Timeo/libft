#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <limits.h>
#include <ctype.h>
#include "libft.h"

Test(isprint, reference) {
	for (int i = 0; i <= UCHAR_MAX; i++)
		cr_expect(eq(int, isprint(i) != 0, ft_isprint(i) != 0), "%d", i);
}

Test(isprint, no_crash) {
	cr_skip("skipped because too long");
	for (long int i = INT_MIN; i <= INT_MAX; i++)
		ft_isprint(i);
}
