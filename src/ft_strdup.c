/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lphelipe <lphelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 03:24:34 by    lphelipe       #+#    #+#             */
/*   Updated: 2022/10/29 12:58:12 by lphelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new_string;
	int		slen;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen(s);
	new_string = malloc(sizeof(char) * (slen + 1));
	ft_strlcpy(new_string, s, slen + 1);
	return (new_string);
}
