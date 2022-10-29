/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lphelipe <lphelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 04:05:47 by lphelipe          #+#    #+#             */
/*   Updated: 2022/09/30 04:20:59 by lphelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_word;
	char			len;
	unsigned char	i;

	len = 0;
	if (s)
		len = ft_strlen(s);
	if (f && len > 0)
	{
		new_word = ft_calloc(len + 1, sizeof(char));
		if (new_word)
		{
			i = 0;
			while (i < len)
			{
				new_word[i] = (f(i, s[i]));
				i++;
			}
			return (new_word);
		}
	}
	return (NULL);
}
