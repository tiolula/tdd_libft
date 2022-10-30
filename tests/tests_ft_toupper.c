#include "minunit.h"
#include "libft.h"
#include "../src/ft_toupper.c"

MU_TEST(test_toupper_entry_x_returns_X)
{
	// ARRANGE
	char c = 'x';
	char expected_result = 'X';
	char actual_result;

	// ACT
	actual_result = ft_toupper(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_toupper_entry_a_returns_A)
{
	// ARRANGE
	char c = 'a';
	char expected_result = 'A';
	char actual_result;

	// ACT
	actual_result = ft_toupper(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_toupper_entry_A_returns_A)
{
	// ARRANGE
	char c = 'A';
	char expected_result = 'A';
	char actual_result;

	// ACT
	actual_result = ft_toupper(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_toupper_entry_asterisc_returns_asterisc)
{
	// ARRANGE
	char c = '*';
	char expected_result = '*';
	char actual_result;

	// ACT
	actual_result = ft_toupper(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_toupper_entry_200_returns_200)
{
	// ARRANGE
	int c = 200;
	int expected_result = 200;
	int actual_result;

	// ACT
	actual_result = ft_toupper(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(ft_toupper_test_suite) 
{
	MU_RUN_TEST(test_toupper_entry_x_returns_X);
	MU_RUN_TEST(test_toupper_entry_a_returns_A);
	MU_RUN_TEST(test_toupper_entry_A_returns_A);
	MU_RUN_TEST(test_toupper_entry_asterisc_returns_asterisc);
	MU_RUN_TEST(test_toupper_entry_200_returns_200);
}