/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 13:20:26 by alegent           #+#    #+#             */
/*   Updated: 2014/12/02 15:41:53 by alegent          ###   ########.fr       */
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

t_dlist				*append(t_dlist *list, char *name)
{
	t_entry			*new;

	if ((new = (t_entry *)malloc(sizeof(t_entry))) == NULL
			|| (new->info = (t_stat *)malloc(sizeof(t_stat))) == NULL)
		return (NULL);
	if (list != NULL)
	{
		new->name = ft_strdup(name);
		stat(name, new->info);
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

t_dlist				*prepend(t_dlist *list, char *name)
{
	t_entry			*new;

	if ((new = (t_entry *)malloc(sizeof(t_entry))) == NULL
			|| (new->info = (t_stat *)malloc(sizeof(t_stat))) == NULL)
		return (NULL);
	if (list != NULL)
	{
		new->name = ft_strdup(name);
		stat(name, new->info);
		new->prec = NULL;
		if (list->end == NULL)
		{
			list->begin = new;
			list->end = new;
			new->next = NULL;
		}
		else
		{
			list->begin->prec = new;
			new->next = list->begin;
			list->begin = new;
		}
		list->lenght++;
	}
	return (list);
}
