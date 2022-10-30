#include "minunit.h"
#include "libft.h"
#include "../src/ft_putnbr_fd.c"

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

MU_TEST_SUITE(ft_putnbr_fd_test_suite) 
{
	MU_RUN_TEST(test_putnbr_fd_entering_42_in_empty_file);
	MU_RUN_TEST(test_putnbr_fd_entering_minus42_in_empty_file);
	MU_RUN_TEST(test_putnbr_fd_entering_MAX_INT_in_empty_file);
	MU_RUN_TEST(test_putnbr_fd_entering_MIN_INT_in_empty_file);
	MU_RUN_TEST(test_putnbr_fd_entering_0_in_empty_file);
}