/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/18 17:13:16 by alegent           #+#    #+#             */
/*   Updated: 2014/12/18 17:23:19 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_node				*sort_time(t_node *list)
{
	t_node			*tmp;
	t_node			*tmp2;
	t_node			*res;

	res = list;
	while (list->next)
	{
		if (list->info->st_mtime < list->next->info->st_mtime)
		{
			tmp = res;
			while (tmp->next->info->st_mtime > list->next->info->st_mtime)
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
