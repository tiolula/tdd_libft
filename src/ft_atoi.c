/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lphelipe <lphelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 23:46:56 by lphelipe          #+#    #+#             */
/*   Updated: 2022/09/12 13:53:53 by lphelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(char c);

int	helper_is_space(const char c)
{
	if (c == ' '
		|| c == '\f'
		|| c == '\n'
		|| c == '\r'
		|| c == '\t'
		|| c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *c)
{
	int	result;
	int	i;
	int	negative;

	result = 0;
	i = 0;
	negative = 1;
	while (helper_is_space(c[0]))
		c++;
	if (c[i] == '-' || c[i] == '+')
	{
		if (c[i] == '-')
			negative = -1;
		c++;
	}
	while (ft_isdigit(c[i]))
	{
		result = (result * 10) + (c[i] - 48);
		i++;
	}
	return (result * negative);
}
