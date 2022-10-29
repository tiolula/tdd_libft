/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ft_strtrim.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lphelipe <lphelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:49:18 by lphelipe          #+#    #+#             */
/*   Updated: 2022/10/29 19:31:00 by lphelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "libft.h"
#include "../src/ft_strtrim.c"

MU_TEST(test_strtrim_passing_space_abc_space_should_return_abc_with_no_spaces)
{
	//ARRANGE
	char	word[] = " abc ";
	char	search_key[] = " ";
	char	expected_result[] = "abc";
	char	*actual_result;

	//ACT
	actual_result = ft_strtrim(word, search_key);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST(test_strtrim_passing_1abc1_with_space_as_search_key_should_return_1abc1)
{
	//ARRANGE
	char	word[] = "1abc1";
	char	search_key[] = " ";
	char	expected_result[] = "1abc1";
	char	*actual_result;

	//ACT
	actual_result = ft_strtrim(word, search_key);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST(test_get_first_not_trimmed_index_searching_space_in_1abc1_should_return_0)
{
	//ARRANGE
	char	word[] = "1abc1";
	char	search_key[] = " ";
	int		expected_result = 0;
	int		actual_result;

	//ACT
	actual_result = get_first_not_trimmed_index(word, search_key);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}


MU_TEST(test_get_last_not_trimmed_index_searching_space_in_1abc1_should_return_4)
{
	//ARRANGE
	char	word[] = "1abc1";
	char	search_key[] = " ";
	int		word_len = 5;
	int		expected_result = 4;
	int		actual_result;

	//ACT
	actual_result = get_last_not_trimmed_index(word, search_key, word_len);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_get_first_not_trimmed_index_searching_o_in_oabco_should_return_1)
{
	//ARRANGE
	char	word[] = "oabco";
	char	search_key[] = "o";
	int		expected_result = 1;
	int		actual_result;

	//ACT
	actual_result = get_first_not_trimmed_index(word, search_key);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_get_last_not_trimmed_index_searching_o_in_oabco_should_return_3)
{
	//ARRANGE
	char	word[] = "oabco";
	char	search_key[] = "o";
	int		word_len = 5;
	int		expected_result = 3;
	int		actual_result;

	//ACT
	actual_result = get_last_not_trimmed_index(word, search_key, word_len);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_get_first_not_trimmed_index_searching_lula_in_lulalivre_should_return_4)
{
	//ARRANGE
	char	word[] = "lulalivre";
	char	search_key[] = "lula";
	int		expected_result = 4;
	int		actual_result;

	//ACT
	actual_result = get_first_not_trimmed_index(word, search_key);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_get_first_not_trimmed_index_searching_nada_in_lulalivre_should_return_0)
{
	//ARRANGE
	char	word[] = "lulalivre";
	char	search_key[] = "nada";
	int		expected_result = 0;
	int		actual_result;

	//ACT
	actual_result = get_first_not_trimmed_index(word, search_key);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_get_first_not_trimmed_index_searching_ba_in_balu_should_return_2)
{
	//ARRANGE
	char	word[] = "balu";
	char	search_key[] = "ba";
	int		expected_result = 2;
	int		actual_result;

	//ACT
	actual_result = get_first_not_trimmed_index(word, search_key);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_get_first_not_trimmed_index_searching_ba_in_babalu_should_return_4)
{
	//ARRANGE
	char	word[] = "babalu";
	char	search_key[] = "ba";
	int		expected_result = 4;
	int		actual_result;

	//ACT
	actual_result = get_first_not_trimmed_index(word, search_key);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_get_last_not_trimmed_index_searching_la_in_lu_should_return_1)
{
	//ARRANGE
	char	word[] = "lu";
	char	search_key[] = "la";
	int		word_len = 2;
	int		expected_result = 1;
	int		actual_result;

	//ACT
	actual_result = get_last_not_trimmed_index(word, search_key, word_len);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_get_last_not_trimmed_index_searching_lu_in_babalu_should_return_3)
{
	//ARRANGE
	char	word[] = "babalu";
	char	search_key[] = "lu";
	int		word_len = 6;
	int		expected_result = 3;
	int		actual_result;

	//ACT
	actual_result = get_last_not_trimmed_index(word, search_key, word_len);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_get_last_not_trimmed_index_searching_la_in_ulala_should_return_0)
{
	//ARRANGE
	char	word[] = "ulala";
	char	search_key[] = "la";
	int		word_len = 5;
	int		expected_result = 0;
	int		actual_result;

	//ACT
	actual_result = get_last_not_trimmed_index(word, search_key, word_len);

	//ASSERT
	mu_assert_int_eq(expected_result, actual_result);
}

MU_TEST(test_strtrim_passing_lulasemprelula_with_lula_as_search_key_should_return_sempre)
{
	//ARRANGE
	char	word[] = "lulasemprelula";
	char	search_key[] = "lula";
	char	expected_result[] = "sempre";
	char	*actual_result;
	
	//ACT
	actual_result = ft_strtrim(word, search_key);

	//ASSERT
	mu_assert_string_eq(expected_result, actual_result);
	free(actual_result);
}

MU_TEST_SUITE(ft_strtrim_test_suite) 
{
	MU_RUN_TEST(test_get_first_not_trimmed_index_searching_space_in_1abc1_should_return_0);
	MU_RUN_TEST(test_get_first_not_trimmed_index_searching_lula_in_lulalivre_should_return_4);
	MU_RUN_TEST(test_get_first_not_trimmed_index_searching_nada_in_lulalivre_should_return_0);
	MU_RUN_TEST(test_get_first_not_trimmed_index_searching_ba_in_balu_should_return_2);
	MU_RUN_TEST(test_get_first_not_trimmed_index_searching_ba_in_babalu_should_return_4);
	MU_RUN_TEST(test_get_first_not_trimmed_index_searching_o_in_oabco_should_return_1);
	MU_RUN_TEST(test_get_last_not_trimmed_index_searching_space_in_1abc1_should_return_4);
	MU_RUN_TEST(test_get_last_not_trimmed_index_searching_o_in_oabco_should_return_3);
	MU_RUN_TEST(test_get_last_not_trimmed_index_searching_la_in_lu_should_return_1);
	MU_RUN_TEST(test_get_last_not_trimmed_index_searching_lu_in_babalu_should_return_3);
	MU_RUN_TEST(test_get_last_not_trimmed_index_searching_la_in_ulala_should_return_0);
	MU_RUN_TEST(test_strtrim_passing_space_abc_space_should_return_abc_with_no_spaces);
	MU_RUN_TEST(test_strtrim_passing_1abc1_with_space_as_search_key_should_return_1abc1);
	MU_RUN_TEST(test_strtrim_passing_lulasemprelula_with_lula_as_search_key_should_return_sempre);
}