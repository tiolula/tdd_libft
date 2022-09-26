#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
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

MU_TEST(test_memcpy_simple_dst_and_src_copying_5_positions)
{
	// ARRANGE
	char	dest[] = "watermelonjuice";
	char	src[] = "apple";
	char	size = 5;
	char	expected_dest[] = "applemelonjuice";
	char	*expected_memory_position = dest;
	char	*returned_memory_position;
	
	// ACT
	returned_memory_position = ft_memcpy(dest, src, size);

	// ASSERT
	mu_assert_string_eq(expected_dest, dest);
	mu_assert(expected_memory_position == returned_memory_position, "memory position should be &dest");
}

MU_TEST(test_memmove_simple_dst_and_src_copyiing_5_positions)
{
	// ARRANGE
	char	word[] = "watermelonjuice";
	char	*dest = &word[10]; //juice
	char	*src = &word[0]; //watermelonjuice
	size_t 	size = 5;
	char	expected_word_result[] = "watermelonwater";
	char	*expected_memory_position = dest;
	char	*returned_memory_position;
	
	// ACT
	returned_memory_position = ft_memmove(dest, src, size);

	// ASSERT
	mu_assert_string_eq(expected_word_result, word);
	mu_assert(expected_memory_position == returned_memory_position, "memory position should be &dest");
}

MU_TEST(test_memmove_dest_overlaping_src)
{
	// ARRANGE
	char	word[] = "watermelonjuice";
	char	*dest = &word[5]; //melonjuice
	char	*src = &word[0]; //watermelonjuice
	char	expected_word_result[] = "waterwatermelon";
	char	*expected_memory_position = dest;
	char	*returned_memory_position;
	
	// ACT
	returned_memory_position = ft_memmove(dest, src, 10);

	// ASSERT
	mu_assert_string_eq(expected_word_result, word);
	mu_assert(expected_memory_position == returned_memory_position, "memory position should be &dest");
}

MU_TEST(test_memmove_src_overlaping_dest)
{
	// ARRANGE
	char	word[] = "watermelonjuice";
	char	*dest = &word[0]; //watermelonjuice
	char	*src = &word[5]; //melonjuice
	char	expected_word_result[] = "melonjuicejuice";
	char	*expected_memory_position = dest;
	char	*returned_memory_position;
	
	// ACT
	returned_memory_position = ft_memmove(dest, src, 10);

	// ASSERT
	mu_assert_string_eq(expected_word_result, word);
	mu_assert(expected_memory_position == returned_memory_position, "memory position should be &dest");
}

MU_TEST_SUITE(test_strchr_look_up_non_existing_character_in_string_should_return_NULL)
{
	//ARRANGE
	const char	string[] = "banana";
	int			character = 'z';
	char		*expected_result = NULL;
	char		*actual_result;

	//ACT
	actual_result = ft_strchr(string, character);

	//ASSERT
	mu_check(expected_result == actual_result);
}

MU_TEST_SUITE(test_strchr_look_up_existing_character_in_string_should_return_its_address)
{
	//ARRANGE
	char	string[] = "banana";
	int			character = 'n';
	char		*expected_result = &string[2]; //first 'n' address
	char		*actual_result;

	//ACT
	actual_result = ft_strchr(string, character);

	//ASSERT
	mu_assert(expected_result == actual_result, "expected_result content is different from actual_result");
}

MU_TEST_SUITE(test_strchr_look_up_null_character_in_string_should_return_the_terminating_zero_address)
{
	//ARRANGE
	char	string[] = "banana";
	int			character = '\0';
	char		*expected_result = &string[6]; // address of terminating '\0'
	char		*actual_result;

	//ACT
	actual_result = ft_strchr(string, character);

	//ASSERT
	mu_assert(expected_result == actual_result, "expected_result should point to the terminating '\\0'");
}

