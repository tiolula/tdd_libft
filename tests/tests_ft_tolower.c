#include "minunit.h"
#include "libft.h"
#include "../src/ft_tolower.c"

MU_TEST(test_tolower_entry_X_returns_x)
{
	// ARRANGE
	char c = 'X';
	char expected_result = 'x';
	char actual_result;

	// ACT
	actual_result = ft_tolower(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_tolower_entry_A_returns_a)
{
	// ARRANGE
	char c = 'A';
	char expected_result = 'a';
	char actual_result;

	// ACT
	actual_result = ft_tolower(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_tolower_entry_a_returns_a)
{
	// ARRANGE
	char c = 'a';
	char expected_result = 'a';
	char actual_result;

	// ACT
	actual_result = ft_tolower(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_tolower_entry_asterisc_returns_asterisc)
{
	// ARRANGE
	char c = '*';
	char expected_result = '*';
	char actual_result;

	// ACT
	actual_result = ft_tolower(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_tolower_entry_200_returns_200)
{
	// ARRANGE
	int c = 200;
	int expected_result = 200;
	int actual_result;

	// ACT
	actual_result = ft_tolower(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(ft_tolower_test_suite) 
{
	MU_RUN_TEST(test_tolower_entry_X_returns_x);
	MU_RUN_TEST(test_tolower_entry_A_returns_a);
	MU_RUN_TEST(test_tolower_entry_a_returns_a);
	MU_RUN_TEST(test_tolower_entry_asterisc_returns_asterisc);
	MU_RUN_TEST(test_tolower_entry_200_returns_200);
}