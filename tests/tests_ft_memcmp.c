#include "minunit.h"
#include "libft.h"
#include "../src/ft_memcmp.c"

MU_TEST(test_memcmp_comparing_lula_and_lula_returns_0)
{
	//ARRANGE
	char	word1[] = "lula";
	char	word2[] = "lula";
	int	size = 4;
	int	expected_result = 0;
	int	actual_result;

	//ACT
	actual_result = ft_memcmp(word1, word2, size);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_memcmp_comparing_lula_and_lulu_returns_minus_1)
{
	//ARRANGE
	char	word1[] = "lula";
	char	word2[] = "lulu";
	int	size = 4;
	int	expected_result = -1;
	int	actual_result;

	//ACT
	actual_result = ft_memcmp(word1, word2, size);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_memcmp_comparing_lulu_and_lula_returns_1)
{
	//ARRANGE
	char	word1[] = "lulu";
	char	word2[] = "lula";
	int	size = 4;
	int	expected_result = 1;
	int	actual_result;

	//ACT
	actual_result = ft_memcmp(word1, word2, size);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(ft_memcmp_test_suite) 
{
	MU_RUN_TEST(test_memcmp_comparing_lula_and_lula_returns_0);
	MU_RUN_TEST(test_memcmp_comparing_lula_and_lulu_returns_minus_1);
	MU_RUN_TEST(test_memcmp_comparing_lulu_and_lula_returns_1);
}