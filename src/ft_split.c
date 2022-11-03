/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lphelipe <lphelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:45:32 by lphelipe          #+#    #+#             */
/*   Updated: 2022/11/03 20:37:35 by lphelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	char			**split;
	unsigned int	word_count;
	unsigned int	word_size;
	unsigned int	i;

	word_count = 3;
	split = ft_calloc(word_count + 1, sizeof(char *));
	i = 0;
	while (*s)
	{
		word_size = 1;
		if (*s != c)
		{
			word_size = 1;
			split[i] = ft_calloc(word_size + 1, sizeof(char));
			ft_strlcpy(split[i], s, word_size + 1);
			i++;
		}
		s += word_size;
	}
	return (split);
}
