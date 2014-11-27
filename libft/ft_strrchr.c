/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:36:10 by alegent           #+#    #+#             */
/*   Updated: 2014/11/19 12:31:22 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	int		i;
	int		x;
	char	*dst;

	i = ft_strlen(s);
	x = 0;
	dst = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	while (s[i] != c && i >= 0)
		i--;
	if (s[i] == c)
	{
		while (s[i] != '\0')
		{
			dst[x] = s[i];
			i++;
			x++;
		}
		dst[x] = '\0';
		return (dst);
	}
	return (NULL);
}
