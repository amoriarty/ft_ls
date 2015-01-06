/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 16:14:55 by alegent           #+#    #+#             */
/*   Updated: 2015/01/06 16:17:57 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_node		*opt_t(t_node *list, t_node *new, t_opt *opt)
{
	t_node			*tmp;
	t_node			*prec;
	int				yes;

	tmp = list;
	prec = NULL;
	yes = FALSE;
	while (tmp && ((!opt->r && new->info->st_mtime <= tmp->info->st_mtime) ||
				(opt->r && new->info->st_mtime > tmp->info->st_mtime)))
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

t_node				*insert_node(t_node *list, t_node *new, t_opt *opt)
{
	t_node			*tmp;
	t_node			*prec;
	int				yes;

	prec = NULL;
	tmp = list;
	yes = FALSE;
	if (!list)
		return (new);
	if (opt->t)
		return (opt_t(list, new, opt));
	while (tmp && ((opt->r && ft_strcmp(tmp->name, new->name) > 0) ||
				(!opt->r && ft_strcmp(tmp->name, new->name) <= 0)))
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
