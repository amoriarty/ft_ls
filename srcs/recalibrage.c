/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recalibrage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 10:01:17 by alegent           #+#    #+#             */
/*   Updated: 2014/12/03 10:09:04 by alegent          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

size_t				len_nlink(t_dlist *list)
{
	size_t			len;
	t_entry			*tmp;

	len = 0;
	tmp = list->begin;
	while (tmp != NULL)
	{
		if (len < digitlen(tmp->info->st_nlink))
			len = digitlen(tmp->info->st_nlink);
		tmp = tmp->next;
	}
	return (len);
}

size_t				len_size(t_dlist *list)
{
	t_entry			*tmp;
	size_t			len;

	len = 0;
	tmp = list->begin;
	while (tmp != NULL)
	{
		if (len < digitlen(tmp->info->st_size))
			len = digitlen(tmp->info->st_size);
		tmp = tmp->next;
	}
	return (len);
}
