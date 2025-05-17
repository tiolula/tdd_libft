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

int	ft_len_to_char(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

unsigned int    count_words(const char *s, char c)
{
    unsigned int	count;
    int				i;

    count = 0;
    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == c)
        {
            i++;
            continue;
        }
        count++;
        while (s[i] != c && s[i] != '\0')
        i++;
    }

    return (count);
}

int init(char ***split, char const *str, char delimiter, unsigned int *word_count)
{
    if (!str)
		return (1);
	*word_count = count_words(str, delimiter);
	*split = ft_calloc(*word_count + 1, sizeof(char *));
	if (!split)
		return (1);

	return (0);
}

char	**ft_split(char const *s, char c)
{
	char			**split;
	unsigned int	word_count;
	unsigned int	word_size;
	unsigned int	i;

	if (init(&split, s, c, &word_count))
	    return (NULL);
	i = 0;
	while (*s != '\0')
	{
		if (*s == c)
		{
			s++;
			continue;
		}
		word_size = ft_len_to_char(s, c);
		split[i] = ft_calloc(word_size + 1, sizeof(char));
		ft_strlcpy(split[i], s, word_size + 1);
		i++;
		s += word_size;
	}
	split[i] = NULL;
	return (split);
}
