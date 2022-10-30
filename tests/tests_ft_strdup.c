#include "minunit.h"
#include "libft.h"
#include "../src/ft_strdup.c"

MU_TEST(test_strdup_passing_one_letter_string)
{
	//ARRANGE
	char	s[] = "A";
	char	expected_result[] = "A";
	char	*actual_result;

	//ACT
	actual_result = ft_strdup(s);

	//ASSERT
	mu_assert(actual_result != s, "The returned pointer should not point to the same memory space passed by parameter");
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST(test_strdup_passing_ten_letters_string)
{
	//ARRANGE
	char	s[] = "1234567890";
	char	expected_result[] = "1234567890";
	char	*actual_result;

	//ACT
	actual_result = ft_strdup(s);

	//ASSERT
	mu_assert(actual_result != s, "The returned pointer should not point to the same memory space passed by parameter");
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST(test_strdup_passing_empty_string)
{
	//ARRANGE
	char	s[] = "";
	char	expected_result[] = "";
	char	*actual_result;

	//ACT
	actual_result = ft_strdup(s);

	//ASSERT
	mu_assert(actual_result != s, "The returned pointer should not point to the same memory space passed by parameter");
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST(test_strdup_passing_null_string)
{
	//ARRANGE
	char	*s = NULL;
	char	*expected_result = NULL;
	char	*actual_result;

	//ACT
	actual_result = ft_strdup(s);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

MU_TEST_SUITE(ft_strdup_test_suite) 
{
	MU_RUN_TEST(test_strdup_passing_one_letter_string);
	MU_RUN_TEST(test_strdup_passing_ten_letters_string);
	MU_RUN_TEST(test_strdup_passing_empty_string);
	MU_RUN_TEST(test_strdup_passing_null_string);
}