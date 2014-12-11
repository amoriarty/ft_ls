/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_annex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 11:15:01 by alegent           #+#    #+#             */
/*   Updated: 2014/12/11 18:36:04 by alegent          ###   ########.fr       */
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

t_entry				*new_entry(void)
{
	t_entry			*new;

	if ((new = (t_entry *)malloc(sizeof(t_entry))) == NULL
			|| (new->info = (t_stat *)malloc(sizeof(t_stat))) == NULL)
		return (NULL);
	return (new);
}

void				putcolor(char *str, char *color)
{
	ft_putstr(color);
	ft_putstr(str);
	ft_putstr(CANCEL);
}