MU_TEST_SUITE(test_strchr_look_up_character_in_empty_string_should_return_null)
{
	//ARRANGE
	char		string[] = "";
	int			character = 'c';
	char		*expected_result = NULL;
	char		*actual_result;

	//ACT
	actual_result = ft_strchr(string, character);

	//ASSERT
	mu_assert(expected_result == actual_result, "expected_result should be NULL");
}

MU_TEST_SUITE(test_strchr_look_up_character_in_null_string_should_return_null)
{
	//ARRANGE
	char		string[] = "";
	int			character = 'c';
	char		*expected_result = NULL;
	char		*actual_result;

	//ACT
	actual_result = ft_strchr(string, character);

	//ASSERT
	mu_assert(expected_result == actual_result, "expected_result should be NULL");
}

MU_TEST_SUITE(test_strnstr_to_find_ora_em_amora_should_return_a_pointer_to_ora_in_amora)
{
	//ARRANGE
	char		big[] = "amora";
	char		little[] = "ora";
	size_t		len = 3;
	char		*expected_result = &big[2];
	char		*actual_result;

	//ACT
	actual_result = ft_strnstr(big, little, len);

	//ASSERT
	mu_assert(expected_result == actual_result, "expected_result should point to address of the char o of amora");
}

MU_TEST_SUITE(test_strnstr_to_find_aro_em_amora_should_return_NULL)
{
	//ARRANGE
	char		big[] = "amora";
	char		little[] = "aro";
	size_t		len = 3;
	char		*expected_result = NULL;
	char		*actual_result;

	//ACT
	actual_result = ft_strnstr(big, little, len);

	//ASSERT
	mu_assert(expected_result == actual_result, "expected_result should be NULL");
}

MU_TEST_SUITE(test_strnstr_if_little_is_empty_string_return_big)
{
	//ARRANGE
	char		big[] = "amora";
	char		little[] = "";
	size_t		len = 3;
	char		*expected_result = big;
	char		*actual_result;

	//ACT
	actual_result = ft_strnstr(big, little, len);

	//ASSERT
	mu_assert(expected_result == actual_result, "expected_result should be point to amora first position");
}

MU_TEST_SUITE(test_strnstr_finding_orabolas_in_amora_but_len_3_should_return_pointer_to_ora_in_amora)
{
	//ARRANGE
	char		big[] = "amora";
	char		little[] = "orabolas";
	size_t		len = 3;
	char		*expected_result = &big[2];
	char		*actual_result;

	//ACT
	actual_result = ft_strnstr(big, little, len);

	//ASSERT
	mu_assert(expected_result == actual_result, "expected_result should point to ora position in amora");
}

MU_TEST_SUITE(test_strnstr_finding_ora_in_amora_but_len_0_should_return_NULL)
{
	//ARRANGE
	char		big[] = "amora";
	char		little[] = "ora";
	size_t		len = 0;
	char		*expected_result = NULL;
	char		*actual_result;

	//ACT
	actual_result = ft_strnstr(big, little, len);

	//ASSERT
	mu_assert(expected_result == actual_result, "expected_result should be NULL");
}

MU_TEST_SUITE(test_strnstr_finding_ora_in_amora_but_len_50_should_return_pointer_to_ora_in_amora)
{
	//ARRANGE
	char		big[] = "amora";
	char		little[] = "ora";
	size_t		len = 50;
	char		*expected_result = &big[2];
	char		*actual_result;

	//ACT
	actual_result = ft_strnstr(big, little, len);

	//ASSERT
	mu_assert(expected_result == actual_result, "expected_result should point to ora position in amora");
}

MU_TEST_SUITE(test_strnstr_finding_orabolas_in_amora_but_len_50_should_return_NULL)
{
	//ARRANGE
	char		big[] = "amora";
	char		little[] = "orabolas";
	size_t		len = 50;
	char		*expected_result = NULL;
	char		*actual_result;

	//ACT
	actual_result = ft_strnstr(big, little, len);

	//ASSERT
	mu_assert(expected_result == actual_result, "expected_result should be NULL");
}

