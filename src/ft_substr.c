/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lphelipe <lphelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 23:40:20 by lphelipe          #+#    #+#             */
/*   Updated: 2022/09/28 00:27:43 by lphelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*substring;

	i = 0;
	if (len != 0 && s[i] && start < ft_strlen(s))
	{
		if (ft_strlen(s) < len)
			len = ft_strlen(s);
		substring = malloc(sizeof(char) * (len) + sizeof(char));
		if (substring)
		{
			while (i < len && s[start + i])
			{
				substring[i] = s[start + i];
				i++;
			}
			substring[i] = '\0';
			return (substring);
		}
	}
	return (NULL);
}
