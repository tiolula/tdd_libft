#include "minunit.h"
#include "libft.h"
#include "../src/ft_putendl_fd.c"

MU_TEST(test_putendl_fd_entering_AB_in_empty_file)
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
	ft_putendl_fd(s, fd);
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

MU_TEST_SUITE(ft_putendl_fd_test_suite) 
{
MU_RUN_TEST(test_putendl_fd_entering_AB_in_empty_file);
}