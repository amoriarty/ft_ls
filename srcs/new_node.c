/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 09:39:00 by alegent           #+#    #+#             */
/*   Updated: 2014/12/28 15:00:29 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_node				*new_node(char *name, char *path)
{
	t_node			*new;

	new = NULL;
	if ((new = (t_node *)malloc(sizeof(t_node))) == NULL)
		return (NULL);
	if ((new->info = (t_stat *)malloc(sizeof(t_stat))) == NULL)
		return (NULL);
	new->name = ft_strdup(name);
	if (is_complet(path) == FALSE)
		path = ft_strjoin(path, "/");
	lstat(ft_strjoin(path, name), new->info);
	new->next = NULL;
	return (new);
}
