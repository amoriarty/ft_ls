/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:50:38 by alegent           #+#    #+#             */
/*   Updated: 2014/11/17 16:33:19 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*pdst;

	i = 0;
	pdst = (char *)dst;
	while (i < n)
	{
		*(char *)dst = *(char *)src;
		i++;
		dst++;
		src++;
	}
	return ((void *)pdst);
}
