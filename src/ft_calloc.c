/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lphelipe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:55:28 by lphelipe          #+#    #+#             */
/*   Updated: 2022/10/27 19:21:54 by lphelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_calloc(size_t count, size_t size)
{
	void *allocated;
	printf(" VAI PRINTAAAAAAAAAAAAAAAAAAAAAAAAR\n");
	allocated = malloc(count * size);
	allocated[0] = 'L';
	printf("allocated: %s\n", allocated);
	return allocated;
}
