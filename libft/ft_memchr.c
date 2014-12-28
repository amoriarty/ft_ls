/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 19:21:44 by alegent           #+#    #+#             */
/*   Updated: 2014/11/17 16:32:23 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	char		*res;

	i = 0;
	while (i < n)
	{
		if (*(char *)s == (unsigned char)c)
		{
			res = (char *)s;
			return ((void *)res);
		}
		i++;
		s++;
	}
	return (NULL);
}
