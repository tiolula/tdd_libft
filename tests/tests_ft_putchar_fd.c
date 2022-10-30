#include "minunit.h"
#include "libft.h"
#include "../src/ft_putchar_fd.c"

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

MU_TEST_SUITE(ft_putchar_fd_test_suite) 
{
	MU_RUN_TEST(test_putchar_fd_entering_A_in_empty_file);
}