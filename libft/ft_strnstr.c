/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/19 14:25:04 by alegent           #+#    #+#             */
/*   Updated: 2014/11/19 14:30:34 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		x;

	i = -1;
	if (!(s2[0]) || n == 0)
		return ((char *)s1);
	while (s1[++i] && i < n && (ft_strlen(s2) + i <= n))
	{
		x = 0;
		if (s1[i] == s2[x])
		{
			while (s1[i + x] == s2[x] && s1[i + x] && s2[x])
			{
				x++;
				if (!(s2[x]))
					return ((char *)s1 + i);
			}
		}
	}
	return (NULL);
}
