/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:19:38 by coder             #+#    #+#             */
/*   Updated: 2022/09/05 01:16:23 by lphelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stddef.h>

unsigned char	*convert_to_unsigned_char(void *b)
{
	return ((unsigned char *)b);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*mem_pos;
	size_t			i;

	mem_pos = convert_to_unsigned_char(b);
	i = 0;
	while (i < len)
	{
		mem_pos[i] = c;
		i++;
	}
	return (b);
}
