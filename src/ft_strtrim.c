/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lphelipe <lphelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:11:15 by lphelipe          #+#    #+#             */
/*   Updated: 2022/10/29 19:41:53 by lphelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_first_not_trimmed_index(char const *s, char const *ignored_string)
{
	size_t	i;
	size_t	search_len;

	i = 0;
	search_len = ft_strlen(ignored_string);
	if (s[0] == ignored_string[0])
	{
		if (ft_strncmp(s, ignored_string, search_len) == 0)
		{
			i += search_len;
			i += get_first_not_trimmed_index(&s[i], ignored_string);
		}
	}
	return (i);
}

int	get_last_not_trimmed_index(char const *s, char const *ignored, int word_len)
{
	size_t	search_len;
	size_t	i;

	search_len = ft_strlen(ignored);
	i = word_len - search_len;
	if (ft_strncmp(&s[i], ignored, search_len) == 0)
	{
		word_len = get_last_not_trimmed_index(s, ignored, i) + 1;
	}
	return (word_len - 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		first_char_index;
	int		last_char_index;
	size_t	word_len;
	size_t	trimmed_word_len;
	char	*trimmed_word;

	if (!s1 || !set)
		return (NULL);
	word_len = ft_strlen(s1);
	first_char_index = get_first_not_trimmed_index(s1, set);
	last_char_index = get_last_not_trimmed_index(s1, set, word_len);
	trimmed_word_len = last_char_index - first_char_index + 1;
	trimmed_word = ft_calloc(trimmed_word_len + 1, sizeof(char));
	if (!trimmed_word)
		return (NULL);
	ft_strlcpy(trimmed_word, &s1[first_char_index], trimmed_word_len + 1);
	return (trimmed_word);
}
