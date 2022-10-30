#include "minunit.h"
#include "libft.h"
#include "../src/ft_strmapi.c"

char	support_function_char_plus_one(unsigned int index, char s)
{
	char	plus_one;

	plus_one = s + 1 + index - index;
	return plus_one;
}

MU_TEST(test_strmapi_passing_a_and_plus_one_function_should_change_it_to_b)
{
	//ARRANGE
	char	s[] = "a";
	char	expected_result[] = "b";
	char	*actual_result;

	//ACT
	actual_result = ft_strmapi(s, support_function_char_plus_one);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST(test_strmapi_passing_abc_and_plus_one_function_should_change_it_to_bcd)
{
	//ARRANGE
	char	s[] = "abc";
	char	expected_result[] = "bcd";
	char	*actual_result;

	//ACT
	actual_result = ft_strmapi(s, support_function_char_plus_one);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST(test_strmapi_passing_empty_string_and_plus_one_function_should_return_NULL)
{
	//ARRANGE
	char	s[] = "";
	char	*expected_result = NULL;
	char	*actual_result;

	//ACT
	actual_result = ft_strmapi(s, support_function_char_plus_one);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST(test_strmapi_passing_abc_and_null_should_return_NULL)
{
	//ARRANGE
	char	s[] = "abc";
	char	*expected_result = NULL;
	char	*actual_result;

	//ACT
	actual_result = ft_strmapi(s, NULL);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST(test_strmapi_passing_null_and_plus_one_function_should_return_NULL)
{
	//ARRANGE
	char	*s = NULL;
	char	*expected_result = NULL;
	char	*actual_result;

	//ACT
	actual_result = ft_strmapi(s, support_function_char_plus_one);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST_SUITE(ft_strmapi_test_suite) 
{
	MU_RUN_TEST(test_strmapi_passing_a_and_plus_one_function_should_change_it_to_b);
	MU_RUN_TEST(test_strmapi_passing_abc_and_plus_one_function_should_change_it_to_bcd);
	MU_RUN_TEST(test_strmapi_passing_empty_string_and_plus_one_function_should_return_NULL);
	MU_RUN_TEST(test_strmapi_passing_abc_and_null_should_return_NULL);
	MU_RUN_TEST(test_strmapi_passing_null_and_plus_one_function_should_return_NULL);
}