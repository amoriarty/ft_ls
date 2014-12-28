/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 14:58:38 by alegent           #+#    #+#             */
/*   Updated: 2014/12/17 16:39:48 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_node				*add_node(t_node *list, char *name, char *path)
{
	t_node			*new;
	t_node			*tmp;

	if (list == NULL)
		return (new_node(name, path));
	else if (list && list->next == NULL)
	{
		if ((new = new_node(name, path)))
			list->next = new;
		return (list);
	}
	else
	{
		if ((new = new_node(name, path)))
		{
			tmp = list;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
			return (list);
		}
	}
	return (list);
}
