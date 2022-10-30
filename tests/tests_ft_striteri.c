#include "minunit.h"
#include "libft.h"
#include "../src/ft_striteri.c"

void	support_function_plus_one(unsigned int index, char *s)
{
	s[index]++;
}

MU_TEST(test_striteri_passing_a_and_plus_one_function_should_change_it_to_b)
{
	//ARRANGE
	char	s[] = "a";
	char	expected_result[] = "b";

	//ACT
	ft_striteri(s, support_function_plus_one);

	//ASSERT
	mu_assert_string_eq(expected_result, s);
}

MU_TEST(test_striteri_passing_abc_and_plus_one_function_should_change_it_to_bcd)
{
	//ARRANGE
	char	s[] = "abc";
	char	expected_result[] = "bcd";

	//ACT
	ft_striteri(s, support_function_plus_one);

	//ASSERT
	mu_assert_string_eq(expected_result, s);
}

MU_TEST(test_striteri_passing_empty_string_and_plus_one_function_should_not_change_it)
{
	//ARRANGE
	char	s[] = "";
	char	expected_result[] = "";

	//ACT
	ft_striteri(s, support_function_plus_one);

	//ASSERT
	mu_assert_string_eq(expected_result, s);
}

MU_TEST(test_striteri_passing_abc_and_null_should_do_nothing)
{
	//ARRANGE
	char	s[] = "abc";
	char	expected_result[] = "abc";

	//ACT
	ft_striteri(s, NULL);

	//ASSERT
	mu_assert_string_eq(expected_result, s);
}

MU_TEST(test_striteri_passing_null_and_plus_one_function_should_do_nothing)
{
	//ARRANGE
	char	*s = NULL;
	char	*expected_result = NULL;

	//ACT
	ft_striteri(s, support_function_plus_one);

	//ASSERT
	mu_assert_string_eq(expected_result, s);
}

MU_TEST_SUITE(ft_striteri_test_suite) 
{
	MU_RUN_TEST(test_striteri_passing_a_and_plus_one_function_should_change_it_to_b);
	MU_RUN_TEST(test_striteri_passing_abc_and_plus_one_function_should_change_it_to_bcd);
	MU_RUN_TEST(test_striteri_passing_empty_string_and_plus_one_function_should_not_change_it);
	MU_RUN_TEST(test_striteri_passing_abc_and_null_should_do_nothing);
	MU_RUN_TEST(test_striteri_passing_null_and_plus_one_function_should_do_nothing);
}