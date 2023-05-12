/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lphelipe <lphelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:45:32 by lphelipe          #+#    #+#             */
/*   Updated: 2023/05/12 00:34:20 by lphelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lentochar(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char			**split;
	unsigned int	word_count;
	unsigned int	word_size;
	unsigned int	i;

	word_count = 3;
	split = ft_calloc(word_count + 1, sizeof(char *));
	i = 0;
	word_size = 0;
	while (*s != '\0')
	{
		word_size = ft_lentochar(s, c);
		if (*s != c)
		{
			split[i] = ft_calloc(word_size + 1, sizeof(char));
			ft_strlcpy(split[i], s, word_size + 1);
			i++;
		}
		else
			s++;
		s += word_size;
	}
	split[i] = '\0';
	return (split);
}

//