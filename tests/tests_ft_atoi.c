#include "minunit.h"
#include "libft.h"
#include "../src/ft_atoi.c"

MU_TEST(test_atoi_convert_1_char_to_1_integer)
{
	// ARRANGE
	char *c = "1";
	int expected_result = 1;
	char actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_convert_2_char_to_2_integer)
{
	// ARRANGE
	char *c = "2";
	int expected_result = 2;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_convert_42_char_to_42_integer)
{
	// ARRANGE
	char *c = "42";
	int expected_result = 42;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_convert_1042_char_to_1042_integer)
{
	// ARRANGE
	char *c = "1042";
	int expected_result = 1042;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_convert_minus_1_char_to_minus_1_integer)
{
	// ARRANGE
	char *c = "-1";
	int expected_result = -1;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_convert_minus_1042_char_to_minus_1042_integer)
{
	// ARRANGE
	char *c = "-1042";
	int expected_result = -1042;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_convert_minus_1042_with_space_char_to_minus_1042_integer)
{
	// ARRANGE
	char *c = "   -1042";
	int expected_result = -1042;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_entering_minus_minus_1042_char_returns_0_integer)
{
	// ARRANGE
	char *c = "--1042";
	int expected_result = 0;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_entering_1042e2_char_returns_1042_integer)
{
	// ARRANGE
	char *c = "1042e2";
	int expected_result = 1042;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_entering_MAX_INT_char_returns_2147483647_integer)
{
	// ARRANGE
	char *c = "2147483647";
	int expected_result = 2147483647;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_entering_MAX_INT_plus_one_char_returns_minus_2147483648_integer)
{
	// ARRANGE
	char *c = "2147483648";
	int expected_result = -2147483648;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_entering_MIN_INT_char_returns_minus_2147483648_integer)
{
	// ARRANGE
	char *c = "-2147483648";
	int expected_result = -2147483648;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_entering_MIN_INT_minus_one_char_returns_positive_2147483647_integer)
{
	// ARRANGE
	char *c = "-2147483649";
	int expected_result = 2147483647;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_entering_0_char_returns_0_integer)
{
	// ARRANGE
	char *c = "0";
	int expected_result = 0;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_entering_plus_42_char_returns_42_integer)
{
	// ARRANGE
	char *c = "+42";
	int expected_result = 42;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_entering_plus_plus_42_char_returns_0_integer)
{
	// ARRANGE
	char *c = "++42";
	int expected_result = 0;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(ft_atoi_test_suite) 
{
	MU_RUN_TEST(test_atoi_convert_1_char_to_1_integer);
	MU_RUN_TEST(test_atoi_convert_2_char_to_2_integer);
	MU_RUN_TEST(test_atoi_convert_42_char_to_42_integer);
	MU_RUN_TEST(test_atoi_convert_1042_char_to_1042_integer);
	MU_RUN_TEST(test_atoi_convert_minus_1_char_to_minus_1_integer);
	MU_RUN_TEST(test_atoi_convert_minus_1042_char_to_minus_1042_integer);
	MU_RUN_TEST(test_atoi_convert_minus_1042_with_space_char_to_minus_1042_integer);
	MU_RUN_TEST(test_atoi_entering_minus_minus_1042_char_returns_0_integer);
	MU_RUN_TEST(test_atoi_entering_1042e2_char_returns_1042_integer);
	MU_RUN_TEST(test_atoi_entering_MAX_INT_plus_one_char_returns_minus_2147483648_integer);
	MU_RUN_TEST(test_atoi_entering_MAX_INT_char_returns_2147483647_integer);
	MU_RUN_TEST(test_atoi_entering_MIN_INT_char_returns_minus_2147483648_integer);
	MU_RUN_TEST(test_atoi_entering_MIN_INT_minus_one_char_returns_positive_2147483647_integer);
	MU_RUN_TEST(test_atoi_entering_0_char_returns_0_integer);
	MU_RUN_TEST(test_atoi_entering_plus_42_char_returns_42_integer);
	MU_RUN_TEST(test_atoi_entering_plus_plus_42_char_returns_0_integer);
}