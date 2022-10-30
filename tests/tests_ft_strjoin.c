#include "minunit.h"
#include "libft.h"
#include "../src/ft_strjoin.c"

MU_TEST(test_strjoin_entering_A_and_B_should_return_AB)
{
	//ARRANGE
	char	s1[] = "A";
	char	s2[] = "B";
	char	expected_result[] = "AB";			
	char	*actual_result;

	//ACT
	actual_result = ft_strjoin(s1, s2);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST(test_strjoin_entering_AB_and_CD_should_return_ABCD)
{
	//ARRANGE
	char	s1[] = "AB";
	char	s2[] = "CD";
	char	expected_result[] = "ABCD";			
	char	*actual_result;

	//ACT
	actual_result = ft_strjoin(s1, s2);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST(test_strjoin_entering_ABC_and_DEF_should_return_ABCDEF)
{
	//ARRANGE
	char	s1[] = "ABC";
	char	s2[] = "DEF";
	char	expected_result[] = "ABCDEF";			
	char	*actual_result;

	//ACT
	actual_result = ft_strjoin(s1, s2);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST(test_strjoin_entering_LULA_and_LIVRE_should_return_LULALIVRE)
{
	//ARRANGE
	char	s1[] = "LULA";
	char	s2[] = "LIVRE";
	char	expected_result[] = "LULALIVRE";			
	char	*actual_result;

	//ACT
	actual_result = ft_strjoin(s1, s2);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST(test_strjoin_entering_empty_string_and_X_should_return_X)
{
	//ARRANGE
	char	s1[] = "";
	char	s2[] = "X";
	char	expected_result[] = "X";			
	char	*actual_result;

	//ACT
	actual_result = ft_strjoin(s1, s2);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST(test_strjoin_entering_X_and_empty_string_should_return_X)
{
	//ARRANGE
	char	s1[] = "X";
	char	s2[] = "";
	char	expected_result[] = "X";			
	char	*actual_result;

	//ACT
	actual_result = ft_strjoin(s1, s2);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST(test_strjoin_entering_empty_string_and_empty_string_should_return_empty_string)
{
	//ARRANGE
	char	s1[] = "";
	char	s2[] = "";
	char	expected_result[] = "";
	char	*actual_result;

	//ACT
	actual_result = ft_strjoin(s1, s2);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST_SUITE(ft_strjoin_test_suite) 
{
	MU_RUN_TEST(test_strjoin_entering_A_and_B_should_return_AB);
	MU_RUN_TEST(test_strjoin_entering_AB_and_CD_should_return_ABCD);
	MU_RUN_TEST(test_strjoin_entering_ABC_and_DEF_should_return_ABCDEF);
	MU_RUN_TEST(test_strjoin_entering_LULA_and_LIVRE_should_return_LULALIVRE);
	MU_RUN_TEST(test_strjoin_entering_empty_string_and_X_should_return_X);
	MU_RUN_TEST(test_strjoin_entering_X_and_empty_string_should_return_X);
	MU_RUN_TEST(test_strjoin_entering_empty_string_and_empty_string_should_return_empty_string);
}