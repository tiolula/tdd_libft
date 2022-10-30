#include "minunit.h"
#include "libft.h"
#include "../src/ft_memmove.c"

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

MU_TEST_SUITE(ft_memmove_test_suite) 
{
	MU_RUN_TEST(test_memmove_simple_dst_and_src_copyiing_5_positions);
	MU_RUN_TEST(test_memmove_dest_overlaping_src);
	MU_RUN_TEST(test_memmove_src_overlaping_dest);

}