MU_TEST_SUITE(test_strrchr_look_up_non_existing_character_in_string_should_return_NULL)
{
	//ARRANGE
	const char	string[] = "banana";
	int			character = 'z';
	char		*expected_result = NULL;
	char		*actual_result;

	//ACT
	actual_result = ft_strrchr(string, character);

	//ASSERT
	mu_check(expected_result == actual_result);
}

MU_TEST_SUITE(test_strrchr_look_up_existing_character_in_string_should_return_its_address)
{
	//ARRANGE
	char		string[] = "banana";
	int			character = 'n';
	char		*expected_result = &string[4]; //last 'n' address
	char		*actual_result;

	//ACT
	actual_result = ft_strrchr(string, character);

	//ASSERT
	mu_assert(expected_result == actual_result, "expected_result content is different from actual_result");
}

MU_TEST_SUITE(test_strrchr_look_up_null_character_in_string_should_return_the_terminating_zero_address)
{
	//ARRANGE
	char		string[] = "banana";
	int			character = '\0';
	char		*expected_result = &string[6]; // address of terminating '\0'
	char		*actual_result;

	//ACT
	actual_result = ft_strrchr(string, character);

	//ASSERT
	mu_assert(expected_result == actual_result, "expected_result should point to the terminating '\\0'");
}

MU_TEST_SUITE(test_strrchr_look_up_character_in_empty_string_should_return_null)
{
	//ARRANGE
	char		string[] = "";
	int			character = 'c';
	char		*expected_result = NULL;
	char		*actual_result;

	//ACT
	actual_result = ft_strrchr(string, character);

	//ASSERT
	mu_assert(expected_result == actual_result, "expected_result should be NULL");
}

MU_TEST_SUITE(test_strrchr_look_up_character_in_null_string_should_return_null)
{
	//ARRANGE
	char		string[] = "";
	int			character = 'c';
	char		*expected_result = NULL;
	char		*actual_result;

	//ACT
	actual_result = ft_strrchr(string, character);

	//ASSERT
	mu_assert(expected_result == actual_result, "expected_result should be NULL");
}

MU_TEST_SUITE(test_strncmp_comparing_banana_and_banana_size_6_should_return_zero)
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

MU_TEST_SUITE(test_strncmp_comparing_bananaA_and_bananaB_size_7_should_return_minus_one)
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

MU_TEST_SUITE(test_strncmp_comparing_bananaA_and_bananaB_size_6_should_return_zero)
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

MU_TEST_SUITE(test_strncmp_comparing_bananaA_and_bananaB_size_0_should_return_zero)
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

MU_TEST_SUITE(test_strncmp_comparing_banana_and_banana_with_a_large_size_should_return_zero)
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

MU_TEST_SUITE(test_strncmp_comparing_A_and_empty_string_string_size_1_should_return_sixty_five)
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

MU_TEST_SUITE(test_strncmp_comparing_B_and_A_size_1_should_return_one)
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

MU_TEST_SUITE(test_strlcat_concat_A_and_B_should_set_dst_as_AB)
{
	//ARRANGE
	char	dst[3] = "A\0";
	char	src[2] = "B";
	size_t	size = 3;
	
	char	expected_result[] = "AB";

	//ACT
	ft_strlcat(dst, src, size);

	//ASSERT
	mu_assert_string_eq(expected_result, dst);
}

