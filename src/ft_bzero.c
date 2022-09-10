/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lphelipe <lphelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 22:58:06 by lphelipe          #+#    #+#             */
/*   Updated: 2022/09/10 22:59:37 by lphelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*typed_s;
	size_t			i;

	typed_s = ((unsigned char *)s);
	i = 0;
	while (i < n)
	{
		typed_s[i] = '\0';
		i++;
	}
}
