#include "minunit.h"
#include "libft.h"
#include "../src/ft_itoa.c"

MU_TEST(test_itoa_entering_1_integer_returns_1_string)
{
	// ARRANGE
	int n = 1;
	char *expected_result = "1";
	char *actual_result;

	// ACT
	actual_result = ft_itoa(n);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST(test_itoa_entering_2_integer_returns_2_string)
{
	// ARRANGE
	int n = 2;
	char *expected_result = "2";
	char *actual_result;

	// ACT
	actual_result = ft_itoa(n);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST(test_itoa_entering_42_integer_returns_42_string)
{
	// ARRANGE
	int n = 42;
	char *expected_result = "42";
	char *actual_result;

	// ACT
	actual_result = ft_itoa(n);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST(test_itoa_entering_minus_42_integer_returns_minus_42_string)
{
	// ARRANGE
	int n = -42;
	char *expected_result = "-42";
	char *actual_result;

	// ACT
	actual_result = ft_itoa(n);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST(test_itoa_entering_0_integer_returns_minus_0_string)
{
	// ARRANGE
	int n = 0;
	char *expected_result = "0";
	char *actual_result;

	// ACT
	actual_result = ft_itoa(n);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST_SUITE(ft_itoa_test_suite) 
{
	MU_RUN_TEST(test_itoa_entering_1_integer_returns_1_string);
	MU_RUN_TEST(test_itoa_entering_2_integer_returns_2_string);
	MU_RUN_TEST(test_itoa_entering_42_integer_returns_42_string);
	MU_RUN_TEST(test_itoa_entering_minus_42_integer_returns_minus_42_string);
	MU_RUN_TEST(test_itoa_entering_0_integer_returns_minus_0_string);
}