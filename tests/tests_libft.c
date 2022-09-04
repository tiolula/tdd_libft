#include <stdlib.h>
#include "minunit.h"
#include "libft.h"

//static const char* foostring = "Thisstring";

void test_setup(void) {
	/* Nothing */	
}

void test_teardown(void) {
	/* Nothing */
}

MU_TEST(test_memset_setting_NUL_in_one_mem_position){
	//ARRANGE
	void*	memory_position = malloc(sizeof(char) * 1);
	// setting a random value (42) to "dirty" it before the test
	memset(memory_position, 42, 1);
	int	value_to_set = 0;
	
	//ACT
	ft_memset(memory_position, value_to_set, 1);

	//ASSERT
	mu_assert(*(unsigned char *)memory_position == value_to_set, "memory value should be set to NUL");
}

MU_TEST(test_memset_setting_NUL_in_two_mem_positions){
	//ARRANGE
	void*	memory_position = malloc(sizeof(char) * 2);
	// setting a random value (42) to "dirty" it before the test
	memset(memory_position, 42, 2);
	int	value_to_set = 0;
	
	//ACT
	ft_memset(memory_position, value_to_set, 2);

	//ASSERT
	mu_assert(*(unsigned char *)memory_position == value_to_set, "the first memory position value should be set to NUL");
	mu_assert(*(unsigned char *)(memory_position + 1) == value_to_set, "the second memory position value should be set to NUL");
}

MU_TEST(test_memset_setting_NUL_in_two_mem_positions_should_return_the_original_pointer){
	//ARRANGE
	void*	memory_position = malloc(sizeof(char) * 2);
	// setting a random value (42) to "dirty" it before the test
	memset(memory_position, 42, 2);
	int	value_to_set = 0;
	void*	returned_memory_position;
	
	//ACT
	returned_memory_position = ft_memset(memory_position, value_to_set, 2);

	//ASSERT
	mu_assert(memory_position == returned_memory_position, "the returned memory position is not the original one");
}

MU_TEST_SUITE(test_isalpha_receiving_A_returns_true)
{
	//ARRANGE
	char	input = 'A';
	int		expected_result = 1024;// it could be any number different from 0
	int		actual_result;

	//ACT
	actual_result = ft_isalpha(input);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(test_isalpha_receiving_char_1_returns_false)
{
	//ARRANGE
	char	input = '1';
	int		expected_result = 0;// false
	int		actual_result;

	//ACT
	actual_result = ft_isalpha(input);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(test_isalpha_receiving_asterisc_returns_false)
{
	//ARRANGE
	int		input = '*';
	int		expected_result = 0;// false
	int		actual_result;

	//ACT
	actual_result = ft_isalpha(input);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(test_isalpha_receiving_minus_65_returns_false)
{
	//ARRANGE
	int		input = -65;
	int		expected_result = 0;// false
	int		actual_result;

	//ACT
	actual_result = ft_isalpha(input);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(test_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);
	
	MU_RUN_TEST(test_memset_setting_NUL_in_one_mem_position);
	MU_RUN_TEST(test_memset_setting_NUL_in_two_mem_positions);
	MU_RUN_TEST(test_memset_setting_NUL_in_two_mem_positions_should_return_the_original_pointer);
	MU_RUN_TEST(test_isalpha_receiving_A_returns_true);
	MU_RUN_TEST(test_isalpha_receiving_char_1_returns_false);
	MU_RUN_TEST(test_isalpha_receiving_asterisc_returns_false);
	MU_RUN_TEST(test_isalpha_receiving_minus_65_returns_false);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}

