/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lphelipe <lphelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 23:19:15 by lphelipe          #+#    #+#             */
/*   Updated: 2022/09/27 00:06:40 by lphelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// first condition: does it still have 2 or more digits?
// > call it again removing the right digit (/10)
// second condition: is it a 1 digit negative number?
// > print a minus sign
// third condition: is it a negative number?
// > print the right digit * -1
// > else print the right digit
void	ft_putnbr_fd(int n, int fd)
{
	if (n < -9 || n > 9)
		ft_putnbr_fd(n / 10, fd);
	if (n < 0 && n >= -9)
		ft_putchar_fd('-', fd);
	if (n < 0)
		ft_putchar_fd(-(n % 10) + '0', fd);
	else
		ft_putchar_fd((n % 10) + '0', fd);
}
