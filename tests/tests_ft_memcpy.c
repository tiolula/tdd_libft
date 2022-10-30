#include "minunit.h"
#include "libft.h"
#include "../src/ft_memcpy.c"

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

MU_TEST_SUITE(ft_memcpy_test_suite) 
{
	MU_RUN_TEST(test_memcpy_simple_dst_and_src_copying_5_positions);
}