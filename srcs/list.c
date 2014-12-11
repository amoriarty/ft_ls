/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 13:20:26 by alegent           #+#    #+#             */
/*   Updated: 2014/12/11 10:53:08 by alegent          ###   ########.fr       */
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

t_dlist				*append(t_dlist *list, char *name, char *path)
{
	t_entry			*new;

	if ((new = (t_entry *)malloc(sizeof(t_entry))) == NULL
			|| (new->info = (t_stat *)malloc(sizeof(t_stat))) == NULL
			|| list == NULL)
		return (NULL);
	new->name = ft_strdup(name);
	stat(ft_strjoin(path, name), new->info);
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
	return (list);
}

t_dlist				*prepend(t_dlist *list, char *name, char *path)
{
	t_entry			*new;

	if ((new = (t_entry *)malloc(sizeof(t_entry))) == NULL
			|| (new->info = (t_stat *)malloc(sizeof(t_stat))) == NULL)
		return (NULL);
	if (list != NULL)
	{
		new->name = ft_strdup(name);
		stat(ft_strjoin(path, name), new->info);
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

static t_dlist		*tmp_tri(t_dlist *list, t_entry *n, t_entry *t, char *path)
{
	stat(ft_strjoin(path, n->name), n->info);
	t->prec->next = n;
	t->next->prec = n;
	n->prec = t->prec;
	n->next = t;
	list->lenght++;
	return (list);
}

t_dlist				*list_tri(t_dlist *list, char *name, char *path)
{
	t_entry			*new;
	t_entry			*tmp;

	if ((new = new_entry()) == NULL)
		return (NULL);
	if (list != NULL && list->begin != NULL)
	{
		new->name = ft_strdup(name);
		tmp = list->begin;
		while (tmp)
		{
			if (ft_strcmp(tmp->name, name) >= 0)
			{
				if (tmp->next == NULL)
					return (list = append(list, name, path));
				list = (tmp->prec == NULL) ? prepend(list, name, path)
					: tmp_tri(list, new, tmp, path);
			}
			if (tmp->next)
				tmp = tmp->next;
			else
				return (list = append(list, name, path));
		}
	}
	return (list->begin == NULL) ? (list = append(list, name, path)) : NULL;
}
