/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_annex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 11:15:01 by alegent           #+#    #+#             */
/*   Updated: 2014/12/03 09:19:40 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					is_hidden(char *name)
{
	if (name[0] == '.')
		return (TRUE);
	return (FALSE);
}

size_t				digitlen(int n)
{
	size_t			res;

	res = 0;
	if (n > 9)
	{
		res++;
		return (res + digitlen(n / 10));
	}
	res++;
	return (res);
}
