/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_first.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/24 10:41:40 by alegent           #+#    #+#             */
/*   Updated: 2014/12/24 10:45:47 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_node				*add_first(t_node *list, char *name, char *path)
{
	t_node			*new;

	if ((new = new_node(name, path)) == NULL)
		return (NULL);
	else
	{
		new->next = list->next;
		list->next = new;
	}
	return (list);
}
