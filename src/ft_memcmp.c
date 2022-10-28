/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lphelipe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 19:56:29 by lphelipe          #+#    #+#             */
/*   Updated: 2022/10/28 20:08:11 by lphelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)s1 < *(unsigned char *)s2)
			return (-1);
		if (*(unsigned char *)s1 > *(unsigned char *)s2)
			return (1);
		s1++;
		s2++;
		i++;
	}
	return (0);
}
