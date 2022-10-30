#include "minunit.h"
#include "libft.h"
#include "../src/ft_isalnum.c"

MU_TEST(test_isalnum_receiving_a_returns_true)
{
	//ARRANGE
	int		input = 'a';
	int		expected_result = 8;// true
	int		actual_result;

	//ACT
	actual_result = ft_isalnum(input);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_isalnum_receiving_asterisc_returns_false)
{
	//ARRANGE
	int		input = '*';
	int		expected_result = 0; // false
	int		actual_result;

	//ACT
	actual_result = ft_isalnum(input);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_isalnum_receiving_1_returns_true)
{
	//ARRANGE
	int		input = '1';
	int		expected_result = 8; // true
	int		actual_result;

	//ACT
	actual_result = ft_isalnum(input);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(ft_isalnum_test_suite) 
{
	MU_RUN_TEST(test_isalnum_receiving_a_returns_true);
	MU_RUN_TEST(test_isalnum_receiving_asterisc_returns_false);
	MU_RUN_TEST(test_isalnum_receiving_1_returns_true);
}