MU_TEST_SUITE(test_strlcat_concat_A_and_B_should_return_2)
{
	//ARRANGE
	char	dst[3] = "A\0";
	char	src[2] = "B";
	size_t	size = 3;

	size_t	expected_result = 2;
	size_t	actual_result;

	//ACT
	actual_result = ft_strlcat(dst, src, size);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(test_strlcat_concat_AB_and_C_should_set_dst_as_ABC_and_return_3)
{
	//ARRANGE
	char	dst[4] = "AB\0";
	char	src[2] = "C";
	size_t	size = 4;

	char	expected_dst[] = "ABC";
	size_t	expected_result = 3;

	size_t	actual_result;

	//ACT
	actual_result = ft_strlcat(dst, src, size);

	//ASSERT
	mu_assert_string_eq(expected_dst, dst);
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(test_strlcat_concat_ABC_and_DEF_size_2_should_keep_dst_as_ABC_and_return_5)
{
	//ARRANGE
	char	dst[7] = "ABC\0";
	char	src[4] = "DEF";
	size_t	size = 2;

	char	expected_dst[] = "ABC";
	size_t	expected_result = 5;

	size_t	actual_result;

	//ACT
	actual_result = ft_strlcat(dst, src, size);

	//ASSERT
	mu_assert_string_eq(expected_dst, dst);
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(test_strlcat_concat_ABC_and_DE_size_1_should_keep_dst_as_ABC_and_return_3)
{
	//ARRANGE
	char	dst[6] = "ABC";
	char	src[3] = "DE";
	size_t	size = 1;
	
	char	expected_dst[] = "ABC";
	size_t	expected_result = 3;

	size_t	actual_result;

	//ACT
	actual_result = ft_strlcat(dst, src, size);

	//ASSERT
	mu_assert_string_eq(expected_dst, dst);
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(test_strlcat_concat_ABC_and_DE_size_10_should_set_dst_as_ABCDE_and_return_5)
{
	//ARRANGE
	char	dst[6] = "ABC";
	char	src[3] = "DE";
	size_t	size = 10;
	
	char	expected_dst[] = "ABCDE";
	size_t	expected_result = 5;

	size_t	actual_result;

	//ACT
	actual_result = ft_strlcat(dst, src, size);

	//ASSERT
	mu_assert_string_eq(expected_dst, dst);
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(test_strlcat_concat_AnullB_and_C_size_5_should_set_dst_as_AC_and_return_2)
{
	//ARRANGE
	char	dst[5] = "A\0B";
	char	src[2] = "C";
	size_t	size = 5;
	
	char	expected_dst[] = "AC";
	size_t	expected_result = 2;

	size_t	actual_result;

	//ACT
	actual_result = ft_strlcat(dst, src, size);

	//ASSERT
	mu_assert_string_eq(expected_dst, dst);
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(test_strlcat_concat_AnullB_and_C_size_15_should_set_dst_as_AC_and_return_2)
{
	//ARRANGE
	char	dst[15] = "A\0B";
	char	src[2] = "C";
	size_t	size = 15;
	
	char	expected_dst[] = "AC";
	size_t	expected_result = 2;

	size_t	actual_result;

	//ACT
	actual_result = ft_strlcat(dst, src, size);

	//ASSERT
	mu_assert_string_eq(expected_dst, dst);
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(test_strlcat_concat_AnullCD_and_B_size_15_should_set_dst_as_ABnullD_and_return_2)
{
	//ARRANGE
	char	dst[15] = "A\0CD";
	char	src[2] = "B";
	size_t	size = 15;
	
	char	expected_dst[] = "AB\0D";
	size_t	expected_result = 2;

	size_t	actual_result;

	//ACT
	actual_result = ft_strlcat(dst, src, size);

	//ASSERT
	mu_assert_char_eq(expected_dst[0], dst[0]);
	mu_assert_char_eq(expected_dst[1], dst[1]);
	mu_assert_char_eq(expected_dst[2], dst[2]);
	mu_assert_char_eq(expected_dst[3], dst[3]);
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(test_strlcat_concat_empty_dst_and_123456789_size_15_should_set_dst_as_123456789_and_return_9)
{
	//ARRANGE
	char	dst[15] = "";
	char	src[10] = "123456789";
	size_t	size = 15;
	
	char	expected_dst[] = "123456789";
	size_t	expected_result = 9;

	size_t	actual_result;

	//ACT
	actual_result = ft_strlcat(dst, src, size);

	//ASSERT
	mu_assert_string_eq(expected_dst, dst);
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(test_strlcat_concat_dst_123_and_empty_src_size_15_should_keep_dst_as_123_and_return_3)
{
	//ARRANGE
	char	dst[15] = "123";
	char	src[10] = "";
	size_t	size = 15;
	
	char	expected_dst[] = "123";
	size_t	expected_result = 3;

	size_t	actual_result;

	//ACT
	actual_result = ft_strlcat(dst, src, size);

	//ASSERT
	mu_assert_string_eq(expected_dst, dst);
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST_SUITE(test_putchar_fd_entering_A_in_empty_file)
{
	//ARRANGE
	char	c = 'A';
	int 	fd = open("test.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	size_t	read_count = 1;
	char	result_buffer;
	char	expected_result = c;

	//ACT
	ft_putchar_fd(c, fd);
	close(fd);

	//ASSERT
	fd = open("test.txt", O_RDONLY);
	read(fd, &result_buffer, read_count);
	close(fd);
	mu_assert_char_eq(expected_result, result_buffer);
	remove("test.txt");
}

MU_TEST_SUITE(test_putstr_fd_entering_AB_in_empty_file)
{
	//ARRANGE
	char	s[3] = "AB";
	int 	fd = open("test.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	size_t	read_count = 2;
	char	result_buffer[2];
	char	expected_first_char = 'A';
	char	expected_second_char = 'B';
	int		expected_read_size = 2;
	int		actual_read_size;

	//ACT
	ft_putstr_fd(s, fd);
	close(fd);

	//ASSERT
	fd = open("test.txt", O_RDONLY);
	actual_read_size = read(fd, result_buffer, read_count);
	close(fd);
	mu_assert_char_eq(expected_first_char, result_buffer[0]);
	mu_assert_char_eq(expected_second_char, result_buffer[1]);
	mu_assert_int_eq(expected_read_size, actual_read_size);
	remove("test.txt");
}

MU_TEST_SUITE(test_putend1_fd_entering_AB_in_empty_file)
{
	//ARRANGE
	char	s[3] = "AB";
	int 	fd = open("test.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	size_t	read_count = 3;
	char	result_buffer[3];
	char	expected_first_char = 'A';
	char	expected_second_char = 'B';
	char	expected_third_char = '\n';
	int		expected_read_size = 3;
	int		actual_read_size;

	//ACT
	ft_putend1_fd(s, fd);
	close(fd);

	//ASSERT
	fd = open("test.txt", O_RDONLY);
	actual_read_size = read(fd, result_buffer, read_count);
	close(fd);
	mu_assert_char_eq(expected_first_char, result_buffer[0]);
	mu_assert_char_eq(expected_second_char, result_buffer[1]);
	mu_assert_char_eq(expected_third_char, result_buffer[2]);
	mu_assert_int_eq(expected_read_size, actual_read_size);
	remove("test.txt");
}

MU_TEST_SUITE(test_putnbr_fd_entering_42_in_empty_file)
{
	//ARRANGE
	int		n = 42;
	int 	fd = open("test.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	size_t	read_count = 2;
	char	result_buffer[2];
	char	expected_first_char = '4';
	char	expected_second_char = '2';
	int		expected_read_size = 2;
	int		actual_read_size;

	//ACT
	ft_putnbr_fd(n, fd);
	close(fd);

	//ASSERT
	fd = open("test.txt", O_RDONLY);
	actual_read_size = read(fd, result_buffer, read_count);
	close(fd);
	mu_assert_char_eq(expected_first_char, result_buffer[0]);
	mu_assert_char_eq(expected_second_char, result_buffer[1]);
	mu_assert_int_eq(expected_read_size, actual_read_size);
	remove("test.txt");
}

MU_TEST_SUITE(test_putnbr_fd_entering_minus42_in_empty_file)
{
	//ARRANGE
	int		n = -42;
	int 	fd = open("test.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	size_t	read_count = 3;
	char	result_buffer[3];
	char	expected_first_char = '-';
	char	expected_second_char = '4';
	char	expected_third_char = '2';
	int		expected_read_size = 3;
	int		actual_read_size;

	//ACT
	ft_putnbr_fd(n, fd);
	close(fd);

	//ASSERT
	fd = open("test.txt", O_RDONLY);
	actual_read_size = read(fd, result_buffer, read_count);
	close(fd);
	mu_assert_char_eq(expected_first_char, result_buffer[0]);
	mu_assert_char_eq(expected_second_char, result_buffer[1]);
	mu_assert_char_eq(expected_third_char, result_buffer[2]);
	mu_assert_int_eq(expected_read_size, actual_read_size);
	remove("test.txt");
}

MU_TEST_SUITE(test_putnbr_fd_entering_MAX_INT_in_empty_file)
{
	//ARRANGE
	int		n = 2147483647;
	int 	fd = open("test.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	size_t	read_count = 10;
	char	result_buffer[11];
	char	expected_result_buffer[11] = "2147483647";
	int		expected_read_size = 10;
	int		actual_read_size;

	//ACT
	ft_putnbr_fd(n, fd);
	close(fd);

	//ASSERT
	fd = open("test.txt", O_RDONLY);
	actual_read_size = read(fd, result_buffer, read_count);
	result_buffer[10] = '\0'; //to use assert string
	close(fd);
	mu_assert_string_eq(expected_result_buffer, result_buffer);
	mu_assert_int_eq(expected_read_size, actual_read_size);
	remove("test.txt");
}

MU_TEST_SUITE(test_putnbr_fd_entering_MIN_INT_in_empty_file)
{
	//ARRANGE
	int		n = -2147483648;
	int 	fd = open("test.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	size_t	read_count = 11;
	char	result_buffer[12];
	char	expected_result_buffer[12] = "-2147483648";
	int		expected_read_size = 11;
	int		actual_read_size;

	//ACT
	ft_putnbr_fd(n, fd);
	close(fd);

	//ASSERT
	fd = open("test.txt", O_RDONLY);
	actual_read_size = read(fd, result_buffer, read_count);
	result_buffer[11] = '\0'; //to use assert string
	close(fd);
	mu_assert_string_eq(expected_result_buffer, result_buffer);
	mu_assert_int_eq(expected_read_size, actual_read_size);
	remove("test.txt");
}

MU_TEST_SUITE(test_putnbr_fd_entering_0_in_empty_file)
{
	//ARRANGE
	int		n = 0;
	int 	fd = open("test.txt", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
	size_t	read_count = 1;
	char	result_buffer;
	char	expected_first_char = '0';
	int		expected_read_size = 1;
	int		actual_read_size;

	//ACT
	ft_putnbr_fd(n, fd);
	close(fd);

	//ASSERT
	fd = open("test.txt", O_RDONLY);
	actual_read_size = read(fd, &result_buffer, read_count);
	close(fd);
	mu_assert_char_eq(expected_first_char, result_buffer);
	mu_assert_int_eq(expected_read_size, actual_read_size);
	remove("test.txt");
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

	MU_RUN_TEST(test_memcpy_simple_dst_and_src_copying_5_positions);
	MU_RUN_TEST(test_memmove_simple_dst_and_src_copyiing_5_positions);
	MU_RUN_TEST(test_memmove_dest_overlaping_src);
	MU_RUN_TEST(test_memmove_src_overlaping_dest);

	MU_RUN_TEST(test_strchr_look_up_non_existing_character_in_string_should_return_NULL);
	MU_RUN_TEST(test_strchr_look_up_existing_character_in_string_should_return_its_address);
	MU_RUN_TEST(test_strchr_look_up_null_character_in_string_should_return_the_terminating_zero_address);
	MU_RUN_TEST(test_strchr_look_up_character_in_empty_string_should_return_null);
	MU_RUN_TEST(test_strchr_look_up_character_in_null_string_should_return_null);

	MU_RUN_TEST(test_strnstr_to_find_ora_em_amora_should_return_a_pointer_to_ora_in_amora);
	MU_RUN_TEST(test_strnstr_to_find_aro_em_amora_should_return_NULL);
	MU_RUN_TEST(test_strnstr_if_little_is_empty_string_return_big);
	MU_RUN_TEST(test_strnstr_finding_orabolas_in_amora_but_len_3_should_return_pointer_to_ora_in_amora);
	MU_RUN_TEST(test_strnstr_finding_ora_in_amora_but_len_0_should_return_NULL);
	MU_RUN_TEST(test_strnstr_finding_ora_in_amora_but_len_50_should_return_pointer_to_ora_in_amora);
	MU_RUN_TEST(test_strnstr_finding_orabolas_in_amora_but_len_50_should_return_NULL);

	MU_RUN_TEST(test_strrchr_look_up_non_existing_character_in_string_should_return_NULL);
	MU_RUN_TEST(test_strrchr_look_up_existing_character_in_string_should_return_its_address);
	MU_RUN_TEST(test_strrchr_look_up_null_character_in_string_should_return_the_terminating_zero_address);
	MU_RUN_TEST(test_strrchr_look_up_character_in_empty_string_should_return_null);
	MU_RUN_TEST(test_strrchr_look_up_character_in_null_string_should_return_null);

	MU_RUN_TEST(test_strncmp_comparing_banana_and_banana_size_6_should_return_zero);
	MU_RUN_TEST(test_strncmp_comparing_bananaA_and_bananaB_size_7_should_return_minus_one);
	MU_RUN_TEST(test_strncmp_comparing_bananaA_and_bananaB_size_6_should_return_zero);
	MU_RUN_TEST(test_strncmp_comparing_bananaA_and_bananaB_size_0_should_return_zero);
	MU_RUN_TEST(test_strncmp_comparing_banana_and_banana_with_a_large_size_should_return_zero);
	MU_RUN_TEST(test_strncmp_comparing_A_and_empty_string_string_size_1_should_return_sixty_five);
	MU_RUN_TEST(test_strncmp_comparing_B_and_A_size_1_should_return_one);

	MU_RUN_TEST(test_strlcat_concat_A_and_B_should_set_dst_as_AB);
	MU_RUN_TEST(test_strlcat_concat_A_and_B_should_return_2);
	MU_RUN_TEST(test_strlcat_concat_AB_and_C_should_set_dst_as_ABC_and_return_3);
	MU_RUN_TEST(test_strlcat_concat_ABC_and_DEF_size_2_should_keep_dst_as_ABC_and_return_5);
	MU_RUN_TEST(test_strlcat_concat_ABC_and_DE_size_1_should_keep_dst_as_ABC_and_return_3);
	MU_RUN_TEST(test_strlcat_concat_ABC_and_DE_size_10_should_set_dst_as_ABCDE_and_return_5);
	MU_RUN_TEST(test_strlcat_concat_AnullB_and_C_size_5_should_set_dst_as_AC_and_return_2);
	MU_RUN_TEST(test_strlcat_concat_AnullB_and_C_size_15_should_set_dst_as_AC_and_return_2);
	MU_RUN_TEST(test_strlcat_concat_AnullCD_and_B_size_15_should_set_dst_as_ABnullD_and_return_2);
	MU_RUN_TEST(test_strlcat_concat_empty_dst_and_123456789_size_15_should_set_dst_as_123456789_and_return_9);
	MU_RUN_TEST(test_strlcat_concat_dst_123_and_empty_src_size_15_should_keep_dst_as_123_and_return_3);

	MU_RUN_TEST(test_putchar_fd_entering_A_in_empty_file);

	MU_RUN_TEST(test_putstr_fd_entering_AB_in_empty_file);

	MU_RUN_TEST(test_putend1_fd_entering_AB_in_empty_file);

	MU_RUN_TEST(test_putnbr_fd_entering_42_in_empty_file);
	MU_RUN_TEST(test_putnbr_fd_entering_minus42_in_empty_file);
	MU_RUN_TEST(test_putnbr_fd_entering_MAX_INT_in_empty_file);
	MU_RUN_TEST(test_putnbr_fd_entering_MIN_INT_in_empty_file);
	MU_RUN_TEST(test_putnbr_fd_entering_0_in_empty_file);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
