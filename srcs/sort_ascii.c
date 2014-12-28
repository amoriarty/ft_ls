/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 16:54:19 by alegent           #+#    #+#             */
/*   Updated: 2014/12/18 17:03:16 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_node				*sort_ascii(t_node *list)
{
	t_node			*tmp;
	t_node			*tmp2;
	t_node			*res;

	res = list;
	while (list->next)
	{
		if (ft_strcmp(list->name, list->next->name) > 1)
		{
			tmp = res;
			while (ft_strcmp(tmp->next->name, list->next->name) <= 0)
				tmp = tmp->next;
			tmp2 = list->next;
			list->next = list->next->next;
			tmp2->next = tmp->next;
			tmp->next = tmp2;
			if (list->next == NULL)
				return (res);
		}
		list = list->next;
	}
	return (res);
}
