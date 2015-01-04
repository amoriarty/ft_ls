/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/04 15:03:41 by alegent           #+#    #+#             */
/*   Updated: 2015/01/04 15:33:33 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_node	*sort(t_node *list, t_node *new, t_opt *opt)
{
	if (opt->t)
	{
		while ((!(opt->r) && list && list->next &&
					new->info->st_mtime <= list->next->info->st_mtime)
				|| (opt->r && list && list->next &&
					new->info->st_mtime > list->next->info->st_mtime))
			list = list->next;
	}
	else
	{
		while ((!(opt->r) && list && list->next &&
					ft_strcmp(new->name, list->next->name) > 0)
				|| (opt->r && list && list->next &&
					ft_strcmp(new->name, list->next->name) <= 0))
			list = list->next;
	}
	return (list);
}

t_node			*insert_node(t_node *list, char *name, char *path, t_opt *opt)
{
	t_node			*first;
	t_node			*tmp;
	t_node			*new;

	if (!(new = new_node(name, path)))
		return (NULL);
	if (!list)
		return (new);
	else
		first = list;
	list = sort(list, new, opt);
	tmp = list->next;
	list->next = new;
	new->next = tmp;
	return (first);
}
