/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lphelipe <lphelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 12:56:31 by lphelipe          #+#    #+#             */
/*   Updated: 2022/10/29 19:53:01 by lphelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "minunit.h"
#include "libft.h"
#include "tests_ft_strtrim.c"
#include "tests_ft_memset.c"
#include "tests_ft_strlcpy.c"

MU_TEST(test_isalpha_receiving_A_returns_true)
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

MU_TEST(test_isalpha_receiving_char_1_returns_false)
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

MU_TEST(test_isalpha_receiving_asterisc_returns_false)
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

MU_TEST(test_isalpha_receiving_minus_65_returns_false)
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

MU_TEST(test_isdigit_receiving_1_returns_true)
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

MU_TEST(test_isdigit_receiving_a_returns_false)
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

MU_TEST(test_isalnum_receiving_a_returns_true)
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

MU_TEST(test_isalnum_receiving_asterisc_returns_false)
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

MU_TEST(test_isalnum_receiving_1_returns_true)
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

MU_TEST(test_strchr_look_up_non_existing_character_in_string_should_return_NULL)
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

MU_TEST(test_strchr_look_up_existing_character_in_string_should_return_its_address)
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

MU_TEST(test_strchr_look_up_null_character_in_string_should_return_the_terminating_zero_address)
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

MU_TEST(test_strchr_look_up_character_in_empty_string_should_return_null)
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

MU_TEST(test_strchr_look_up_character_in_null_string_should_return_null)
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

MU_TEST(test_strnstr_to_find_ora_em_amora_should_return_a_pointer_to_ora_in_amora)
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

MU_TEST(test_strnstr_to_find_aro_em_amora_should_return_NULL)
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

MU_TEST(test_strnstr_if_little_is_empty_string_return_big)
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

MU_TEST(test_strnstr_finding_orabolas_in_amora_but_len_3_should_return_pointer_to_ora_in_amora)
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

MU_TEST(test_strnstr_finding_ora_in_amora_but_len_0_should_return_NULL)
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

MU_TEST(test_strnstr_finding_ora_in_amora_but_len_50_should_return_pointer_to_ora_in_amora)
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

MU_TEST(test_strnstr_finding_orabolas_in_amora_but_len_50_should_return_NULL)
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

MU_TEST(test_strrchr_look_up_non_existing_character_in_string_should_return_NULL)
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

MU_TEST(test_strrchr_look_up_existing_character_in_string_should_return_its_address)
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

MU_TEST(test_strrchr_look_up_null_character_in_string_should_return_the_terminating_zero_address)
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

MU_TEST(test_strrchr_look_up_character_in_empty_string_should_return_null)
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

MU_TEST(test_strrchr_look_up_character_in_null_string_should_return_null)
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

MU_TEST(test_strlcat_concat_A_and_B_should_set_dst_as_AB)
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

MU_TEST(test_strlcat_concat_A_and_B_should_return_2)
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

MU_TEST(test_strlcat_concat_AB_and_C_should_set_dst_as_ABC_and_return_3)
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

MU_TEST(test_strlcat_concat_ABC_and_DEF_size_2_should_keep_dst_as_ABC_and_return_5)
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

MU_TEST(test_strlcat_concat_ABC_and_DE_size_1_should_keep_dst_as_ABC_and_return_3)
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

MU_TEST(test_strlcat_concat_ABC_and_DE_size_10_should_set_dst_as_ABCDE_and_return_5)
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

MU_TEST(test_strlcat_concat_AnullB_and_C_size_5_should_set_dst_as_AC_and_return_2)
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

MU_TEST(test_strlcat_concat_AnullB_and_C_size_15_should_set_dst_as_AC_and_return_2)
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

MU_TEST(test_strlcat_concat_AnullCD_and_B_size_15_should_set_dst_as_ABnullD_and_return_2)
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

MU_TEST(test_strlcat_concat_empty_dst_and_123456789_size_15_should_set_dst_as_123456789_and_return_9)
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

MU_TEST(test_strlcat_concat_dst_123_and_empty_src_size_15_should_keep_dst_as_123_and_return_3)
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

MU_TEST(test_putchar_fd_entering_A_in_empty_file)
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

MU_TEST(test_putstr_fd_entering_AB_in_empty_file)
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

MU_TEST(test_putend1_fd_entering_AB_in_empty_file)
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

MU_TEST(test_putnbr_fd_entering_42_in_empty_file)
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

MU_TEST(test_putnbr_fd_entering_minus42_in_empty_file)
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

MU_TEST(test_putnbr_fd_entering_MAX_INT_in_empty_file)
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

MU_TEST(test_putnbr_fd_entering_MIN_INT_in_empty_file)
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

MU_TEST(test_putnbr_fd_entering_0_in_empty_file)
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

MU_TEST(test_strdup_passing_one_letter_string)
{
	//ARRANGE
	char	s[] = "A";
	char	expected_result[] = "A";
	char	*actual_result;

	//ACT
	actual_result = ft_strdup(s);

	//ASSERT
	mu_assert(actual_result != s, "The returned pointer should not point to the same memory space passed by parameter");
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST(test_strdup_passing_ten_letters_string)
{
	//ARRANGE
	char	s[] = "1234567890";
	char	expected_result[] = "1234567890";
	char	*actual_result;

	//ACT
	actual_result = ft_strdup(s);

	//ASSERT
	mu_assert(actual_result != s, "The returned pointer should not point to the same memory space passed by parameter");
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST(test_strdup_passing_empty_string)
{
	//ARRANGE
	char	s[] = "";
	char	expected_result[] = "";
	char	*actual_result;

	//ACT
	actual_result = ft_strdup(s);

	//ASSERT
	mu_assert(actual_result != s, "The returned pointer should not point to the same memory space passed by parameter");
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST(test_strdup_passing_null_string)
{
	//ARRANGE
	char	*s = NULL;
	char	*expected_result = NULL;
	char	*actual_result;

	//ACT
	actual_result = ft_strdup(s);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
}

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

MU_TEST(test_memcmp_comparing_lula_and_lula_returns_0)
{
	//ARRANGE
	char	word1[] = "lula";
	char	word2[] = "lula";
	int	size = 4;
	int	expected_result = 0;
	int	actual_result;

	//ACT
	actual_result = ft_memcmp(word1, word2, size);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_memcmp_comparing_lula_and_lulu_returns_minus_1)
{
	//ARRANGE
	char	word1[] = "lula";
	char	word2[] = "lulu";
	int	size = 4;
	int	expected_result = -1;
	int	actual_result;

	//ACT
	actual_result = ft_memcmp(word1, word2, size);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_memcmp_comparing_lulu_and_lula_returns_1)
{
	//ARRANGE
	char	word1[] = "lulu";
	char	word2[] = "lula";
	int	size = 4;
	int	expected_result = 1;
	int	actual_result;

	//ACT
	actual_result = ft_memcmp(word1, word2, size);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

char	support_function_char_plus_one(unsigned int index, char s)
{
	char	plus_one;

	plus_one = s + 1 + index - index;
	return plus_one;
}

MU_TEST(test_strmapi_passing_a_and_plus_one_function_should_change_it_to_b)
{
	//ARRANGE
	char	s[] = "a";
	char	expected_result[] = "b";
	char	*actual_result;

	//ACT
	actual_result = ft_strmapi(s, support_function_char_plus_one);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST(test_strmapi_passing_abc_and_plus_one_function_should_change_it_to_bcd)
{
	//ARRANGE
	char	s[] = "abc";
	char	expected_result[] = "bcd";
	char	*actual_result;

	//ACT
	actual_result = ft_strmapi(s, support_function_char_plus_one);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST(test_strmapi_passing_empty_string_and_plus_one_function_should_return_NULL)
{
	//ARRANGE
	char	s[] = "";
	char	*expected_result = NULL;
	char	*actual_result;

	//ACT
	actual_result = ft_strmapi(s, support_function_char_plus_one);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST(test_strmapi_passing_abc_and_null_should_return_NULL)
{
	//ARRANGE
	char	s[] = "abc";
	char	*expected_result = NULL;
	char	*actual_result;

	//ACT
	actual_result = ft_strmapi(s, NULL);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST(test_strmapi_passing_null_and_plus_one_function_should_return_NULL)
{
	//ARRANGE
	char	*s = NULL;
	char	*expected_result = NULL;
	char	*actual_result;

	//ACT
	actual_result = ft_strmapi(s, support_function_char_plus_one);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
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

	MU_RUN_TEST(test_substr_entering_ABCDE_start_1_len_1_should_return_A);
	MU_RUN_TEST(test_substr_entering_ABCDE_start_1_len_1_should_return_B);
	MU_RUN_TEST(test_substr_entering_ABCDE_start_1_len_3_should_return_BCD);
	MU_RUN_TEST(test_substr_entering_ABCDE_start_1_len_8_should_return_BCDE);
	MU_RUN_TEST(test_substr_entering_ABCDE_start_1_len_0_should_return_NULL);
	MU_RUN_TEST(test_substr_entering_ABCDE_start_0_len_3_should_return_ABC);
	MU_RUN_TEST(test_substr_entering_empty_string_start_0_len_3_should_return_NULL);
	MU_RUN_TEST(test_substr_entering_ABCDE_start_5_len_1_should_return_NULL);

	MU_RUN_TEST(test_strjoin_entering_A_and_B_should_return_AB);
	MU_RUN_TEST(test_strjoin_entering_AB_and_CD_should_return_ABCD);
	MU_RUN_TEST(test_strjoin_entering_ABC_and_DEF_should_return_ABCDEF);
	MU_RUN_TEST(test_strjoin_entering_LULA_and_LIVRE_should_return_LULALIVRE);
	MU_RUN_TEST(test_strjoin_entering_empty_string_and_X_should_return_X);
	MU_RUN_TEST(test_strjoin_entering_X_and_empty_string_should_return_X);
	MU_RUN_TEST(test_strjoin_entering_empty_string_and_empty_string_should_return_empty_string);

	MU_RUN_TEST(test_strdup_passing_one_letter_string);
	MU_RUN_TEST(test_strdup_passing_ten_letters_string);
	MU_RUN_TEST(test_strdup_passing_empty_string);
	MU_RUN_TEST(test_strdup_passing_null_string);

	MU_RUN_TEST(test_striteri_passing_a_and_plus_one_function_should_change_it_to_b);
	MU_RUN_TEST(test_striteri_passing_abc_and_plus_one_function_should_change_it_to_bcd);
	MU_RUN_TEST(test_striteri_passing_empty_string_and_plus_one_function_should_not_change_it);
	MU_RUN_TEST(test_striteri_passing_abc_and_null_should_do_nothing);
	MU_RUN_TEST(test_striteri_passing_null_and_plus_one_function_should_do_nothing);

	MU_RUN_TEST(test_calloc_allocating_1_byte_char);
	MU_RUN_TEST(test_calloc_allocating_100000_bytes_char);
	MU_RUN_TEST(test_calloc_allocating_more_than_size_t_max_should_return_null);
	
	MU_RUN_TEST(test_memchr_searching_l_in_lula_returns_the_first_letter_pointer);
	MU_RUN_TEST(test_memchr_searching_u_in_lula_returns_the_second_letter_pointer);

	MU_RUN_TEST(test_memcmp_comparing_lula_and_lula_returns_0);
	MU_RUN_TEST(test_memcmp_comparing_lula_and_lulu_returns_minus_1);
	MU_RUN_TEST(test_memcmp_comparing_lulu_and_lula_returns_1);

	MU_RUN_TEST(test_strmapi_passing_a_and_plus_one_function_should_change_it_to_b);
	MU_RUN_TEST(test_strmapi_passing_abc_and_plus_one_function_should_change_it_to_bcd);
	MU_RUN_TEST(test_strmapi_passing_empty_string_and_plus_one_function_should_return_NULL);
	MU_RUN_TEST(test_strmapi_passing_abc_and_null_should_return_NULL);
	MU_RUN_TEST(test_strmapi_passing_null_and_plus_one_function_should_return_NULL);
}

int main() {
	MU_RUN_SUITE(test_suite);
	MU_RUN_SUITE(ft_memset_test_suite);
	MU_RUN_SUITE(ft_strtrim_test_suite);
	MU_RUN_SUITE(ft_strlcpy_test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
