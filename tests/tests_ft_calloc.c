#include "minunit.h"
#include "libft.h"
#include "../src/ft_calloc.c"

MU_TEST(test_calloc_allocating_1_byte_char)
{
	//ARRANGE
	size_t	count = 1;
	size_t	size = sizeof(char);
	char	expected_result = '\0';
	char	*actual_result;

	//ACT
	actual_result = ft_calloc(count, size);

	//ASSERT
	mu_assert_char_eq(expected_result, *actual_result);
	free(actual_result);
}

MU_TEST(test_calloc_allocating_100000_bytes_char)
{
	//ARRANGE
	size_t	count = 100000;
	size_t	size = sizeof(char);
	char	expected_result[100000] = {0};
	char	*actual_result;

	//ACT
	actual_result = ft_calloc(count, size);

	//ASSERT
	mu_assert_mem_eq(expected_result, actual_result, count);
	free(actual_result);
}

//TODO: FIND A WAY TO SEE THIS TEST FAILING :'( #NOTFAIL
MU_TEST(test_calloc_allocating_more_than_size_t_max_should_return_null)
{
	//ARRANGE
	
#define SIZE_MAX ((size_t)~((size_t)0))

	size_t	count = SIZE_MAX + 1;
	size_t	size = sizeof(char);
	char	*expected_result = NULL;
	char	*actual_result;

	//ACT
	actual_result = ft_calloc(count, size);

	//ASSERT
	mu_assert_mem_eq(expected_result, actual_result, count);
	free(actual_result);
}

MU_TEST_SUITE(ft_calloc_test_suite) 
{
	MU_RUN_TEST(test_calloc_allocating_1_byte_char);
	MU_RUN_TEST(test_calloc_allocating_100000_bytes_char);
	MU_RUN_TEST(test_calloc_allocating_more_than_size_t_max_should_return_null);
}