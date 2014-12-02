/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 13:20:26 by alegent           #+#    #+#             */
/*   Updated: 2014/12/02 14:10:26 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_dlist				*new_list(void)
{
	t_dlist			*new;

	if ((new = (t_dlist *)malloc(sizeof(t_dlist))) == NULL)
		return (NULL);
	new->lenght = 0;
	new->begin = NULL;
	new->end = NULL;
	return (new);
}

t_dlist				*append(t_dlist *list, char *name, t_stat *info)
{
	t_entry			*new;

	if ((new = (t_entry *)malloc(sizeof(t_entry))) == NULL)
		return (NULL);
	if (list != NULL)
	{
		new->name = ft_strdup(name);
		new->info = info;
		new->next = NULL;
		if (list->end == NULL)
		{
			list->begin = new;
			list->end = new;
			new->prec = NULL;
		}
		else
		{
			list->end->next = new;
			new->prec = list->end;
			list->end = new;
		}
		list->lenght++;
	}
	return (list);
}
