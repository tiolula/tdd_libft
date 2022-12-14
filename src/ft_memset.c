/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lphelipe <lphelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:19:38 by lphelipe          #+#    #+#             */
/*   Updated: 2022/10/29 12:58:06 by lphelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*typed_b;
	size_t			i;

	typed_b = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		typed_b[i] = c;
		i++;
	}
	return (b);
}
