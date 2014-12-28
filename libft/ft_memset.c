/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:53:17 by alegent           #+#    #+#             */
/*   Updated: 2014/11/17 16:34:29 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		*ft_memset(void *b, int c, size_t len)
{
	size_t		i;
	char		*pb;

	i = 0;
	pb = (char *)b;
	while (i < len)
	{
		*(char *)b = (char)c;
		b++;
		i++;
	}
	return ((void *)pb);
}
