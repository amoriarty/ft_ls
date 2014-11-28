/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:00:40 by alegent           #+#    #+#             */
/*   Updated: 2014/11/19 14:57:36 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strchr(const char *s, int c)
{
	int		i;
	int		x;
	char	*dst;

	i = 0;
	x = 0;
	if (s == NULL)
		return (NULL);
	dst = (char *)malloc(sizeof(char) * ft_strlen(s));
	if (c == '\0')
		return (dst);
	while (s[i] && s[i] != c)
		i++;
	if (!(s[i]))
		return (NULL);
	while (s[i] != '\0')
	{
		dst[x] = s[i];
		i++;
		x++;
	}
	dst[x] = '\0';
	return (dst);
}
