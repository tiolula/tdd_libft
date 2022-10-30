#include "minunit.h"
#include "libft.h"
#include "../src/ft_strlen.c"


MU_TEST(test_strlen_entering_abc_returns_3)
{
	// ARRANGE
	char	*s = "abc";
	int	expected_result = 3;
	int	actual_result;

	// ACT
	actual_result = ft_strlen(s);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_strlen_entering_a_returns_1)
{
	// ARRANGE
	char	*s = "a";
	int	expected_result = 1;
	int	actual_result;

	// ACT
	actual_result = ft_strlen(s);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_strlen_entering_empty_string_returns_0)
{
	// ARRANGE
	char	*s = "";
	int	expected_result = 0;
	int	actual_result;

	// ACT
	actual_result = ft_strlen(s);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(ft_strlen_test_suite) 
{
	MU_RUN_TEST(test_strlen_entering_abc_returns_3);
	MU_RUN_TEST(test_strlen_entering_a_returns_1);
	MU_RUN_TEST(test_strlen_entering_empty_string_returns_0);
}