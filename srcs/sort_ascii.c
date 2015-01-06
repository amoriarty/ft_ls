/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 14:28:23 by alegent           #+#    #+#             */
/*   Updated: 2015/01/06 14:28:35 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_node				*sort_ascii(t_node *list, t_node *new)
{
	int				yes;
	t_node			*prec;
	t_node			*tmp;

	yes = FALSE;
	tmp = list;
	prec = NULL;
	if (!list)
		return (new);
	if (tmp)
	{
		while (tmp && ft_strcmp(tmp->name, new->name) <= 0)
		{
			yes = TRUE;
			prec = tmp;
			tmp = tmp->next;
		}
		if (prec)
			prec->next = new;
		new->next = tmp;
		if (yes)
			return (list);
		return (new);
	}
	return (list);
}
