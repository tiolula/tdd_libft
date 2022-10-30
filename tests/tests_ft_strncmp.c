#include "minunit.h"
#include "libft.h"
#include "../src/ft_strncmp.c"

MU_TEST(test_strncmp_comparing_banana_and_banana_size_6_should_return_zero)
{
	//ARRANGE
	char	first_word[] = "banana";
	char	second_word[] = "banana";
	size_t	size = 6;
	int		expected_result = 0;
	int		actual_result;

	//ACT
	actual_result = ft_strncmp(first_word, second_word, size);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_strncmp_comparing_bananaA_and_bananaB_size_7_should_return_minus_one)
{
	//ARRANGE
	char	first_word[] = "bananaA";
	char	second_word[] = "bananaB";
	size_t	size = 7;
	int		expected_result = -1;
	int		actual_result;

	//ACT
	actual_result = ft_strncmp(first_word, second_word, size);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_strncmp_comparing_bananaA_and_bananaB_size_6_should_return_zero)
{
	//ARRANGE
	char	first_word[] = "bananaA";
	char	second_word[] = "bananaB";
	size_t	size = 6;
	int		expected_result = 0;
	int		actual_result;

	//ACT
	actual_result = ft_strncmp(first_word, second_word, size);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_strncmp_comparing_bananaA_and_bananaB_size_0_should_return_zero)
{
	//ARRANGE
	char	first_word[] = "bananaA";
	char	second_word[] = "bananaB";
	size_t	size = 0;
	int		expected_result = 0;
	int		actual_result;

	//ACT
	actual_result = ft_strncmp(first_word, second_word, size);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_strncmp_comparing_banana_and_banana_with_a_large_size_should_return_zero)
{
	//ARRANGE
	char	first_word[] = "banana";
	char	second_word[] = "banana";
	size_t	size = 120;
	int		expected_result = 0;
	int		actual_result;

	//ACT
	actual_result = ft_strncmp(first_word, second_word, size);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_strncmp_comparing_A_and_empty_string_string_size_1_should_return_sixty_five)
{
	//ARRANGE
	char	first_word[] = "A";
	char	second_word[] = "";
	size_t	size = 1;
	int		expected_result = 65;
	int		actual_result;

	//ACT
	actual_result = ft_strncmp(first_word, second_word, size);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_strncmp_comparing_B_and_A_size_1_should_return_one)
{
	//ARRANGE
	char	first_word[] = "B";
	char	second_word[] = "A";
	size_t	size = 1;
	int		expected_result = 1;
	int		actual_result;

	//ACT
	actual_result = ft_strncmp(first_word, second_word, size);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(ft_strncmp_test_suite) 
{
	MU_RUN_TEST(test_strncmp_comparing_banana_and_banana_size_6_should_return_zero);
	MU_RUN_TEST(test_strncmp_comparing_bananaA_and_bananaB_size_7_should_return_minus_one);
	MU_RUN_TEST(test_strncmp_comparing_bananaA_and_bananaB_size_6_should_return_zero);
	MU_RUN_TEST(test_strncmp_comparing_bananaA_and_bananaB_size_0_should_return_zero);
	MU_RUN_TEST(test_strncmp_comparing_banana_and_banana_with_a_large_size_should_return_zero);
	MU_RUN_TEST(test_strncmp_comparing_A_and_empty_string_string_size_1_should_return_sixty_five);
	MU_RUN_TEST(test_strncmp_comparing_B_and_A_size_1_should_return_one);
}