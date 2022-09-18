/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lphelipe <lphelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:37:52 by lphelipe          #+#    #+#             */
/*   Updated: 2022/09/18 17:32:59 by lphelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	size_t	i;

	if (src > dest)
		return (ft_memcpy(dest, src, size));
	i = size;
	while (i > 0)
	{
		((char *)dest)[i - 1] = ((char *)src)[i - 1];
		i--;
	}
	return (dest);
}
