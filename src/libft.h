/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lphelipe <lphelipe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 23:37:42 by lphelipe          #+#    #+#             */
/*   Updated: 2022/09/11 01:47:50 by lphelipe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stddef.h>

void	*ft_memset(void *b, int c, size_t len);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_toupper(int c);
void	ft_bzero(void *s, size_t n);
int		ft_atoi(const char *c);
char	*ft_itoa(int n);
#endif
