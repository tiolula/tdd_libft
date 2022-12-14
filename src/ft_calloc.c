/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lphelipe <lphelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:55:28 by lphelipe          #+#    #+#             */
/*   Updated: 2022/10/29 12:59:00 by lphelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

// There is a verification to check if count * size is bigger than size_t.
// To prevent overflow on this evaluation, we pass 'size' to the other
// side of the equation.
// To prevent division by zero, we check it before evaluating.
// OMG.
void	*ft_calloc(size_t count, size_t size)
{
	void	*allocated;
	size_t	size_max;

	size_max = ((size_t) ~((size_t) 0));
	if (size != 0 && count > size_max / size)
		return (NULL);
	if (size * count == 0)
		return (NULL);
	allocated = malloc(count * size);
	if (allocated == NULL)
		return (NULL);
	ft_bzero(allocated, count * size);
	return (allocated);
}
