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

MU_TEST(test_memset_setting_1_in_two_mem_positions){
	//ARRANGE
	void*	memory_position = malloc(sizeof(char) * 2);
	// setting a random value (42) to "dirty" it before the test
	memset(memory_position, 42, 2);
	int	value_to_set = 1;
	
	//ACT
	ft_memset(memory_position, value_to_set, 2);
	
	//ASSERT
	mu_assert(*(unsigned char *)memory_position == value_to_set, "the first memory position value should be set to 1");
	mu_assert(*(unsigned char *)(memory_position + 1) == value_to_set, "the second memory position value should be set to 1");
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
	int c = 200;
	int expected_result = 200;
	int actual_result;

	// ACT
	actual_result = ft_toupper(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_bzero_passing_just_one_byte_should_set_it_to_null)
{
	// ARRANGE
	char c = 'x';
	char *s = &c;
	size_t n = 1;
	int expected_result = '\0'; // NULL

	// ACT
	ft_bzero(s, n);
	
	// ASSERT
	mu_assert_int_eq(expected_result, c);
}


MU_TEST(test_bzero_passing_just_two_bytes_and_size_two_should_set_them_to_null)
{
	// ARRANGE
	char c[2] = {'a', 'b'};
	char *s = &c[0];
	size_t n = 2;
	int expected_result = '\0'; // NULL

	// ACT
	ft_bzero(s, n);
	
	// ASSERT
	mu_assert_int_eq(expected_result, c[0]);
	mu_assert_int_eq(expected_result, c[1]);
}

MU_TEST(test_bzero_passing_just_two_bytes_and_size_zero_should_change_nothing)
{
	// ARRANGE
	char c[2] = {'a', 'b'};
	char *s = &c[0];
	size_t n = 0;
	int expected_result_a = 'a';
	int expected_result_b = 'b';

	// ACT
	ft_bzero(s, n);
	
	// ASSERT
	mu_assert_int_eq(expected_result_a, c[0]);
	mu_assert_int_eq(expected_result_b, c[1]);
}

MU_TEST(test_atoi_convert_1_char_to_1_integer)
{
	// ARRANGE
	char *c = "1";
	int expected_result = 1;
	char actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_convert_2_char_to_2_integer)
{
	// ARRANGE
	char *c = "2";
	int expected_result = 2;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_convert_42_char_to_42_integer)
{
	// ARRANGE
	char *c = "42";
	int expected_result = 42;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_convert_1042_char_to_1042_integer)
{
	// ARRANGE
	char *c = "1042";
	int expected_result = 1042;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_convert_minus_1_char_to_minus_1_integer)
{
	// ARRANGE
	char *c = "-1";
	int expected_result = -1;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_convert_minus_1042_char_to_minus_1042_integer)
{
	// ARRANGE
	char *c = "-1042";
	int expected_result = -1042;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_convert_minus_1042_with_space_char_to_minus_1042_integer)
{
	// ARRANGE
	char *c = "   -1042";
	int expected_result = -1042;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_entering_minus_minus_1042_char_returns_0_integer)
{
	// ARRANGE
	char *c = "--1042";
	int expected_result = 0;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_entering_1042e2_char_returns_1042_integer)
{
	// ARRANGE
	char *c = "1042e2";
	int expected_result = 1042;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_entering_MAX_INT_char_returns_2147483647_integer)
{
	// ARRANGE
	char *c = "2147483647";
	int expected_result = 2147483647;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_entering_MAX_INT_plus_one_char_returns_minus_2147483648_integer)
{
	// ARRANGE
	char *c = "2147483648";
	int expected_result = -2147483648;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_entering_MIN_INT_char_returns_minus_2147483648_integer)
{
	// ARRANGE
	char *c = "-2147483648";
	int expected_result = -2147483648;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_entering_MIN_INT_minus_one_char_returns_positive_2147483647_integer)
{
	// ARRANGE
	char *c = "-2147483649";
	int expected_result = 2147483647;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_entering_0_char_returns_0_integer)
{
	// ARRANGE
	char *c = "0";
	int expected_result = 0;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_entering_plus_42_char_returns_42_integer)
{
	// ARRANGE
	char *c = "+42";
	int expected_result = 42;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_atoi_entering_plus_plus_42_char_returns_0_integer)
{
	// ARRANGE
	char *c = "++42";
	int expected_result = 0;
	int actual_result;

	// ACT
	actual_result = ft_atoi(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_itoa_entering_1_integer_returns_1_string)
{
	// ARRANGE
	int n = 1;
	char *expected_result = "1";
	char *actual_result;

	// ACT
	actual_result = ft_itoa(n);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST(test_itoa_entering_2_integer_returns_2_string)
{
	// ARRANGE
	int n = 2;
	char *expected_result = "2";
	char *actual_result;

	// ACT
	actual_result = ft_itoa(n);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST(test_itoa_entering_42_integer_returns_42_string)
{
	// ARRANGE
	int n = 42;
	char *expected_result = "42";
	char *actual_result;

	// ACT
	actual_result = ft_itoa(n);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST(test_itoa_entering_minus_42_integer_returns_minus_42_string)
{
	// ARRANGE
	int n = -42;
	char *expected_result = "-42";
	char *actual_result;

	// ACT
	actual_result = ft_itoa(n);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST(test_itoa_entering_0_integer_returns_minus_0_string)
{
	// ARRANGE
	int n = 0;
	char *expected_result = "0";
	char *actual_result;

	// ACT
	actual_result = ft_itoa(n);

	// ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST(test_isascii_entering_a_returns_true)
{
	// ARRANGE
	int c = 'a';
	int	expected_result = 1; //true
	int	actual_result;

	// ACT
	actual_result = ft_isascii(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_isascii_entering_128_returns_false)
{
	// ARRANGE
	int c = 128;
	int	expected_result = 0; //false
	int	actual_result;

	// ACT
	actual_result = ft_isascii(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_isascii_entering_0_returns_true)
{
	// ARRANGE
	int c = 0;
	int	expected_result = 1; //true
	int	actual_result;

	// ACT
	actual_result = ft_isascii(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_isascii_entering_129_returns_false)
{
	// ARRANGE
	int c = 129;
	int	expected_result = 0; //false
	int	actual_result;

	// ACT
	actual_result = ft_isascii(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_isascii_entering_127_returns_true)
{
	// ARRANGE
	int c = 127;
	int	expected_result = 1; //true
	int	actual_result;

	// ACT
	actual_result = ft_isascii(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_isprint_entering_a_returns_true)
{
	// ARRANGE
	int c = 'a';
	int	expected_result = 16384; //true
	int	actual_result;

	// ACT
	actual_result = ft_isprint(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_isprint_entering_space_returns_true)
{
	// ARRANGE
	int c = ' ';
	int	expected_result = 16384; //true
	int	actual_result;

	// ACT
	actual_result = ft_isprint(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_isprint_entering_del_returns_false)
{
	// ARRANGE
	int c = 127;
	int	expected_result = 0; //false
	int	actual_result;

	// ACT
	actual_result = ft_isprint(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_isprint_entering_tab_returns_false)
{
	// ARRANGE
	int c = '\t';
	int	expected_result = 0; //false
	int	actual_result;

	// ACT
	actual_result = ft_isprint(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_isprint_entering_0_returns_false)
{
	// ARRANGE
	int c = 0;
	int	expected_result = 0; //false
	int	actual_result;

	// ACT
	actual_result = ft_isprint(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_isprint_entering_126_returns_true)
{
	// ARRANGE
	int c = 126;
	int	expected_result = 16384; //false
	int	actual_result;

	// ACT
	actual_result = ft_isprint(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_strlen_entering_abc_returns_3)
{
	// ARRANGE
	char	*s = "abc";
	int	expected_result = 3;
	int	actual_result;

	// ACT
	actual_result = ft_strlen(s);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_strlen_entering_a_returns_1)
{
	// ARRANGE
	char	*s = "a";
	int	expected_result = 1;
	int	actual_result;

	// ACT
	actual_result = ft_strlen(s);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_strlen_entering_empty_string_returns_0)
{
	// ARRANGE
	char	*s = "";
	int	expected_result = 0;
	int	actual_result;

	// ACT
	actual_result = ft_strlen(s);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_tolower_entry_X_returns_x)
{
	// ARRANGE
	char c = 'X';
	char expected_result = 'x';
	char actual_result;

	// ACT
	actual_result = ft_tolower(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_tolower_entry_A_returns_a)
{
	// ARRANGE
	char c = 'A';
	char expected_result = 'a';
	char actual_result;

	// ACT
	actual_result = ft_tolower(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_tolower_entry_a_returns_a)
{
	// ARRANGE
	char c = 'a';
	char expected_result = 'a';
	char actual_result;

	// ACT
	actual_result = ft_tolower(c);

	// ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_tolower_entry_asterisc_returns_asterisc)
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

MU_TEST(test_tolower_entry_200_returns_200)
{
	// ARRANGE
	int c = 200;
	int expected_result = 200;
	int actual_result;

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
	MU_RUN_TEST(test_memset_setting_1_in_two_mem_positions);
	
	MU_RUN_TEST(test_toupper_entry_x_returns_X);
	MU_RUN_TEST(test_toupper_entry_a_returns_A);
	MU_RUN_TEST(test_toupper_entry_A_returns_A);
	MU_RUN_TEST(test_toupper_entry_asterisc_returns_asterisc);
	MU_RUN_TEST(test_toupper_entry_200_returns_200);

	MU_RUN_TEST(test_bzero_passing_just_one_byte_should_set_it_to_null);
	MU_RUN_TEST(test_bzero_passing_just_two_bytes_and_size_two_should_set_them_to_null);
	MU_RUN_TEST(test_bzero_passing_just_two_bytes_and_size_zero_should_change_nothing);

	MU_RUN_TEST(test_atoi_convert_1_char_to_1_integer);
	MU_RUN_TEST(test_atoi_convert_2_char_to_2_integer);
	MU_RUN_TEST(test_atoi_convert_42_char_to_42_integer);
	MU_RUN_TEST(test_atoi_convert_1042_char_to_1042_integer);
	MU_RUN_TEST(test_atoi_convert_minus_1_char_to_minus_1_integer);
	MU_RUN_TEST(test_atoi_convert_minus_1042_char_to_minus_1042_integer);
	MU_RUN_TEST(test_atoi_convert_minus_1042_with_space_char_to_minus_1042_integer);
	MU_RUN_TEST(test_atoi_entering_minus_minus_1042_char_returns_0_integer);
	MU_RUN_TEST(test_atoi_entering_1042e2_char_returns_1042_integer);
	MU_RUN_TEST(test_atoi_entering_MAX_INT_plus_one_char_returns_minus_2147483648_integer);
	MU_RUN_TEST(test_atoi_entering_MAX_INT_char_returns_2147483647_integer);
	MU_RUN_TEST(test_atoi_entering_MIN_INT_char_returns_minus_2147483648_integer);
	MU_RUN_TEST(test_atoi_entering_MIN_INT_minus_one_char_returns_positive_2147483647_integer);
	MU_RUN_TEST(test_atoi_entering_0_char_returns_0_integer);
	MU_RUN_TEST(test_atoi_entering_plus_42_char_returns_42_integer);
	MU_RUN_TEST(test_atoi_entering_plus_plus_42_char_returns_0_integer);

	MU_RUN_TEST(test_itoa_entering_1_integer_returns_1_string);
	MU_RUN_TEST(test_itoa_entering_2_integer_returns_2_string);
	MU_RUN_TEST(test_itoa_entering_42_integer_returns_42_string);
	MU_RUN_TEST(test_itoa_entering_minus_42_integer_returns_minus_42_string);
	MU_RUN_TEST(test_itoa_entering_0_integer_returns_minus_0_string);

	MU_RUN_TEST(test_isascii_entering_a_returns_true);
	MU_RUN_TEST(test_isascii_entering_128_returns_false);
	MU_RUN_TEST(test_isascii_entering_0_returns_true);
	MU_RUN_TEST(test_isascii_entering_129_returns_false);
	MU_RUN_TEST(test_isascii_entering_127_returns_true);

	MU_RUN_TEST(test_isprint_entering_a_returns_true);
	MU_RUN_TEST(test_isprint_entering_space_returns_true);
	MU_RUN_TEST(test_isprint_entering_del_returns_false);
	MU_RUN_TEST(test_isprint_entering_tab_returns_false);
	MU_RUN_TEST(test_isprint_entering_0_returns_false);
	MU_RUN_TEST(test_isprint_entering_126_returns_true);

	MU_RUN_TEST(test_strlen_entering_abc_returns_3);
	MU_RUN_TEST(test_strlen_entering_a_returns_1);
	MU_RUN_TEST(test_strlen_entering_empty_string_returns_0);

	MU_RUN_TEST(test_tolower_entry_X_returns_x);
	MU_RUN_TEST(test_tolower_entry_A_returns_a);
	MU_RUN_TEST(test_tolower_entry_a_returns_a);
	MU_RUN_TEST(test_tolower_entry_asterisc_returns_asterisc);
	MU_RUN_TEST(test_tolower_entry_200_returns_200);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}

