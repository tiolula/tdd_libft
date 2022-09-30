/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 03:24:34 by coder             #+#    #+#             */
/*   Updated: 2022/09/30 03:40:01 by coder            ###   ########.fr       */
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
