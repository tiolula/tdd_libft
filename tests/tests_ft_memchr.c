#include "minunit.h"
#include "libft.h"
#include "../src/ft_memchr.c"

MU_TEST(test_memchr_searching_l_in_lula_returns_the_first_letter_pointer)
{
	//ARRANGE
	char	word[] = "lula";
	char	letter = 'l';
	size_t	size = 4;
	char	*expected_result = &word[0];
	void	*actual_result;

	//ACT
	actual_result = ft_memchr(word, letter, size);

	//ASSERT
	mu_assert(expected_result == actual_result, "the returned memory position is not the expected one");
}

MU_TEST(test_memchr_searching_u_in_lula_returns_the_second_letter_pointer)
{
	//ARRANGE
	char	word[] = "lula";
	char	letter = 'u';
	size_t	size = 4;
	char	*expected_result = &word[1];
	void	*actual_result;

	//ACT
	actual_result = ft_memchr(word, letter, size);

	//ASSERT
	mu_assert(expected_result == actual_result, "the returned memory position is not the expected one");
}

MU_TEST_SUITE(ft_memchr_test_suite) 
{
	MU_RUN_TEST(test_memchr_searching_l_in_lula_returns_the_first_letter_pointer);
	MU_RUN_TEST(test_memchr_searching_u_in_lula_returns_the_second_letter_pointer);
}