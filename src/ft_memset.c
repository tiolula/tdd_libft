/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 16:19:38 by coder             #+#    #+#             */
/*   Updated: 2022/09/03 17:20:27 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned char	*convert_to_unsigned_char(void *b)
{
	return ((unsigned char *)b);
}

void	*ft_memset(void *b, int c, int len)
{
	unsigned char	*mem_pos;
	int				i;

	mem_pos = convert_to_unsigned_char(b);
	i = 0;
	while (i < len)
	{
		mem_pos[i] = c;
		i++;
	}
	return (b);
}
