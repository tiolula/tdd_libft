#include "minunit.h"
#include "libft.h"
#include "../src/ft_isprint.c"

MU_TEST(test_isprint_entering_a_returns_true)
{
	// ARRANGE
	int c = 'a';
	int	expected_result = 16384; //true
	int	actual_result;

	// ACT
	actual_result = ft_isprint(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_isprint_entering_space_returns_true)
{
	// ARRANGE
	int c = ' ';
	int	expected_result = 16384; //true
	int	actual_result;

	// ACT
	actual_result = ft_isprint(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_isprint_entering_del_returns_false)
{
	// ARRANGE
	int c = 127;
	int	expected_result = 0; //false
	int	actual_result;

	// ACT
	actual_result = ft_isprint(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_isprint_entering_tab_returns_false)
{
	// ARRANGE
	int c = '\t';
	int	expected_result = 0; //false
	int	actual_result;

	// ACT
	actual_result = ft_isprint(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_isprint_entering_0_returns_false)
{
	// ARRANGE
	int c = 0;
	int	expected_result = 0; //false
	int	actual_result;

	// ACT
	actual_result = ft_isprint(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_isprint_entering_126_returns_true)
{
	// ARRANGE
	int c = 126;
	int	expected_result = 16384; //false
	int	actual_result;

	// ACT
	actual_result = ft_isprint(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(ft_isprint_test_suite) 
{
	MU_RUN_TEST(test_isprint_entering_a_returns_true);
	MU_RUN_TEST(test_isprint_entering_space_returns_true);
	MU_RUN_TEST(test_isprint_entering_del_returns_false);
	MU_RUN_TEST(test_isprint_entering_tab_returns_false);
	MU_RUN_TEST(test_isprint_entering_0_returns_false);
	MU_RUN_TEST(test_isprint_entering_126_returns_true);
}