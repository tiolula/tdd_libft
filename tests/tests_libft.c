#include <stdlib.h>
#include "minunit.h"
#include "libft.h"

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
	free(memory_position);
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
	free(memory_position);
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
	free(memory_position);
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

MU_TEST_SUITE(test_isdigit_receiving_1_returns_true)
{
	//ARRANGE
	int		input = '1';
	int		expected_result = 2048;// true
	int		actual_result;

	//ACT
	actual_result = ft_isdigit(input);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(test_isdigit_receiving_a_returns_false)
{
	//ARRANGE
	int		input = 'a';
	int		expected_result = 0;// false
	int		actual_result;

	//ACT
	actual_result = ft_isdigit(input);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(test_isalnum_receiving_a_returns_true)
{
	//ARRANGE
	int		input = 'a';
	int		expected_result = 8;// true
	int		actual_result;

	//ACT
	actual_result = ft_isalnum(input);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(test_isalnum_receiving_asterisc_returns_false)
{
	//ARRANGE
	int		input = '*';
	int		expected_result = 0; // false
	int		actual_result;

	//ACT
	actual_result = ft_isalnum(input);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(test_isalnum_receiving_1_returns_true)
{
	//ARRANGE
	int		input = '1';
	int		expected_result = 8; // true
	int		actual_result;

	//ACT
	actual_result = ft_isalnum(input);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(test_strlcpy_entering_ai_oi_2_set_dst_as_o_and_returns_2)
{
	//ARRANGE
	char	dst[] = "ai";
	char	src[] = "oi";
	int		size = 2;
	int		expected_result = 2;
	char	expected_dst[] = "o";
	int		actual_result;

	//ACT
	actual_result = ft_strlcpy(dst, src, size);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
	mu_assert_string_eq(expected_dst, dst);
}

MU_TEST_SUITE(test_strlcpy_entering_ah_oi_3_set_dst_as_oi_and_returns_2)
{
	//ARRANGE
	char	dst[] = "ah";
	char	src[] = "oi";
	int		size = 3;
	int		expected_result = 2;
	char	expected_dst[] = "oi";
	int		actual_result;

	//ACT
	actual_result = ft_strlcpy(dst, src, size);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
	mu_assert_string_eq(expected_dst, dst);
}

MU_TEST_SUITE(test_strlcpy_entering_ah_boi_3_set_dst_as_bo_and_returns_3)
{
	//ARRANGE
	char	dst[] = "ah";
	char	src[] = "boi";
	int		size = 3;
	int		expected_result = 3;
	char	expected_dst[] = "bo";
	int		actual_result;

	//ACT
	actual_result = ft_strlcpy(dst, src, size);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
	mu_assert_string_eq(expected_dst, dst);
}

MU_TEST_SUITE(test_strlcpy_entering_papelada_boiada_9_keep_dst7_as_a)
{
	//ARRANGE
	char	dst[] = "papelada";
	char	src[] = "boiada";
	int		size = 9;

	//ACT
	ft_strlcpy(dst, src, size);

	//ASSERT
	mu_assert_int_eq('a', dst[7]);
}

MU_TEST_SUITE(test_strlcpy_entering_lu_la_minus_1_set_dst_as_la_and_returns_2)
{
	//ARRANGE
	char	dst[] = "lu";
	char	src[] = "la";
	int		size = -1;
	int		expected_result = 2;
	char	expected_dst[] = "la";
	int		actual_result;

	//ACT
	actual_result = ft_strlcpy(dst, src, size);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
	mu_assert_string_eq(expected_dst, dst);
}

MU_TEST_SUITE(test_strlcpy_entering_mochida_rapdos_0_do_not_modify_dst_and_returns_6)
{
	//ARRANGE
	char	dst[] = "mochida";
	char	src[] = "rapdos";
	int		size = 0;
	int		expected_result = 6;
	char	expected_dst[] = "mochida";
	int		actual_result;

	//ACT
	actual_result = ft_strlcpy(dst, src, size);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
	mu_assert_string_eq(expected_dst, dst);
}

MU_TEST(test_toupper_entry_x_returns_X)
{
	// ARRANGE
	char c = 'x';
	char expected_result = 'X';
	char actual_result;

	// ACT
	actual_result = ft_toupper(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_toupper_entry_a_returns_A)
{
	// ARRANGE
	char c = 'a';
	char expected_result = 'A';
	char actual_result;

	// ACT
	actual_result = ft_toupper(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_toupper_entry_A_returns_A)
{
	// ARRANGE
	char c = 'A';
	char expected_result = 'A';
	char actual_result;

	// ACT
	actual_result = ft_toupper(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_toupper_entry_asterisc_returns_asterisc)
{
	// ARRANGE
	char c = '*';
	char expected_result = '*';
	char actual_result;

	// ACT
	actual_result = ft_toupper(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_toupper_entry_200_returns_200)
{
	// ARRANGE
	char c = 200;
	char expected_result = 200;
	char actual_result;

	// ACT
	actual_result = ft_toupper(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(test_suite) {
	MU_RUN_TEST(test_isalpha_receiving_A_returns_true);
	MU_RUN_TEST(test_isalpha_receiving_char_1_returns_false);
	MU_RUN_TEST(test_isalpha_receiving_asterisc_returns_false);
	MU_RUN_TEST(test_isalpha_receiving_minus_65_returns_false);

	MU_RUN_TEST(test_isdigit_receiving_1_returns_true);
	MU_RUN_TEST(test_isdigit_receiving_a_returns_false);

	MU_RUN_TEST(test_isalnum_receiving_a_returns_true);
	MU_RUN_TEST(test_isalnum_receiving_asterisc_returns_false);
	MU_RUN_TEST(test_isalnum_receiving_1_returns_true);

	MU_RUN_TEST(test_strlcpy_entering_mochida_rapdos_0_do_not_modify_dst_and_returns_6);
	MU_RUN_TEST(test_strlcpy_entering_lu_la_minus_1_set_dst_as_la_and_returns_2);
	MU_RUN_TEST(test_strlcpy_entering_papelada_boiada_9_keep_dst7_as_a);
	MU_RUN_TEST(test_strlcpy_entering_ah_boi_3_set_dst_as_bo_and_returns_3);
	MU_RUN_TEST(test_strlcpy_entering_ah_oi_3_set_dst_as_oi_and_returns_2);
	MU_RUN_TEST(test_strlcpy_entering_ai_oi_2_set_dst_as_o_and_returns_2);

	MU_RUN_TEST(test_memset_setting_NUL_in_one_mem_position);
	MU_RUN_TEST(test_memset_setting_NUL_in_two_mem_positions);
	MU_RUN_TEST(test_memset_setting_NUL_in_two_mem_positions_should_return_the_original_pointer);
	
	MU_RUN_TEST(test_toupper_entry_x_returns_X);
	MU_RUN_TEST(test_toupper_entry_a_returns_A);
	MU_RUN_TEST(test_toupper_entry_A_returns_A);
	MU_RUN_TEST(test_toupper_entry_asterisc_returns_asterisc);
	MU_RUN_TEST(test_toupper_entry_200_returns_200);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}

