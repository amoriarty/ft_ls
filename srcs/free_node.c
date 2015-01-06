/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 11:01:27 by alegent           #+#    #+#             */
/*   Updated: 2015/01/06 11:14:22 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			free_node(t_node *list)
{
	if (!list)
		return ;
	if (list->next)
		free_node(list->next);
	if (list->info)
		free(list->info);
	free(list->name);
	free(list->path);
	free(list);
}
