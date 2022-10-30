#include "minunit.h"
#include "libft.h"
#include "../src/ft_bzero.c"

MU_TEST(test_bzero_passing_just_one_byte_should_set_it_to_null)
{
	// ARRANGE
	char c = 'x';
	char *s = &c;
	size_t n = 1;
	int expected_result = '\0'; // NULL

	// ACT
	ft_bzero(s, n);
	
	// ASSERT
	mu_assert_int_eq(expected_result, c);
}


MU_TEST(test_bzero_passing_just_two_bytes_and_size_two_should_set_them_to_null)
{
	// ARRANGE
	char c[2] = {'a', 'b'};
	char *s = &c[0];
	size_t n = 2;
	int expected_result = '\0'; // NULL

	// ACT
	ft_bzero(s, n);
	
	// ASSERT
	mu_assert_int_eq(expected_result, c[0]);
	mu_assert_int_eq(expected_result, c[1]);
}

MU_TEST(test_bzero_passing_just_two_bytes_and_size_zero_should_change_nothing)
{
	// ARRANGE
	char c[2] = {'a', 'b'};
	char *s = &c[0];
	size_t n = 0;
	int expected_result_a = 'a';
	int expected_result_b = 'b';

	// ACT
	ft_bzero(s, n);
	
	// ASSERT
	mu_assert_int_eq(expected_result_a, c[0]);
	mu_assert_int_eq(expected_result_b, c[1]);
}

MU_TEST_SUITE(ft_bzero_test_suite) 
{
	MU_RUN_TEST(test_bzero_passing_just_one_byte_should_set_it_to_null);
	MU_RUN_TEST(test_bzero_passing_just_two_bytes_and_size_two_should_set_them_to_null);
	MU_RUN_TEST(test_bzero_passing_just_two_bytes_and_size_zero_should_change_nothing);
}