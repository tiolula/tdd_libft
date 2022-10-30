#include "minunit.h"
#include "libft.h"
#include "../src/ft_strlcat.c"

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

MU_TEST_SUITE(ft_strlcat_test_suite) 
{
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
}