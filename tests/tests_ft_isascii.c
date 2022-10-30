#include "minunit.h"
#include "libft.h"
#include "../src/ft_isascii.c"

MU_TEST(test_isascii_entering_a_returns_true)
{
	// ARRANGE
	int c = 'a';
	int	expected_result = 1; //true
	int	actual_result;

	// ACT
	actual_result = ft_isascii(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_isascii_entering_128_returns_false)
{
	// ARRANGE
	int c = 128;
	int	expected_result = 0; //false
	int	actual_result;

	// ACT
	actual_result = ft_isascii(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_isascii_entering_0_returns_true)
{
	// ARRANGE
	int c = 0;
	int	expected_result = 1; //true
	int	actual_result;

	// ACT
	actual_result = ft_isascii(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_isascii_entering_129_returns_false)
{
	// ARRANGE
	int c = 129;
	int	expected_result = 0; //false
	int	actual_result;

	// ACT
	actual_result = ft_isascii(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_isascii_entering_127_returns_true)
{
	// ARRANGE
	int c = 127;
	int	expected_result = 1; //true
	int	actual_result;

	// ACT
	actual_result = ft_isascii(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(ft_isascii_test_suite) 
{
	MU_RUN_TEST(test_isascii_entering_a_returns_true);
	MU_RUN_TEST(test_isascii_entering_128_returns_false);
	MU_RUN_TEST(test_isascii_entering_0_returns_true);
	MU_RUN_TEST(test_isascii_entering_129_returns_false);
	MU_RUN_TEST(test_isascii_entering_127_returns_true);
}