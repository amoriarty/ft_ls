/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:32:41 by alegent           #+#    #+#             */
/*   Updated: 2014/11/28 12:40:52 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		x;
	char		*res;

	if (s == NULL)
		return (NULL);
	x = 0;
	res = ft_strnew((len));
	if (res == NULL)
		return (NULL);
	while (x < len)
	{
		res[x] = s[start];
		x++;
		start++;
	}
	return (res);
}
