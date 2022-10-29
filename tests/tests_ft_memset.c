/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ft_memset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lphelipe <lphelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:50:28 by lphelipe          #+#    #+#             */
/*   Updated: 2022/10/29 16:50:52 by lphelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

MU_TEST_SUITE(ft_memset_test_suite)
{
	MU_RUN_TEST(test_memset_setting_NUL_in_one_mem_position);
	MU_RUN_TEST(test_memset_setting_NUL_in_two_mem_positions);
	MU_RUN_TEST(test_memset_setting_NUL_in_two_mem_positions_should_return_the_original_pointer);
	MU_RUN_TEST(test_memset_setting_1_in_two_mem_positions);
}