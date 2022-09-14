/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lphelipe <lphelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 01:48:25 by lphelipe          #+#    #+#             */
/*   Updated: 2022/09/15 01:42:41 by lphelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n);

static int	helper_count_digits(int n)
{
	int	counter;

	counter = 1;
	while (n > 9)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		n_size;
	int		i;
	int		is_negative;

	is_negative = 0;
	if (n < 0)
	{
		is_negative = 1;
		n *= -1;
	}
	n_size = helper_count_digits(n);
	result = malloc(sizeof(char) * (n_size + is_negative + 1));
	ft_bzero(result, (n_size + is_negative + 1));
	result[n_size] = '\0';
	i = n_size - 1;
	while (i >= 0)
	{
		result[i + is_negative] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
	if (is_negative)
		result[0] = '-';
	return (result);
}
