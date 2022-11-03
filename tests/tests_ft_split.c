/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ft_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lphelipe <lphelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:34:33 by lphelipe          #+#    #+#             */
/*   Updated: 2022/11/03 20:23:29 by lphelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minunit.h"
#include "libft.h"
#include "../src/ft_split.c"

MU_TEST(test_split_passing_a1b1c_using_1_as_delimiter_returns_an_array_with_a_b_c_NULL)
{
	//ARRANGE
	char	*input = "a1b1c";
	char	delimiter = '1';
	char	*expected_result[] = {"a", "b", "c"};
	char	**actual_result;

	//ACT
	actual_result = ft_split(input, delimiter);

	//ASSERT
	mu_assert_string_eq(expected_result[0], actual_result[0]);
	mu_assert_string_eq(expected_result[1], actual_result[1]);
	mu_assert_string_eq(expected_result[2], actual_result[2]);

	free(actual_result[0]);
	free(actual_result[1]);
	free(actual_result[2]);
	free(actual_result);
}

MU_TEST(test_split_passing_a2b2c_using_2_as_delimiter_returns_an_array_with_a_b_c_NULL)
{
	//ARRANGE
	char	*input = "a2b2c";
	char	delimiter = '2';
	char	*expected_result[] = {"a", "b", "c"};
	char	**actual_result;

	//ACT
	actual_result = ft_split(input, delimiter);

	//ASSERT
	mu_assert_string_eq(expected_result[0], actual_result[0]);
	mu_assert_string_eq(expected_result[1], actual_result[1]);
	mu_assert_string_eq(expected_result[2], actual_result[2]);

	free(actual_result[0]);
	free(actual_result[1]);
	free(actual_result[2]);
	free(actual_result);
}

MU_TEST_SUITE(ft_split_test_suite) 
{
	MU_RUN_TEST(test_split_passing_a1b1c_using_1_as_delimiter_returns_an_array_with_a_b_c_NULL);
	MU_RUN_TEST(test_split_passing_a2b2c_using_2_as_delimiter_returns_an_array_with_a_b_c_NULL);
}