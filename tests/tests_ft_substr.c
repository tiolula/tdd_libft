#include "minunit.h"
#include "libft.h"
#include "../src/ft_substr.c"

MU_TEST(test_substr_entering_ABCDE_start_1_len_1_should_return_A)
{
	//ARRANGE
	char				s[] = "ABCDE";
	unsigned int		start = 0;
	int					len = 1;
	char				expected_result[] = "A";
	char				*actual_result;

	//ACT
	actual_result = ft_substr(s, start, len);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST(test_substr_entering_ABCDE_start_1_len_1_should_return_B)
{
	//ARRANGE
	char				s[] = "ABCDE";
	unsigned int		start = 1;
	int					len = 1;
	char				expected_result[] = "B";
	char				*actual_result;

	//ACT
	actual_result = ft_substr(s, start, len);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST(test_substr_entering_ABCDE_start_1_len_3_should_return_BCD)
{
	//ARRANGE
	char				s[] = "ABCDE";
	unsigned int		start = 1;
	int					len = 3;
	char				expected_result[] = "BCD";
	char				*actual_result;

	//ACT
	actual_result = ft_substr(s, start, len);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST(test_substr_entering_ABCDE_start_1_len_8_should_return_BCDE)
{
	//ARRANGE
	char				s[] = "ABCDE";
	unsigned int		start = 1;
	int					len = 8;
	char				expected_result[] = "BCDE";
	char				*actual_result;

	//ACT
	actual_result = ft_substr(s, start, len);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST(test_substr_entering_ABCDE_start_1_len_0_should_return_NULL)
{
	//ARRANGE
	char				s[] = "ABCDE";
	unsigned int		start = 1;
	int					len = 0;
	char				*actual_result;

	//ACT
	actual_result = ft_substr(s, start, len);

	//ASSERT
	mu_assert(actual_result == NULL, "The result should be NULL");
}

MU_TEST(test_substr_entering_ABCDE_start_0_len_3_should_return_ABC)
{
	//ARRANGE
	char				s[] = "ABCDE";
	unsigned int		start = 0;
	int					len = 3;
	char				expected_result[] = "ABC";
	char				*actual_result;

	//ACT
	actual_result = ft_substr(s, start, len);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST(test_substr_entering_empty_string_start_0_len_3_should_return_NULL)
{
	//ARRANGE
	char				s[] = "";
	unsigned int		start = 0;
	int					len = 3;
	char				*actual_result;

	//ACT
	actual_result = ft_substr(s, start, len);

	//ASSERT
	mu_assert(actual_result == NULL, "The result should be NULL");
}

MU_TEST(test_substr_entering_ABCDE_start_5_len_1_should_return_NULL)
{
	//ARRANGE
	char				s[] = "ABCDE";
	unsigned int		start = 5;
	int					len = 1;
	char				*actual_result;

	//ACT
	actual_result = ft_substr(s, start, len);

	//ASSERT
	mu_assert(actual_result == NULL, "The result should be NULL");
}

MU_TEST_SUITE(ft_substr_test_suite) 
{
	MU_RUN_TEST(test_substr_entering_ABCDE_start_1_len_1_should_return_A);
	MU_RUN_TEST(test_substr_entering_ABCDE_start_1_len_1_should_return_B);
	MU_RUN_TEST(test_substr_entering_ABCDE_start_1_len_3_should_return_BCD);
	MU_RUN_TEST(test_substr_entering_ABCDE_start_1_len_8_should_return_BCDE);
	MU_RUN_TEST(test_substr_entering_ABCDE_start_1_len_0_should_return_NULL);
	MU_RUN_TEST(test_substr_entering_ABCDE_start_0_len_3_should_return_ABC);
	MU_RUN_TEST(test_substr_entering_empty_string_start_0_len_3_should_return_NULL);
	MU_RUN_TEST(test_substr_entering_ABCDE_start_5_len_1_should_return_NULL);
}