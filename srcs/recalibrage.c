/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recalibrage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alegent <alegent@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 10:01:17 by alegent           #+#    #+#             */
/*   Updated: 2014/12/09 17:27:32 by alegent          ###   ########.fr       */
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

size_t				len_usr(t_dlist *list)
{
	t_entry			*tmp;
	t_passwd		*my_passwd;
	size_t			len;

	len = 0;
	tmp = list->begin;
	while (tmp != NULL)
	{
		my_passwd = getpwuid(tmp->info->st_uid);
		if (len < ft_strlen(my_passwd->pw_name))
			len = ft_strlen(my_passwd->pw_name);
		tmp = tmp->next;
	}
	return (len);
}

size_t				len_grp(t_dlist *list)
{
	t_entry			*tmp;
	t_group			*my_grp;
	size_t			len;

	len = 0;
	tmp = list->begin;
	while (tmp != NULL)
	{
		my_grp = getgrgid(tmp->info->st_gid);
		if (len < ft_strlen(my_grp->gr_name))
			len = ft_strlen(my_grp->gr_name);
		tmp = tmp->next;
	}
	return (len);
}

void				print_total(t_dlist *list)
{
	size_t			size;
	t_entry			*tmp;

	size = 0;
	if ((tmp = (t_entry *)malloc(sizeof(t_entry))) == NULL)
		return ;
	tmp = list->begin;
	while (tmp != NULL)
	{
		size += tmp->info->st_blocks;
		tmp = tmp->next;
	}
	ft_putstr("total ");
	ft_putnbr(size);
	ft_putchar(EOL);
}
