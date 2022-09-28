/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lphelipe <lphelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 00:34:52 by lphelipe          #+#    #+#             */
/*   Updated: 2022/09/28 01:08:22 by lphelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*word;
	int		len;

	len = ft_strlen(s1) + ft_strlen(s2);
	word = malloc(sizeof(char) * (len + 1));
	if (word)
	{
		ft_strlcpy(word, s1, ft_strlen(s1) + 1);
		ft_strlcat(word, s2, len + 1);
		return (word);
	}
	return (NULL);
}
