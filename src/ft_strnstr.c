/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lphelipe <lphelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 01:15:24 by lphelipe          #+#    #+#             */
/*   Updated: 2022/09/20 01:21:41 by lphelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*little == '\0')
		return ((char *) big);
	while (i++ < len && big[i])
	{
		if (big[i] == little[0])
		{
			while (little[j++])
			{
				if (big[i + j] != little[j])
				{
					j = 0;
					break ;
				}
				if (j == len - 1 || little[j + 1] == '\0')
					return ((char *)&big[i]);
			}
		}
	}
	return ((char *) 0);
}
